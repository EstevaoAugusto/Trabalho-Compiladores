# Trabalho-Compiladores

Trabalho da Disciplina "Compiladores" do curso de Ciência de Computação da **Universidade Federal de Lavras (UFLA)**. O objetivo desse trabalho é criar um analisador léxico e sintático utilizando **Flex** e **Bison**, duas ferramentas amplamente utilizadas para a construção de compiladores e analisadores.

Este projeto consiste em:

1. **Analisador Léxico**: Realiza a leitura e classificação dos tokens de uma linguagem de programação.
2. **Analisador Sintático**: Verifica a estrutura do código conforme uma gramática definida e gera uma árvore de sintaxe abstrata.

## Instalação

### Pré-requisitos

Antes de começar a instalação, certifique-se de que as ferramentas **Flex** e **Bison** estão instaladas no seu sistema. Você também precisará do compilador **GCC** para compilar o código gerado pelas ferramentas.

### Ubuntu

No **Ubuntu**, você pode instalar as ferramentas necessárias usando os seguintes comandos:

```bash
sudo apt update
sudo apt install flex bison gcc
```

## Uso do Flex

### Estrutura do Projeto

O projeto utiliza Flex para criar um analisador léxico que reconhece tokens da linguagem de programação simplificada, como identificadores, palavras-chave, operadores e literais.

### Compilando o Analisador Léxico

#### 1. Gerar o código do analisador léxico com o Flex:

No arquivo lex.yy.l, você define as regras para o reconhecimento dos tokens. Para gerar o código C correspondente, use o seguinte comando:

```bash
flex projeto.l
```
Isso cria o arquivo projeto.yy.c, que contém o código do analisador léxico.

#### 2. Compilar o código gerado com o GCC:

Em seguida, compile o arquivo lex.yy.c para gerar o executável. O comando abaixo utiliza o GCC para compilar:

```bash
gcc projeto.yy.c -o projeto.o
```

### Executando o Analisador Léxico

Após a compilação, você pode executar o analisador, passando um arquivo de entrada com o código fonte a ser analisado. Por exemplo.

```bash
./projeto.o < teste.c
```

O analisador léxico vai processar o código fonte do arquivo teste.c, identificar os tokens conforme as regras definidas no arquivo projeto.l e exibir os resultados.

## Uso do Flex no Windows

### Compilando o Analisador Léxico

#### 1. Gerar o código do analisador léxico com o Flex:

No arquivo lex.yy.l, você define as regras para o reconhecimento dos tokens. Para gerar o código C correspondente, use o seguinte comando:

```bash
flex projeto.l
```
Isso cria o arquivo projeto.yy.c, que contém o código do analisador léxico.

#### 2. Compilar o código gerado com o GCC:

Em seguida, compile o arquivo lex.yy.c para gerar o executável. O comando abaixo utiliza o GCC para compilar:

```bash
gcc lex.yy.c -o projeto.exe
```

### Executando o Analisador Léxico

Após a compilação, você pode executar o analisador, passando um arquivo de entrada com o código fonte a ser analisado. Por exemplo.

```bash
Get-Content testeErro.c | .\projeto.exe
```

## Integrantes

- Estevão Augusto da Fonseca Santos
- Felipe Crisostomo Silva Oliveira
- Bernardo Coelho Pavani Marinho
