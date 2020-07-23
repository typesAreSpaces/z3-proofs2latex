%{

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

%}

%union {
    int                         ival;
    char                      * sval;
    struct string_string      * ssval;
    struct list_string        * slist;
    struct list_string_string * sslist;
}

%token<ival> T_INT
%token<sval> T_NAME T_PROOF_RULE END REL_SYM OP_SYM MINUS_SYM
%token PAREN_LEFT PAREN_RIGHT COMMA 
%token UNSAT_TOKEN EXCLAMATION_MARK_TOKEN
%token FORALL_TOKEN EXISTS_TOKEN 
%token INTERPOLANTS_TOKEN PATTERN_TOKEN
%token AND_TOKEN OR_TOKEN NOT_TOKEN
%token EQUAL_TOKEN LET_TOKEN
%token SELECT_TOKEN STORE_TOKEN ARRAY_EXT_TOKEN UNDERSCORE_TOKEN ZERO_TOKEN PERCENT_TOKEN
%token BOOL_TYPE_TOKEN INT_TYPE_TOKEN ARRAY_TYPE_TOKEN
%left REL_SYM OP_SYM MINUS_SYM
%type<sval> formula type
%type<slist> list_formula
%type<ssval> one_type binding;
%type<sslist> list_type list_binding

%start parse

%%

parse:
     { 
       printf("\\documentclass{article}\n\\begin{document}\n"); 
     }
     UNSAT_TOKEN 
     interpolants 
     {
       free_strings(string_database); 
       free_strings_strings(string_string_database); 
       free_list_strings(lists_database); 
       printf("\n\\end{document}\n\n"); 
     } ;

interpolants: PAREN_LEFT INTERPOLANTS_TOKEN list_interpolant PAREN_RIGHT;

formula:
       PAREN_LEFT EXCLAMATION_MARK_TOKEN formula PATTERN_TOKEN PAREN_RIGHT                                       {
       $$=$3; // done
       }|
       PAREN_LEFT LET_TOKEN PAREN_LEFT list_binding PAREN_RIGHT formula PAREN_RIGHT                              {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       /*strcpy(temp_s, "(let \\\\");*/
       strcpy(temp_s, "let \\\\");
       unsigned count = 0;
       struct list_string_string * aux = $4;
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
       strcat(temp_s, $6);
       /*strcat(temp_s, ")");*/
       $$ = temp_s;
       }| // let // done
       PAREN_LEFT FORALL_TOKEN PAREN_LEFT list_type PAREN_RIGHT formula PAREN_RIGHT                              {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\forall ");
       unsigned count = 0;
       struct list_string_string * aux = $4;
       fold_quantifier($4, &temp_s, $6);
       $$ = temp_s;
       }| // forall // done
       PAREN_LEFT EXISTS_TOKEN PAREN_LEFT list_type PAREN_RIGHT formula PAREN_RIGHT                              {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\exists ");
       unsigned count = 0;
       fold_quantifier($4, &temp_s, $6);
       $$ = temp_s;
       }| // exists // done
       PAREN_LEFT AND_TOKEN list_formula PAREN_RIGHT                                                             {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "("); 
       fold($3, &temp_s, " \\land ");
       strcat(temp_s, ")");
       $$=temp_s;
       }| // and // done
       PAREN_LEFT OR_TOKEN list_formula PAREN_RIGHT                                                              {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(");
       fold($3, &temp_s, " \\lor ");
       strcat(temp_s, ")");
       $$=temp_s;
       }| // or // done
       PAREN_LEFT NOT_TOKEN formula PAREN_RIGHT                                                                  {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(\\neg ");
       strcat(temp_s, $3);
       strcat(temp_s, ")");
       $$=temp_s;
       }| // not // done
       PAREN_LEFT EQUAL_TOKEN list_formula PAREN_RIGHT                                                           {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "("); 
       fold($3, &temp_s, " = ");
       strcat(temp_s, ")");
       $$=temp_s;
       }| // equality // done
       PAREN_LEFT SELECT_TOKEN formula formula PAREN_RIGHT                                                       {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcat(temp_s, "select( "); 
       strcat(temp_s, $3);
       strcat(temp_s, ", "); 
       strcat(temp_s, $4);
       strcat(temp_s, ")"); 
       $$=temp_s;
       }| // select function // done
       PAREN_LEFT STORE_TOKEN formula formula formula PAREN_RIGHT                                                {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "store("); 
       strcat(temp_s, $3);
       strcat(temp_s, ", "); 
       strcat(temp_s, $4);
       strcat(temp_s, ", "); 
       strcat(temp_s, $5);
       strcat(temp_s, ")"); 
       $$=temp_s;
       }| // store function // done
       PAREN_LEFT PAREN_LEFT UNDERSCORE_TOKEN ARRAY_EXT_TOKEN ZERO_TOKEN PAREN_RIGHT formula formula PAREN_RIGHT {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "array-ext("); 
       strcat(temp_s, $7);
       strcat(temp_s, ", "); 
       strcat(temp_s, $8);
       strcat(temp_s, ")"); 
       $$ = temp_s;
       }| // array-ext axiom // partially-wrong
       PAREN_LEFT T_NAME list_formula PAREN_RIGHT                                                                {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, $2); 
       strcat(temp_s, "("); 
       fold($3, &temp_s, ", ");
       strcat(temp_s, ")");
       $$=temp_s;
       }| // function application //done
       PAREN_LEFT T_NAME PAREN_RIGHT                                                                             {
       if(temp_s != 0)
         add_string(&string_database, temp_s);
       temp_s = (char*)malloc(STRING_SIZE);
       strcpy(temp_s, "(");
       strcat(temp_s, $2);
       strcpy(temp_s, ")");
       $$=temp_s; // done
       }|
       T_NAME                                                                                                    {
       $$=$1; // done
       };

