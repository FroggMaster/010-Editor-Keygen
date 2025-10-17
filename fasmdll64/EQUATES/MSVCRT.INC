;errno.h crtdefs.h ctype.h limits.h fcntl.h time.h io.h float.h math.h excpt.h direct.h locale.h share.h signal.h fpieee.h malloc.h
;process.h srv.h crtdbg.h stdio.h stdlib.h wchar.h setjmp.h stats.h

;errno.h - system wide error numbers (set by system calls)
;	   Copyright (c) Microsoft Corporation. All rights reserved.
;Purpose:  This file defines the system-wide error numbers (set by system calls).  Conforms to the XENIX standard.  Extended
;	   for compatibility with Uniforum standard. [System V]

EPERM = 1
ENOENT = 2
ESRCH = 3
EINTR = 4
EIO = 5
ENXIO = 6
E2BIG = 7
ENOEXEC = 8
EBADF = 9
ECHILD = 10
EAGAIN = 11
ENOMEM = 12
EACCES = 13
EFAULT = 14
EBUSY = 16
EEXIST = 17
EXDEV = 18
ENODEV = 19
ENOTDIR = 20
EISDIR = 21
ENFILE = 23
EMFILE = 24
ENOTTY = 25
EFBIG = 27
ENOSPC = 28
ESPIPE = 29
EROFS = 30
EMLINK = 31
EPIPE = 32
EDOM = 33
EDEADLK = 36
ENAMETOOLONG = 38
ENOLCK = 39
ENOSYS = 40
ENOTEMPTY = 41

EINVAL = 22
ERANGE = 34
EILSEQ = 42
STRUNCATE = 80

;crtdefs.h - definitions/declarations common to all CRT
;Purpose: This file has mostly defines used by the entire CRT.
_VC_ASSEMBLY_PUBLICKEYTOKEN	 equ "1fc8b3b9a1e18e3b"
_CRT_ASSEMBLY_VERSION		 equ "9.0.21022.8"
__LIBRARIES_ASSEMBLY_NAME_PREFIX equ "Microsoft.VC90"

_CRT_PACKING = 8
_ARGMAX = 100

struct _locale_tstruct
       locinfo dq ?
       mbcinfo dq ?
ends

struct LC_ID
       wLanguage dw ?
       wCountry dw ?
       wCodePage dw ?
ends

struct _lc_category
       locale dq ?
       wlocale dq ?
       refcount dq ?
       wrefcount dq ?
ends

struct threadlocinfo
       refcount dd ?
       lc_codepage dd ?
       lc_collate_cp dd ?
       lc_handle dd 6 dup(?) ;24
       lc_id LC_ID
	     db sizeof.LC_ID*5 dup(?) ;36
       lc_category _lc_category
		   db sizeof._lc_category*5 dup(?) ;128
       lc_clike dd ?
       mb_cur_max dd ?
       lconv_intl_refcount dq ?
       lconv_num_refcount dq ?
       lconv_mon_refcount dq ?
       lconv dq ?
       ctype1_refcount dq ?
       ctype1 dq ?
       pctype dq ?
       pclmap dq ?
       pcumap dq ?
       lc_time_curr dq ?
ends

;ctype.h - character conversion macros and ctype macros
;Purpose: Defines macros for character classification/conversion. [ANSI/System V]
WEOF = $FFFF

_UPPER = 1
_LOWER = 2
_DIGIT = 4
_SPACE = 8

_PUNCT = $10
_CONTROL = $20
_BLANK = $40
_HEX = $80

_LEADBYTE = $8000
_ALPHA = ($100 or _UPPER or _LOWER)

;limits.h - implementation dependent values
;Purpose: Contains defines for a number of implementation dependent values hich are commonly used in C programs. [ANSI]
CHAR_BIT = 8
SCHAR_MIN = -128
SCHAR_MAX = 127
UCHAR_MAX = $ff
UCHAR_MIN = 0

MB_LEN_MAX = 5
SHRT_MIN = -32768
SHRT_MAX = 32767
USHRT_MAX = 0xffff
INT_MIN = -2147483647 - 1
INT_MAX = 2147483647
UINT_MAX = $ffffffff
LONG_MIN = -2147483647 - 1
LONG_MAX = 2147483647
ULONG_MAX = $ffffffff
LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775807 - 1
ULLONG_MAX = $ffffffffffffffff

I8_MIN = -127 - 1
I8_MAX = 127
UI8_MAX = $ff

I16_MIN = -32767 - 1
I16_MAX = 32767
UI16_MAX = $ffff

I32_MIN = -2147483647 - 1
I32_MAX = 2147483647
UI32_MAX = $ffffffff

I64_MIN = -9223372036854775807 - 1
I64_MAX = 9223372036854775807
UI64_MAX = $ffffffffffffffff

;I128_MIN     -170141183460469231731687303715884105727 - 1)
;I128_MAX     170141183460469231731687303715884105727
;UI128_MAX    $ffffffffffffffffffffffffffffffff

POSIX_ARG_MAX = 4096
POSIX_CHILD_MAX = 6
POSIX_LINK_MAX = 8
POSIX_MAX_CANON = 255
POSIX_MAX_INPUT = 255
POSIX_NAME_MAX = 14
POSIX_NGROUPS_MAX = 0
POSIX_OPEN_MAX = 16
POSIX_PATH_MAX = 255
POSIX_PIPE_BUF = 512
POSIX_SSIZE_MAX = 32767
POSIX_STREAM_MAX = 8
POSIX_TZNAME_MAX = 3

ARG_MAX = 14500
LINK_MAX = 1024
MAX_CANON = POSIX_MAX_CANON
MAX_INPUT = POSIX_MAX_INPUT
NAME_MAX = 255
NGROUPS_MAX = 16
OPEN_MAX = 32
PATH_MAX = 512
PIPE_BUF = POSIX_PIPE_BUF
SSIZE_MAX = POSIX_SSIZE_MAX
STREAM_MAX = 20
TZNAME_MAX = 10

;fcntl.h - file control options used by open()
;Purpose:  This file defines constants for the file control options used by the _open() function.
O_RDONLY = 0
O_WRONLY = 1
O_RDWR = 2
O_APPEND = 8

