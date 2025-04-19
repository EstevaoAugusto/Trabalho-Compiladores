%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>

int line_number = 1;
int column_number = 1;
%}

digit					[0-9]
number                  {digit}+(\.{digit}+)?
delim                   [ \t\n]
ws                      {delim}+
comment                 #.*
other                   .

%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{number}                { fprintf(yyout,"%d(%d): %s (NUMBER)\n",line_number,column_number,yytext); column_number+=yyleng; }
{comment}               {}
\n                      {line_number++; column_number = 1; }
{ws}                    {}
"+"                     { fprintf(yyout,"%d(%d): + (PLUS)\n",line_number,column_number); column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): - (MINUS)\n",line_number,column_number); column_number+=yyleng; }
{other}                 { fprintf(yyout, "Lexical error on line %d and column %d. Input -> \"%s\"\n",line_number, column_number, yytext); column_number+=yyleng; }


%%
/*------------------------ User subrotines ------------------------*/
int main(int argc, char *argv[]){
    if (argc != 2){
        printf("It does not work like that.\n");
        printf("Usage: ./compiler <filename>");
        return -1;
    }
    yyin = fopen(argv[1], "r");
    yyout=stdout;
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap(){
    return 0;
}