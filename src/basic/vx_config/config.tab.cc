/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         configparse
#define yylex           configlex
#define yyerror         configerror
#define yydebug         configdebug
#define yynerrs         confignerrs
#define yylval          configlval
#define yychar          configchar

/* First part of user prologue.  */
#line 3 "config.tab.yy"


////////////////////////////////////////////////////////////////////////


#define YYDEBUG 1


////////////////////////////////////////////////////////////////////////


using namespace std;

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

#include "vx_log.h"
#include "math_constants.h"
#include "is_bad_data.h"
#include "scanner_stuff.h"
#include "threshold.h"
#include "is_number.h"
#include "concat_string.h"
#include "pwl.h"
#include "dictionary.h"
#include "icode.h"
#include "idstack.h"
#include "calculator.h"
#include "fix_float.h"

#include "scanner_stuff.h"
#include "threshold.h"


////////////////////////////////////////////////////////////////////////


   //
   //  declarations that have external linkage
   //


extern int            yylex();

extern void           yyerror(const char *);

extern "C" int        configwrap();


   //
   //  definitions that have external linkage
   //

char *            configtext;

stringstream *    configin;

int               LineNumber            = 1;

int               Column                = 1;

const char *      bison_input_filename  = (const char *) 0;

DictionaryStack * dict_stack            = (DictionaryStack *) 0;

bool              is_lhs                = true;    //  used by the scanner

ThreshNode *      result                = 0;   //  for testing

bool              test_mode             = false;

char number_string [max_id_length + 1];

IdentifierArray  ida;

bool is_function_def = false;

Calculator hp;


////////////////////////////////////////////////////////////////////////


   //
   //  static definitions
   //

static PiecewiseLinear pwl;

static Dictionary DD;

static SingleThresh STH;

static const char default_print_prefix [] = "config";


static ICVStack         icvs;



static ConcatString function_name;

static const char apm = 'b';   //  assign_prefix mark
static const char fcm = 'f';   //  function def mark


////////////////////////////////////////////////////////////////////////


   //
   //  static declarations
   //

static void do_op(char op);

static Number do_integer_op(char op, const Number & a, const Number & b);

static void do_negate();
static void do_paren_exp();

static void do_builtin_call(int which);


static void do_assign_boolean   (const char * name, bool);
static void do_assign_exp       (const char * name);
static void do_assign_string    (const char * name, const char * text);
static void do_assign_threshold (const char * name);

static void do_assign_id      (const char * LHS, const char * RHS);

static void do_assign_dict    (const char * name);

static void do_assign_exp_array(const char * name);

static void do_dict();

static void do_string(const char *);

static void do_boolean(const bool &);

static void store_exp();

static void do_thresh(ThreshNode *);

static void do_na_thresh();

static void add_point();

static void do_pwl(const char * LHS);

static void do_number(const Number &);

static void do_local_var(int);


static ThreshNode * do_and_thresh    (ThreshNode *, ThreshNode *);
static ThreshNode * do_or_thresh     (ThreshNode *, ThreshNode *);
static ThreshNode * do_not_thresh    (ThreshNode *);
static ThreshNode * do_paren_thresh  (ThreshNode *);
static ThreshNode * do_simple_thresh (ThreshType, const Number &);

static ThreshNode * do_simple_perc_thresh (const ThreshType, const PC_info &);
static ThreshNode * do_compound_perc_thresh (const ThreshType, const PC_info &, const Number &);
static ThreshNode * do_fortran_thresh(const char *);


static void set_number_string();
static void set_number_string(const char *);

static void mark(int);

static void do_user_function_call(const DictionaryEntry *);

static void do_print(const char *);

static void do_user_function_def();


////////////////////////////////////////////////////////////////////////



