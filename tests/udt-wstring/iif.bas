#include "fbcunit.bi"
#include once "uwstring-fixed.bi"
#include once "chk-wstring.bi"

#define ustring UWSTRING_FIXED

SUITE( fbc_tests.udt_wstring_.iif_ )

	#macro check_wstring( expr, true_expr, false_expr )
		scope
			dim t1 as wstring * 50 = true_expr
			dim t2 as wstring * 50 = false_expr

			dim u1 as ustring = true_expr
			dim u2 as ustring = false_expr

			'' WSTRING = iif( expr, LITERAL1, LITERAL2 )
			scope
				dim a as wstring * 50 = iif( expr, true_expr, false_expr )
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				endif
			end scope

			'' WSTRING = iif( expr, WSTRING1, LITERAL2 )
			scope
				dim a as wstring * 50 = iif( expr, t1, false_expr )
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				endif
			end scope

			'' WSTRING = iif( expr, LITERAL1, WSTRING2 )
			Scope
				Dim a As WString * 50 = IIf( expr, true_expr, t2 )
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				EndIf
			End Scope

			'' WSTRING = iif( expr, WSTRING1, WSTRING2 )
			Scope
				Dim a As WString * 50 = IIf( expr, t1, t2 )
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				EndIf
			End Scope

			'' WSTRING = iif( expr, USTRING1, LITERAL2 )
			Scope
				Dim a As WString * 50 = IIf( expr, u1, false_expr )
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				EndIf
			End Scope

			'' WSTRING = iif( expr, LITERAL1, USTRING2 )
			Scope
				Dim a As WString * 50 = IIf( expr, true_expr, u2 )
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				EndIf
			End Scope

			'' WSTRING = iif( expr, USTRING1, USTRING2 )
			Scope
				Dim a As WString * 50 = IIf( expr, u1, u2 )
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( a, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( a, t2 )
				EndIf
			End Scope
		End Scope
	#endmacro

	#macro check_ustring( expr, true_expr, false_expr )
		Scope
			Dim t1 As WString * 50 = true_expr
			Dim t2 As WString * 50 = false_expr

			Dim u1 As ustring = true_expr
			Dim u2 As ustring = false_expr

			'' USTRING = iif( expr, LITERAL1, LITERAL2 )
			Scope
				Dim a As ustring = IIf( expr, true_expr, false_expr )
				Dim r As WString * 50 = a
				If( expr ) Then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				Else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				EndIf
			End Scope

			'' USTRING = iif( expr, WSTRING1, LITERAL2 )
			scope
				dim a as ustring = iif( expr, t1, false_expr )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

			'' USTRING = iif( expr, LITERAL1, WSTRING2 )
			scope
				dim a as ustring = iif( expr, true_expr, t2 )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

			'' USTRING = iif( expr, WSTRING1, WSTRING2 )
			scope
				dim a as ustring = iif( expr, t1, t2 )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

			'' USTRING = iif( expr, USTRING1, LITERAL2 )
			scope
				dim a as ustring = iif( expr, u1, false_expr )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

			'' USTRING = iif( expr, LITERAL1, USTRING2 )
			scope
				dim a as ustring = iif( expr, true_expr, u2 )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

			'' USTRING = iif( expr, USTRING1, USTRING2 )
			scope
				dim a as ustring = iif( expr, u1, u2 )
				dim r as wstring * 50 = a
				if( expr ) then
					CU_ASSERT_WSTRING_EQUAL( r, t1 )
				else
					CU_ASSERT_WSTRING_EQUAL( r, t2 )
				endif
			end scope

		end scope
	#endmacro

	TEST( wstring_iif )
		
		check_wstring(  0, "", "a" )
		check_wstring( -1, "", "a" )

		check_wstring(  0, "a", "xyz" )
		check_wstring( -1, "a", "xyz" )

		check_wstring(  0, !"\u3041\u3043\u3045", "a" )
		check_wstring( -1, !"\u3041\u3043\u3045", "a" )

		check_wstring(  0, "a", !"\u3041\u3043\u3045" )
		check_wstring( -1, "a", !"\u3041\u3043\u3045" )

		check_wstring(  0, !"\u3047", !"\u3041\u3043\u3045" )
		check_wstring( -1, !"\u3047", !"\u3041\u3043\u3045" )

	END_TEST

	TEST( ustring_iif )
		
		check_ustring(  0, "", "a" )
		check_ustring( -1, "", "a" )

		check_ustring(  0, "a", "xyz" )
		check_ustring( -1, "a", "xyz" )

		check_ustring(  0, !"\u3041\u3043\u3045", "a" )
		check_ustring( -1, !"\u3041\u3043\u3045", "a" )

		check_ustring(  0, "a", !"\u3041\u3043\u3045" )
		check_ustring( -1, "a", !"\u3041\u3043\u3045" )

		check_ustring(  0, !"\u3047", !"\u3041\u3043\u3045" )
		check_ustring( -1, !"\u3047", !"\u3041\u3043\u3045" )

	END_TEST

END_SUITE
