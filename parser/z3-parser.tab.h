/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 104 "z3-parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Z3_PARSER_TAB_H_INCLUDED  */
