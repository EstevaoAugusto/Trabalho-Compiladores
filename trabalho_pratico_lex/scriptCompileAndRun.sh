#!/bin/bash

# Verifica se os parâmetros foram passados
if [ $# -ne 2 ]; then
  echo "Uso: $0 <nome_compilacao> <arquivo_txt>"
  exit 1
fi

NOME_COMPILACAO="$1"
ARQUIVO_TEXTO="$2"

# Verifica se o arquivo existe
if [ ! -f "$ARQUIVO_TEXTO" ]; then
  echo "Erro: Arquivo '$ARQUIVO_TEXTO' não encontrado."
  exit 1
fi

cd "$NOME_COMPILACAO"

# echo highlight -S c -O latex -o "$NOME_COMPILACAO.tex" "$NOME_COMPILACAO.l"
# echo pdflatex "$NOME_COMPILACAO.tex"
# highlight -S c -O latex -o "$NOME_COMPILACAO.tex" "$NOME_COMPILACAO.l"
# pdflatex "$NOME_COMPILACAO.tex" > /dev/null
# rm "$NOME_COMPILACAO.tex" 

# Gera o analisador léxico com flex
echo flex "$NOME_COMPILACAO.l"
flex "$NOME_COMPILACAO.l"

# Compila o código gerado
echo gcc lex.yy.c -ll -o "$NOME_COMPILACAO"
gcc lex.yy.c -ll -o "$NOME_COMPILACAO"

# Executa o programa com o arquivo de entrada
echo ./"$NOME_COMPILACAO" ../"$ARQUIVO_TEXTO"
./"$NOME_COMPILACAO" ../"$ARQUIVO_TEXTO"


%flex ${1}
%yacc -d ${2} -r 'all'
%gcc y.tab.c lex.yy.c -o ${3} -lfl -ly
%echo "Run "${3}
%./${3} ${4}