#line 265 "config.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "config.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_QUOTED_STRING = 4,              /* QUOTED_STRING  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_BOOLEAN = 7,                    /* BOOLEAN  */
  YYSYMBOL_COMPARISON = 8,                 /* COMPARISON  */
  YYSYMBOL_NA_COMPARISON = 9,              /* NA_COMPARISON  */
  YYSYMBOL_LOGICAL_OP_NOT = 10,            /* LOGICAL_OP_NOT  */
  YYSYMBOL_LOGICAL_OP_AND = 11,            /* LOGICAL_OP_AND  */
  YYSYMBOL_LOGICAL_OP_OR = 12,             /* LOGICAL_OP_OR  */
  YYSYMBOL_FORTRAN_THRESHOLD = 13,         /* FORTRAN_THRESHOLD  */
  YYSYMBOL_BUILTIN = 14,                   /* BUILTIN  */
  YYSYMBOL_LOCAL_VAR = 15,                 /* LOCAL_VAR  */
  YYSYMBOL_SIMPLE_PERC_THRESH = 16,        /* SIMPLE_PERC_THRESH  */
  YYSYMBOL_USER_FUNCTION = 17,             /* USER_FUNCTION  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_19_ = 19,                       /* '+'  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_23_ = 23,                       /* '^'  */
  YYSYMBOL_UNARY_MINUS = 24,               /* UNARY_MINUS  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* ']'  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_statement_list = 35,            /* statement_list  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_print_stmt = 37,                /* print_stmt  */
  YYSYMBOL_print_prefix = 38,              /* print_prefix  */
  YYSYMBOL_assign_stmt = 39,               /* assign_stmt  */
  YYSYMBOL_id_list = 40,                   /* id_list  */
  YYSYMBOL_function_prefix = 41,           /* function_prefix  */
  YYSYMBOL_assign_prefix = 42,             /* assign_prefix  */
  YYSYMBOL_array_prefix = 43,              /* array_prefix  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_dictionary = 45,                /* dictionary  */
  YYSYMBOL_dictionary_list = 46,           /* dictionary_list  */
  YYSYMBOL_string_list = 47,               /* string_list  */
  YYSYMBOL_threshold_list = 48,            /* threshold_list  */
  YYSYMBOL_threshold = 49,                 /* threshold  */
  YYSYMBOL_thresh_node = 50,               /* thresh_node  */
  YYSYMBOL_simple_thresh = 51,             /* simple_thresh  */
  YYSYMBOL_number = 52,                    /* number  */
  YYSYMBOL_boolean_list = 53,              /* boolean_list  */
  YYSYMBOL_opt_semi = 54,                  /* opt_semi  */
  YYSYMBOL_opt_comma = 55,                 /* opt_comma  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_expression_list = 59,           /* expression_list  */
  YYSYMBOL_piecewise_linear = 60,          /* piecewise_linear  */
  YYSYMBOL_point_list = 61,                /* point_list  */
  YYSYMBOL_point = 62                      /* point  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    21,    19,    27,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    26,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   255,   255,   256,   259,   260,   261,   265,   266,   270,
     275,   276,   277,   278,   280,   281,   282,   284,   285,   286,
     287,   288,   289,   291,   297,   298,   302,   306,   310,   310,
     314,   318,   319,   323,   324,   328,   329,   332,   333,   337,
     338,   339,   340,   341,   345,   346,   347,   348,   352,   353,
     357,   358,   362,   363,   367,   368,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   381,   382,   382,   387,
     388,   392,   396,   397,   401
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "QUOTED_STRING", "INTEGER", "FLOAT", "BOOLEAN", "COMPARISON",
  "NA_COMPARISON", "LOGICAL_OP_NOT", "LOGICAL_OP_AND", "LOGICAL_OP_OR",
  "FORTRAN_THRESHOLD", "BUILTIN", "LOCAL_VAR", "SIMPLE_PERC_THRESH",
  "USER_FUNCTION", "PRINT", "'+'", "'-'", "'*'", "'/'", "'^'",
  "UNARY_MINUS", "';'", "']'", "','", "'('", "')'", "'='", "'['", "'{'",
  "'}'", "$accept", "statement_list", "statement", "print_stmt",
  "print_prefix", "assign_stmt", "id_list", "function_prefix",
  "assign_prefix", "array_prefix", "$@1", "dictionary", "dictionary_list",
  "string_list", "threshold_list", "threshold", "thresh_node",
  "simple_thresh", "number", "boolean_list", "opt_semi", "opt_comma",
  "expression", "$@2", "$@3", "expression_list", "piecewise_linear",
  "point_list", "point", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,   -16,     3,   -17,   110,   -17,   -17,   110,    24,   -17,
     -17,   141,   -17,   189,    87,   122,   -17,    27,   -17,    12,
     -17,   -17,   -17,    -8,   -17,   -17,    17,   -17,   -17,    -2,
       7,   -17,    23,   189,   189,   -17,   177,   207,    45,    52,
      73,   157,    40,     0,   -17,    78,   214,    81,   -17,   -17,
      92,   173,   -17,    18,    28,    33,   -17,   107,   228,   133,
     110,   110,   -17,    58,   108,   -17,   -17,   189,   -17,   -17,
     -17,    53,   189,   189,   189,   189,   189,   -17,   -17,   -17,
     -17,   -17,   173,   147,   -17,     8,   -17,   -17,   -17,   -17,
     -17,    96,   112,   115,   145,   132,    71,   139,   159,   143,
     189,   -17,   -17,   170,   150,   153,   221,   189,   189,   -17,
     130,   130,   161,   161,   -17,   191,   189,   -17,   -17,   164,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   228,
     -17,   -17,   -17,   -17,    95,   114,   189,    89,   -17,   -17,
     -17,   -17,   202,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    38,     0,    47,     9,     0,     0,     2,
       5,     0,     4,     0,    28,     0,     6,    37,    39,     0,
      27,    48,    49,    45,    44,    42,     0,     1,     3,    55,
       0,    57,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,    33,    50,
       0,     0,    31,     0,     0,     0,    35,     0,    69,     0,
       0,     0,    24,     0,     0,    43,    54,     0,    65,    67,
      63,     0,     0,     0,     0,     0,     0,     7,    23,    12,
      15,    10,     0,     0,    72,     0,    29,    14,    11,    13,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,    41,     0,     0,     0,     0,     0,     0,    64,
      58,    59,    60,    61,    62,     0,     0,    71,    73,    53,
      21,    32,    19,    34,    20,    36,    17,    51,    18,    70,
      25,    26,    46,     8,     0,     0,     0,     0,    52,    30,
      66,    68,     0,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -17,   163,    -7,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,    -9,   -17,   -17,   -17,   -10,     6,   -17,     5,   -17,
     -17,   -17,   -11,   -17,   -17,    84,   -17,   -17,   124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    63,    13,    14,    15,
      43,    44,    53,    54,    55,    16,    17,    18,    35,    57,
     139,    67,    58,   107,   108,    59,    47,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    28,    37,    46,    45,    56,    52,    24,    21,    22,
      25,     1,    19,    26,    20,    62,     2,     3,     4,    23,
      64,     5,    70,    71,    27,    66,     6,     1,    60,    61,
      71,    86,     2,     3,     4,    68,     7,     5,    60,    61,
      71,   119,     6,     1,    91,    92,    65,    26,     2,     3,
       4,    69,     7,     5,    93,    94,   106,    26,     6,    95,
      96,   110,   111,   112,   113,   114,   101,   102,     7,   105,
      79,   115,    72,    73,    74,    75,    76,    80,    28,     2,
       3,     4,   109,   121,     5,   103,   125,   104,    26,   129,
      38,    39,    21,    22,    40,     2,     3,     4,    81,     7,
       5,    30,    31,    87,    32,   137,    89,    33,    72,    73,
      74,    75,    76,    21,    22,    41,   136,    90,     2,    42,
       4,   120,   100,     5,   140,   142,    48,    21,    22,    49,
       2,     3,     4,    97,    98,     5,    30,    31,     7,    32,
     122,   100,    33,   141,    42,    29,    21,    22,    50,   123,
      51,    74,    75,    76,    42,    30,    31,   124,    32,    99,
     100,    33,    21,    22,   126,     2,   127,     4,   128,    34,
       5,    30,    31,   130,    32,   116,   117,    33,    21,    22,
     131,     2,   132,     4,    76,    82,     5,    30,    31,   138,
      32,   134,   135,    33,    21,    22,    72,    73,    74,    75,
      76,    51,    77,    30,    31,    85,    32,   118,     0,    33,
      72,    73,    74,    75,    76,     0,     0,    34,   136,     0,
     109,    72,    73,    74,    75,    76,    72,    73,    74,    75,
      76,   143,    78,    72,    73,    74,    75,    76,     0,    88,
      72,    73,    74,    75,    76,     0,   133,    72,    73,    74,
      75,    76
};

static const yytype_int16 yycheck[] =
{
      11,     8,    13,    14,    14,    15,    15,     2,     5,     6,
       4,     3,    28,     7,    30,     3,     8,     9,    10,    16,
      28,    13,    33,    34,     0,    27,    18,     3,    11,    12,
      41,    31,     8,     9,    10,    28,    28,    13,    11,    12,
      51,    33,    18,     3,    26,    27,    29,    41,     8,     9,
      10,    28,    28,    13,    26,    27,    67,    51,    18,    26,
      27,    72,    73,    74,    75,    76,    60,    61,    28,    64,
      25,    82,    19,    20,    21,    22,    23,    25,    85,     8,
       9,    10,    29,    92,    13,    27,    96,    29,    82,   100,
       3,     4,     5,     6,     7,     8,     9,    10,    25,    28,
      13,    14,    15,    25,    17,   116,    25,    20,    19,    20,
      21,    22,    23,     5,     6,    28,    27,    25,     8,    32,
      10,    25,    27,    13,    29,   136,     4,     5,     6,     7,
       8,     9,    10,    26,    27,    13,    14,    15,    28,    17,
      25,    27,    20,    29,    32,     4,     5,     6,    26,     4,
      28,    21,    22,    23,    32,    14,    15,    25,    17,    26,
      27,    20,     5,     6,    25,     8,     7,    10,    25,    28,
      13,    14,    15,     3,    17,    28,    29,    20,     5,     6,
      30,     8,    29,    10,    23,    28,    13,    14,    15,    25,
      17,   107,   108,    20,     5,     6,    19,    20,    21,    22,
      23,    28,    25,    14,    15,    42,    17,    83,    -1,    20,
      19,    20,    21,    22,    23,    -1,    -1,    28,    27,    -1,
      29,    19,    20,    21,    22,    23,    19,    20,    21,    22,
      23,    29,    25,    19,    20,    21,    22,    23,    -1,    25,
      19,    20,    21,    22,    23,    -1,    25,    19,    20,    21,
      22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    10,    13,    18,    28,    35,    36,
      37,    38,    39,    41,    42,    43,    49,    50,    51,    28,
      30,     5,     6,    16,    52,    50,    50,     0,    36,     4,
      14,    15,    17,    20,    28,    52,    56,    56,     3,     4,
       7,    28,    32,    44,    45,    49,    56,    60,     4,     7,
      26,    28,    45,    46,    47,    48,    49,    53,    56,    59,
      11,    12,     3,    40,    28,    29,    27,    55,    28,    28,
      56,    56,    19,    20,    21,    22,    23,    25,    25,    25,
      25,    25,    28,    61,    62,    35,    31,    25,    25,    25,
      25,    26,    27,    26,    27,    26,    27,    26,    27,    26,
      27,    50,    50,    27,    29,    52,    56,    57,    58,    29,
      56,    56,    56,    56,    56,    56,    28,    29,    62,    33,
      25,    45,    25,     4,    25,    49,    25,     7,    25,    56,
       3,    30,    29,    25,    59,    59,    27,    56,    25,    54,
      29,    29,    56,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    36,    37,    37,    38,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    40,    40,    41,    42,    44,    43,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    56,    58,    56,    59,
      59,    60,    61,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     1,
       3,     3,     3,     3,     3,     3,     2,     4,     4,     4,
       4,     4,     3,     3,     1,     3,     5,     2,     0,     3,
       4,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     3,     2,     3,     2,     2,     5,     1,     1,     1,
       1,     3,     1,     0,     1,     0,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     0,     5,     0,     5,     1,
       3,     3,     1,     2,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 8;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* statement_list: statement  */
