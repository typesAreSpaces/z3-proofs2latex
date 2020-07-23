/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "z3-parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 100000

extern int yylex();
    extern int yyparse();
    extern FILE* yyin;

void yyerror(const char* s);

struct list_string {
  char * address;
  struct list_string * next;
};

struct string_string {
  char * address_first;
  char * address_second;
};

struct list_string_string {
  struct string_string * pair_address;
  struct list_string_string * next;
};

struct list_of_list_string {
  struct list_string * element;
  struct list_of_list_string * next;
};

char                       * temp_s                 = 0;
struct string_string       * temp_ss                = 0;
struct list_string         * string_database        = 0;
struct list_string_string  * string_string_database = 0;
struct list_of_list_string * lists_database         = 0;

void print_list_string(struct list_string * string_database){
  struct list_string * temp = string_database;
  while(temp != 0 && temp->address != 0){
    printf("%s (inside print_list_string) \n", temp->address);
    temp = temp->next;
  }
}

void fold(struct list_string * aux, char ** res, char * op){
  unsigned count = 0;
  while(aux != 0 && aux->address != 0){
    if(count > 0)
      strcat(*res, op);
    strcat(*res, aux->address); 
    aux = aux->next;
    count++;
  }
}

void fold_quantifier(struct list_string_string * aux, char ** res, char * formula){
  unsigned count = 0; 
  while(aux != 0 && aux->pair_address != 0){
    if(count > 0)
      strcat(*res, ", ");
    strcat(*res, "(");
    strcat(*res, aux->pair_address->address_first);
    strcat(*res, " : ");
    strcat(*res, aux->pair_address->address_second);
    strcat(*res, ")");
    aux = aux->next;
    count++;
  }
  strcat(*res, ". \\\\");
  strcat(*res, formula);
  strcat(*res, ")");
}

void add_string(struct list_string ** string_database, char * new_addres){
  struct list_string * updated = (struct list_string*)malloc(sizeof(struct list_string *));
  updated->address = new_addres;
  updated->next = *string_database;
  *string_database = updated;
}

void add_string_string(struct list_string_string ** string_string_database, struct string_string * new_addres){
  struct list_string_string * updated = (struct list_string_string*)malloc(sizeof(struct list_string_string *));
  updated->pair_address = new_addres;
  updated->next = *string_string_database;
  *string_string_database = updated;
}

void add_list_string(struct list_of_list_string ** lists, struct list_string * new_element){
  struct list_of_list_string * updated = (struct list_of_list_string *)malloc(sizeof(struct list_of_list_string *));
  updated->element = new_element;
  updated->next = *lists;
  *lists = updated;
}

void free_strings(struct list_string * string_database){
  while(string_database != 0){
    free(string_database->address);
    struct list_string * temp = string_database->next;
    free(string_database);
    string_database = temp;
  }
}

void free_strings_strings(struct list_string_string * string_string_database){
  while(string_string_database != 0){
    free(string_string_database->pair_address);
    struct list_string_string * temp = string_string_database->next;
    free(string_string_database);
    string_string_database = temp;
  }
}

void free_list_strings(struct list_of_list_string * lists_database){
  while(lists_database!= 0){
    free(lists_database->element);
    struct list_of_list_string * temp = lists_database->next;
    free(lists_database);
    lists_database = temp;
  }
}


