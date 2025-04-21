%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>

int line_number = 1;
int column_number = 1;
%}

/*-------------------------- Definições --------------------------*/

letra                           [a-z]
digito                          [0-9]
ident                           {letra}({letra}|{digito})*
num_int                         {digito}+
num                             [+-]?[0-9]+(\.[0-9]+)?([E][+-]?[0-9]+)?
abre_chave                      \{
fecha_chave                     \}
abre_colchete                   \[
fecha_colchete                  \]
abre_parenteses                 \(
fecha_parenteses                \)


delim                           [ \t\n]
ws                              {delim}+
comment                         "/*"([^*]|\*+[^/])*\*+"/"
char_literal                    \'([^\\\n]|\\.)\'
string_literal                  \"([^\\\"\n]|\\.)*\"
other                           .

soma                            \+|\-
multi                           \/|\*

var                             {ident}|{ident}({abre_colchete}{expressao}{fecha_colchete})+
fator                           \({expressao}\)|{var}|{ativacao}|{num}|{num_int}
termo                           {fator}({multi}{fator})*
expressao_soma                  {termo}({soma}{termo})*
expressao_simples               {expressao_soma}{relacional}{expressao_soma}|{expressao_soma}
expressao                       ({var}={expressao}|{expressao_simples})

arg_lista                       {expressao}(,{expressao})*
args                            {arg_lista}?
ativacao                        {ident}\({args}\)

expressao_decl                  {expressao};|;
selecao_decl                    (if\({expressao}\){comando}|if\({expressao}\){comando}else{comando})
iteracao_decl                   while\({expressao}\){comando}
retorno_decl                    return;|return{expressao};

comando                         {expressao_decl}|{composto_decl}|{selecao_decl}|{iteracao_decl}|{retorno_decl}
comando_lista                   {comando}*
local_declaracoes               {var_declaracao}*
composto_decl                   {abre_chave}{local_declaracoes}{comando_lista}{fecha_chave}

param                           ({tipo_especificador}{ident}|{tipo_especificador}{ident}{abre_colchete}{fecha_colchete})
params_lista                    {param}(,{param})*
params                          {params_lista}|void

var_declaracao                  {tipo_especificador}{ident};|{tipo_especificador}{ident}({abre_colchete}{num_int}{fecha_colchete})+
atributos_declaracao            {var_declaracao}+
tipo_especificador              (int|float|char|void|struct{ident}{abre_chave}{atributos_declaracao}{fecha_chave})
func_declaracao                 {tipo_especificador}{ident}\({params}\){composto_decl}
declaracao                      {var_declaracao}|{func_declaracao}
declaracao_lista                {declaracao}+
programa                        {declaracao_lista}


%%

%{

/*----------------------------- Regras -----------------------------*/
%}

{comment}                       { column_number+=yyleng; }
"if"                            { fprintf(yyout, "%d(%d): %s (KW: IF)\n", line_number, column_number, yytext); column_number += yyleng; }
"else"                          { fprintf(yyout, "%d(%d): %s (KW: ELSE)\n", line_number, column_number, yytext); column_number += yyleng; }
"while"                         { fprintf(yyout, "%d(%d): %s (KW: WHILE)\n", line_number, column_number, yytext); column_number += yyleng; }
"return"                        { fprintf(yyout, "%d(%d): %s (KW: RETURN)\n", line_number, column_number, yytext); column_number += yyleng; }
"int"                           { fprintf(yyout, "%d(%d): %s (Tipo: INT)\n", line_number, column_number, yytext); column_number += yyleng; }
"float"                         { fprintf(yyout, "%d(%d): %s (Tipo: FLOAT)\n", line_number, column_number, yytext); column_number += yyleng; }
"char"                          { fprintf(yyout, "%d(%d): %s (Tipo: CHAR)\n", line_number, column_number, yytext); column_number += yyleng; }
"struct"                        { fprintf(yyout, "%d(%d): %s (KW: STRUCT)\n", line_number, column_number, yytext); column_number += yyleng; }
"void"                          { fprintf(yyout, "%d(%d): %s (Tipo: VOID)\n", line_number, column_number, yytext); column_number += yyleng; }
"=="                            { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
"!="                            { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
"<="                            { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
">="                            { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
"<"                             { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
">"                             { fprintf(yyout, "%d(%d): %s (RELOP) \n", line_number, column_number, yytext); column_number += yyleng; }
"="                             { fprintf(yyout, "%d(%d): %s (Atribuicao) \n", line_number, column_number, yytext); column_number += yyleng; }
{abre_chave}                    { fprintf(yyout,"%d(%d): %s (Abre Chave) \n",line_number,column_number,yytext); column_number+=yyleng; }
{fecha_chave}                   { fprintf(yyout,"%d(%d): %s (Fecha Chave) \n",line_number,column_number,yytext); column_number+=yyleng; }
{abre_colchete}                 { fprintf(yyout,"%d(%d): %s (Abre Colchetes) \n",line_number,column_number,yytext); column_number+=yyleng; }
{fecha_colchete}                { fprintf(yyout,"%d(%d): %s (Fecha Colchetes) \n",line_number,column_number,yytext); column_number+=yyleng; }
{abre_parenteses}               { fprintf(yyout,"%d(%d): %s (Abre Parenteses) \n",line_number,column_number,yytext); column_number+=yyleng; }
{fecha_parenteses}              { fprintf(yyout,"%d(%d): %s (Fecha Parenteses) \n",line_number,column_number,yytext); column_number+=yyleng; }

{char_literal}                  { fprintf(yyout, "%d(%d): %s (Char Literal)\n", line_number, column_number, yytext); column_number += yyleng; }
{string_literal}                { fprintf(yyout, "%d(%d): %s (String)\n", line_number, column_number, yytext); column_number += yyleng;}

{soma}                          { fprintf(yyout,"%d(%d): %s (SOMA) \n",line_number,column_number,yytext); column_number+=yyleng; }
{multi}                         { fprintf(yyout,"%d(%d): %s (MULTI) \n",line_number,column_number,yytext); column_number+=yyleng; }
";"                             { fprintf(yyout, "%d(%d): %s (Ponto e Vírgula)\n", line_number, column_number, yytext); column_number += yyleng; }
","                             { fprintf(yyout, "%d(%d): %s (Vírgula)\n", line_number, column_number, yytext); column_number += yyleng; }


{num_int}                       { fprintf(yyout,"%d(%d): %s (Numero_Int) \n",line_number,column_number,yytext); column_number+=yyleng; }
{num}                           { fprintf(yyout,"%d(%d): %s (Numero) \n",line_number,column_number,yytext); column_number+=yyleng; }
{ident}                         { fprintf(yyout,"%d(%d): %s (ID) \n",line_number,column_number,yytext); column_number+=yyleng; }
\n                              { line_number++; column_number = 1; }
{ws}                            {}
{other}                         {   
                                    fprintf(yyout, "Erro léxico na linha %d, coluna %d: símbolo inválido '%s'\n", line_number, column_number, yytext);
                                    column_number += yyleng;
                                }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Enter string input: ");
    yylex();
    
    return 0;
}