O_CREAT = $100
O_TRUNC = $200
O_EXCL = $400

O_TEXT = $4000
O_BINARY = $8000
O_WTEXT = $10000
O_U16TEXT = $20000
O_U8TEXT = $40000

O_RAW = O_BINARY
O_NOINHERIT = $80
O_TEMPORARY = $40
O_SHORT_LIVED = $1000
O_SEQUENTIAL = $20
O_RANDOM = $10

;time.h - definitions/declarations for time routines
;Purpose:  This file has declarations of time routines and defines the structure returned by the localtime and gmtime routines and
;	   used by asctime.
struct tm
       tm_sec dd ?
       tm_min dd ?
       tm_hour dd ?
       tm_mday dd ?
       tm_mon dd ?
       tm_year dd ?
       tm_wday dd ?
       tm_yday dd ?
       tm_isdst dd ?
ends

CLOCKS_PER_SEC = 1000
CLK_TCK = CLOCKS_PER_SEC

;io.h - declarations for low-level file handling and I/O functions
;Purpose:  This file contains the function declarations for the low-level file handling and I/O functions.

;typedef unsigned long _fsize_t; /* Could be 64 bits for Win32 */
struct _finddata32_t
       attrib dd ?
       time_create dd ?
       time_access dd ?
       time_write dd ?
       size dd ?
       name db 260 dup(?)
ends

struct _finddata32i64_t
       attrib dd ?
       time_create dd ?
       time_access dd ?
       time_write dd ?
       size dq ?
       name db 264 dup(?)
ends

struct _finddata64i32_t
       attrib dd ?,?
       time_create dq ?
       time_access dq ?
       time_write dq ?
       size dd ?
       name db 260 dup(?)
ends

struct __finddata64_t
       attrib dd ?,?
       time_create dq ?
       time_access dq ?
       time_write dq ?
       size dq ?
       name db 264 dup(?)
ends

struct _wfinddata32_t
       attrib dd ?
       time_create dd ?
       time_access dd ?
       time_write dd ?
       size dd ?
       name du 260 dup(?)
ends

struct _wfinddata32i64_t
       attrib dd ?
       time_create dd ?
       time_access dd ?
       time_write dd ?
       size dq ?
       name du 260 dup(?)
ends

struct _wfinddata64i32_t
       attrib dd ?,?
       time_create dq ?
       time_access dq ?
       time_write dq ?
       size dd ?
       name du 262 dup(?)
ends

struct _wfinddata64_t
       attrib dd ?,?
       time_create dq ?
       time_access dq ?
       time_write dq ?
       size dq ?
       name du 260 dup(?)
ends

A_NORMAL = 0
A_RDONLY = 1
A_HIDDEN = 2
A_SYSTEM = 4
A_SUBDIR = $10
A_ARCH = $20

;float.h - constants for floating point values
;Purpose:  This file contains defines for a number of implementation dependent values which are commonly used by
;	   sophisticated numerical (floating point) programs.
DBL_DIG 	equ 15			    ;# of decimal digits of precision */
DBL_EPSILON	equ 2.2204460492503131e-016 ;smallest such that 1.0+DBL_EPSILON != 1.0 */
DBL_MANT_DIG	equ 53			    ;# of bits in mantissa */
DBL_MAX 	equ 1.7976931348623158e+308 ;max value */
DBL_MAX_10_EXP	equ 308 		    ;max decimal exponent */
DBL_MAX_EXP	equ 1024		    ;max binary exponent */
DBL_MIN 	equ 2.2250738585072014e-308 ;min positive value */
DBL_MIN_10_EXP	equ -307		    ;min decimal exponent */
DBL_MIN_EXP	equ -1021		    ;min binary exponent */
_DBL_RADIX	equ 2			    ;exponent radix */
_DBL_ROUNDS	equ 1			    ;addition rounding: near */

FLT_DIG 	equ 6		    ;# of decimal digits of precision */
FLT_EPSILON	equ 1.192092896e-07 ;smallest such that 1.0+FLT_EPSILON != 1.0 */
FLT_GUARD	equ 0
FLT_MANT_DIG	equ 24		    ;# of bits in mantissa */
FLT_MAX 	equ 3.402823466e+38 ;max value */
FLT_MAX_10_EXP	equ 38		    ;max decimal exponent */
FLT_MAX_EXP	equ 128 	    ;max binary exponent */
FLT_MIN 	equ 1.175494351e-38 ;min positive value */
FLT_MIN_10_EXP	equ -37 	    ;min decimal exponent */
FLT_MIN_EXP	equ -125	    ;min binary exponent */
FLT_NORMALIZE	equ 0
FLT_RADIX	equ 2		    ;exponent radix */
FLT_ROUNDS	equ 1		    ;addition rounding: near */

LDBL_DIG	equ DBL_DIG	   ;# of decimal digits of precision */
LDBL_EPSILON	equ DBL_EPSILON    ;smallest such that 1.0+LDBL_EPSILON != 1.0 */
LDBL_MANT_DIG	equ DBL_MANT_DIG   ;# of bits in mantissa */
LDBL_MAX	equ DBL_MAX	   ;max value */
LDBL_MAX_10_EXP equ DBL_MAX_10_EXP ;max decimal exponent */
LDBL_MAX_EXP	equ DBL_MAX_EXP    ;max binary exponent */
LDBL_MIN	equ DBL_MIN	   ;min positive value */
LDBL_MIN_10_EXP equ DBL_MIN_10_EXP ;min decimal exponent */
LDBL_MIN_EXP	equ DBL_MIN_EXP    ;min binary exponent */
_LDBL_RADIX	equ DBL_RADIX	   ;exponent radix */
_LDBL_ROUNDS	equ DBL_ROUNDS	   ;addition rounding: near */

_SW_INEXACT = 1
_SW_UNDERFLOW = 2
_SW_OVERFLOW = 4
_SW_ZERODIVIDE = 8
_SW_INVALID = $10
_SW_DENORMAL = $80000

_EM_AMBIGUIOUS = $80000000
_EM_AMBIGUOUS = $80000000