type: BOOL_TYPE_TOKEN {$$ = "Bool";} | INT_TYPE_TOKEN  {$$ = "Int";} | PAREN_LEFT ARRAY_TYPE_TOKEN type type PAREN_RIGHT 
    { 
    if(temp_s != 0)
      add_string(&string_database, temp_s);
    temp_s = (char*)malloc(STRING_SIZE);
    strcpy(temp_s, "Array(");
    strcat(temp_s, $3);
    strcat(temp_s, ", ");
    strcat(temp_s, $4);
    strcat(temp_s, ")");
    $$ = temp_s;
    };

binding: PAREN_LEFT T_NAME formula PAREN_RIGHT  
       {
         if(temp_ss != 0)
           add_string_string(&string_string_database, temp_ss);
         temp_ss = (struct string_string *)malloc(sizeof(struct string_string *));
         temp_ss->address_first = $2;
         temp_ss->address_second = $3;
         $$ = temp_ss;
         };

one_type: PAREN_LEFT T_NAME type PAREN_RIGHT
       {
         if(temp_ss != 0)
           add_string_string(&string_string_database, temp_ss);
         temp_ss = (struct string_string *)malloc(sizeof(struct string_string *));
         temp_ss->address_first = $2;
         temp_ss->address_second = $3;
         $$ = temp_ss;
         };

list_binding: binding {
            struct list_string_string * new = (struct list_string_string *)malloc(sizeof(struct list_string_string *));
            add_string_string(&new, $1);
            /*add_list_string_string(&sslists, new);*/
            $$ = new;
            } | binding list_binding {
            struct list_string_string * old = $2;
            add_string_string(&old, $1);
            $$ = old;
            };

list_type: one_type {
         struct list_string_string * new = (struct list_string_string *)malloc(sizeof(struct list_string_string *));
            add_string_string(&new, $1);
            /*add_list_string_string(&sslists, new);*/
            $$ = new;
         } | one_type list_type {
            struct list_string_string * old = $2;
            add_string_string(&old, $1);
            $$ = old;
         };

list_formula: formula {
            struct list_string * new = (struct list_string *)malloc(sizeof(struct list_string *)); 
            add_string(&new, $1); 
            add_list_string(&lists_database, new); 
            $$ = new;
            } | 
            formula list_formula {
            struct list_string * old = $2; 
            add_string(&old, $1); 
            $$ = old;
            };

list_interpolant: formula {printf("$%s$\n", $1);} | formula {printf("$%s$\n", $1);} list_interpolant;

%%

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