#line 197 "z3-parser.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Z3_PARSER_TAB_H_INCLUDED
# define YY_YY_Z3_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_INT = 258,                   /* T_INT  */
    T_NAME = 259,                  /* T_NAME  */
    T_PROOF_RULE = 260,            /* T_PROOF_RULE  */
    END = 261,                     /* END  */
    REL_SYM = 262,                 /* REL_SYM  */
    OP_SYM = 263,                  /* OP_SYM  */
    MINUS_SYM = 264,               /* MINUS_SYM  */
    PAREN_LEFT = 265,              /* PAREN_LEFT  */
    PAREN_RIGHT = 266,             /* PAREN_RIGHT  */
    COMMA = 267,                   /* COMMA  */
    UNSAT_TOKEN = 268,             /* UNSAT_TOKEN  */
    EXCLAMATION_MARK_TOKEN = 269,  /* EXCLAMATION_MARK_TOKEN  */
    FORALL_TOKEN = 270,            /* FORALL_TOKEN  */
    EXISTS_TOKEN = 271,            /* EXISTS_TOKEN  */
    INTERPOLANTS_TOKEN = 272,      /* INTERPOLANTS_TOKEN  */
    PATTERN_TOKEN = 273,           /* PATTERN_TOKEN  */
    AND_TOKEN = 274,               /* AND_TOKEN  */
    OR_TOKEN = 275,                /* OR_TOKEN  */
    NOT_TOKEN = 276,               /* NOT_TOKEN  */
    EQUAL_TOKEN = 277,             /* EQUAL_TOKEN  */
    LET_TOKEN = 278,               /* LET_TOKEN  */
    SELECT_TOKEN = 279,            /* SELECT_TOKEN  */
    STORE_TOKEN = 280,             /* STORE_TOKEN  */
    ARRAY_EXT_TOKEN = 281,         /* ARRAY_EXT_TOKEN  */
    UNDERSCORE_TOKEN = 282,        /* UNDERSCORE_TOKEN  */
    ZERO_TOKEN = 283,              /* ZERO_TOKEN  */
    PERCENT_TOKEN = 284,           /* PERCENT_TOKEN  */
    BOOL_TYPE_TOKEN = 285,         /* BOOL_TYPE_TOKEN  */
    INT_TYPE_TOKEN = 286,          /* INT_TYPE_TOKEN  */
    ARRAY_TYPE_TOKEN = 287         /* ARRAY_TYPE_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 127 "z3-parser.y"

    int                         ival;
    char                      * sval;
    struct string_string      * ssval;
    struct list_string        * slist;
    struct list_string_string * sslist;

#line 287 "z3-parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Z3_PARSER_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_NAME = 4,                     /* T_NAME  */
  YYSYMBOL_T_PROOF_RULE = 5,               /* T_PROOF_RULE  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_REL_SYM = 7,                    /* REL_SYM  */
  YYSYMBOL_OP_SYM = 8,                     /* OP_SYM  */
  YYSYMBOL_MINUS_SYM = 9,                  /* MINUS_SYM  */
  YYSYMBOL_PAREN_LEFT = 10,                /* PAREN_LEFT  */
  YYSYMBOL_PAREN_RIGHT = 11,               /* PAREN_RIGHT  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_UNSAT_TOKEN = 13,               /* UNSAT_TOKEN  */
  YYSYMBOL_EXCLAMATION_MARK_TOKEN = 14,    /* EXCLAMATION_MARK_TOKEN  */
  YYSYMBOL_FORALL_TOKEN = 15,              /* FORALL_TOKEN  */
  YYSYMBOL_EXISTS_TOKEN = 16,              /* EXISTS_TOKEN  */
  YYSYMBOL_INTERPOLANTS_TOKEN = 17,        /* INTERPOLANTS_TOKEN  */
  YYSYMBOL_PATTERN_TOKEN = 18,             /* PATTERN_TOKEN  */
  YYSYMBOL_AND_TOKEN = 19,                 /* AND_TOKEN  */
  YYSYMBOL_OR_TOKEN = 20,                  /* OR_TOKEN  */
  YYSYMBOL_NOT_TOKEN = 21,                 /* NOT_TOKEN  */
  YYSYMBOL_EQUAL_TOKEN = 22,               /* EQUAL_TOKEN  */
  YYSYMBOL_LET_TOKEN = 23,                 /* LET_TOKEN  */
  YYSYMBOL_SELECT_TOKEN = 24,              /* SELECT_TOKEN  */
  YYSYMBOL_STORE_TOKEN = 25,               /* STORE_TOKEN  */
  YYSYMBOL_ARRAY_EXT_TOKEN = 26,           /* ARRAY_EXT_TOKEN  */
  YYSYMBOL_UNDERSCORE_TOKEN = 27,          /* UNDERSCORE_TOKEN  */
  YYSYMBOL_ZERO_TOKEN = 28,                /* ZERO_TOKEN  */
  YYSYMBOL_PERCENT_TOKEN = 29,             /* PERCENT_TOKEN  */
  YYSYMBOL_BOOL_TYPE_TOKEN = 30,           /* BOOL_TYPE_TOKEN  */
  YYSYMBOL_INT_TYPE_TOKEN = 31,            /* INT_TYPE_TOKEN  */
  YYSYMBOL_ARRAY_TYPE_TOKEN = 32,          /* ARRAY_TYPE_TOKEN  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_parse = 34,                     /* parse  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_interpolants = 36,              /* interpolants  */
  YYSYMBOL_formula = 37,                   /* formula  */
  YYSYMBOL_type = 38,                      /* type  */
  YYSYMBOL_binding = 39,                   /* binding  */
  YYSYMBOL_one_type = 40,                  /* one_type  */
  YYSYMBOL_list_binding = 41,              /* list_binding  */
  YYSYMBOL_list_type = 42,                 /* list_type  */
  YYSYMBOL_list_formula = 43,              /* list_formula  */
  YYSYMBOL_list_interpolant = 44,          /* list_interpolant  */
  YYSYMBOL_45_2 = 45                       /* $@2  */
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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   85

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  32
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