_MCW_EM = $8001f
_EM_INEXACT = 1
_EM_UNDERFLOW = 2
_EM_OVERFLOW = 4
_EM_ZERODIVIDE = 8
_EM_INVALID = $10
_EM_DENORMAL = $80000

_MCW_RC = $300
_RC_NEAR = 0
_RC_DOWN = $100
_RC_UP = $200
_RC_CHOP = $300

_MCW_PC = $30000
_PC_64 = 0
_PC_53 = $10000
_PC_24 = $20000

_MCW_IC = $40000
_IC_AFFINE = $40000
_IC_PROJECTIVE = 0

_MCW_DN = $3000000
_DN_SAVE = 0
_DN_FLUSH = $1000000
_DN_FLUSH_OPERANDS_SAVE_RESULTS = $2000000
_DN_SAVE_OPERANDS_FLUSH_RESULTS = $3000000

_SW_UNEMULATED = $40
_SW_SQRTNEG = $80
_SW_STACKOVERFLOW = $200
_SW_STACKUNDERFLOW = $400

_FPE_INVALID = $81
_FPE_DENORMAL = $82
_FPE_ZERODIVIDE = $83
_FPE_OVERFLOW = $84
_FPE_UNDERFLOW = $85
_FPE_INEXACT = $86
_FPE_UNEMULATED = $87
_FPE_SQRTNEG = $88
_FPE_STACKOVERFLOW = $8a
_FPE_STACKUNDERFLOW = $8b
_FPE_EXPLICITGEN = $8c

_FPCLASS_SNAN = 1
_FPCLASS_QNAN = 2
_FPCLASS_NINF = 4
_FPCLASS_NN = 8
_FPCLASS_ND = $10
_FPCLASS_NZ = $20
_FPCLASS_PZ = $40
_FPCLASS_PD = $80
_FPCLASS_PN = $100
_FPCLASS_PINF = $200

DBL_RADIX     equ _DBL_RADIX
DBL_ROUNDS    equ _DBL_ROUNDS
LDBL_RADIX    equ _LDBL_RADIX
LDBL_ROUNDS   equ _LDBL_ROUNDS
EM_AMBIGUIOUS equ _EM_AMBIGUOUS
EM_AMBIGUOUS  equ _EM_AMBIGUOUS
MCW_EM	      equ _MCW_EM
EM_INVALID    equ _EM_INVALID
EM_DENORMAL   equ _EM_DENORMAL
EM_ZERODIVIDE equ _EM_ZERODIVIDE
EM_OVERFLOW   equ _EM_OVERFLOW
EM_UNDERFLOW  equ _EM_UNDERFLOW
EM_INEXACT    equ _EM_INEXACT
MCW_IC	      equ _MCW_IC
IC_AFFINE     equ _IC_AFFINE
IC_PROJECTIVE equ _IC_PROJECTIVE
MCW_RC	      equ _MCW_RC
RC_CHOP       equ _RC_CHOP
RC_UP	      equ _RC_UP
RC_DOWN       equ _RC_DOWN
RC_NEAR       equ _RC_NEAR
MCW_PC	      equ _MCW_PC
PC_24	      equ _PC_24
PC_53	      equ _PC_53
PC_64	      equ _PC_64

CW_DEFAULT	  equ _CW_DEFAULT

SW_INVALID	  equ _SW_INVALID
SW_DENORMAL	  equ _SW_DENORMAL
SW_ZERODIVIDE	  equ _SW_ZERODIVIDE
SW_OVERFLOW	  equ _SW_OVERFLOW
SW_UNDERFLOW	  equ _SW_UNDERFLOW
SW_INEXACT	  equ _SW_INEXACT
SW_UNEMULATED	  equ _SW_UNEMULATED
SW_SQRTNEG	  equ _SW_SQRTNEG
SW_STACKOVERFLOW  equ _SW_STACKOVERFLOW
SW_STACKUNDERFLOW equ _SW_STACKUNDERFLOW

FPE_INVALID	   equ _FPE_INVALID
FPE_DENORMAL	   equ _FPE_DENORMAL
FPE_ZERODIVIDE	   equ _FPE_ZERODIVIDE
FPE_OVERFLOW	   equ _FPE_OVERFLOW
FPE_UNDERFLOW	   equ _FPE_UNDERFLOW
FPE_INEXACT	   equ _FPE_INEXACT
FPE_UNEMULATED	   equ _FPE_UNEMULATED
FPE_SQRTNEG	   equ _FPE_SQRTNEG
FPE_STACKOVERFLOW  equ _FPE_STACKOVERFLOW
FPE_STACKUNDERFLOW equ _FPE_STACKUNDERFLOW
FPE_EXPLICITGEN    equ _FPE_EXPLICITGEN

;math.h - definitions and declarations for math library
;Purpose:  This file contains constant definitions and external subroutine declarations for the math subroutine library. [ANSI/System V]
struct _exception
       type dd ?,?
       name dq ?
       arg1 dq ?
       arg2 dq ?
       retval dq ?
ends

struct _complex
       x dq ?
       y dq ?
ends

_DOMAIN = 1
_SING = 2
_OVERFLOW = 3
_UNDERFLOW = 4
_TLOSS = 5
_PLOSS = 6

EDOM = 33
ERANGE = 34

HUGE_VAL equ double

DOMAIN	  equ _DOMAIN
SING	  equ _SING
OVERFLOW  equ _OVERFLOW
UNDERFLOW equ _UNDERFLOW
TLOSS	  equ _TLOSS
PLOSS	  equ _PLOSS

M_E	   equ 2.71828182845904523536	 ;e
M_LOG2E    equ 1.44269504088896340736	 ;log2(e)
M_LOG10E   equ 0.434294481903251827651	 ;log10(e)
M_LN2	   equ 0.693147180559945309417	 ;ln(2)
M_LN10	   equ 2.30258509299404568402	 ;ln(10)
M_PI	   equ 3.14159265358979323846	 ;pi
M_PI_2	   equ 1.57079632679489661923	 ;pi/2
M_PI_4	   equ 0.785398163397448309616	 ;pi/4
M_1_PI	   equ 0.318309886183790671538	 ;1/pi
M_2_PI	   equ 0.636619772367581343076	 ;2/pi
M_2_SQRTPI equ 1.12837916709551257390	 ;2/sqrt(pi)
M_SQRT2    equ 1.41421356237309504880	 ;sqrt(2)
M_SQRT1_2  equ 0.707106781186547524401	 ;1/sqrt(2)

