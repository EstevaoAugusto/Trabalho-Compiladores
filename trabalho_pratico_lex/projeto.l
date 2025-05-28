%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>

int line_number = 1;
int column_number = 1;
static int start_line;   // Variável estática para linha inicial do comentário
static int start_col;    // Variável estática para coluna inicial do comentário

void processa_avanco_posicao(const char* texto_token, int tamanho_token) {
    for (int i = 0; i < tamanho_token; ++i) {
        if (texto_token[i] == '\n') {
            line_number++; 
            column_number = 1; 
        } else if (texto_token[i] == '\t') {
            column_number += 4; 
        } else {
            column_number++;
        }
    }
}

void printToken(const char* tokenType, const char* lexeme, int line, int col) {
    fprintf(yyout, "%d(%d): %s (%s)\n", line, col, lexeme, tokenType);
}

void printError(const char* errorMessage, const char* lexeme, int line, int col) {
    fprintf(yyout, "Erro léxico na linha %d, coluna %d: %s '%s'\n", line, col, errorMessage, lexeme);
}

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

var_declaracao                  {tipo_especificador}{ident};|{tipo_especificador}{ident}({abre_colchete}{num_int}{fecha_colchete})+;
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


[ \t]+          { 
                    /* Apenas avança a posição, não imprime token para whitespace */
                    processa_avanco_posicao(yytext, yyleng); 
                }

\n              { 
                    /* Apenas atualiza linha e reseta coluna, não imprime token */
                    line_number++; 
                    column_number = 1; 
                }

{comment}       { 
                    int linha_token = line_number;    // Posição inicial do token
                    int coluna_token = column_number; // Posição inicial do token
                    /* Opcional: imprimir um token para comentário. Ex: */
                    /* fprintf(yyout, "%d(%d): lexema '%s' (COMENTARIO)\n", linha_token, coluna_token, yytext); */
                    processa_avanco_posicao(yytext, yyleng); /* Essencial para tratar novas linhas dentro do comentário */
                }

"if"            { int l = line_number; int c = column_number; printToken("IF", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"else"          { int l = line_number; int c = column_number; printToken("ELSE", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"while"         { int l = line_number; int c = column_number; printToken("WHILE", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"return"        { int l = line_number; int c = column_number; printToken("RETURN", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"int"           { int l = line_number; int c = column_number; printToken("INT", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"float"         { int l = line_number; int c = column_number; printToken("FLOAT", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"char"          { int l = line_number; int c = column_number; printToken("CHAR", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"struct"        { int l = line_number; int c = column_number; printToken("STRUCT", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"void"          { int l = line_number; int c = column_number; printToken("VOID", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }

"=="            { int l = line_number; int c = column_number; printToken("EQUAL_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"!="            { int l = line_number; int c = column_number; printToken("NOT_EQUAL_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"<="            { int l = line_number; int c = column_number; printToken("LESS_EQUAL_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
">="            { int l = line_number; int c = column_number; printToken("RIGHT_EQUAL_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"<"             { int l = line_number; int c = column_number; printToken("LEFT_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
">"             { int l = line_number; int c = column_number; printToken("RIGHT_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }

"="             { int l = line_number; int c = column_number; printToken("ASSIGN_OP", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }

{abre_chave}        { int l = line_number; int c = column_number; printToken("LEFT_BRACE", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{fecha_chave}       { int l = line_number; int c = column_number; printToken("RIGHT_BRACE", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{abre_colchete}     { int l = line_number; int c = column_number; printToken("LEFT_BRACKET", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{fecha_colchete}    { int l = line_number; int c = column_number; printToken("RIGHT_BRACKET", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{abre_parenteses}   { int l = line_number; int c = column_number; printToken("LEFT_PAREN", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{fecha_parenteses}  { int l = line_number; int c = column_number; printToken("RIGHT_PAREN", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
";"                 { int l = line_number; int c = column_number; printToken("SEMICOLON", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
","                 { int l = line_number; int c = column_number; printToken("COMMA", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }

{char_literal}      { int l = line_number; int c = column_number; printToken("CONSTCHAR", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
{string_literal}    { int l = line_number; int c = column_number; printToken("CONSTSTRING", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }

"+"                 { int l = line_number; int c = column_number; printToken("PLUS", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"-"                 { int l = line_number; int c = column_number; printToken("MINUS", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"/"                 { int l = line_number; int c = column_number; printToken("DIVISION", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }
"*"                 { int l = line_number; int c = column_number; printToken("MULTIPLY", yytext, l, c); processa_avanco_posicao(yytext, yyleng); }


{num_int}       { 
                    int linha_token = line_number; int coluna_token = column_number;
                    fprintf(yyout,"%d(%d): %s (CONSTINT)\n",linha_token,coluna_token,yytext); 
                    processa_avanco_posicao(yytext, yyleng);
                }
{num}           { /* Alterado de {num_real} para {num} para corresponder à sua definição */
                    int linha_token = line_number; int coluna_token = column_number;
                    fprintf(yyout,"%d(%d): %s (CONSTFLOAT)\n",linha_token,coluna_token,yytext); 
                    processa_avanco_posicao(yytext, yyleng);
                }
{ident}         { 
                    int linha_token = line_number; int coluna_token = column_number;
                    fprintf(yyout,"%d(%d): %s (IDENTIFIER)\n",linha_token,coluna_token,yytext); 
                    processa_avanco_posicao(yytext, yyleng);
                }

.               { 
                    int linha_token = line_number;
                    int coluna_token = column_number;
                    printError("símbolo inválido", yytext, line_number, column_number);
                    processa_avanco_posicao(yytext, yyleng); 
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
