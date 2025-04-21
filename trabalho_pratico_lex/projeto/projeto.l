%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>

int line_number = 1;
int column_number = 1;
%}

/*-------------------------- Definições --------------------------*/

programa                        {declaracao_lista}
declaracao_lista                {declaracao}+
declaracao                      {var_declaracao}|{func_declaracao}
var_declaracao                  {tipo_especificador}{ident};|{tipo_especificador}{ident}({abre_colchete}{num_int}{fecha_colchete})+
tipo_especificador              (int|float|char|void|struct{ident}{abre_chave}{atributos_declaracao}{fecha_chave})
atributos_declaracao            {var_declaracao}+
func_declaracao                 {tipo_especificador}{ident}\({params}\){composto_decl}
params                          {params_lista}|void
params_lista                    {param}([,]{param})*
param                           ({tipo_especificador}{ident}|{tipo_especificador}{ident}{abre_colchete}{fecha_colchete})
composto_decl                   {abre_chave}{local_declaracoes}{comando_lista}{fecha_chave}
local_declaracoes               {var_declaracao}*
comando_lista                   {comando}*
comando                         {expressao_decl}|{composto_decl}|{selecao_decl}|{iteracao_decl}|{retorno_decl}
expressao_decl                  {expressao};|;
selecao_decl                    (if\({expressao}\){comando}|if\({expressao}\){comando}else{comando})
iteracao_decl                   while\({expressao}\){comando}
retorno_decl                    return;|return{expressao};
expressao                       ({var}={expressao}|{expressao_simples})
var                             {ident}|{ident}({abre_colchete}{expressao}{fecha_colchete})+
expressao_simples               {expressao_soma}{relacional}{expressao_soma}|{expressao_soma}
relacional                      <=|<|>=|>|==|!=
expressao_soma                  {termo}({soma}{termo})*
soma                            +|-
termo                           {fator}({multi}{fator})*
multi                           /|*
fator                           \({expressao}\)|{var}|{ativacao}|{num}|{num_int}
ativacao                        {ident}\({args}\)
args                            {arg_lista}?
arg_lista                       {expressao}(,{expressao})*
num                             [+-]?[0-9]+(\.[0-9]+)?([E][+-]?[0-9]+)?
num_int                         {digito}+
digito                          [0-9]
ident                           {letra}({letra}|{digito})*
letra                           [a-z]
abre_chave                      {
fecha_chave                     }
abre_colchete                   [
fecha_colchete                  ]
other                           .
delim                           [ \t\n]
ws                              {delim}+
comment                         "/*"([^*]|\*+[^/])*\*+"/"


%%

%{

/*----------------------------- Regras -----------------------------*/
%}

\n                              {line_number++; column_number = 1; }
{ws}                            {}
{other}                         { fprintf(yyout, "'%s' não foi identificado\n", yytext);}

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Enter string input: ");
    yylex();
    
    return 0;
}
