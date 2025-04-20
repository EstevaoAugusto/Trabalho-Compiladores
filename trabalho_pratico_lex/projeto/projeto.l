%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>

int line_number = 1;
int column_number = 1;
%}

/*-------------------------- Tokens --------------------------*/
digit           [0-9]
float_number    {digit}+(\.{digit}+)?([eE][+-]?{digit}+)?
comment         (\/\/[^\n]*|\/\*([^*]|\*+[^*/])*\*+\/)
delimiter       [\{\}\[\]\(\)\.;,]

%%

%{

/*----------------------------- Regras -----------------------------*/
%}

"if"            { printf("TOKEN: KEYWORD        -> %s\n", yytext); }
"else"          { printf("TOKEN: KEYWORD        -> %s\n", yytext); }
"while"         { printf("TOKEN: KEYWORD        -> %s\n", yytext); }
"return"        { printf("TOKEN: KEYWORD        -> %s\n", yytext); }
"do"            { printf("TOKEN: KEYWORD        -> %s\n", yytext); }

"int"           { printf("TOKEN: TIPO           -> %s\n", yytext); }
"float"         { printf("TOKEN: TIPO           -> %s\n", yytext); }
"char"          { printf("TOKEN: TIPO           -> %s\n", yytext); }
"bool"          { printf("TOKEN: TIPO           -> %s\n", yytext); }
"double"        { printf("TOKEN: TIPO           -> %s\n", yytext); }

{delimiter}     { printf("TOKEN: DELIMITER      -> %s\n", yytext); }
{float_number}  { printf("TOKEN: NUMBER         -> %s\n", yytext); }
{digit}+        { printf("TOKEN: NUMBER         -> %s\n", yytext); }

[a-zA-Z][a-zA-Z0-9_]*      { printf("TOKEN: IDENTIFIER     -> %s\n", yytext);}

\"([^\\\"]|\\.)*\"          {printf("TOKEN: STRING         -> %s\n", yytext);}

{comment}       ;   // Ignora comentários

[ \t\r]+        ;   // Ignora espaços e tabs

\n              { line_number++; column_number = 1; }

.               { printf("TOKEN: SIMBOLO        -> %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Enter string input: ");
    yylex();
    
    return 0;
}
