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
- Outros arquivos auxiliares para testes ou execução.

### Executando o projeto

Para executar o compilador, basta utilizar o script bash ExecutarCompilador.sh atráves dos comandos abaixo.

```bash
chmod +x ExecutarCompilador.sh
./ExecutarCompilador.sh
```

## Integrantes

- Estevão Augusto da Fonseca Santos
- Felipe Crisostomo Silva Oliveira
- Bernardo Coelho Pavani Marinho