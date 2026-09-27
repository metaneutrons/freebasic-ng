'' WString 以语言允许的所有方式使用。
''
'' 这同时是一个展示和测试。下面的每个构造都经过检查，而不仅仅是编译，
'' 因此它也可以作为您可以信赖的文档：如果某种形式在此文件中，那么它就能工作，
'' 并且预期值会写在旁边。
''
'' 覆盖范围：每种声明形式，动态和固定，数组（静态、动态、多维、初始化），
'' UDT，继承和虚方法，属性，运算符重载，每种参数传递方式（BYVAL / BYREF /
'' BYREF AS CONST，动态和固定），指针，以及每种返回形式（BYVAL，BYREF，定长）。
''
'' 未覆盖，因为不支持：CONST u AS WString = "..."。
'' fbc 的 CONST 只接受 FB_DATATYPE_STRING —— WSTRING 也会被拒绝。
'' 请参阅 README.md 的“已知缺口”部分。此处的其他所有内容均有效。
#define UNICODE
#define ASTRAL WChr(&h1D11E)      '' 一个字符，两个代码单元
#include once "win/shlwapi.bi"
Dim FileName As WString * 260 = "C:\test.txt"
Print PathFileExistsW(FileName) 
Print PathFileExistsW(@FileName)
Print PathFileExistsW(StrPtr(FileName))
FileName &= "你好" & "123"
Print FileName & " 你好 " & WStr(123)
Dim FileName1 As WString = "C:\test.txt"
Print PathFileExistsW(FileName1) 
Print PathFileExistsW(@FileName1) 
Print PathFileExistsW(StrPtr(FileName1))
FileName1 = "你好" & "123)"
Print FileName1 & " 你好 " & WStr(123)
Print "SizeOf(WString)=" & SizeOf(WString)
Dim As WString Ptr FCaption = CAllocate((Len(FileName) + 1) * SizeOf(WString))
*FCaption = FileName
FCaption[Len(FileName) - 1] = WChr(65)
Print *FCaption


Dim As WString Ptr FCaption1 = CAllocate((Len(FileName1) + 1) * SizeOf(WString))
*FCaption1 = FileName1
FCaption1[0] = WChr(65)
Print *FCaption1

#define VER_MAJOR "1"
#define VER_MINOR "3"
#define VER_PATCH "8"
#define VER_BUILD "0"
Const VERSION    = VER_MAJOR + "." + VER_MINOR + "." + VER_PATCH
Const BUILD_DATE = __DATE__
Dim As WString FolderName, ExeFileName, ExeFileName111 = "abc.exe"
ExeFileName = IIf(FolderName = "", "/Projects/" , FolderName) & ExeFileName111
Print ExeFileName
Dim Shared As Integer g_run, g_fail
ExeFileName111 = WStr(g_run)
Declare Function total_len( u() As WString ) As Integer

Sub chk( ByRef nm As String, ByVal got As LongInt, ByVal want As LongInt )
    g_run += 1
    If( got <> want ) Then
        g_fail += 1
        Print "FAIL in chk, "; nm; " got="; got; " want="; want
    End If
End Sub

Sub chks( ByRef nm As WString, ByRef got As WString, ByRef want As WString )
    g_run += 1
    If( got <> want ) Then
        g_fail += 1
        Dim As WString a = got, b = want
        Print "FAIL in chks, "; nm; " got=["; a; "] want=["; b; "]"
    End If
End Sub


'' =====================================================================
''  1. 声明形式
'' =====================================================================

'' -- 模块级别的 SHARED，以及 COMMON SHARED
Dim Shared As WString g_dyn
Dim Shared As WString * 32 g_fix
Common Shared As WString g_common

Type MyZ Extends ZString
    Dim As Integer extraz
End Type

'' -- Extends WString / ZString: 旧版 wchar/zchar 缓冲类 UDT
Type UStringW Extends WString
    Dim As Integer extra
    Dim As Integer Length
    mData As WString
    Private:
	m_Capacity As Integer
Public:
	Declare Constructor()
	'Declare Constructor(ByRef Value As Const WString)
	Declare Constructor(ByRef Value As WString)
	'Declare Operator Let(ByRef Value As Const WString)
	Declare Operator Cast() As WString
	Declare Operator Let(ByRef Value As WString)
End Type

Private Constructor UStringW()
	mData = ""
End Constructor

Private Constructor UStringW(ByRef Value As WString)
	mData = Value
End Constructor

Private Operator UStringW.Let(ByRef lhs As WString)
 mData = lhs
End Operator

Private Operator UStringW.Cast() As WString
    Return mData
End Operator

'' -- FIXWSTR 多路径探测用的声明
Declare Sub p_fb ( ByRef s As WString )
Declare Function p_func ( ByVal p As WString Ptr ) As Integer

'' -- 类型别名可以像任何其他类型名称一样使用
Type ustr_t As WString
Type ufix_t As WString * 12