#define YYMAXUTOK   287


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   156,   168,   171,   174,   198,   208,   217,
     226,   235,   244,   253,   264,   277,   288,   298,   307,   311,
     311,   311,   324,   334,   344,   349,   355,   360,   366,   372,
     378,   378,   378
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
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_NAME",
  "T_PROOF_RULE", "END", "REL_SYM", "OP_SYM", "MINUS_SYM", "PAREN_LEFT",
  "PAREN_RIGHT", "COMMA", "UNSAT_TOKEN", "EXCLAMATION_MARK_TOKEN",
  "FORALL_TOKEN", "EXISTS_TOKEN", "INTERPOLANTS_TOKEN", "PATTERN_TOKEN",
  "AND_TOKEN", "OR_TOKEN", "NOT_TOKEN", "EQUAL_TOKEN", "LET_TOKEN",
  "SELECT_TOKEN", "STORE_TOKEN", "ARRAY_EXT_TOKEN", "UNDERSCORE_TOKEN",
  "ZERO_TOKEN", "PERCENT_TOKEN", "BOOL_TYPE_TOKEN", "INT_TYPE_TOKEN",
  "ARRAY_TYPE_TOKEN", "$accept", "parse", "$@1", "interpolants", "formula",
  "type", "binding", "one_type", "list_binding", "list_type",
  "list_formula", "list_interpolant", "$@2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -79,    10,    21,   -79,    25,    19,   -79,     1,   -79,     4,
      26,    27,    29,    14,     1,    32,    33,     1,     1,     1,
       1,    35,     1,     1,     1,   -79,   -79,     1,    36,    20,
      30,    39,    39,    40,    41,    42,    43,    48,     1,     1,
     -79,   -79,   -79,    37,    49,    57,    39,    52,    53,   -79,
     -79,   -79,   -79,    62,    48,    56,    58,     1,    59,   -79,
      -9,   -79,     1,     1,     1,   -79,     1,   -79,    60,     1,
      44,   -79,   -79,    63,    64,    66,    67,    68,   -79,     1,
      -9,   -79,   -79,   -79,   -79,   -79,    69,    -9,   -79,    70,
     -79
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     0,    18,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,    17,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    29,    16,     0,     0,     0,    26,     0,     0,     9,
      10,    11,    12,     0,    24,     0,     0,     0,     0,     5,
       0,    27,     0,     0,     0,    25,     0,    13,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    14,     0,
       0,    23,     7,     8,    22,     6,     0,     0,    15,     0,
      21
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -79,   -79,    -7,   -78,   -79,   -79,    28,    -2,
     -14,    61,   -79
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,    27,    73,    54,    46,    55,    47,
      28,    11,    24
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      10,    70,    87,    33,    34,     8,    36,    30,    12,    89,
       3,     9,    35,    41,    13,    38,    39,    10,    14,    15,
      16,    71,    72,    17,    18,    19,    20,    21,    22,    23,
      48,    56,    57,     8,     4,     5,     7,   -30,    25,     9,
      26,    29,    31,    32,    61,    37,    43,    42,    44,    45,
      68,    49,    50,    51,    52,    74,    75,    76,    53,    77,
      59,    60,    79,    62,    63,    58,    64,    66,     0,    67,
      69,    78,    86,     0,    81,    82,    80,    83,    84,    85,
      88,    90,    65,     0,     0,    40
};