;excpt.h - defines exception values, types and routines
;Purpose:  This file contains the definitions and prototypes for the compiler-dependent intrinsics, support functions and keywords
;	   which implement the structured exception handling extensions.
ExceptionContinueExecution = 0
ExceptionContinueSearch = 1
ExceptionNestedException = 2
ExceptionCollidedUnwind = 3

EXCEPTION_EXECUTE_HANDLER = 1
EXCEPTION_CONTINUE_SEARCH = 0
EXCEPTION_CONTINUE_EXECUTION = -1

;direct.h - function declarations for directory handling/creation
;Purpose:  This include file contains the function declarations for the library functions related to directory handling and creation.
struct _diskfree_t
       total_clusters dd ?
       avail_clusters dd ?
       sectors_per_cluster dd ?
       bytes_per_sector dd ?
ends

;locale.h - definitions/declarations for localization routines
;Purpose:  This file defines the structures, values, macros, and functions used by the localization routines.
LC_ALL = 0
LC_COLLATE = 1
LC_CTYPE = 2
LC_MONETARY = 3
LC_NUMERIC = 4
LC_TIME = 5
LC_MIN = LC_ALL
LC_MAX = LC_TIME

struct lconv
       decimal_point dq ?
       thousands_sep dq ?
       grouping dq ?
       int_curr_symbol dq ?
       currency_symbol dq ?
       mon_decimal_point dq ?
       mon_thousands_sep dq ?
       mon_grouping dq ?
       positive_sign dq ?
       negative_sign dq ?
       int_frac_digits db ?
       frac_digits db ?
       p_cs_precedes db ?
       p_sep_by_space db ?
       n_cs_precedes db ?
       n_sep_by_space db ?
       p_sign_posn db ?
       n_sign_posn db ?
       _W_decimal_point dq ?
       _W_thousands_sep dq ?
       _W_int_curr_symbol dq ?
       _W_currency_symbol dq ?
       _W_mon_decimal_point dq ?
       _W_mon_thousands_sep dq ?
       _W_positive_sign dq ?
       _W_negative_sign dq ?
ends

_ENABLE_PER_THREAD_LOCALE = 1
_DISABLE_PER_THREAD_LOCALE = 2
_ENABLE_PER_THREAD_LOCALE_GLOBAL = $10
_DISABLE_PER_THREAD_LOCALE_GLOBAL = $20
_ENABLE_PER_THREAD_LOCALE_NEW = $100
_DISABLE_PER_THREAD_LOCALE_NEW = $200

;share.h - defines file sharing modes for sopen
;Purpose:  This file defines the file sharing modes for sopen().
_SH_DENYRW = $10
_SH_DENYWR = $20
_SH_DENYRD = $30
_SH_DENYNO = $40
_SH_SECURE = $80

SH_DENYRW = _SH_DENYRW
SH_DENYWR = _SH_DENYWR
SH_DENYRD = _SH_DENYRD
SH_DENYNO = _SH_DENYNO

;signal.h - defines signal values and routines
;Purpose:  This file defines the signal values and declares the signal functions.
NSIG = 23
SIGINT = 2
SIGILL = 4
SIGFPE = 8
SIGSEGV = 11
SIGTERM = 15
SIGBREAK = 21
SIGABRT = 22
SIGABRT_COMPAT = 6

SIG_ERR = -1
SIG_DFL = 0
SIG_IGN = 1
SIG_GET = 2
SIG_SGE = 3
SIG_ACK = 4

;fpieee.h - Definitions for floating point IEEE exception handling
;Purpose:  This file contains constant and type definitions for handling floating point exceptions [ANSI/IEEE std. 754]
_FpCompareEqual = 0
_FpCompareGreater = 1
_FpCompareLess = 2
_FpCompareUnordered = 3

_FpFormatFp32 = 0
_FpFormatFp64 = 1
_FpFormatFp80 = 2
_FpFormatFp128 = 3
_FpFormatI16 = 4
_FpFormatI32 = 5
_FpFormatI64 = 6
_FpFormatU16 = 7
_FpFormatU32 = 8
_FpFormatU64 = 9
_FpFormatBcd80 = 10
_FpFormatCompare = 11
_FpFormatString = 12
_FpFormatFp82 = 13

_FpCodeUnspecified = 0
_FpCodeAdd = 1
_FpCodeSubtract = 2
_FpCodeMultiply = 3
_FpCodeDivide = 4
_FpCodeSquareRoot = 5
_FpCodeRemainder = 6
_FpCodeCompare = 7
_FpCodeConvert = 8
_FpCodeRound = 9
_FpCodeTruncate = 10
_FpCodeFloor = 11
_FpCodeCeil = 12
_FpCodeAcos = 13
_FpCodeAsin = 14
_FpCodeAtan = 15
_FpCodeAtan2 = 16
_FpCodeCabs = 17
_FpCodeCos = 18
_FpCodeCosh = 19
_FpCodeExp = 20
_FpCodeFabs = 21
_FpCodeFmod = 22
_FpCodeFrexp = 23
_FpCodeHypot = 24
_FpCodeLdexp = 25
_FpCodeLog = 26
_FpCodeLog10 = 27
_FpCodeModf = 28
_FpCodePow = 29
_FpCodeSin = 30
_FpCodeSinh = 31
_FpCodeTan = 32
_FpCodeTanh = 33
_FpCodeY0 = 34
_FpCodeY1 = 35
_FpCodeYn = 36
_FpCodeLogb = 37
_FpCodeNextafter = 38
_FpCodeNegate = 39
_FpCodeFmin = 40
_FpCodeFmax = 41
_FpCodeConvertTrunc = 42

