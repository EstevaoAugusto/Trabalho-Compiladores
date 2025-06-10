bison -d parser.y
flex projeto.l
gcc -o Compiler lex.yy.c parser.tab.c #Linux: "-lfl" ao invés de "-ly -ll" 
.\Compiler.exe <nome_arq>