static const yytype_int8 yycheck[] =
{
       7,    10,    80,    17,    18,     4,    20,    14,     4,    87,
       0,    10,    19,    27,    10,    22,    23,    24,    14,    15,
      16,    30,    31,    19,    20,    21,    22,    23,    24,    25,
      32,    38,    39,     4,    13,    10,    17,    11,    11,    10,
      11,    27,    10,    10,    46,    10,    26,    11,    18,    10,
      57,    11,    11,    11,    11,    62,    63,    64,    10,    66,
      11,     4,    69,    11,    11,    28,     4,    11,    -1,    11,
      11,    11,    79,    -1,    11,    11,    32,    11,    11,    11,
      11,    11,    54,    -1,    -1,    24
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,     0,    13,    10,    36,    17,     4,    10,
      37,    44,     4,    10,    14,    15,    16,    19,    20,    21,
      22,    23,    24,    25,    45,    11,    11,    37,    43,    27,
      37,    10,    10,    43,    43,    37,    43,    10,    37,    37,
      44,    43,    11,    26,    18,    10,    40,    42,    42,    11,
      11,    11,    11,    10,    39,    41,    37,    37,    28,    11,
       4,    42,    11,    11,     4,    41,    11,    11,    37,    11,
      10,    30,    31,    38,    37,    37,    37,    37,    11,    37,
      32,    11,    11,    11,    11,    11,    37,    38,    11,    38,
      11
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    35,    34,    36,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    38,
      38,    38,    39,    40,    41,    41,    42,    42,    43,    43,
      44,    45,    44
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     4,     5,     7,     7,     7,     4,
       4,     4,     4,     5,     6,     9,     4,     3,     1,     1,
       1,     5,     4,     4,     1,     2,     1,     2,     1,     2,
       1,     0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2:
#line 156 "z3-parser.y"
     { 
       printf("\\documentclass{article}\n\\begin{document}\n"); 
     }
#line 1372 "z3-parser.tab.c"
    break;

  case 3:
#line 161 "z3-parser.y"
     {
       free_strings(string_database); 
       free_strings_strings(string_string_database); 
       free_list_strings(lists_database); 
       printf("\n\\end{document}\n\n"); 
     }
#line 1383 "z3-parser.tab.c"
    break;

  case 5:
#line 171 "z3-parser.y"
                                                                                                                 {
       (yyval.sval)=(yyvsp[-2].sval); // done
       }
#line 1391 "z3-parser.tab.c"
    break;

  case 6:
#line 174 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       /*strcpy(temp_s, "(let \\\\");*/
       strcpy(temp_s, "let \\\\");
       unsigned count = 0;
       struct list_string_string * aux = (yyvsp[-3].sslist);
       while(aux != 0 && aux->pair_address != 0){
         if(count > 0)
           strcat(temp_s, "\\\\ ");
         /*strcat(temp_s, "(");*/
         strcat(temp_s, aux->pair_address->address_first);
         strcat(temp_s, " = ");
         strcat(temp_s, aux->pair_address->address_second);
         /*strcat(temp_s, ")");*/
         aux = aux->next;
         count++;
       }
       strcat(temp_s, " in \\\\");
       strcat(temp_s, (yyvsp[-1].sval));
       /*strcat(temp_s, ")");*/
       (yyval.sval) = temp_s;
       }