#line 255 "config.tab.yy"
                                          { is_lhs = true; }
#line 1430 "config.tab.cc"
    break;

  case 3: /* statement_list: statement_list statement  */
#line 256 "config.tab.yy"
                                          { is_lhs = true; }
#line 1436 "config.tab.cc"
    break;

  case 4: /* statement: assign_stmt  */
#line 259 "config.tab.yy"
                          { is_lhs = true; }
#line 1442 "config.tab.cc"
    break;

  case 5: /* statement: print_stmt  */
#line 260 "config.tab.yy"
                          { is_lhs = true; }
#line 1448 "config.tab.cc"
    break;

  case 6: /* statement: threshold  */
#line 261 "config.tab.yy"
                          { }
#line 1454 "config.tab.cc"
    break;

  case 7: /* print_stmt: print_prefix expression ';'  */
#line 265 "config.tab.yy"
                                                                 { do_print( 0); }
#line 1460 "config.tab.cc"
    break;

  case 8: /* print_stmt: print_prefix QUOTED_STRING opt_comma expression ';'  */
#line 266 "config.tab.yy"
                                                                 { do_print((yyvsp[-3].text)); }
#line 1466 "config.tab.cc"
    break;

  case 9: /* print_prefix: PRINT  */
#line 270 "config.tab.yy"
                       { is_lhs = false; }
#line 1472 "config.tab.cc"
    break;

  case 10: /* assign_stmt: assign_prefix BOOLEAN ';'  */
#line 275 "config.tab.yy"
                                                        { do_assign_boolean   ((yyvsp[-2].text), (yyvsp[-1].bval)); }
#line 1478 "config.tab.cc"
    break;

  case 11: /* assign_stmt: assign_prefix expression ';'  */
#line 276 "config.tab.yy"
                                                        { do_assign_exp       ((yyvsp[-2].text)); }
#line 1484 "config.tab.cc"
    break;

  case 12: /* assign_stmt: assign_prefix IDENTIFIER ';'  */
#line 277 "config.tab.yy"
                                                        { do_assign_id        ((yyvsp[-2].text), (yyvsp[-1].text)); }