Sub decl_forms( )
    Print "两种顺序,带或不带初始化器"
    Dim As WString a
    Dim As WString b = "beta"
    Dim c As WString
    Dim d As WString = "delta"

    '' 一条语句中多个变量，混合初始化
    Dim As WString e, f = "phi", g

    a = "alpha" : c = "gamma" : e = "epsilon" : g = "omega"

    chks( "dim as WString a",          a, "alpha" )
    chks( "dim as WString b = ...",    b, "beta" )
    chks( "dim c as WString",          c, "gamma" )
    chks( "dim d as WString = ...",    d, "delta" )
    chks( "multiple in one dim",       e + f + g, "epsilonphiomega" )

    '' 定长 —— N 是代码单元数，不是字节数
    Dim As WString * 16 h = "fixed"
    Dim i As WString * 8 = "eight"
    chks( "dim as WString * 16",       h, "fixed" )
    chks( "dim i as WString * 8",      i, "eight" )
    chk ( "LEN of fixed is text len",  Len(h), 5 )
    chk ( "SIZEOF WString * 16",       SizeOf(h), 32 )      '' 16 个单元 × 2 字节

    '' VAR 推断为动态形式，即使源是定长的
    Var v1 = b + "!"
    Var v2 = h                        '' 来自 WString * 16 -> 动态
    chks( "VAR from expression",       v1, "beta!" )
    chks( "VAR from fixed",            v2, "fixed" )
    v2 += " grows"                    '' 证明它确实是动态的
    chks( "VAR result is dynamic",     v2, "fixed grows" )

    '' 类型别名
    Dim As ustr_t t1 = "aliased"
    Dim As ufix_t t2 = "alias12"
    chks( "TYPE alias, dynamic",       t1, "aliased" )
    chks( "TYPE alias, fixed",         t2, "alias12" )

    '' STATIC 在多次调用间保持其值
    Static As WString s_acc
    s_acc += "x"

    '' shared / common
    g_dyn = "shared"
    g_fix = "sharedfix"
    g_common = "common"
    chks( "DIM SHARED",                g_dyn, "shared" )
    chks( "DIM SHARED fixed",          g_fix, "sharedfix" )
    chks( "COMMON SHARED",             g_common, "common" )

    '' 指针：WString Ptr 是宽字符数据指针，*p 是单个代码单元
    Dim As WString Ptr p = @b
    chk( "WString PTR deref",          *p, Asc("b") )
    *p = Asc("B")
    chks( "write through the pointer",  b, "Beta" )
    chk ( "VARPTR is non-null",        CInt( VarPtr(b) <> 0 ), -1 )

    '' STRPTR 给出原始的 UTF-16 单元
    Dim As WString uni = WChr(&h20AC) & "A"
    Dim As UShort Ptr up = StrPtr(uni)      '' USHORT PTR，无需强制转换
    chk ( "STRPTR unit 0 (euro)",      up[0], &h20AC )
    chk ( "STRPTR unit 1 (A)",         up[1], Asc("A") )
End Sub

'' 两次调用间的 STATIC
Sub static_counter( ByRef out_len As Integer )
    Static As WString acc
    acc += "ab"
    out_len = Len(acc)
End Sub


'' =====================================================================
''  2. 数组
'' =====================================================================

Sub arrays( )
    Print "动态 WString 的定长数组"
    Dim As WString a(0 To 3)
    For i As Integer = 0 To 3
        a(i) = "item" & i
    Next
    chks( "array of dynamic",          a(2), "item2" )

    '' 带初始化器的数组
    Dim As WString b(0 To 2) = { "one", "two", "three" }
    chks( "array initialiser",         b(0) + b(1) + b(2), "onetwothree" )

    '' 定长 WString 的数组
    Dim As WString * 8 c(0 To 2)
    c(0) = "aa" : c(1) = "bb" : c(2) = "cc"
    chks( "array of fixed",            c(0) + c(1) + c(2), "aabbcc" )
'
    '' 多维
    Dim As WString d(0 To 1, 0 To 1)
    d(0,0) = "00" : d(0,1) = "01" : d(1,0) = "10" : d(1,1) = "11"
    chks( "2-D array",                 d(1,0), "10" )

    '' 动态数组，用 REDIM PRESERVE 扩展
    ReDim As WString e(0 To 1)
    e(0) = "keep" : e(1) = "me"
    ReDim Preserve e(0 To 4)
    e(4) = "added"
    chks( "REDIM PRESERVE keeps [0]",  e(0), "keep" )
    chks( "REDIM PRESERVE keeps [1]",  e(1), "me" )
    chks( "REDIM PRESERVE new slot",   e(4), "added" )
    chk ( "UBOUND after REDIM",        UBound(e), 4 )
'
    '' ERASE 释放内容
    Erase(e)  
    'chk ( "ERASE empties the array - Erase e ",   Len(e(0)), 0 )
    
    '' 通过描述符传递给过程的数组
    chk ( "array BYDESC total length", total_len( a() ), 5 * 4 )
End Sub

'' 数组通过描述符传递
Function total_len( u() As WString ) As Integer
    Dim As Integer n
    For i As Integer = LBound(u) To UBound(u)
        n += Len( u(i) )
    Next
    Return n
End Function


'' =====================================================================
''  3. 用户定义类型
'' =====================================================================

Type Simple
    As WString      dyn            '' 动态字段
    As WString * 8  fix            '' 定长字段
    As WString      arr(0 To 2)    '' 数组字段
End Type

Type Inner
    As WString tag
End Type

Type Outer
    As Inner   inner_
    As WString name
End Type

Union UBox
    As WString * 4 text            '' 仅定长：联合成员不能是变长描述符
    As UShort      units(0 To 3)
End Union

'' 带有构造函数、析构函数、属性和运算符的类型
Type Box
    Public:
        Declare Constructor( )
        Declare Constructor( ByRef s As WString )
        Declare Destructor( )
        Declare Property value( ) As WString
        Declare Property value( ByRef s As WString )
        Declare Property valueNumber( ) As Integer
        Declare Property valueNumber( ByVal s As Integer)
        Declare Operator let( ByRef s As WString )
        Declare Operator cast( ) As WString
        Declare Operator [](ByRef iKey As WString) As WString
        Declare Function shout( ByRef s As WString = "" ) As WString
        As WString LetFixWstr
    Private:
        As WString m_v
        As Integer m_Number