#line 1420 "z3-parser.tab.c"
    break;

  case 7:
#line 198 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\forall ");
       unsigned count = 0;
       struct list_string_string * aux = (yyvsp[-3].sslist);
       fold_quantifier((yyvsp[-3].sslist), &temp_s, (yyvsp[-1].sval));
       (yyval.sval) = temp_s;
       }
#line 1435 "z3-parser.tab.c"
    break;

  case 8:
#line 208 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\exists ");
       unsigned count = 0;
       fold_quantifier((yyvsp[-3].sslist), &temp_s, (yyvsp[-1].sval));
       (yyval.sval) = temp_s;
       }
#line 1449 "z3-parser.tab.c"
    break;

  case 9:
#line 217 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "("); 
       fold((yyvsp[-1].slist), &temp_s, " \\land ");
       strcat(temp_s, ")");
       (yyval.sval)=temp_s;
       }
#line 1463 "z3-parser.tab.c"
    break;

  case 10:
#line 226 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(");
       fold((yyvsp[-1].slist), &temp_s, " \\lor ");
       strcat(temp_s, ")");
       (yyval.sval)=temp_s;
       }
#line 1477 "z3-parser.tab.c"
    break;

  case 11:
#line 235 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\neg ");
       strcat(temp_s, (yyvsp[-1].sval));
       strcat(temp_s, ")");
       (yyval.sval)=temp_s;
       }
#line 1491 "z3-parser.tab.c"
    break;

  case 12:
#line 244 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "("); 
       fold((yyvsp[-1].slist), &temp_s, " = ");
       strcat(temp_s, ")");
       (yyval.sval)=temp_s;
       }
#line 1505 "z3-parser.tab.c"
    break;

  case 13:
#line 253 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcat(temp_s, "select( "); 
       strcat(temp_s, (yyvsp[-2].sval));
       strcat(temp_s, ", "); 
       strcat(temp_s, (yyvsp[-1].sval));
       strcat(temp_s, ")"); 
       (yyval.sval)=temp_s;
       }
#line 1521 "z3-parser.tab.c"
    break;

  case 14:
#line 264 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "store("); 
       strcat(temp_s, (yyvsp[-3].sval));
       strcat(temp_s, ", "); 
       strcat(temp_s, (yyvsp[-2].sval));
       strcat(temp_s, ", "); 
       strcat(temp_s, (yyvsp[-1].sval));
       strcat(temp_s, ")"); 
       (yyval.sval)=temp_s;
       }
#line 1539 "z3-parser.tab.c"
    break;

  case 15:
#line 277 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "array-ext("); 
       strcat(temp_s, (yyvsp[-2].sval));
       strcat(temp_s, ", "); 
       strcat(temp_s, (yyvsp[-1].sval));
       strcat(temp_s, ")"); 
       (yyval.sval) = temp_s;
       }
#line 1555 "z3-parser.tab.c"
    break;

  case 16:
#line 288 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, (yyvsp[-2].sval)); 
       strcat(temp_s, "("); 
       fold((yyvsp[-1].slist), &temp_s, ", ");
       strcat(temp_s, ")");
       (yyval.sval)=temp_s;
       }
#line 1570 "z3-parser.tab.c"
    break;

  case 17:
#line 298 "z3-parser.y"
                                                                                                                 {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(");
       strcat(temp_s, (yyvsp[-1].sval));
       strcpy(temp_s, ")");
       (yyval.sval)=temp_s; // done
       }
#line 1584 "z3-parser.tab.c"
    break;

  case 18:
#line 307 "z3-parser.y"
                                                                                                                 {
       (yyval.sval)=(yyvsp[0].sval); // done
       }
#line 1592 "z3-parser.tab.c"
    break;

  case 19:
#line 311 "z3-parser.y"
                      {(yyval.sval) = "Bool";}
#line 1598 "z3-parser.tab.c"
    break;

  case 20:
#line 311 "z3-parser.y"
                                                       {(yyval.sval) = "Int";}
#line 1604 "z3-parser.tab.c"
    break;

  case 21:
#line 312 "z3-parser.y"
    { 
    if(temp_s != 0)
      add_string(&string_database, temp_s);
    temp_s = (char*)malloc(STRING_SIZE);
    strcpy(temp_s, "Array(");
    strcat(temp_s, (yyvsp[-2].sval));
    strcat(temp_s, ", ");
    strcat(temp_s, (yyvsp[-1].sval));
    strcat(temp_s, ")");
    (yyval.sval) = temp_s;
    }
#line 1620 "z3-parser.tab.c"
    break;

  case 22:
#line 325 "z3-parser.y"
       {
         if(temp_ss != 0)
           add_string_string(&string_string_database, temp_ss);
         temp_ss = (struct string_string *)malloc(sizeof(struct string_string *));
         temp_ss->address_first = (yyvsp[-2].sval);
         temp_ss->address_second = (yyvsp[-1].sval);
         (yyval.ssval) = temp_ss;
         }
#line 1633 "z3-parser.tab.c"
    break;

  case 23:
#line 335 "z3-parser.y"
       {
         if(temp_ss != 0)
           add_string_string(&string_string_database, temp_ss);
         temp_ss = (struct string_string *)malloc(sizeof(struct string_string *));
         temp_ss->address_first = (yyvsp[-2].sval);
         temp_ss->address_second = (yyvsp[-1].sval);
         (yyval.ssval) = temp_ss;
         }
#line 1646 "z3-parser.tab.c"
    break;

  case 24:
#line 344 "z3-parser.y"
                      {
            struct list_string_string * new = (struct list_string_string *)malloc(sizeof(struct list_string_string *));
            add_string_string(&new, (yyvsp[0].ssval));
            /*add_list_string_string(&sslists, new);*/
            (yyval.sslist) = new;
            }
#line 1657 "z3-parser.tab.c"
    break;

  case 25:
#line 349 "z3-parser.y"
                                     {
            struct list_string_string * old = (yyvsp[0].sslist);
            add_string_string(&old, (yyvsp[-1].ssval));
            (yyval.sslist) = old;
            }
#line 1667 "z3-parser.tab.c"
    break;

  case 26:
#line 355 "z3-parser.y"
                    {
         struct list_string_string * new = (struct list_string_string *)malloc(sizeof(struct list_string_string *));
            add_string_string(&new, (yyvsp[0].ssval));
            /*add_list_string_string(&sslists, new);*/
            (yyval.sslist) = new;
         }
#line 1678 "z3-parser.tab.c"
    break;

  case 27:
#line 360 "z3-parser.y"
                                {
            struct list_string_string * old = (yyvsp[0].sslist);
            add_string_string(&old, (yyvsp[-1].ssval));
            (yyval.sslist) = old;
         }
#line 1688 "z3-parser.tab.c"
    break;

  case 28:
#line 366 "z3-parser.y"
                      {
            struct list_string * new = (struct list_string *)malloc(sizeof(struct list_string *)); 
            add_string(&new, (yyvsp[0].sval)); 
            add_list_string(&lists_database, new); 
            (yyval.slist) = new;
            }
#line 1699 "z3-parser.tab.c"
    break;

  case 29:
#line 372 "z3-parser.y"
                                 {
            struct list_string * old = (yyvsp[0].slist); 
            add_string(&old, (yyvsp[-1].sval)); 
            (yyval.slist) = old;
            }
#line 1709 "z3-parser.tab.c"
    break;

  case 30:
#line 378 "z3-parser.y"
                          {printf("$%s$\n", (yyvsp[0].sval));}
#line 1715 "z3-parser.tab.c"
    break;

  case 31:
#line 378 "z3-parser.y"
                                                            {printf("$%s$\n", (yyvsp[0].sval));}
#line 1721 "z3-parser.tab.c"
    break;


#line 1725 "z3-parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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

#line 380 "z3-parser.y"


int main() {
    yyin = stdin;

do {
  yyparse();
    } while(!feof(yyin));

return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}