#line 1490 "config.tab.cc"
    break;

  case 13: /* assign_stmt: assign_prefix piecewise_linear ';'  */
#line 278 "config.tab.yy"
                                                        { do_pwl              ((yyvsp[-2].text)); }
#line 1496 "config.tab.cc"
    break;

  case 14: /* assign_stmt: assign_prefix threshold ';'  */
#line 280 "config.tab.yy"
                                                        { do_assign_threshold ((yyvsp[-2].text)); }
#line 1502 "config.tab.cc"
    break;

  case 15: /* assign_stmt: assign_prefix QUOTED_STRING ';'  */
#line 281 "config.tab.yy"
                                                        { do_assign_string    ((yyvsp[-2].text), (yyvsp[-1].text)); }
#line 1508 "config.tab.cc"
    break;

  case 16: /* assign_stmt: assign_prefix dictionary  */
#line 282 "config.tab.yy"
                                                        { do_assign_dict      ((yyvsp[-1].text)); }
#line 1514 "config.tab.cc"
    break;

  case 17: /* assign_stmt: array_prefix boolean_list ']' ';'  */
#line 284 "config.tab.yy"
                                                        { do_assign_dict((yyvsp[-3].text)); }
#line 1520 "config.tab.cc"
    break;

  case 18: /* assign_stmt: array_prefix expression_list ']' ';'  */
#line 285 "config.tab.yy"
                                                        { do_assign_exp_array((yyvsp[-3].text)); }
#line 1526 "config.tab.cc"
    break;

  case 19: /* assign_stmt: array_prefix string_list ']' ';'  */
#line 286 "config.tab.yy"
                                                        { do_assign_dict((yyvsp[-3].text)); }
#line 1532 "config.tab.cc"
    break;

  case 20: /* assign_stmt: array_prefix threshold_list ']' ';'  */
#line 287 "config.tab.yy"
                                                        { do_assign_dict((yyvsp[-3].text)); }
#line 1538 "config.tab.cc"
    break;

  case 21: /* assign_stmt: array_prefix dictionary_list ']' ';'  */
#line 288 "config.tab.yy"
                                                        { do_assign_dict((yyvsp[-3].text)); }
#line 1544 "config.tab.cc"
    break;

  case 22: /* assign_stmt: array_prefix ']' ';'  */
#line 289 "config.tab.yy"
                                                        { do_assign_dict((yyvsp[-2].text)); }
#line 1550 "config.tab.cc"
    break;

  case 23: /* assign_stmt: function_prefix expression ';'  */
#line 291 "config.tab.yy"
                                                        { do_user_function_def(); }
#line 1556 "config.tab.cc"
    break;

  case 24: /* id_list: IDENTIFIER  */
#line 297 "config.tab.yy"
                                 { ida.add((yyvsp[0].text)); }
#line 1562 "config.tab.cc"
    break;

  case 25: /* id_list: id_list ',' IDENTIFIER  */
#line 298 "config.tab.yy"
                                 { ida.add((yyvsp[0].text)); }
#line 1568 "config.tab.cc"
    break;

  case 26: /* function_prefix: IDENTIFIER '(' id_list ')' '='  */
#line 302 "config.tab.yy"
                                                    { is_lhs = false;  function_name = (yyvsp[-4].text);  is_function_def = true; }
#line 1574 "config.tab.cc"
    break;

  case 27: /* assign_prefix: IDENTIFIER '='  */
#line 306 "config.tab.yy"
                                   { is_lhs = false;  strcpy((yyval.text), (yyvsp[-1].text)); }
#line 1580 "config.tab.cc"
    break;

  case 28: /* $@1: %empty  */
#line 310 "config.tab.yy"
                             { mark(apm); }
#line 1586 "config.tab.cc"
    break;

  case 29: /* array_prefix: assign_prefix $@1 '['  */
#line 310 "config.tab.yy"
                                                  { is_lhs = false;  strcpy((yyval.text), (yyvsp[-2].text)); }
#line 1592 "config.tab.cc"
    break;

  case 30: /* dictionary: '{' statement_list '}' opt_semi  */
#line 314 "config.tab.yy"
                                               { do_dict(); }
#line 1598 "config.tab.cc"
    break;

  case 33: /* string_list: QUOTED_STRING  */
#line 323 "config.tab.yy"
                                             { do_string((yyvsp[0].text)); }
#line 1604 "config.tab.cc"
    break;

  case 34: /* string_list: string_list ',' QUOTED_STRING  */
#line 324 "config.tab.yy"
                                             { do_string((yyvsp[0].text)); }
#line 1610 "config.tab.cc"
    break;

  case 37: /* threshold: thresh_node  */
#line 332 "config.tab.yy"
                                   { do_thresh    ((yyvsp[0].node)); }
#line 1616 "config.tab.cc"
    break;

  case 38: /* threshold: NA_COMPARISON  */
#line 333 "config.tab.yy"
                                   { do_na_thresh (); }
#line 1622 "config.tab.cc"
    break;

  case 39: /* thresh_node: simple_thresh  */
#line 337 "config.tab.yy"
                                                     { (yyval.node) = (yyvsp[0].node); }
#line 1628 "config.tab.cc"
    break;

  case 40: /* thresh_node: thresh_node LOGICAL_OP_AND thresh_node  */
