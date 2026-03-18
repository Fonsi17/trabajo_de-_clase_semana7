%{
#include <stdio.h>
#include "symbols.h"
#include <string.h>
#include "parser_helper.h"
int yylex();
void yyerror(const char *s);
extern FILE *yyin;

%}

/*Define the yylval structure*/
%union {
    int i_val;
    int n_val;
    int b_val;
    double d_val;
    char c_val;
    char* s_val;
    int type_enum;
    struct SymbolEntry *entry;
}

%token VAR PRINT
%token INT_TYPE CHAR_TYPE DOUBLE_TYPE BOOL_TYPE STRING_TYPE
%token  COLON SEMICOLON LBRACKET RBRACKET ASSIGN LPARENT RPARENT
%token PLUS SUB
/*Type definitions for TOKEN*/
%token <entry> IDENTIFIER
%token <i_val> INT_LITERAL
%token <n_val> NUMBER
%token <d_val> DOUBLE_LITERAL
%token <c_val> CHAR_LITERAL
%token <b_val> BOOL_LITERAL
%token <s_val> STRING_LITERAL
%token MULT DIV

%left MULT DIV
%left PLUS SUB

/*Defining types into the parser*/
%type <type_enum> data_type
%type <n_val> expression

%%
program:
        program statement
        | /**/
        ;
statement:  variable_definition SEMICOLON
         | print_expression SEMICOLON
         ;

data_type:
       INT_TYPE  { $$=TYPE_INT; }
       | DOUBLE_TYPE { $$=TYPE_DOUBLE; }
       | CHAR_TYPE { $$=TYPE_CHAR; }
       | STRING_TYPE { $$=TYPE_STRING; }
       | BOOL_TYPE { $$=TYPE_BOOL; }
       ;

expression:
    NUMBER          { $$ = $1; }
    | INT_LITERAL   { $$ = (int) $1; }
    | DOUBLE_LITERAL { $$ = (double) $1; }
    | CHAR_LITERAL  { $$ = (char) $1; }
    | IDENTIFIER {
      switch($1->data_type){
        /* CAMBIADO A .data POR TU SYMBOLS.H */
        case TYPE_INT:    $$ = $1->data.i_value; break;
        case TYPE_DOUBLE: $$ = $1->data.d_value; break;
        case TYPE_BOOL:   printf("TYPE ERROR: No se puede operar con booleano\n"); $$=0; break;
        default: $$ = 0;
      }
    }
    | expression PLUS expression { $$ = $1 + $3; }
    | expression SUB expression  { $$ = $1 - $3; }
    | expression MULT expression { $$ = $1 * $3; }
    | expression DIV expression  { 
        if ($3 == 0) {
            yyerror("Error: División por cero");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
    | LPARENT expression RPARENT { $$ = $2; }
    ;

print_expression: 
    PRINT IDENTIFIER {
        switch($2->data_type) {
            /* CAMBIADO A .data POR TU SYMBOLS.H */
            case TYPE_INT:    printf("%d\n", $2->data.i_value); break;
            case TYPE_BOOL:   printf("%s\n", $2->data.i_value ? "true" : "false"); break;
            case TYPE_DOUBLE: printf("%f\n", $2->data.d_value); break;
            case TYPE_CHAR:   printf("'%c'\n", $2->data.i_value); break;
            case TYPE_STRING: printf("%s\n", $2->data.s_value); break;
        }
    }
    | PRINT STRING_LITERAL {
        printf("%s\n", $2);
        free($2); /* Liberación de memoria para strings literales */
    }
    ;

variable_definition: VAR COLON LBRACKET data_type RBRACKET IDENTIFIER ASSIGN expression {
    $6->data_type =(DataType) $4;
    assing_numeric_value($6 , $4, $8);
}
| VAR COLON LBRACKET data_type RBRACKET IDENTIFIER ASSIGN STRING_LITERAL {
    $6->data_type = (DataType)$4;
    assing_string_value($6,$4,$8);
}
;

print_expression: PRINT IDENTIFIER {
  switch($2->data_type) {
    case TYPE_INT:     printf("%d\n", $2->data.i_value); break;
    case TYPE_BOOL: printf("%s\n", $2->data.b_value ? "true" : "false"); break;
    case TYPE_DOUBLE:  printf("%f\n", $2->data.d_value); break;
    case TYPE_CHAR:    printf("'%c'\n", $2->data.c_value); break;
    case TYPE_STRING:    printf("'%s'\n", $2->data.s_value); break;
  }

}
;

%%

/* Error handler */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/*Main  Function*/
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            return 1;
        }
        extern FILE *yyin;
        yyin = file;
    }

    int result = yyparse();

    if (result == 0) {
        printf("Parse Successful!\n");
    }

    return result;
}