_XMMIAddps = 43
_XMMIAddss = 44
_XMMISubps = 45
_XMMISubss = 46
_XMMIMulps = 47
_XMMIMulss = 48
_XMMIDivps = 49
_XMMIDivss = 50
_XMMISqrtps = 51
_XMMISqrtss = 52
_XMMIMaxps = 53
_XMMIMaxss = 54
_XMMIMinps = 55
_XMMIMinss = 56
_XMMICmpps = 57
_XMMICmpss = 58
_XMMIComiss = 59
_XMMIUComiss = 60
_XMMICvtpi2ps = 61
_XMMICvtsi2ss = 62
_XMMICvtps2pi = 63
_XMMICvtss2si = 64
_XMMICvttps2pi = 65
_XMMICvttss2si = 66
_XMMIAddsubps = 67
_XMMIHaddps = 68
_XMMIHsubps = 69
_XMMIRoundps = 70
_XMMIRoundss = 71
_XMMIDpps = 72

_XMMI2Addpd = 73
_XMMI2Addsd = 74
_XMMI2Subpd = 75
_XMMI2Subsd = 76
_XMMI2Mulpd = 77
_XMMI2Mulsd = 78
_XMMI2Divpd = 79
_XMMI2Divsd = 80
_XMMI2Sqrtpd = 81
_XMMI2Sqrtsd = 82
_XMMI2Maxpd = 83
_XMMI2Maxsd = 84
_XMMI2Minpd = 85
_XMMI2Minsd = 86
_XMMI2Cmppd = 87
_XMMI2Cmpsd = 88
_XMMI2Comisd = 89
_XMMI2UComisd = 90
_XMMI2Cvtpd2pi = 91
_XMMI2Cvtsd2si = 92
_XMMI2Cvttpd2pi = 93
_XMMI2Cvttsd2si = 94
_XMMI2Cvtps2pd = 95
_XMMI2Cvtss2sd = 96
_XMMI2Cvtpd2ps = 97
_XMMI2Cvtsd2ss = 98
_XMMI2Cvtdq2ps = 99
_XMMI2Cvttps2dq = 100
_XMMI2Cvtps2dq = 101
_XMMI2Cvttpd2dq = 102
_XMMI2Cvtpd2dq = 103
_XMMI2Addsubpd = 104
_XMMI2Haddpd = 105
_XMMI2Hsubpd = 106
_XMMI2Roundpd = 107
_XMMI2Roundsd = 108
_XMMI2Dppd = 109

;IA64
_FpCodeFma = 110
_FpCodeFmaSingle = 111
_FpCodeFmaDouble = 112
_FpCodeFms = 113
_FpCodeFmsSingle = 114
_FpCodeFmsDouble = 115
_FpCodeFnma = 116
_FpCodeFnmaSingle = 117
_FpCodeFnmaDouble = 118
_FpCodeFamin = 119
_FpCodeFamax = 120

_FpRoundNearest = 0
_FpRoundMinusInfinity = 1
_FpRoundPlusInfinity = 2
_FpRoundChopped = 3

_FpPrecisionFull = 0
_FpPrecision53 = 1
_FpPrecision24 = 2
_FpPrecision64 = 3
_FpPrecision113 = 4

;struct _FP80,16
;	W dw 5 dup(?)
;ends
;
;struct _FP128,16
;	W dd 4 dup(?)
;ends
;
;struct _I64,8
;	W dd ?,?
;ends
;
;struct _U64
;	W dd ?,?
;ends
;
;struct _BCD80,16
;	W dw 5 dup(?)
;ends

;struct _FPQ64,16
;	W dq ?,?
;ends

_FP32 fix dd ?
_FP64 fix dq ?
_I16 fix dw ?
_I32 fix dd ?
_U16 fix dw ?
_U32 fix dd ?
_Q64 fix dq ?

;struct _FPIEEE_VALUE
;	union
;	    Fp32Value _FP32
;	    Fp64Value _FP64
;	    Fp80Value _FP80
;	    Fp128Value _FP128
;	    I16Value _I16
;	    I32Value _I32
;	    I64Value _I64
;	    U16Value _U16
;	    U32Value _U32
;	    U64Value _U64
;	    Bcd80Value _BCD80
;	    StringValue dd ?
;	    CompareValue dd ?
;	    Q64Value _Q64
;	    Fpq64Value _FPQ64
;	ends
;	union
;	    OperandValid dd ?
;	    Format dd ?
;	ends
;ends

_FPIEEE_VALUE_OperandValid = (1 shl 0)
_FPIEEE_VALUE_Format = (1 shl 4)

_FPIEEE_EXCEPTION_FLAGS_Inexact = (1 shl 0)
_FPIEEE_EXCEPTION_FLAGS_Underflow = (1 shl 1)
_FPIEEE_EXCEPTION_FLAGS_Overflow = (1 shl 2)
_FPIEEE_EXCEPTION_FLAGS_ZeroDivide = (1 shl 3)
_FPIEEE_EXCEPTION_FLAGS_InvalidOperation = (1 shl 4)

struct _FPIEEE_EXCEPTION_FLAGS
       union
	   Inexact dd ?
	   Underflow dd ?
	   Overflow dd ?
	   ZeroDivide dd ?
	   InvalidOperation dd ?
       ends
ends

;struct _FPIEEE_RECORD
;	bits dd ?
;	Cause dd ?
;	Enable dd ?
;	Status dd ?
;	Operand1 _FPIEEE_VALUE
;	Operand2 _FPIEEE_VALUE
;	Result _FPIEEE_VALUE
;ends

_FPIEEE_RECORD_RoundingMode = (1 shl 2)
_FPIEEE_RECORD_Precision = (1 shl 3)
_FPIEEE_RECORD_Operation = (1 shl 12)

;malloc.h - declarations and definitions for memory allocation functions
;Purpose:  Contains the function declarations for memory allocation functions also defines manifest constants and types
;	   used by the heap routines.
_WIN64_HEAP_MAXREQ = $FFFFFFFFFFFFFFE0
_HEAP_MAXREQ = $FFFFFFE0

_HEAPEMPTY = -1
_HEAPOK = -2
_HEAPBADBEGIN = -3
_HEAPBADNODE = -4
_HEAPEND = -5
_HEAPBADPTR = -6
_FREEENTRY = 0
_USEDENTRY = 1