End Type

Constructor Box( )
    m_v = "(empty)"
End Constructor

Constructor Box( ByRef s As WString )
    m_v = s
End Constructor

Destructor Box( )
    '' m_v 由生成的字段析构函数销毁
End Destructor

Property Box.value( ) As WString
    Return m_v
End Property

Property Box.value( ByRef s As WString )
    m_v = s
End Property

Property Box.valueNumber( ) As Integer
    Return m_Number
End Property

Property Box.valueNumber( ByVal s As Integer )
    m_Number = s
End Property

Operator Box.let( ByRef s As WString )
    m_v = s
End Operator

Operator Box.cast( ) As WString
    Return m_v
End Operator

Operator Box.[](ByRef iKey As WString) As WString
    Return m_v
End Operator

Function Box.shout( ByRef s As WString = "") As WString
    Return UCase( m_v ) & s & "!"
End Function

'' 接受 WString 的自由运算符
Operator + ( ByRef b As Box, ByRef s As WString ) As WString
    Return b.value & s
End Operator

Sub udts( )
    Print "测试UDTs"
    Dim As Simple s
    s.dyn = "dynamic field"
    s.fix = "fixed"
    s.arr(1) = "in an array field"
    chks( "UDT dynamic field",         s.dyn, "dynamic field" )
    chks( "UDT fixed field",           s.fix, "fixed" )
    chks( "UDT array field",           s.arr(1), "in an array field" )

    Dim As Outer o
    o.inner_.tag = "nested"
    o.name = "outer"
    chks( "nested UDT field",          o.inner_.tag, "nested" )

    '' WITH
    With o
        .name = "with-assigned"
    End With
    chks( "WITH block",                o.name, "with-assigned" )

    Dim As UBox ub
    ub.text = "AB"
    chk ( "UNION fixed member unit 0", ub.units(0), Asc("A") )
    chk ( "UNION fixed member unit 1", ub.units(1), Asc("B") )

    '' 构造函数
    Dim As Box b1
    Dim As Box b2 = Box( "made" )
    chks( "default constructor",       b1.value, "(empty)" )
    chks( "constructor with WString",  b2.value, "made" )

    '' 属性 get/set
    b1.value = "via property"
    chks( "property set/get",          b1.value, "via property" )
    '' @/StrPtr 作用于属性 get：取返回的临时 wstring 的数据指针
    Dim As WString Ptr pprop = @b1.value
    chk ( "property @ non-null",       CInt( pprop <> 0 ), -1 )
    chks( "property @ deref",          *pprop, "via property" )
    Dim As Any Ptr psp = StrPtr(b1.value)
    chk ( "property StrPtr non-null",  CInt( psp <> 0 ), -1 )

    '' OPERATOR LET
    b1 = "via LET"
    chks( "OPERATOR LET",              b1.value, "via LET" )

    '' OPERATOR CAST 转换为 WString
    Dim As WString casted = b1
    chks( "OPERATOR CAST",             casted, "via LET" )

    '' 返回 WString 的方法
    chks( "method returns WString",    b2.shout(), "MADE!" )

    '' 自由运算符
    chks( "free operator +",           b2 + " it", "made it" )
    '' 自由运算符
    chks( "free operator &",           b2 & " by", "made by" )

    '' UDT 数组，每个都带有 WString 字段
    Dim As Box boxes(0 To 2)
    For i As Integer = 0 To 2
        boxes(i).value = "box" & i
    Next
    chks( "array of UDTs",             boxes(2).value, "box2" )
    Dim As WString sh = b2.shout( )   ' 方法返回临时值, 不能作 &= 左值; 用属性演示 UDT 复合赋值
    b2.value &= "中"
    chks( "operator of UDTs &=",      b2.value, "made中" )
    b2.value += "文"
    chks( "operator of UDTs +=",      b2.value, "made中文" )
    b2.valueNumber = 123456
    Dim As WString * 260 FileName = "中文"
    Print "b2[]=" & b2["Test"]
    b2.value = b2.shout("made" & FileName)
    b2.value &= WStr(g_run)
    b2.LetFixWstr = FileName
End Sub


'' =====================================================================
''  4. “类” —— FB 中用 TYPE ... EXTENDS 表示
'' =====================================================================

Type Animal Extends Object
    Declare Constructor( )
    Declare Constructor( ByRef nm As WString )
    Declare Virtual Function speak( ) As WString
    Declare Virtual Destructor( )
    As WString name
End Type

Constructor Animal( )
    name = "(unnamed)"
End Constructor

Constructor Animal( ByRef nm As WString )
    name = nm
End Constructor

Virtual Destructor Animal( )
End Destructor

Virtual Function Animal.speak( ) As WString
    Return name & " makes a sound"
End Function

Type Dog Extends Animal
    Declare Constructor( ByRef nm As WString )
    Declare Function speak( ) As WString Override
End Type

Constructor Dog( ByRef nm As WString )
    Base( nm )
End Constructor

Function Dog.speak( ) As WString
    Return name & " says wöff"
End Function

