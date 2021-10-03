%{

#include <stdlib.h>
#include <stdio.h>

int yylex();
int yyerror(char *);

%}
 
%union { int i; char *s;}
 
%token<i> INT 
%token<s> ID TMENOS BOOLEAN AOP LOP CMP PROGRAM EXTERN WHILE BOOL INTEGER IF ELSE THEN VOID RETURN

%left '<' '>' "==" '+' '*' '/' '%' "&&" "||" '!' '-'
%%
program: PROGRAM '{' variables methods '}'  
       | PROGRAM '{' methods '}' 
       | PROGRAM '{' variables '}' 
       | PROGRAM '{' '}' 
;  

variables: variables v_declaration  
         | v_declaration
;

v_declaration: type ides ';' ;

ides: ID ',' ides           
    | ID 
;

methods: methods m_declaration
        | m_declaration
;

m_declaration: method_type '(' typeides ')' m_declaration_final 
           | method_type '(' ')' m_declaration_final 
;

method_type: type ID 
            | VOID ID 
;

m_declaration_final: block
                 | EXTERN ';'
;

typeides: type ID ',' typeides { } 
        | type ID
;

block: '{' variables statements '}' { } 
     | '{' statements '}' 
     | '{' variables '}' 
     | '{' '}' 
;

statements: statement statements { }
          | statement
;

type: INTEGER
    | BOOL 
;

statement: ID '=' expression ';' 
         | method_call ';' 
         | if_stmt
         | WHILE expression block 
         | return_stmt
         | block 
         | ';' 
;

return_stmt: RETURN expression
           | RETURN ';'
;

if_stmt: IF '(' expression ')' THEN block
       | IF '(' expression ')' THEN block ELSE block
;

method_call: ID '(' expressions ')'
           | ID '(' ')' 
;

expressions: expressions ',' expression
     | expression 
;

expression: terminal              
        | terminal operator expression 
        | operator expression 
        | '(' expression ')' 
;


operator: '-'                 
        | '!'
        | CMP
        | LOP
        | AOP
;

terminal: ID                
        | method_call 
        | literal
;

literal: INT 
       | BOOLEAN
;
%%