struct _HEAPINFO
       _pentry dq ?
       _size dq ?
       _useflag dd ?,?
ends

_MAX_WAIT_MALLOC_CRT = 60000

_ALLOCA_S_THRESHOLD = 1024
_ALLOCA_S_STACK_MARKER = $CCCC
_ALLOCA_S_HEAP_MARKER = $DDDD

_HEAP_MALLOC = 1
_HEAP_CALLOC = 2
_HEAP_FREE = 3
_HEAP_REALLOC = 4
_HEAP_MSIZE = 5
_HEAP_EXPAND = 6

;process.h - definition and declarations for process control functions
;Purpose:  This file defines the modeflag values for spawnxx calls.  Also contains the function argument declarations for all
;	   process control related routines.
_P_WAIT = 0
_P_NOWAIT = 1
_OLD_P_OVERLAY = 2
_P_NOWAITO = 3
_P_DETACH = 4
_P_OVERLAY = 2

_WAIT_CHILD = 0
_WAIT_GRANDCHILD = 1

P_WAIT = _P_WAIT
P_NOWAIT = _P_NOWAIT
P_OVERLAY = _P_OVERLAY
OLD_P_OVERLAY = _OLD_P_OVERLAY
P_NOWAITO = _P_NOWAITO
P_DETACH = _P_DETACH
WAIT_CHILD = _WAIT_CHILD
WAIT_GRANDCHILD = _WAIT_GRANDCHILD

;srv.h - Open Data Services header file: srv.h
struct DBDATETIME
       dtdays dd ?
       dttime dd ?
ends

struct DBMONEY
       mnyhigh dd ?
       mnylow dd ?
ends

struct DBDATETIM4
       numdays dw ?
       nummins dw ?
ends

MAXNUMERICLEN = 16

struct DBNUMERIC
       precision db ?
       scale db ?
       sign db ?
       val db MAXNUMERICLEN dup(?)
ends

SRV_TDS_NULL = $1f
SRV_TDS_TEXT = $23
SRV_TDS_GUID = $24
SRV_TDS_VARBINARY = $25
SRV_TDS_INTN = $26
SRV_TDS_VARCHAR = $27
SRV_TDS_BINARY = $2d
SRV_TDS_IMAGE = $22
SRV_TDS_CHAR = $2f
SRV_TDS_INT1 = $30
SRV_TDS_BIT = $32
SRV_TDS_INT2 = $34
SRV_TDS_DECIMAL = $37
SRV_TDS_INT4 = $38
SRV_TDS_DATETIM4 = $3a
SRV_TDS_FLT4 = $3b
SRV_TDS_MONEY = $3c
SRV_TDS_DATETIME = $3d
SRV_TDS_FLT8 = $3e
SRV_TDS_NUMERIC = $3f
SRV_TDS_SSVARIANT = $62
SRV_TDS_NTEXT = $63
SRV_TDS_BITN = $68
SRV_TDS_DECIMALN = $6a
SRV_TDS_NUMERICN = $6c
SRV_TDS_FLTN = $6d
SRV_TDS_MONEYN = $6e
SRV_TDS_DATETIMN = $6f
SRV_TDS_MONEY4 = $7a
SRV_TDS_INT8 = $7f
SRV_TDS_BIGVARBINARY = $A5
SRV_TDS_BIGVARCHAR = $A7
SRV_TDS_BIGBINARY = $AD
SRV_TDS_BIGCHAR = $AF
SRV_TDS_NVARCHAR = $e7
SRV_TDS_NCHAR = $ef

SRVNULL = SRV_TDS_NULL
SRVTEXT = SRV_TDS_TEXT
SRVGUID = SRV_TDS_GUID
SRVVARBINARY = SRV_TDS_VARBINARY
SRVINTN = SRV_TDS_INTN
SRVVARCHAR = SRV_TDS_VARCHAR
SRVBINARY = SRV_TDS_BINARY
SRVIMAGE = SRV_TDS_IMAGE
SRVCHAR = SRV_TDS_CHAR
SRVINT1 = SRV_TDS_INT1
SRVBIT = SRV_TDS_BIT
SRVINT2 = SRV_TDS_INT2
SRVDECIMAL = SRV_TDS_DECIMAL
SRVINT4 = SRV_TDS_INT4
SRVDATETIM4 = SRV_TDS_DATETIM4
SRVFLT4 = SRV_TDS_FLT4
SRVMONEY = SRV_TDS_MONEY
SRVDATETIME = SRV_TDS_DATETIME
SRVFLT8 = SRV_TDS_FLT8
SRVNUMERIC = SRV_TDS_NUMERIC
SRVSSVARIANT = SRV_TDS_SSVARIANT
SRVNTEXT = SRV_TDS_NTEXT
SRVBITN = SRV_TDS_BITN
SRVDECIMALN = SRV_TDS_DECIMALN
SRVNUMERICN = SRV_TDS_NUMERICN
SRVFLTN = SRV_TDS_FLTN
SRVMONEYN = SRV_TDS_MONEYN
SRVDATETIMN = SRV_TDS_DATETIMN
SRVMONEY4 = SRV_TDS_MONEY4
SRVINT8 = SRV_TDS_INT8
SRVBIGVARBINARY = SRV_TDS_BIGVARBINARY
SRVBIGVARCHAR = SRV_TDS_BIGVARCHAR
SRVBIGBINARY = SRV_TDS_BIGBINARY
SRVBIGCHAR = SRV_TDS_BIGCHAR
SRVNVARCHAR = SRV_TDS_NVARCHAR
SRVNCHAR = SRV_TDS_NCHAR