Sub classes( )
    Dim As Animal a = Animal( "Generic" )
    chks( "base virtual method",       a.speak(), "Generic makes a sound" )

    Dim As Dog d = Dog( "Rex" )
    chks( "derived override",          d.speak(), "Rex says w" & WChr(&hF6) & "ff" )

    '' 通过基类指针调用 —— vtable 分发返回 WString
    Dim As Animal Ptr p = @d
    chks( "virtual via base ptr",      p->speak(), "Rex says w" & WChr(&hF6) & "ff" )

    '' NEW / DELETE
    Dim As Dog Ptr heap_ = New Dog( "Heap" )
    chks( "NEW'd object",              heap_->speak(), "Heap says w" & WChr(&hF6) & "ff" )
    Delete heap_
End Sub


'' =====================================================================
''  5. 参数传递
'' =====================================================================

'' BYVAL —— 被调用者获得副本，调用者不受影响
Sub p_byval( ByVal u As WString )
    u += " MODIFIED"
End Sub

'' BYREF —— 被调用者通过引用修改调用者
Sub p_byref( ByRef u As WString )
    u += " MODIFIED"
End Sub

'' BYREF AS CONST —— 只读，也接受字面量和临时值
Function p_byref_const( ByRef u As Const WString ) As Integer
    Return Len( u )
End Function

'' BYVAL AS CONST
Function p_byval_const( ByVal u As Const WString ) As Integer
    Return Len( u )
End Function

'' 定长参数绑定到动态参数
Function p_from_fixed( ByRef u As Const WString ) As WString
	Dim As Const WString Ptr p = @u
	Dim As Integer  Posi = InStr(LCase(u), "gdb")
    Return UCase( u )
End Function

'' 注意：“byref f as WString * 8” 无法编译 —— FB 拒绝定长字符串与 BYREF
'' 结合，对任何字符串类型都是如此：
''
''   error 324: Fixed-length string combined with BYREF (not supported)
''
'' 对于 STRING * N, ZSTRING * N 和 WSTRING * N 完全相同，因此这是 FB
'' 的通用规则，不是 WString 的限制。使用动态参数；定长实参可以绑定到它，
'' 并且通过它写回是有效的。
Sub p_fixed( ByRef f As WString )
    f = "setfix"
End Sub

'' 指针参数：p 是宽字符数据指针，*p 是单个代码单元
Sub p_ptr( ByVal p As WString Ptr )
    *p = Asc("P")
End Sub

'' 带默认值的可选参数
Function p_optional( ByRef u As Const WString = "defaulted" ) As WString
    Return u
End Function

'' 仅在字符串类型上不同的重载 —— 解析必须选择正确的
Function which_ovl Overload ( ByRef u As Const WString ) As String
    Return "WString"
End Function
Function which_ovl Overload ( ByRef s As Const String ) As String
    Return "string"
End Function
Function which_ovl Overload ( ByVal w As Const WString Ptr ) As String
    Return "wstring"
End Function

Sub params( )
    Dim As WString u = "orig"

    p_byval( u )
    chks( "BYVAL does not modify",     u, "orig" )

    p_byref( u )
    chks( "BYREF modifies",            u, "orig MODIFIED" )
     
    chk ( "BYREF AS CONST",            p_byref_const( u ), 13 )
    chk ( "BYREF AS CONST literal",    p_byref_const( "12345" ), 5 )
    chk ( "BYREF AS CONST temporary",  p_byref_const( u + "xx" ), 15 )
    chk ( "BYVAL AS CONST",            p_byval_const( "中㊎㊏" ), 3 )

    '' STRING 实参在传入时转换
    chk ( "narrow arg converts",       p_byref_const( "plain string" ), 12 )

    '' 定长实参传递给动态参数
    Dim As WString * 16 f = "fixedarg"
    chks( "fixed arg -> dynamic param", p_from_fixed( f ), "FIXEDARG" )

    '' 定长参数
    Dim As WString * 8 g = "before"
    p_fixed( g )
    chks( "fixed-length parameter",    g, "setfix" )

    '' 指针参数
    Dim As WString h = "point"
    p_ptr( @h )
    chks( "WString PTR parameter",     h, "Point" )

    '' 可选参数
    chks( "optional, omitted",         p_optional( ), "defaulted" )
    chks( "optional, supplied",        p_optional( "given" ), "given" )
    If p_optional( g) <> p_optional( g) Then 
    	
    End If
    '' 重载解析
    Dim As WString ou = "u"
    Dim As String  os = "s"
    Dim As WString Ptr op = @ou
    chk ( "overload picks WString",    CInt( which_ovl( ou ) = "WString" ), -1 )
    chk ( "overload picks string",     CInt( which_ovl( os ) = "string" ), -1 )
    chk ( "overload picks wstring",    CInt( which_ovl( op ) = "wstring" ), -1 )
End Sub


'' =====================================================================
''  6. 返回值
'' =====================================================================

'' 按值，通过 RETURN
Function r_return( ) As WString
    Return "returned"
End Function

'' 按值，通过函数名
Function r_fname( ) As WString
    r_fname = "by name"
End Function

'' 注意：“function r() as WString * 8” 无法编译：
''
''   error 55: Fixed-len strings cannot be returned from functions
''
'' 与 STRING * N 和 WSTRING * N 相同。定长结果将是指向无处可存的缓冲区的
'' 指针。应返回动态形式 —— 调用者可以直接将其赋值给定长变量。
''
'' （这是通过编写此文件发现的一个真正的 WString 错误：parser-proc.bas 中
'' 缺少对 FIXUSTR 的检查，因此它被接受然后错误编译 —— gcc 后端将结果
'' 类型视为单个 uint16 并将返回的指针截断为 16 位。）
Function r_into_fixed( ) As WString
    Return "fixedret"