#line 338 "config.tab.yy"
                                                     { (yyval.node) = do_and_thresh   ((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1634 "config.tab.cc"
    break;

  case 41: /* thresh_node: thresh_node LOGICAL_OP_OR thresh_node  */
#line 339 "config.tab.yy"
                                                     { (yyval.node) = do_or_thresh    ((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1640 "config.tab.cc"
    break;

  case 42: /* thresh_node: LOGICAL_OP_NOT thresh_node  */
#line 340 "config.tab.yy"
                                                     { (yyval.node) = do_not_thresh   ((yyvsp[0].node));     }
#line 1646 "config.tab.cc"
    break;

  case 43: /* thresh_node: '(' thresh_node ')'  */
#line 341 "config.tab.yy"
                                                     { (yyval.node) = do_paren_thresh ((yyvsp[-1].node));     }
#line 1652 "config.tab.cc"
    break;

  case 44: /* simple_thresh: COMPARISON number  */
#line 345 "config.tab.yy"
                                                                   { (yyval.node) = do_simple_thresh((yyvsp[-1].cval), (yyvsp[0].nval));     }
#line 1658 "config.tab.cc"
    break;

  case 45: /* simple_thresh: COMPARISON SIMPLE_PERC_THRESH  */
#line 346 "config.tab.yy"
                                                                   { (yyval.node) = do_simple_perc_thresh((yyvsp[-1].cval), (yyvsp[0].pc_info)); }
#line 1664 "config.tab.cc"
    break;

  case 46: /* simple_thresh: COMPARISON SIMPLE_PERC_THRESH '(' number ')'  */
#line 347 "config.tab.yy"
                                                                   { (yyval.node) = do_compound_perc_thresh((yyvsp[-4].cval), (yyvsp[-3].pc_info), (yyvsp[-1].nval)); }
#line 1670 "config.tab.cc"
    break;

  case 47: /* simple_thresh: FORTRAN_THRESHOLD  */
#line 348 "config.tab.yy"
                                                                   { (yyval.node) = do_fortran_thresh((yyvsp[0].text));        }
#line 1676 "config.tab.cc"
    break;

  case 48: /* number: INTEGER  */
#line 352 "config.tab.yy"
                 { set_number_string(); }
#line 1682 "config.tab.cc"
    break;

  case 49: /* number: FLOAT  */
#line 353 "config.tab.yy"
                 { set_number_string(); }
#line 1688 "config.tab.cc"
    break;

  case 50: /* boolean_list: BOOLEAN  */
#line 357 "config.tab.yy"
                                         { do_boolean((yyvsp[0].bval)); }
#line 1694 "config.tab.cc"
    break;

  case 51: /* boolean_list: boolean_list ',' BOOLEAN  */
#line 358 "config.tab.yy"
                                         { do_boolean((yyvsp[0].bval)); }
#line 1700 "config.tab.cc"
    break;

  case 56: /* expression: number  */
#line 372 "config.tab.yy"
                                                                   { do_number((yyvsp[0].nval)); }
#line 1706 "config.tab.cc"
    break;

  case 57: /* expression: LOCAL_VAR  */
#line 373 "config.tab.yy"
                                                                   { do_local_var((yyvsp[0].index)); }
#line 1712 "config.tab.cc"
    break;

  case 58: /* expression: expression '+' expression  */
#line 374 "config.tab.yy"
                                                                   { do_op('+'); }
#line 1718 "config.tab.cc"
    break;

  case 59: /* expression: expression '-' expression  */
#line 375 "config.tab.yy"
                                                                   { do_op('-'); }
#line 1724 "config.tab.cc"
    break;

  case 60: /* expression: expression '*' expression  */
#line 376 "config.tab.yy"
                                                                   { do_op('*'); }
#line 1730 "config.tab.cc"
    break;

  case 61: /* expression: expression '/' expression  */
#line 377 "config.tab.yy"
                                                                   { do_op('/'); }
#line 1736 "config.tab.cc"
    break;

  case 62: /* expression: expression '^' expression  */
#line 378 "config.tab.yy"
                                                                   { do_op('^'); }
#line 1742 "config.tab.cc"
    break;

  case 63: /* expression: '-' expression  */
#line 379 "config.tab.yy"
                                                                   { do_negate(); }
#line 1748 "config.tab.cc"
    break;

  case 64: /* expression: '(' expression ')'  */
#line 380 "config.tab.yy"
                                                                   { do_paren_exp(); }
#line 1754 "config.tab.cc"
    break;

  case 65: /* $@2: %empty  */
#line 381 "config.tab.yy"
                               { mark(fcm); }
#line 1760 "config.tab.cc"
    break;

  case 66: /* expression: BUILTIN '(' $@2 expression_list ')'  */
#line 381 "config.tab.yy"
                                                                   { do_builtin_call((yyvsp[-4].index));  }
#line 1766 "config.tab.cc"
    break;

  case 67: /* $@3: %empty  */
#line 382 "config.tab.yy"
                               { mark(fcm); }
#line 1772 "config.tab.cc"
    break;

  case 68: /* expression: USER_FUNCTION '(' $@3 expression_list ')'  */
#line 382 "config.tab.yy"
                                                                   { do_user_function_call((yyvsp[-4].entry)); }
#line 1778 "config.tab.cc"
    break;

  case 69: /* expression_list: expression  */
#line 387 "config.tab.yy"
                                                 { store_exp(); }
#line 1784 "config.tab.cc"
    break;

  case 70: /* expression_list: expression_list ',' expression  */
#line 388 "config.tab.yy"
                                                 { store_exp(); }
#line 1790 "config.tab.cc"
    break;

  case 71: /* piecewise_linear: '(' point_list ')'  */
#line 392 "config.tab.yy"
                                        { }
#line 1796 "config.tab.cc"
    break;

  case 72: /* point_list: point  */
#line 396 "config.tab.yy"
                                { }
#line 1802 "config.tab.cc"
    break;

  case 73: /* point_list: point_list point  */
#line 397 "config.tab.yy"
                                { }
#line 1808 "config.tab.cc"
    break;

  case 74: /* point: '(' expression ',' expression ')'  */
#line 401 "config.tab.yy"
                                            { add_point(); }
#line 1814 "config.tab.cc"
    break;


#line 1818 "config.tab.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 405 "config.tab.yy"



////////////////////////////////////////////////////////////////////////


   //
   //  standard yacc stuff
   //


////////////////////////////////////////////////////////////////////////


void yyerror(const char * s)

{

int j, j1, j2;
int line_len, text_len;
int c;
char line[max_id_length + 1];
ifstream in;
ConcatString msg;


c = (int) (Column - strlen(configtext));

mlog << Error
     << "\n"
     << "yyerror() -> syntax error in file \"" << bison_input_filename << "\"\n\n"
     << "   line   = " << LineNumber << "\n\n"
     << "   column = " << c << "\n\n"
     << "   text   = \"" << configtext << "\"\n\n";

met_open(in, bison_input_filename);

for (j=1; j<LineNumber; ++j)  {   //  j starts at one here, not zero

   in.getline(line, sizeof(line));

}

in.getline(line, sizeof(line));

in.close();




mlog << Error
     << "\n" << line << "\n";

line_len = strlen(line);

text_len = strlen(configtext);

j1 = c;
j2 = c + text_len - 1;

msg.erase();
for (j=1; j<=line_len; ++j)  {   //  j starts at one here, not zero

   if ( (j >= j1) && (j <= j2) )  msg << '^';
   else                           msg << '_';

}

mlog << Error
     << msg << "\n\n";


exit ( 1 );

}


////////////////////////////////////////////////////////////////////////


int configwrap()

{

return ( 1 );

}


////////////////////////////////////////////////////////////////////////


void do_op(char op)

{

IcodeCell cell;
IcodeVector L, R;


R = icvs.pop();
L = icvs.pop();


switch ( op )  {


   case '+':  cell.type = op_add;       break;
   case '-':  cell.type = op_subtract;  break;


   case '*':  cell.type = op_multiply;  break;
   case '/':  cell.type = op_divide;    break;


   case '^':
      if ( (R.length() == 1) && (R[0].type == integer) && (R[0].i == 2) )   cell.type = op_square;
      else                                                                  cell.type = op_power;
      break;


   default:
      cerr << "\n\n  do_op() -> unrecognized op ... \"" << op << "\"\n\n";
      exit ( 1 );

}   //  switch

if ( cell.type != op_square )   L.add(R);

L.add(cell);

icvs.push(L);

   //
   //  done
   //

return;

}


////////////////////////////////////////////////////////////////////////


Number do_integer_op(char op, const Number & a, const Number & b)

{

Number c;
int A, B, C;

A = a.i;
B = b.i;

switch ( op )  {

   case '+':  C = A + B;  break;
   case '-':  C = A - B;  break;
   case '*':  C = A * B;  break;
   case '/':
      if ( B == 0 )  {
         mlog << Error << "\ndo_integer_op() -> "
              << "division by zero!\n\n";
         exit ( 1 );
      }
      C = A / B;
      break;

   default:
      mlog << Error << "\ndo_integer_op() -> "
           << "bad operator ... \"" << op << "\"\n\n";
      exit ( 1 );

}

set_int(c, C);

   //
   //  done
   //

return ( c );

}


////////////////////////////////////////////////////////////////////////


void do_negate()

{

IcodeVector v;
IcodeCell cell;

cell.type = op_negate;

v = icvs.pop();

v.add(cell);

icvs.push(v);

return;

}


////////////////////////////////////////////////////////////////////////


void do_paren_exp()

{

   //
   //  nothing to do here!
   //

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_boolean(const char * name, bool tf)

{

DictionaryEntry entry;

entry.set_boolean(name, tf);

dict_stack->store(entry);

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_threshold(const char * name)

{

DictionaryEntry e;

e.set_threshold(name, STH);

dict_stack->store(e);

STH.clear();

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_exp(const char * name)

{

DictionaryEntry entry;
IcodeVector v;
Number n;

v = icvs.pop();

hp.run(v);

n = hp.pop();

if ( n.is_int)  entry.set_int    (name, n.i);
else            entry.set_double (name, n.d);

dict_stack->store(entry);


return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_string(const char * name, const char * text)

{

DictionaryEntry entry;

entry.set_string(name, text);

dict_stack->store(entry);

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_id(const char * LHS, const char * RHS)

{

const DictionaryEntry * e = dict_stack->lookup(RHS);

if ( !e )  {

   mlog << Error << "\ndo_assign_id() -> "
        << "identifier \"" << RHS
        << "\" not defined in this scope!\n\n";

   exit ( 1 );

}

DictionaryEntry ee = *e;

ee.set_name(LHS);

dict_stack->store(ee);

return;

}


////////////////////////////////////////////////////////////////////////


void do_dict()

{

DD = *(dict_stack->top());

dict_stack->erase_top();

if ( ! dict_stack->top_is_array() )  return;

DictionaryEntry e;

e.set_dict("", DD);

dict_stack->store(e);

DD.clear();

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_dict (const char * name)

{

if ( DD.n_entries() > 0 )  {

   DictionaryEntry e;

   e.set_dict(name, DD);

   dict_stack->store(e);

   DD.clear();

} else {

   dict_stack->pop_dict(name);

}

if ( icvs.top_is_mark(apm) )  icvs.toss();

return;

}


////////////////////////////////////////////////////////////////////////


void do_assign_exp_array(const char * name)

{

int j, count;
IcodeVector v;
Number n;
NumberStack ns;
DictionaryEntry e;



count = 0;

while ( 1 )  {

   v = icvs.pop();

   if ( v.is_mark() )  break;

   hp.run(v);

   n = hp.pop();

   ns.push(n);

   ++count;

}   //  while


for (j=0; j<count; ++j)  {

   e.clear();

   n = ns.pop();

   if ( n.is_int )  e.set_int    ("", n.i);
   else             e.set_double ("", n.d);

   dict_stack->store(e);

}   //  for j

dict_stack->set_top_is_array(true);

dict_stack->pop_dict(name);


DD.clear();

if ( icvs.top_is_mark(apm) )  icvs.toss();

return;

}


////////////////////////////////////////////////////////////////////////


void do_string(const char * text)

{

DictionaryEntry e;

e.set_string("", text);

dict_stack->store(e);


return;

}


////////////////////////////////////////////////////////////////////////


void do_boolean(const bool & boolean)

{

DictionaryEntry e;

e.set_boolean("", boolean);

dict_stack->store(e);


return;

}


////////////////////////////////////////////////////////////////////////


void store_exp()

{


// DictionaryEntry e;
// IcodeVector v;
// Number n;
//
// v = icvs.pop();
//
// hp.run(v);
//
// n = hp.pop();
//
// if ( n.is_int )  e.set_int    (0, n.i);
// else             e.set_double (0, n.d);
//
// dict_stack->store(e);


return;

}


////////////////////////////////////////////////////////////////////////


void do_thresh(ThreshNode * node)

{

if ( test_mode )  {

   result = node;

}

else {

   if ( dict_stack->top_is_array() )  {

      DictionaryEntry e;
      SingleThresh T;

      T.set(node);

      e.set_threshold("", T);

      dict_stack->store(e);

   }  else STH.set(node);

}

return;

}


////////////////////////////////////////////////////////////////////////


void do_na_thresh()

{

if ( !dict_stack->top_is_array() )  return;

DictionaryEntry e;
SingleThresh T;

T.set(na_str);

e.set_threshold("", T);

dict_stack->store(e);

   //
   //  done
   //

return;

}


////////////////////////////////////////////////////////////////////////


void add_point()

{

double x, y;
IcodeVector xv, yv;
Number n;

yv = icvs.pop();
xv = icvs.pop();

hp.run(xv);

n = hp.pop();

x = as_double(n);

hp.run(yv);

n = hp.pop();

y = as_double(n);

pwl.add_point(x, y);

return;

}


////////////////////////////////////////////////////////////////////////


void do_pwl(const char * LHS)

{

DictionaryEntry e;

e.set_pwl(LHS, pwl);

dict_stack->store(e);


   //
   //  done
   //

pwl.clear();

return;

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_and_thresh    (ThreshNode * a, ThreshNode * b)

{

And_Node * n = new And_Node;

n->left_child  = a;
n->right_child = b;

n->s << a->s << "&&" << b->s;

n->abbr_s << a->abbr_s << ".and." << b->abbr_s;

return ( n );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_or_thresh (ThreshNode * a, ThreshNode * b)

{

Or_Node * n = new Or_Node;

n->left_child  = a;
n->right_child = b;

n->s << a->s << "||" << b->s;

n->abbr_s << a->abbr_s << ".or." << b->abbr_s;

return ( n );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_not_thresh    (ThreshNode * n)

{

Not_Node * nn = new Not_Node;

nn->child = n;

nn->s << '!' << n->s;

nn->abbr_s << ".not." << n->abbr_s;

return ( nn );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_paren_thresh  (ThreshNode * n)

{

ConcatString b;

b.erase();

b << '(' << n->s << ')';

n->s = b;

b.erase();

b << '(' << n->abbr_s << ')';

n->abbr_s = b;

return ( n );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_simple_thresh (ThreshType op, const Number & n)

{

Simple_Node * s = new Simple_Node;

s->op = op;

s->T = as_double(n);

if ( op >= 0 )  {

   s->s      << thresh_type_str[op] << number_string;
   s->abbr_s << thresh_abbr_str[op] << number_string;

}

return ( s );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_fortran_thresh(const char * text)

{

ThreshType op  = no_thresh_type;
const char * p = text + 2;         //  we know that all the prefixes
                                   //  (like "le" or "gt") are two
                                   //  characters long

  //  foo


     if ( strncmp(text, "le", 2) == 0 )  op = thresh_le;
else if ( strncmp(text, "lt", 2) == 0 )  op = thresh_lt;

else if ( strncmp(text, "gt", 2) == 0 )  op = thresh_gt;
else if ( strncmp(text, "ge", 2) == 0 )  op = thresh_ge;

else if ( strncmp(text, "eq", 2) == 0 )  op = thresh_eq;
else if ( strncmp(text, "ne", 2) == 0 )  op = thresh_ne;

else {

   mlog << Error << "do_fortran_thresh(const char *) -> "
        << "can't parse threshold text \""
        << text << "\"\n\n";

   exit ( 1 );

}

Number n;
const double value = atof(p);

n.is_int = 0;

n.d = value;

set_number_string(p);

return ( do_simple_thresh (op, n) );

}


////////////////////////////////////////////////////////////////////////


void set_number_string()

{

set_number_string(configtext);

return;

}


////////////////////////////////////////////////////////////////////////


void set_number_string(const char * text)

{

const int k = (int) (sizeof(number_string));

strncpy(number_string, text, k);

number_string[k - 1] = (char) 0;

return;

}


////////////////////////////////////////////////////////////////////////


void mark(int k)

{

IcodeVector v;
IcodeCell cell;


cell.type = cell_mark;

cell.i = k;

v.add(cell);

icvs.push(v);


return;

}


////////////////////////////////////////////////////////////////////////


void do_number(const Number & n)

{

IcodeVector v;
IcodeCell cell;

if ( n.is_int )  {

   cell.set_integer(n.i);

} else {

   cell.set_double (n.d);

}

v.add(cell);

icvs.push(v);


return;

}


////////////////////////////////////////////////////////////////////////


void do_local_var(int n)

{

IcodeVector v;
IcodeCell cell;

cell.set_local_var(n);

v.add(cell);

icvs.push(v);



return;

}


////////////////////////////////////////////////////////////////////////


void do_print(const char * s)

{

IcodeVector v;
Number n;


if ( bison_input_filename )  cout << bison_input_filename;
else                         cout << default_print_prefix;

cout << ": ";

if ( s )  cout << s;

v = icvs.pop();

hp.run(v);

n = hp.pop();

if ( n.is_int )  cout << (n.i) << "\n";
else             cout << (n.d) << "\n";



cout.flush();

return;

}


////////////////////////////////////////////////////////////////////////


void do_builtin_call(int which)

{

int j;
IcodeVector v;
IcodeCell cell;
const BuiltinInfo & info = binfo[which];


if ( is_function_def )  {

   IcodeVector vv;

      //  pop the args (in reverse order) from the icodevector stack

   for (j=0; j<(info.n_args); ++j)  {

      vv = icvs.pop();

      v.add_front(vv);

   }

   if ( icvs.top_is_mark(fcm) )  icvs.toss();

      //

   cell.set_builtin(which);

   v.add(cell);

      //

   icvs.push(v);

   return;

}   //  if is function def

   ///////////////////////////////////////

Number n[max_builtin_args];
Number cur_result;

   //
   //  pop the args (in reverse order) from the icodevector stack
   //

for (j=0; j<(info.n_args); ++j)  {

   v = icvs.pop();

   if ( v.is_mark() )  {

      cerr << "\n\n  do_builtin_call(int) -> too few arguments to builtin function \""
           << info.name << "\"\n\n";

      exit ( 1 );

   }

   hp.run(v);

   n[info.n_args - 1 - j] = hp.pop();

}

   //
   //  next one should be a mark
   //

v = icvs.pop();

if ( ! (v.is_mark()) )  {

   cerr << "\n\n  do_builtin_call(int) -> too many arguments to builtin function \""
        << info.name << "\"\n\n";

   exit ( 1 );

}

   //
   //  call the function
   //

hp.do_builtin(which, n);

cur_result = hp.pop();

if ( cur_result.is_int )  cell.set_integer (cur_result.i);
else                      cell.set_double  (cur_result.d);

v.clear();

v.add(cell);

icvs.push(v);


   //
   //  done
   //

return;

}


////////////////////////////////////////////////////////////////////////


void do_user_function_call(const DictionaryEntry * e)

{

int j;
IcodeVector v;
IcodeCell cell;
const int Nargs = e->n_args();


if ( is_function_def )  {

   IcodeVector vv;

      //  pop the args (in reverse order) from the icodevector stack

   for (j=0; j<Nargs; ++j)  {

      vv = icvs.pop();

      v.add_front(vv);

   }

   if ( icvs.top_is_mark(fcm) )  icvs.toss();

      //

   cell.set_user_function(e);

   v.add(cell);

      //

   icvs.push(v);

   return;

}   //  if is function def


   //////////////////////////////////////

Number n[max_user_function_args];
Number cur_result;

   //
   //  pop the args (in reverse order) from the icodevector stack
   //

for (j=0; j<Nargs; ++j)  {

   v = icvs.pop();

   if ( v.is_mark() )  {

      cerr << "\n\n  do_user_function_call(int) -> too few arguments to user function \""
           << (e->name()) << "\"\n\n";

      exit ( 1 );

   }

   hp.run(v);

   n[Nargs - 1 - j] = hp.pop();

}


if ( icvs.top_is_mark(fcm) )  icvs.toss();


   //
   //  call the function
   //

hp.run(*(e->icv()), n);

cur_result = hp.pop();

if ( cur_result.is_int )  cell.set_integer (cur_result.i);
else                      cell.set_double  (cur_result.d);

v.clear();

v.add(cell);

icvs.push(v);






   //
   //  done
   //

// if ( icvs.top_is_mark(fcm) )  icvs.toss();

return;

}


////////////////////////////////////////////////////////////////////////


void do_user_function_def()

{

DictionaryEntry e;

if ( ida.n_elements() > max_user_function_args )  {

   cerr << "\n\n  do_user_function_def() -> too many arguments to function \""
        << function_name << "\" definition\n\n";

   exit ( 1 );

}

e.set_user_function(function_name.c_str(), icvs.pop(), ida.n_elements());

dict_stack->store(e);

   //
   //  done
   //

is_function_def = false;

ida.clear();

function_name.erase();

return;

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_simple_perc_thresh (const ThreshType op, const PC_info & info)

{

Simple_Node * s = new Simple_Node;

s->op = op;

if ( (info.perc_index < 0) || (info.perc_index >= n_perc_thresh_infos) )  {

   mlog << Error
        << "\ndo_simple_perc_thresh() -> bad perc_index ... "
        << (info.perc_index) << "\n\n";

   exit ( 1 );

}

s->T     = bad_data_double;

s->PT    = info.value;

s->Ptype = perc_thresh_info[info.perc_index].type;

   //
   //  sanity check
   //

if ( s->PT < 0 || s->PT > 100 )  {

   mlog << Error << "\ndo_simple_perc_thresh() -> "
        << "the percentile (" << s->PT << ") must be between 0 and 100!\n\n";

   exit ( 1 );

}

if ( s->Ptype == perc_thresh_freq_bias && s->PT <= 0 )  {

   mlog << Error << "\ndo_simple_perc_thresh() -> "
        << "unsupported frequency bias percentile threshold!\n\n";

   exit ( 1 );

}

   //
   //  update the strings
   //

if ( op >= 0 )  {

   ConcatString cs;
   cs << perc_thresh_info[info.perc_index].short_name;
   cs << info.value;
   fix_float(cs);

   s->s      << thresh_type_str[op] << cs;
   s->abbr_s << thresh_abbr_str[op] << cs;

}

   //
   //  done
   //

return ( s );

}


////////////////////////////////////////////////////////////////////////


ThreshNode * do_compound_perc_thresh (const ThreshType op, const PC_info & info, const Number & num)

{

Simple_Node * s = new Simple_Node;

s->op = op;

if ( (info.perc_index < 0) || (info.perc_index >= n_perc_thresh_infos) )  {

   mlog << Error
        << "\ndo_compound_perc_thresh() -> bad perc_index ... "
        << (info.perc_index) << "\n\n";

   exit ( 1 );

}

if ( num.is_int )  s->T     = (double) (num.i);
else               s->T     = num.d;

s->PT    = info.value;

s->Ptype = perc_thresh_info[info.perc_index].type;

   //
   //  sanity check
   //

if ( s->PT < 0 || s->PT > 100 )  {

   mlog << Error << "\ndo_compound_perc_thresh() -> "
        << "the percentile (" << s->PT << ") must be between 0 and 100!\n\n";

   exit ( 1 );

}

if ( s->Ptype == perc_thresh_freq_bias && !is_eq(s->PT, 1.0) )  {

   mlog << Error << "\ndo_compound_perc_thresh() -> "
        << "unsupported frequency bias percentile threshold!\n\n";

   exit ( 1 );

}

   //
   //  update the strings
   //

if ( op >= 0 )  {

   ConcatString cs;
   cs << perc_thresh_info[info.perc_index].short_name;
   cs << info.value;
   fix_float(cs);
   cs << "(" << number_string << ")";

   s->s      << thresh_type_str[op] << cs;
   s->abbr_s << thresh_abbr_str[op] << cs;

}

   //
   //  done
   //

return ( s );

}


////////////////////////////////////////////////////////////////////////