SRV_ERROR = 0
SRV_DONE = 1
SRV_DATATYPE = 2
SRV_EVENT = 4
SRV_ENO_OS_ERR = 0
SRV_INFO = 1
SRV_FATAL_PROCESS = 10
SRV_FATAL_SERVER = 19
SRV_CONTINUE = 0
SRV_LANGUAGE = 1
SRV_CONNECT = 2
SRV_RPC = 3
SRV_RESTART = 4
SRV_DISCONNECT = 5
SRV_ATTENTION = 6
SRV_SLEEP = 7
SRV_START = 8
SRV_STOP = 9
SRV_EXIT = 10
SRV_CANCEL = 11
SRV_SETUP = 12
SRV_CLOSE = 13
SRV_PRACK = 14
SRV_PRERROR = 15
SRV_ATTENTION_ACK = 16
SRV_CONNECT_V7 = 16
SRV_SKIP = 17
SRV_TRANSMGR = 18
SRV_PRELOGIN = 19
SRV_OLEDB = 20
SRV_INTERNAL_HANDLER = 99
SRV_PROGRAMMER_DEFINED = 100

SRV_SERVERNAME = 0
SRV_VERSION = 6
SRV_NULLTERM = -1
SRV_MSG_INFO = 1
SRV_MSG_ERROR = 2
SRV_DONE_FINAL = 0
SRV_DONE_MORE = 1
SRV_DONE_ERROR = 2
SRV_DONE_COUNT = $10
SRV_DONE_RPC_IN_BATCH = $80
SRV_PARAMRETURN = 1
SRV_PARAMDEFAULT = 2
SRV_PARAMSORTORDER = 4
SRV_RECOMPILE = 1
SRV_NOMETADATA = 2
SRV_SPID = 10
SRV_NETSPID = 11
SRV_TYPE = 12
SRV_STATUS = 13
SRV_RMTSERVER = 14
SRV_HOST = 15
SRV_USER = 16
SRV_PWD = 17
SRV_CPID = 18
SRV_APPLNAME = 19
SRV_TDS = 20
SRV_CLIB = 21
SRV_LIBVERS = 22
SRV_ROWSENT = 23
SRV_BCPFLAG = 24
SRV_NATLANG = 25
SRV_PIPEHANDLE = 26
SRV_NETWORK_MODULE = 27
SRV_NETWORK_VERSION = 28
SRV_NETWORK_CONNECTION = 29
SRV_LSECURE = 30
SRV_SAXP = 31
SRV_UNICODE_USER = 33
SRV_UNICODE_PWD = 35
SRV_SPROC_CODEPAGE = 36
SRV_MSGLCID = 37
SRV_INSTANCENAME = 38
SRV_HASHPWD = 39
SRV_UNICODE_CURRENTLOGIN = 40
SRV_TDS_NONE = 0
SRV_TDS_2_0 = 1
SRV_TDS_3_4 = 2
SRV_TDS_4_2 = 3
SRV_TDS_6_0 = 4
SRV_TDS_7_0 = 5
SRV_DUPLICATE_HANDLER = 2

SUCCEED = 1
FAIL = 0

SS_MAJOR_VERSION = 7
SS_MINOR_VERSION = 0
SS_LEVEL_VERSION = 0
SS_MINIMUM_VERSION equ "7.00.00.0000"
ODS_VERSION = ((SS_MAJOR_VERSION shl 24) or (SS_MINOR_VERSION shl 16))

;crtdbg.h - Supports debugging features of the C runtime library.
;Purpose:  Support CRT debugging features.
_CRT_WARN = 0
_CRT_ERROR = 1
_CRT_ASSERT = 2
_CRT_ERRCNT = 3

_CRTDBG_MODE_FILE = 1
_CRTDBG_MODE_DEBUG = 2
_CRTDBG_MODE_WNDW = 4
_CRTDBG_REPORT_MODE = -1

_CRTDBG_INVALID_HFILE = -1
_CRTDBG_HFILE_ERROR = -2
_CRTDBG_FILE_STDOUT = -4
_CRTDBG_FILE_STDERR = -5
_CRTDBG_REPORT_FILE = -6

_CRT_RPTHOOK_INSTALL = 0
_CRT_RPTHOOK_REMOVE = 1

_HOOK_ALLOC = 1
_HOOK_REALLOC = 2
_HOOK_FREE = 3

_CRTDBG_ALLOC_MEM_DF = 1
_CRTDBG_DELAY_FREE_MEM_DF = 2
_CRTDBG_CHECK_ALWAYS_DF = 4
_CRTDBG_RESERVED_DF = 8
_CRTDBG_CHECK_CRT_DF = $10
_CRTDBG_LEAK_CHECK_DF = $20

_CRTDBG_CHECK_EVERY_16_DF = $100000
_CRTDBG_CHECK_EVERY_128_DF = $800000
_CRTDBG_CHECK_EVERY_1024_DF = $4000000
_CRTDBG_CHECK_DEFAULT_DF = 0
_CRTDBG_REPORT_FLAG = -1

;_BLOCK_TYPE(block)	     (block & 0xFFFF)
;_BLOCK_SUBTYPE(block)	     (block >> 16 & 0xFFFF)
_FREE_BLOCK = 0
_NORMAL_BLOCK = 1
_CRT_BLOCK = 2
_IGNORE_BLOCK = 3
_CLIENT_BLOCK = 4
_MAX_BLOCKS = 5

struct _CrtMemState
       pBlockHeader dq ?
       lCounts dq _MAX_BLOCKS dup(?)
       lSizes dq _MAX_BLOCKS dup(?)
       lHighWaterCount dq ?
       lTotalCount dq ?
ends

;stdio.h - definitions/declarations for standard I/O routines
;Purpose:  This file defines the structures, values, macros, and functions used by the level 2 I/O ("standard I/O") routines.
;	   [ANSI/System V]
BUFSIZ = 512
_NSTREAM_ = 512
_NFILE = _NSTREAM_
_IOB_ENTRIES = 20
EOF = -1

struct _iobuf
       _ptr dq ?
       _cnt dd ?,?
       _base dq ?
       _flag dd ?
       _file dd ?
       _charbuf dd ?
       _bufsiz dd ?
       _tmpfname dq ?
ends

struct FILE _iobuf
ends

L_ctermid = 9
L_cuserid = 32

SEEK_CUR = 1
SEEK_END = 2
SEEK_SET = 0

FILENAME_MAX = 260
FOPEN_MAX = 20
_SYS_OPEN = 20
TMP_MAX = 32767

_TMP_MAX_S = 2147483647
TMP_MAX_S = _TMP_MAX_S