End Function

'' BYREF 结果 —— 返回对调用者自身变量的引用
Function r_byref( ByRef u As WString ) ByRef As WString
    Return u
End Function

'' 由多个项构建的结果
Function r_built( ByVal n As Integer ) As WString
    Dim As WString acc
    For i As Integer = 1 To n
        acc += "ab"
    Next
    Return acc
End Function

Sub returns( )
    chks( "RETURN a WString",          r_return(), "returned" )
    chks( "result via function name",  r_fname(), "by name" )
    '' 将动态结果赋值给定长变量。
    '' 注意容量：WString * 8 可容纳 8 个代码单元（包括终止符），
    '' 因此文本为 7 个字符 —— 与 WSTRING * 8 相同，不同于 STRING * 8
    '' （无终止符，可容纳完整 8 个字符）。
    Dim As WString * 8 into = r_into_fixed()
    chks( "dynamic result -> fixed var", into, "fixedre" )
    chk ( "WString * 8 holds 7 units",  Len( into ), 7 )
    Dim As WString * 9 into9 = r_into_fixed()
    chks( "WString * 9 holds all 8",   into9, "fixedret" )

    '' BYREF 结果作为对调用者自身变量的引用进行读取。
    '' 注意：将其用作赋值目标 —— r_byref(t) = "x" —— 无法编译，
    '' 对 STRING 也是如此（错误 58），因此这是关于字符串结果的 FB 规则，
    '' 与 WString 无关。
    Dim As WString target = "start"
    chks( "BYREF result reads",        r_byref( target ), "start" )
    chk ( "BYREF result in LEN",       Len( r_byref( target ) ), 5 )
    target += "ed"
    chks( "BYREF result tracks source", r_byref( target ), "started" )

    chks( "built result",              r_built(3), "ababab" )
    chk ( "result used in an expr",    Len( r_return() & r_fname() ), 15 )

    '' 丢弃的结果不得泄漏临时描述符 —— 如果泄漏，20000 个将耗尽 256 槽的池
    For i As Integer = 1 To 20000
        r_return()
    Next
    chks( "pool survives discards",    r_return(), "returned" )
End Sub


'' =====================================================================
''  7. [] 索引 —— 读写单个代码单元
'' =====================================================================
''
'' u[i] 是一个 16 位代码单元，从零开始，双向 O(1)。
'' 它读取为数字（单元的值），而不是单字符字符串，
'' 与 STRING 和 WSTRING 索引相同。

Sub indexing( )
	Print "[] 索引 —— 读写单个代码单元"
    '' -- 读取
    Dim As WString u = "中㊎㊏"
    chk( "u[0]",                       u[0], Asc("中") )
    chk( "u[1]",                       u[1], Asc("㊎") )
    chk( "u[len-1] is the last unit",  u[Len(u) - 1], Asc("㊏") )
    chk( "u[len] is the terminator",   u[Len(u)], 0 )

    '' -- 写入
    u[1] = Asc("X")
    chks( "write through u[i]",         u, "中X㊏" )
    chk ( "and reads back",             u[1], Asc("X") )

    '' -- 非 ASCII BMP 字符读取为其实际码点
    Dim As WString e = WChr(&h20AC) & "A"        '' 欧元符号
    chk( "euro unit value",             e[0], 8364 )
    chk( "euro is one unit",            Len(e), 2 )

    '' -- 辅助字符是代理对：两个单元，一个字符
    Dim As WString m = "a" & ASTRAL & "b"
    chk( "astral string is 4 units",    Len(m), 4 )
    chk( "m[0] is 'a'",                 m[0], Asc("a") )
    chk( "m[1] is the HIGH surrogate",  m[1], &hD834 )
    chk( "m[2] is the LOW surrogate",   m[2], &hDD1E )
    chk( "m[3] is 'b'",                 m[3], Asc("b") )

    '' 可以从两个单元重建该对
    Dim As UInteger cp = &h10000 + ((m[1] - &hD800) Shl 10) + (m[2] - &hDC00)
    chk( "units recombine to U+1D11E",  cp, &h1D11E )

    '' -- 对定长 WString 进行索引，读写
    Dim As WString * 8 f = "中㊎㊏"
    chk ( "fixed f[1]",                 f[1], Asc("㊎") )
    f[1] = Asc("Y")
    chks( "write through f[i]",         f, "中Y㊏" )

    '' -- 对 UDT 字段、数组元素和通过指针进行索引
    Dim As Simple sm
    sm.dyn = "field"
    sm.arr(0) = "array"
    chk( "index a UDT field",           sm.dyn[0], Asc("f") )
    sm.dyn[0] = Asc("F")
    chks( "write into a UDT field",     sm.dyn, "Field" )
    chk( "index an array field",        sm.arr(0)[0], Asc("a") )

    Dim As WString arr(0 To 1)
    arr(1) = "zed"
    chk( "index an array element",      arr(1)[0], Asc("z") )

    Dim As WString Ptr p = @u
    chk( "index through a pointer",     (*p)[0], Asc("中") )

    '' -- [] 和 STRPTR 必须一致，因为两者都遍历同一缓冲区
    Dim As UShort Ptr raw = StrPtr(e)
    chk( "STRPTR agrees with [] at 0",  raw[0], e[0] )
    chk( "STRPTR agrees with [] at 1",  raw[1], e[1] )

    '' -- 在循环中索引：求和单元，并从它们重建字符串
    Dim As WString src = "Hello"
    Dim As Integer sum
    Dim As WString rebuilt
    For i As Integer = 0 To Len(src) - 1
        sum += src[i]
        rebuilt += WChr( src[i] )
    Next
    chk ( "sum of units",               sum, 500 )     '' 72+101+108+108+111
    chks( "rebuilt from its units",     rebuilt, src )

    '' -- 就地反转字符串，完全通过 []
    Dim As WString rev = "中㊎㊏def"
    For i As Integer = 0 To Len(rev)\2 - 1
        Dim As UInteger t = rev[i]
        rev[i] = rev[Len(rev)-1-i]
        rev[Len(rev)-1-i] = t
    Next
    chks( "reversed via []",            rev, "fed㊏㊎中" )
