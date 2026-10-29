#!/usr/bin/env python3
"""Contract tests for the MorphOS QEMU harness."""

from __future__ import annotations

import hashlib
import importlib.util
from pathlib import Path
import tempfile
import unittest


MODULE_PATH = Path(__file__).with_name("harness.py")
SPEC = importlib.util.spec_from_file_location("morphos_qemu_harness", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
HARNESS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(HARNESS)


class HarnessContractTests(unittest.TestCase):
    def test_repository_manifest_is_valid(self) -> None:
        manifest = HARNESS.load_manifest(Path(__file__).with_name("fixture-manifest.json"))
        self.assertEqual(manifest["morphos"]["version"], "3.20")
        self.assertEqual(manifest["qemu"]["machine"], "pegasos2")

    def test_archive_listing_ignores_non_utf8_filenames(self) -> None:
        listing = b"boot.img\nmanual/Fran\xe7ais.txt\n"
        self.assertEqual(HARNESS.archive_member_count(listing, "boot.img"), 1)
        self.assertEqual(HARNESS.archive_member_count(listing, "missing.img"), 0)

    def test_verified_file_passes_and_corrupt_copy_fails(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "input"
            source.write_bytes(b"known fixture")
            spec = {
                "size": source.stat().st_size,
                "md5": hashlib.md5(source.read_bytes()).hexdigest(),
                "sha256": hashlib.sha256(source.read_bytes()).hexdigest(),
            }
            HARNESS.verify_file(source, spec, "test input")
            source.write_bytes(b"broken fixture")
            with self.assertRaisesRegex(HARNESS.HarnessError, "size mismatch|SHA256 mismatch|MD5 mismatch"):
                HARNESS.verify_file(source, spec, "test input")

    def test_serial_success_and_nonzero_counter_probe(self) -> None:
        markers = {
            "begin": "FBNG:BEGIN",
            "pass": "FBNG:PROGRAM=PASS",
            "exit_prefix": "FBNG:EXIT=",
        }
        HARNESS.parse_serial_log(
            "boot noise\r\nFBNG:BEGIN\r\nsmoke output\r\n"
            "FBNG:PROGRAM=PASS\r\nFBNG:EXIT=0\r\n",
            markers,
        )
        with self.assertRaisesRegex(HARNESS.HarnessError, "exit code 20"):
            HARNESS.parse_serial_log(
                "FBNG:BEGIN\nFBNG:PROGRAM=PASS\nFBNG:EXIT=20\n", markers
            )

    def test_missing_and_duplicate_markers_are_rejected(self) -> None:
        markers = {
            "begin": "FBNG:BEGIN",
            "pass": "FBNG:PROGRAM=PASS",
            "exit_prefix": "FBNG:EXIT=",
        }
        with self.assertRaisesRegex(HARNESS.HarnessError, "occurred 0 times"):
            HARNESS.parse_serial_log("FBNG:BEGIN\nFBNG:EXIT=0\n", markers)
        with self.assertRaisesRegex(HARNESS.HarnessError, "occurred 2 times"):
            HARNESS.parse_serial_log(
                "FBNG:BEGIN\nFBNG:BEGIN\nFBNG:PROGRAM=PASS\nFBNG:EXIT=0\n", markers
            )

    def test_malformed_and_out_of_order_markers_are_rejected(self) -> None:
        markers = {
            "begin": "FBNG:BEGIN",
            "pass": "FBNG:PROGRAM=PASS",
            "exit_prefix": "RESULT:",
        }
        with self.assertRaisesRegex(HARNESS.HarnessError, "malformed serial exit marker"):
            HARNESS.parse_serial_log(
                "FBNG:BEGIN\nFBNG:PROGRAM=PASS\nRESULT:not-a-number\n", markers
            )
        with self.assertRaisesRegex(HARNESS.HarnessError, "out of order"):
            HARNESS.parse_serial_log(
                "FBNG:PROGRAM=PASS\nFBNG:BEGIN\nRESULT:0\n", markers
            )

    def test_powerpc_elf_probe_has_a_counter_probe(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            executable = Path(directory) / "smoke"
            header = bytearray(20)
            header[:6] = b"\x7fELF\x01\x02"
            header[18:20] = (20).to_bytes(2, "big")
            executable.write_bytes(header)
            HARNESS.verify_morphos_executable(executable)
            header[5] = 1
            executable.write_bytes(header)
            with self.assertRaisesRegex(HARNESS.HarnessError, "32-bit big-endian"):
                HARNESS.verify_morphos_executable(executable)

    def test_qemu_command_has_no_network_and_uses_an_overlay(self) -> None:
        command = HARNESS.build_qemu_command(
            "qemu-system-ppc",
            "pegasos2",
            Path("boot.img"),
            Path("overlay.qcow2"),
            Path("payload.iso"),
            Path("serial.log"),
        )
        self.assertIn("pegasos2", command)
        self.assertIn("none", command[command.index("-net") + 1 : command.index("-net") + 2])
        self.assertTrue(any("overlay.qcow2" in argument for argument in command))
        self.assertFalse(any("morphos.qcow2" in argument for argument in command))


if __name__ == "__main__":
    unittest.main()
