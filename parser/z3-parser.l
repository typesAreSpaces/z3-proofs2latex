%option noyywrap

%{
#include <stdio.h>

#define YY_DECL int yylex()

#include "z3-parser.tab.h"

%}

%%

 /*array_decl_plugin::array_decl_plugin():*/
  /*1     m_store_sym("store"),*/
  /*2     m_select_sym("select"),*/
  /*3     m_const_sym("const"),*/
  /*4     m_default_sym("default"),*/
  /*5     m_map_sym("map"),*/
  /*6     m_set_union_sym("union"),*/
  /*7     m_set_intersect_sym("intersection"),*/
  /*8     m_set_difference_sym("setminus"),*/
  /*9     m_set_complement_sym("complement"),*/
 /*10     m_set_subset_sym("subset"),*/
 /*11     m_array_ext_sym("array-ext"),*/
 /*12     m_as_array_sym("as-array"),*/
 /*13     m_set_has_size_sym("set-has-size"),*/
 /*14     m_set_card_sym("card") {*/

[ \t]	; // ignore all whitespace
"unsat"        {return UNSAT_TOKEN;}
"interpolants" {return INTERPOLANTS_TOKEN;}
"!"            {return EXCLAMATION_MARK_TOKEN;}
":qid itp"     {return PATTERN_TOKEN;}
"let"          {return LET_TOKEN;}
"forall"       {return FORALL_TOKEN;}
"exists"       {return EXISTS_TOKEN;}
"and"          {return AND_TOKEN;}
"or"           {return OR_TOKEN;}
"not"          {return NOT_TOKEN;}
"="            {return EQUAL_TOKEN;}
"select"       {return SELECT_TOKEN;}
"store"        {return STORE_TOKEN;}
"array-ext"    {return ARRAY_EXT_TOKEN;}
"_"            {return UNDERSCORE_TOKEN;}
"0"            {return ZERO_TOKEN;}
"%"            {return PERCENT_TOKEN;}

"Bool"  {return BOOL_TYPE_TOKEN;}
"Int"   {return INT_TYPE_TOKEN;}
"Array" {return ARRAY_TYPE_TOKEN;}

"(" {return PAREN_LEFT;}
")" {return PAREN_RIGHT;}
"," {return COMMA;}

"<"     {yylval.sval = strdup(yytext); return REL_SYM;}
">"     {yylval.sval = strdup(yytext); return REL_SYM;}
"<="    {yylval.sval = strdup(yytext); return REL_SYM;}
">="    {yylval.sval = strdup(yytext); return REL_SYM;}
"=="    {yylval.sval = strdup(yytext); return REL_SYM;}
"!="    {yylval.sval = strdup(yytext); return REL_SYM;}
"+"     {yylval.sval = strdup(yytext); return OP_SYM;}
"*"     {yylval.sval = strdup(yytext); return OP_SYM;}
"/"     {yylval.sval = strdup(yytext); return OP_SYM;}
"-"     {yylval.sval = strdup(yytext); return MINUS_SYM;}

[a-zA-Z0-9_!%{}]+ {yylval.sval = strdup(yytext); return T_NAME;}

%%