End Sub


'' =====================================================================
''  8. WString 作为指针
'' =====================================================================
''
'' 两种指针，容易混淆：
''
''   WString PTR   宽字符数据指针（WCHAR PTR），完全保持 legacy 语义。
''                 解引用得到一个 UTF-16 代码单元；索引/算术按 2 字节
''                 单元进行。LPWSTR / PWSTR 就是它。
''   USHORT PTR    STRPTR() 返回的：同一缓冲区，同样按代码单元遍历。
''
'' @s 与 STRPTR(s) 一致，都是数据地址；VARPTR(s) 是描述符地址（与
'' STRING 的规则相同）。定长 WString * N 的变量本身就是缓冲区，因此
'' @ / STRPTR / VARPTR 三者一致。

'' 接受并返回指向 WString 的指针（返回的是数据指针）
Function first_nonempty( p() As WString ) As WString Ptr
    For i As Integer = LBound(p) To UBound(p)
        If( Len( p(i) ) > 0 ) Then Return @p(i)
    Next
    Return 0
End Function

'' 通过数据指针把 extra 的第一个字符写到目标（*p 是单个代码单元）
Sub append_through( ByVal p As WString Ptr, ByRef extra As Const WString )
    If( p <> 0 ) Then *p = extra[0]
End Sub

Type Holder
    As WString Ptr q
End Type

Sub pointers( )
    Dim As WString u = "中㊎㊏"

    '' -- @ 与 STRPTR 都是数据地址；VARPTR 是描述符地址
    Dim As WString Ptr p = @u
    chk( "@ = STRPTR",                 CInt( Cast(Any Ptr, p) = Cast(Any Ptr, StrPtr(u)) ), -1 )
    chk( "VARPTR <> data address",     CInt( VarPtr(u) <> Cast(Any Ptr, StrPtr(u)) ), -1 )

    '' -- 解引用得到一个可读写的代码单元（WCHAR）
    chk( "deref reads first unit",     *p, Asc("中") )
    *p = Asc("一")
    chk( "deref writes first unit",    u[0], Asc("一") )
    chk( "LEN through a deref",        Len(u), 3 )

    '' -- 索引/算术按 2 字节单元进行
    chk( "p[1] is the next unit",      p[1], Asc("㊎") )
    chk( "*(p+1) same",                *(p+1), Asc("㊎") )
    chk( "p[len] is the terminator",   p[Len(u)], 0 )

    '' -- STRPTR 的 USHORT PTR 与 p 遍历同一缓冲区
    Dim As UShort Ptr raw = StrPtr(u)
    chk( "STRPTR walks code units",    raw[0], Asc("一") )
    raw[0] = Asc("X")
    chks( "writing raw units shows up", u, "X㊎㊏" )
    chk( "STRPTR and p share buffer",  raw[1], p[1] )

    '' -- 变长 WString 数组：@arr(i) 是数据指针（指向各自的堆缓冲），
    ''    因此指针算术只能遍历单个元素自己的代码单元
    Dim As WString arr(0 To 2) = { "a", "b", "c" }
    Dim As WString Ptr ap = @arr(0)
    chk( "array element data ptr",     ap[0], Asc("a") )
    chk( "ap[1] is the terminator",    ap[1], 0 )
    chk( "another element @",          ( @arr(1) )[0], Asc("b") )

    '' -- 双重间接
    Dim As WString Ptr Ptr pp = @p
    chk( "WString PTR PTR",            **pp, Asc("X") )

    '' -- 使用 NEW / DELETE 进行堆分配：legacy 的 New WString 是一个 wchar_t
    Dim As WString Ptr heap_ = New WString
    chk( "NEW WString is 2 bytes",     SizeOf(*heap_), 2 )
    *heap_ = Asc("h")
    chk( "NEW WString write",          *heap_, Asc("h") )
    Delete heap_

    '' 它们的数组：按 wchar_t 单元分配
    Dim As WString Ptr many = New WString[6]
    many[0] = Asc("z") : many[1] = Asc("e") : many[2] = Asc("r")
    many[3] = Asc("o") : many[4] = 0
    chk( "NEW WString[6] units",       CInt( (many[0] = Asc("z")) And (many[3] = Asc("o")) And (many[4] = 0) ), -1 )
    Delete[] many

    '' -- 存储在 UDT 中的指针，以及指针数组
    Dim As Holder h
    h.q = @u
    chk( "pointer field in a UDT",     *(h.q), Asc("X") )

    Dim As WString Ptr parr(0 To 1)
    parr(0) = @u
    parr(1) = @arr(0)
    chk( "array of WString PTR",       CInt( (*(parr(0)) = Asc("X")) And (*(parr(1)) = Asc("a")) ), -1 )

    '' -- 传递和返回指针
    Dim As WString blanks(0 To 2)
    blanks(1) = "found"
    Dim As WString Ptr got = first_nonempty( blanks() )
    chk ( "returned pointer is valid", CInt( got <> 0 ), -1 )
    chk ( "returned pointer derefs",   *got, Asc("f") )

    append_through( got, " it" )
    chks( "callee wrote through it",   blanks(1), " ound" )

    '' 空结果，以及处理它的守卫
    Dim As WString empties(0 To 1)
    chk( "null when nothing matches",  CInt( first_nonempty( empties() ) = 0 ), -1 )
    append_through( 0, "ignored" )   '' 不得崩溃
    chk( "null guard survived",        1, 1 )

    '' -- 定长 WString：变量本身是缓冲区，因此 @ / STRPTR / VARPTR 一致，
    ''    与上面的变长情况不同
    Dim As WString * 8 f = "fix"
    Dim As UShort Ptr fraw = StrPtr(f)
    chk ( "fixed: STRPTR = VARPTR",    CInt( Cast(Any Ptr, fraw) = VarPtr(f) ), -1 )
    chk ( "fixed: @ = STRPTR",         CInt( Cast(Any Ptr, @f) = Cast(Any Ptr, fraw) ), -1 )
    fraw[0] = Asc("F")
    chks( "fixed: write via STRPTR",   f, "Fix" )
