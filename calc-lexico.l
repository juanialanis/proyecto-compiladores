%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "calc-sintaxis.tab.h"
int yyparse();

%}

%option noyywrap
%option yylineno

letter [a-zA-Z]
digit [0-9]

%%

{digit}+                          { yylval.i = atoi(yytext);
                                printf("INT : %d\n",atoi(yytext)); 
                                return INT;}   

"+"                     { printf("OPERATOR: %s\n",yytext);
                                return TPLUS; }

"/"                     { printf("OPERATOR: %s\n",yytext);
                                return TDIV; }

"-"                     { printf("OPERATOR: %s\n",yytext);
                                return TMINUS; }

"*"                     { printf("OPERATOR: %s\n",yytext);
                                return TMULT; }

"!"                     { printf("OPERATOR: %s\n",yytext);
                                return TNOT; }

"%"                     { printf("OPERATOR: %s\n",yytext);
                                return TMOD; }

"||"                     { printf("OPERATOR: %s\n",yytext);
                                return TOR; }

"&&"                     { printf("OPERATOR: %s\n",yytext);
                                return TAND; }

"Program"                       { printf("PROGRAM: %s\n",yytext);
                                return PROGRAM; }

"integer"                       { printf("INTEGER: %s\n",yytext);
                                return INTEGER; }

"bool"                          { printf("BOOL: %s\n",yytext);
                                return BOOL; }

"extern"                        { printf("EXTERN: %s\n",yytext);
                                return EXTERN; }

"while"                        { printf("WHILE: %s\n",yytext);
                                return WHILE; }

"return"                       { printf("RETURN: %s\n",yytext);
                                return RETURN; }

"if"                          { printf("IF: %s\n",yytext);
                                return IF; }

"then"                        { printf("THEN: %s\n",yytext);
                                return THEN; }

"else"                        { printf("ELSE: %s\n",yytext);
                                return ELSE; }

"void"                        { printf("VOID: %s\n",yytext);
                                return VOID; }

"true"                { printf("BOOLEAN: %s\n",yytext);
                               return BTRUE; }

"false"                { printf("BOOLEAN: %s\n",yytext);
                               return BFALSE; }

{letter}({letter}|{digit}|"_")* { yylval.s=(char *) malloc(sizeof(yytext)*yyleng);
                                strcpy(yylval.s,yytext);
                                printf("ID : %s\n",yytext);
                                return ID;}

[;()={},]                   { printf("SYMBOL: %s\n",yytext);
                                return *yytext;}

">"                  { printf("COMPARATION SYMBOL: %s\n",yytext);
                                return HIGHER; }
                                
"<"                  { printf("COMPARATION SYMBOL: %s\n",yytext);
                                return LOWER; }

"=="                  { printf("COMPARATION SYMBOL: %s\n",yytext);
                                return EQUAL; }

"//".*                                    { /* ONE LINE COMMENT, DO NOTHING */ }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* MULTI LINE COMMENT, DO NOTHING */ }


.|"//"|\n                          ; /* ignore all the rest */

%%

void yyerror(){
	printf("%s%d\n","-> SINTAX ERROR at line: ",yylineno);
}

int main(int argc,char *argv[]){
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;

	yyparse();

}
