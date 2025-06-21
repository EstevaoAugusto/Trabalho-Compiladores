bison -d parser.y
flex projeto.l
gcc -o Compiler.o lex.yy.c parser.tab.c #Linux: "-lfl" ao invés de "-ly -ll" 
./Compiler.o teste.txt
#./Compiler TP_tipo1_teste_etapa2.cm