End Sub


'' =====================================================================
''  8. 上述所有内容中的 Unicode 和内置函数
'' =====================================================================

Sub unicode_( )
    '' UDT 字段、数组元素和定长字段都保存非 ASCII 字符
    Dim As Simple s
    s.dyn = "caf" & WChr(&hE9)
    s.fix = WChr(&h20AC) & "12"
    s.arr(0) = ASTRAL

    chk ( "accented field is 4 units",  Len(s.dyn), 4 )
    chk ( "euro in a fixed field",      s.fix[0], &h20AC )
    chk ( "astral is 2 code units",     Len(s.arr(0)), 2 )

    '' 内置函数
    Dim As WString u = "  Grüße, Welt  "
    chks( "TRIM",                       Trim(u), "Grüße, Welt" )
    '' 简单的大小写映射：一个输入单元，一个输出单元。sharp s 会大写为 "SS"，
    '' 这会改变长度，因此保持不变 —— 其他 FB 字符串类型也遵循相同规则。
    chks( "UCASE (simple mapping)",     UCase(Trim(u)), "GRÜßE, WELT" )
    chks( "LEFT",                       Left(Trim(u), 5), "Grüße" )
    chks( "RIGHT",                      Right(Trim(u), 4), "Welt" )
    chks( "MID",                        Mid(Trim(u), 8, 4), "Welt" )
    chk ( "INSTR",                      InStr(Trim(u), "Welt"), 8 )
 
    '' MID 语句
    Dim As WString m = "中㊎㊏def"
    Mid(m, 2, 3) = "一二三"
    chks( "MID statement",              m, "中一二三ef" )

    '' UDT 字段与局部变量之间的 SWAP
    Dim As WString other = "swapped"
    Swap s.dyn, other
    chks( "SWAP UDT field",             s.dyn, "swapped" )
    chks( "SWAP local",                 other, "caf" & WChr(&hE9) )

    '' 通过其他字符串类型往返
    '' 注意：WSTRING -> STRING 的窄化按系统 ANSI 代码页转换（与官方 fbc
    '' 一致）。GBK 等 CJK 代码页无法表示 ü/ß 这类字符时，窄化会产生
    '' best-fit '?' 且不可往返，因此窄化往返使用 ASCII 内容演示该形式；
    '' 定宽 WString * 32 的往返不受代码页影响，保留全 Unicode 内容。
    Dim As WString ascii_src = "Hello, World 123"
    Dim As String  narrow = ascii_src
    Dim As WString * 32 wide = Trim(u)
    '' 注意：CAST(WString, x) 无法编译 —— 但 CAST(string, x) 也不行；
    '' 转换为字符串类型不是 fbc 的特性。普通赋值就是转换，并且在两个方向上都是隐式的。
    Dim As WString back_n = narrow
    Dim As WString back_w = wide
    chks( "-> STRING -> back (ASCII)",  back_n, ascii_src )
    chks( "-> WSTRING -> back",         back_w, Trim(u) )
End Sub


