#include "fbcunit.bi"

SUITE( fbc_tests.wstring_.wchr_ )

	const TESTVALUE_1 = wchr( 65, 66, 67 )
	const TESTVALUE_2 = wchr( 256, 257, 258 )
	
	declare sub run_test( byval s1 as wstring ptr, byval s2 as wstring ptr )	
	
	TEST( default )
	
		dim s as wstring * 32
		dim ps as wstring ptr
		
		s = TESTVALUE_1
		run_test( s, TESTVALUE_1 )
	
		s = TESTVALUE_2
		run_test( s, TESTVALUE_2 )
		
	END_TEST
	
	sub run_test( byval s1 as wstring ptr, byval s2 as wstring ptr )	
		
		CU_ASSERT( len( *s1 ) = len( *s2 ) )
		
		CU_ASSERT( *s1 = *s2 )
		
	end sub
	
	TEST( maximum_args )
	
		'' The maximum number of arguments is 32
		dim const_wstr_long as wstring * 33 = wchr( _
			48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, _
			64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 _
		)
		CU_ASSERT_EQUAL( const_wstr_long, "0123456789:;<=>?@ABCDEFGHIJKLMNO" )
	
		'' Test case where internal escape codes are emitted (causing maximum
		'' internal representation length) during compile-time evaluation
		#if sizeof(wstring) >= 2
			scope
				dim const_wstr_long as wstring * 33 = wchr( _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff, &hffff, &hffff, &hffff, _
					&hffff, &hffff _
				)
				dim correct as wstring * 33
				correct[0] = &hffff
				correct &= correct
				correct &= correct
				correct &= correct
				correct &= correct
				correct &= correct
				CU_ASSERT_EQUAL( const_wstr_long, correct )
			end scope
		#endif
	
		#if sizeof(wstring) = 4
			scope
				dim const_wstr_long as wstring * 33 = wchr( _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, &hffffffffU, _
					&hffffffffU, &hffffffffU _
				)
				dim correct as wstring * 33
				correct[0] = &hffffffffU
				correct &= correct
				correct &= correct
				correct &= correct
				correct &= correct
				correct &= correct
				CU_ASSERT_EQUAL( const_wstr_long, correct )
			end scope
		#endif
	END_TEST
	
	TEST( high_codepoints )
	
		'' Test compile-time evaluation of wchr. However there is no way
		'' to test that it produces the correct result if both host and
		'' target have wstring < 4 bytes, as clipping is inevitable.
		#if sizeof(wstring) >= 2
			CU_ASSERT( asc( wchr( &hffff ) ) = &hffff )
			'' In case the compiler evaluates ASC at compile-time, test with run-time ASC
			dim ws1 as wstring * 3 = wchr( &hffff )
			CU_ASSERT( asc( ws1 ) = &hffff )
		#endif
		#if sizeof(wstring) = 4
			'' &h10ffff is the max valid unicode codepoint
			CU_ASSERT( asc( wchr( &h10ffff ) ) = &h10ffff )
			dim ws2 as wstring * 3 = wchr( &h10ffff )
			CU_ASSERT( asc( ws2 ) = &h10ffff )
	
			'' Check characters out of unicode range
			CU_ASSERT( asc( wchr( &hffffffffU ) ) = &hffffffffU )
			dim ws3 as wstring * 3 = wchr( &hffffffffU )
			CU_ASSERT( asc( ws3 ) = &hffffffffU )
		#endif
	
		'' Force run-time evaluation of wchr
		dim temp as integer
		#if sizeof(wstring) >= 2
			temp = &hffff
			CU_ASSERT( wchr( temp ) = !"\uffff" )
			CU_ASSERT( asc( wchr( temp ) ) = &hffff )
		#endif
		#if sizeof(wstring) = 4
			temp = &h10ffff
			CU_ASSERT( asc( wchr( temp ) ) = &h10ffff )
			temp = &hffffffff
			CU_ASSERT( asc( wchr( temp ) ) = &hffffffffU )
		#endif
	
	END_TEST

	TEST( astral_codepoint_target_width )

		dim folded as wstring * 5 = "a" & wchr( &h1D11E ) & "b"
		dim direct as wstring * 3 = wchr( &h1D11E )
		dim bmp as wstring * 4 = "a" & wchr( &h20AC ) & "b"

		#if sizeof( wstring ) = 2
			CU_ASSERT_EQUAL( len( folded ), 4 )
			CU_ASSERT_EQUAL( folded[0], &h0061 )
			CU_ASSERT_EQUAL( folded[1], &hD834 )
			CU_ASSERT_EQUAL( folded[2], &hDD1E )
			CU_ASSERT_EQUAL( folded[3], &h0062 )
			CU_ASSERT_EQUAL( len( direct ), 2 )
			CU_ASSERT_EQUAL( direct[0], &hD834 )
			CU_ASSERT_EQUAL( direct[1], &hDD1E )
		#elseif sizeof( wstring ) = 4
			CU_ASSERT_EQUAL( len( folded ), 3 )
			CU_ASSERT_EQUAL( folded[0], &h0061 )
			CU_ASSERT_EQUAL( folded[1], &h1D11E )
			CU_ASSERT_EQUAL( folded[2], &h0062 )
			CU_ASSERT_EQUAL( len( direct ), 1 )
			CU_ASSERT_EQUAL( direct[0], &h1D11E )
		#endif

		'' Counter-probe: BMP values stay one code unit on both targets.
		CU_ASSERT_EQUAL( len( bmp ), 3 )
		CU_ASSERT_EQUAL( bmp[0], &h0061 )
		CU_ASSERT_EQUAL( bmp[1], &h20AC )
		CU_ASSERT_EQUAL( bmp[2], &h0062 )

	END_TEST
	
END_SUITE