;stdin	(&__iob_func()[0])
;stdout (&__iob_func()[1])
;stderr (&__iob_func()[2])

_IOREAD = 1
_IOWRT = 2
_IOFBF = 0
_IOLBF = $40
_IONBF = 4
_IOMYBUF = 8
_IOEOF = $10
_IOERR = $20
_IOSTRG = $40
_IORW = $80
_IOAPPEND = $200

_TWO_DIGIT_EXPONENT = 1
WEOF = $FFFF

;stdlib.h - declarations/definitions for commonly used library functions
;Purpose:  This include file contains the function declarations for commonly used library functions which either don't fit
;	   somewhere else, or, cannot be declared in the normal place for other reasons.  [ANSI]
EXIT_SUCCESS = 0
EXIT_FAILURE = 1

RAND_MAX = $7fff

_MAX_PATH = 260
_MAX_DRIVE = 3
_MAX_DIR = 256
_MAX_FNAME = 256
_MAX_EXT = 256

_OUT_TO_DEFAULT = 0
_OUT_TO_STDERR = 1
_OUT_TO_MSGBOX = 2
_REPORT_ERRMODE = 3

_WRITE_ABORT_MSG = 1
_CALL_REPORTFAULT = 2
_MAX_ENV = 32767

_CVTBUFSIZE = 309+40

;wchar.h - declarations for wide character functions
;Purpose:  This file contains the types, macros and function declarations for all wide character-related functions.
;	   They may also be declared in individual header files on a functional basis.
WCHAR_MIN = 0
WCHAR_MAX = $ffff

WEOF = $FFFF

_UPPER = 1
_LOWER = 2
_DIGIT = 4
_SPACE = 8

_PUNCT = $10
_CONTROL = $20
_BLANK = $40
_HEX = $80

_LEADBYTE = $8000
_ALPHA = $100 or _UPPER or _LOWER

struct _stat32
       st_dev dd ?
       st_ino dw ?
       st_mode dw ?
       st_nlink dw ?
       st_uid dw ?
       st_gid dw ?,?
       st_rdev dd ?
       st_size dd ?
       st_atime dd ?
       st_mtime dd ?
       st_ctime dd ?
ends

struct _stat32i64
       st_dev dd ?
       st_ino dw ?
       st_mode dw ?
       st_nlink dw ?
       st_uid dw ?
       st_gid dw ?,?
       st_rdev dd ?,?
       st_size dq ?
       st_atime dd ?
       st_mtime dd ?
       st_ctime dd ?,?
ends

struct _stat64i32
       st_dev dd ?
       st_ino dw ?
       st_mode dw ?
       st_nlink dw ?
       st_uid dw ?
       st_gid dw ?,?
       st_rdev dd ?
       st_size dd ?
       st_atime dq ?
       st_mtime dq ?
       st_ctime dq ?
ends

struct _stat64
       st_dev dd ?
       st_ino dw ?
       st_mode dw ?
       st_nlink dw ?
       st_uid dw ?
       st_gid dw ?,?
       st_rdev dd ?,?
       st_size dq ?
       st_atime dq ?
       st_mtime dq ?
       st_ctime dq ?
ends

INT8_MAX = 127
UINT8_MAX = $ff
BYTE_MAX = $ff
SHORT_MAX = 32767
INT16_MAX = 32767
USHORT_MAX = $ffff
UINT16_MAX = $ffff
WORD_MAX = $ffff
INT_MAX = 2147483647
INT32_MAX = 2147483647
UINT_MAX = $ffffffff
UINT32_MAX = $ffffffff
LONG_MAX = 2147483647
ULONG_MAX = $ffffffff
DWORD_MAX = $ffffffff
LONGLONG_MAX = 9223372036854775807
LONG64_MAX = 9223372036854775807
INT64_MAX = 9223372036854775807
ULONGLONG_MAX = $ffffffffffffffff
DWORDLONG_MAX = $ffffffffffffffff
ULONG64_MAX = $ffffffffffffffff
DWORD64_MAX = $ffffffffffffffff
UINT64_MAX = $ffffffffffffffff
INT128_MAX equ 170141183460469231731687303715884105727
UINT128_MAX equ $ffffffffffffffffffffffffffffffff
INT_PTR_MAX = 9223372036854775807
UINT_PTR_MAX = $ffffffffffffffff
LONG_PTR_MAX = 9223372036854775807
ULONG_PTR_MAX = $ffffffffffffffff
DWORD_PTR_MAX = $ffffffffffffffff
PTRDIFF_T_MAX = 9223372036854775807
SIZE_T_MAX = $ffffffffffffffff
SSIZE_T_MAX = 9223372036854775807
_SIZE_T_MAX = $ffffffffffffffff

;setjmp.h - definitions/declarations for setjmp/longjmp routines
_JBLEN = 16

;_CRT_ALIGN(16)
;struct SETJMP_FLOAT128,16
;	LowPart dq ?
;	HighPart dq ?
;ends

;struct _JUMP_BUFFER
;	Frame dq ?
;	Rbx dq ?
;	Rsp dq ?
;	Rbp dq ?
;	Rsi dq ?
;	Rdi dq ?
;	R12 dq ?
;	R13 dq ?
;	R14 dq ?
;	R15 dq ?
;	Rip dq ?
;	Spare dq ?
;	Xmm6 SETJMP_FLOAT128
;	Xmm7 SETJMP_FLOAT128
;	Xmm8 SETJMP_FLOAT128
;	Xmm9 SETJMP_FLOAT128
;	Xmm10 SETJMP_FLOAT128
;	Xmm11 SETJMP_FLOAT128
;	Xmm12 SETJMP_FLOAT128
;	Xmm13 SETJMP_FLOAT128
;	Xmm14 SETJMP_FLOAT128
;	Xmm15 SETJMP_FLOAT128
;ends

;sys/stat.h - defines structure used by stat() and fstat()
;Purpose:     This file defines the structure used by the _stat() and _fstat()

_S_IFMT = $F000
_S_IFDIR = $4000
_S_IFCHR = $2000
_S_IFIFO = $1000
_S_IFREG = $8000
_S_IREAD = $100
_S_IWRITE = $80
_S_IEXEC = $40