'' =====================================================================
'' FIXWSTR (WString * N) "既是缓冲又是描述符"的双重身份
'' 检查所有可能路径，确保 FIXWSTR 按值传递时直接作为缓冲处理
'' (不当作变长 WSTRING 描述符: rtlToWchr/rtlToStr 错解)
Sub fixwstr_paths( )
    Dim As WString * 16 fa = "abc"
    Dim As WString * 16 fb = "xyz"
    Dim As WString    dyn = "中"

    '' 1. 拼接 + (&) 拼接 - 上一轮已修
    chks( "FIXWSTR + lit",                fa + "Q",  "abcQ" )
    chks( "lit + FIXWSTR",                "Q" + fa,  "Qabc" )
    chks( "FIXWSTR + FIXWSTR",            fa + fb,  "abcxyz" )
    chks( "FIXWSTR + WString",            fa + dyn, "abc中" )

    '' 1a. SIZEOF(WString) 作为类型名 = 单个 wchar_t 大小 (平台相关,
    ''     Windows 上 = SizeOf(UShort)), 用于 API 缓冲分配
    ''     (Allocate((ls+1) * SizeOf(WString)))。存储仍是描述符大小。
    chk ( "SIZEOF(WString) type = wchar",  SizeOf(WString), SizeOf(UShort) )
    chk ( "SIZEOF(var) stays descr",       SizeOf(fa), 32 )   '' 16 units * 2
    chk ( "LEN(WString) == SIZEOF(WString)", Len(WString), SizeOf(WString) )

    '' 1b. WString(n, fill) 填充: fill 可为整数码点 / WString 变量 /
    ''     WString*N 定长 / String 变量 / 字面量 (与官方一致)
    chks( "WString fill int",              WString(3, 65), "AAA" )
    Dim wszFill As WString = " "
    chks( "WString fill WString var",      WString(3, wszFill), "   " )
    Dim wfix As WString * 4 = "B"
    chks( "WString fill WString*N",        WString(3, wfix), "BBB" )
    chks( "WString fill literal",          WString(3, "C"), "CCC" )
    chks( "WString fill String var",       WString(3, "D"), "DDD" )

    '' 2. 算术 + (数字+数字不应有警告;但与字符串时)
    Dim As Integer n1 = 1
    chk ( "FIXWSTR passed to Len()",      Len(fa), 3 )
    chk ( "FIXWSTR in expression",        (fa = "abc"), -1 )

    '' 3. 数组索引: arr(i) 类型
    Dim As WString * 4 ai(0 To 2)
    ai(0) = "i0"
    ai(1) = "i1"
    ai(2) = "i2"
    chks( "FIXWSTR arr idx",              ai(1) + "X", "i1X" )

    '' 3a. 描述符数组 Redim / Redim Preserve / Erase
    '' (WString 描述符数组行为与官方 STRING 数组一致:
    ''  非 Preserve 重置内容, Preserve 保留, Erase 后 UBound = -1)
    Dim As WString dyn_arr()
    ReDim dyn_arr(0 To 2)
    dyn_arr(0) = "d0"
    dyn_arr(1) = "d1"
    chks( "WString arr init",              dyn_arr(1), "d1" )
    ReDim Preserve dyn_arr(0 To 4)
    chks( "ReDim Preserve keeps",          dyn_arr(1), "d1" )
    chk ( "ReDim Preserve new empty",      Len(dyn_arr(3)), 0 )
    ReDim dyn_arr(0 To 4)   '' 非 Preserve: 内容重置
    chk ( "ReDim (no preserve) resets",    Len(dyn_arr(1)), 0 )
    Erase dyn_arr
    chk ( "Erase -> UBound = -1",          UBound(dyn_arr), -1 )

    '' 13. Extends WString / ZString (legacy buffer UDT)
    Dim As UStringW u, v
    u.extra = 7
    u = "数组"
    v = "数组"
    chk( "Extends WString member",         u.extra, 7 )
    chks( "Extends WString mData",         u.mData, "数组" )
    '这是 FreeBASIC 的语言规则:UDT 之间没有默认 =/<> 比较,无 Cast,u = v 现报 error 24——定义 Operator Cast() As WString 即可获得默认比较。
    chk( "Extends WString ==",             (u = v), -1 )
    v = "数组1"
    chks( "Extends WString reassign",      v.mData, "数组1" )
    chk( "Extends WString <>",             (u <> v), -1 )

    Dim z As MyZ
    z.extraz = 5
    chk( "Extends ZString member",         z.extraz, 5 )

    '' 7. 显式 Cast
    Dim As Any Ptr p = Cast(Any Ptr, @fa)
    chk ( "FIXWSTR @-addr cast non-null",  (p <> NULL), -1 )

    '' 8. Mid() 语句对 FIXWSTR
    Dim As WString * 12 mf = "12345"
    Mid(mf, 2, 3) = "ABC"
    chks( "MID statement FIXWSTR",         mf, "1ABC5" )

    '' 9. 复合赋值: &=, += 等
    Dim As WString * 16 mu = "mut"
    mu += "X"
    chks( "FIXWSTR +=",                   mu, "mutX" )
    mu &= "Y"
    chks( "FIXWSTR &=",                   mu, "mutXY" )

    '' 10. 整体作实参传给 WString Ptr 函数
    chk( "FIXWSTR passed by val WString Ptr", p_func(fa), 3 )   '' Len("abc")=3

    '' 11. = 赋值给/从 FIXWSTR
    Dim As WString * 8 src = "src"
    Dim As WString * 8 dst = "init"
    dst = src
    chks( "FIXWSTR = FIXWSTR",            dst, "src" )

    '' 12. ByRef 参数传 FIXWSTR
    Dim As WString * 8 byref_arg = "byref"
    p_fb( byref_arg )
End Sub

Sub p_fb ( ByRef s As WString )
    '' 通过 ByRef 不应触发 FIXWSTR 当作 WSTRING 的错解
    '' (不能改 s = "x",但赋值给临时 s_t 可以验证)
    Dim As WString s_t = s
    chks( "FIXWSTR ByRef param content", s_t, "byref" )
End Sub

Function p_func ( ByVal p As WString Ptr ) As Integer
    Return Len(*p)
End Function


'' =====================================================================

Print "WString usage showcase"
Print

decl_forms( )

Dim As Integer l1, l2
static_counter( l1 )
static_counter( l2 )
chk( "STATIC local persists", l2 - l1, 2 )

arrays( )
udts( )
classes( )
params( )
returns( )
indexing( )
pointers( )
unicode_( )
fixwstr_paths( )

Print
Print g_run; " checks,中文变量类型中❸㊎㊏"; g_fail; " failed"
Sleep(8000)
If( g_fail <> 0 ) Then End 1