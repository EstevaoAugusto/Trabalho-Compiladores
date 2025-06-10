# Trabalho-Compiladores

Trabalho da Disciplina **Compiladores** do curso de Ciência de Computação da **Universidade Federal de Lavras (UFLA)**. O objetivo desse trabalho é criar um analisador léxico e sintático utilizando **Flex** e **Bison**, duas ferramentas amplamente utilizadas para a construção de compiladores e analisadores.

Este projeto consiste em:

1. **Analisador Léxico**: Realiza a leitura e classificação dos tokens de uma linguagem de programação.
2. **Analisador Sintático**: Verifica a estrutura do código conforme uma gramática definida e gera uma árvore de sintaxe abstrata.

## Instalação

### Pré-requisitos

Certifique-se de que as seguintes ferramentas estão instaladas:

- **Flex** – para geração do analisador léxico.
- **Bison** – para geração do analisador sintático.
- **GCC** – compilador C para gerar o executável.

### Ubuntu

No **Ubuntu**, você pode instalar as ferramentas necessárias usando os seguintes comandos:

```bash
sudo apt update
sudo apt install flex bison gcc
```

## Uso do Flex

### Estrutura do Projeto

- ```projeto.l```: Arquivo com as definições das expressões regulares do analisador léxico.
- ```parser.y```: Arquivo com as regras gramaticais do analisador sintático.
- Arquivos em C para testes.
- Outros arquivos auxiliares para testes ou execução.

### Compilando o Analisador Léxico

#### 1. Gerar o código do analisador léxico com o Flex:

```bash
flex projeto.l
```
Isso cria o arquivo lex.yy.c, que contém o código do analisador léxico.

#### 2. Gerar o código do analisador sintático com Bison:

```bash
bison -d projeto.y
```

Isso gera dois arquivos:

- ```projeto.tab.c```: código C do parser gerado pelo Bison.
- ```projeto.tab.h```: cabeçalho com definições de tokens para uso no Flex.

#### 3. Compilar o código gerado com o GCC:

```bash
gcc lex.yy.c projeto.tab.c -o analisador -lfl
```

O parâmetro ```-lfl``` inclui a biblioteca do Flex necessária para a execução.

### Executando o Analisador Léxico

Após a compilação, execute o analisador com um arquivo de teste:

```bash
./analisador < BisonTesteCerto.c
```

O analisador irá processar o código de entrada, reconhecer os tokens e validar a estrutura sintática conforme a gramática definida.

## Integrantes

- Estevão Augusto da Fonseca Santos
- Felipe Crisostomo Silva Oliveira
- Bernardo Coelho Pavani Marinho