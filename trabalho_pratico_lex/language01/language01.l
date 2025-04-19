%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
%}

digit					[0-9]
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{digit}                 { fprintf(yyout,"%d (DIGIT)\n",atoi(yytext)); }
{other}                 { fprintf(yyout, "Lexical error. Input -> \"%s\"\n", yytext); }


%%
/*------------------------ User subrotines ------------------------*/
int main(int argc, char *argv[]){
    yyin = fopen("test02.txt", "r");
    yyout=stdout;
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap(){
    return 0;
}