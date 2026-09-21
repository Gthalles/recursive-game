# Quiz Recursivo de Estruturas de Dados

Um quiz de terminal desenvolvido em linguagem C sobre conceitos básicos de Estruturas de Dados.

O jogo apresenta perguntas de múltipla escolha sobre temas como pilha, fila, árvore, grafo, lista encadeada, vetores, ponteiros e busca.

As perguntas são exibidas uma por uma e o avanço entre elas é realizado utilizando uma **função recursiva**.

Cada pergunta possui 5 alternativas (A até E) e cada resposta correta vale **10 pontos**.

## Integrantes

* **Miguel Soares de Souza** — RA: 2678233
* **Vitor Hugo Santos Oliveira** — RA: 2706555
* **Thalles Guilherme Barboza Garbelotti** — RA: 1884255
* **José Lucas Albino Delmonico** — RA: 2768615
* **Eduardo Henryque Camargo Silva** — RA: 2766981

## Funcionamento do jogo

Ao iniciar o programa, uma mensagem de apresentação é exibida no terminal.

Em seguida, as perguntas são apresentadas individualmente.

O jogador deve informar uma alternativa entre **A e E**.

O programa:

1. Exibe a pergunta atual.
2. Mostra as cinco alternativas.
3. Lê a resposta do jogador.
4. Verifica se a resposta está correta.
5. Adiciona 10 pontos caso a resposta esteja correta.
6. Mostra a pontuação atual.
7. Utiliza recursividade para passar para a próxima pergunta.
8. Ao terminar todas as perguntas, apresenta o resultado final.

O programa também verifica entradas inválidas. Caso o jogador digite algo diferente de uma alternativa entre A e E, o programa solicita uma nova resposta.

## Pontuação

Cada resposta correta vale **10 pontos**.

O jogo possui 12 perguntas, portanto a pontuação máxima é:

**120 pontos**

Ao final, o programa apresenta uma mensagem de acordo com a pontuação obtida.

## Estrutura do projeto

```text
recursive-game/
│
├── Makefile
├── README.md
│
└── src/
    ├── main.c
    ├── game.c
    ├── game.h
    ├── questions.c
    └── question.h
```

### Descrição dos arquivos

**main.c**

É o ponto de entrada do programa. Inicia o quiz, chama a função responsável pelas perguntas e apresenta o resultado final.

**game.c**

Contém a lógica principal do jogo. É responsável por:

* Exibir as perguntas;
* Ler as respostas;
* Validar as alternativas;
* Verificar respostas corretas e incorretas;
* Controlar a pontuação;
* Utilizar recursividade para avançar entre as perguntas;
* Exibir o resultado final.

**game.h**

Contém as declarações das funções utilizadas pelo arquivo `game.c`.

**questions.c**

Contém as 12 perguntas do quiz, suas cinco alternativas e a resposta correta de cada pergunta.

**question.h**

Define a estrutura `Question`, a quantidade de perguntas e a quantidade de alternativas.

## Conceito de recursividade

A principal característica do projeto é o uso de **recursividade**.

A função `runQuiz()` chama a si mesma para passar para a próxima pergunta.

O funcionamento pode ser representado da seguinte forma:

```text
Pergunta 1
    ↓
runQuiz()
    ↓
Pergunta 2
    ↓
runQuiz()
    ↓
Pergunta 3
    ↓
runQuiz()
    ↓
...
    ↓
Pergunta 12
    ↓
Resultado final
```

A recursividade termina quando o índice atual chega ao total de perguntas.

## Como rodar no macOS/Linux

Com o GCC instalado, execute:

```bash
make run
```

Ou compile manualmente:

```bash
gcc -Wall -Wextra -Wpedantic src/main.c src/game.c src/questions.c -o quiz
```

Depois execute:

```bash
./quiz
```

## Como rodar no Windows

É necessário ter o GCC instalado e disponível no terminal.

Uma opção é utilizar o [MSYS2](https://www.msys2.org/).

Depois de instalar e configurar o GCC:

### 1. Abra o terminal

Entre na pasta do projeto:

```powershell
cd caminho\para\recursive-game
```

Por exemplo:

```powershell
cd C:\Users\Aluno\Desktop\recursive-game
```

### 2. Compile o projeto

```powershell
gcc -Wall -Wextra -Wpedantic src\main.c src\game.c src\questions.c -o quiz.exe
```

### 3. Execute o jogo

```powershell
.\quiz.exe
```

## Exemplo de funcionamento

Ao iniciar:

```text
========================================
          DATA STRUCTURES QUIZ
========================================
Each correct answer is worth 10 points.
```

Depois o programa apresenta uma pergunta:

```text
========================================
QUESTION 1
========================================
O que e uma estrutura de dados?

A) Um programa para criar sites
B) Um tipo de computador
C) Uma forma de organizar e armazenar dados
D) Um sistema operacional
E) Um banco de dados

Enter your answer (A-E):
```

Após responder, o programa informa se a resposta está correta e mostra a pontuação atual.

Ao finalizar todas as perguntas, o resultado final é apresentado:

```text
========================================
FINAL RESULT
========================================
Your score: 120 out of 120 points.
Excellent! You answered every question correctly!
```

## Tecnologias utilizadas

* Linguagem C
* GCC
* Terminal
* Git/GitHub
* Recursividade
* Structs
* Arrays
* Funções
* Entrada e saída de dados
* Validação de entrada

## Objetivo do projeto

O objetivo do projeto é desenvolver um jogo simples em linguagem C para aplicar conceitos de programação e estruturas de dados, principalmente o conceito de **recursividade**, além de trabalhar com funções, estruturas (`struct`), arrays, validação de entrada e organização do código em diferentes arquivos.
