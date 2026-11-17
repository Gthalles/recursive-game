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

Ao iniciar, o programa apresenta o menu principal:

```text
1 - Jogar
2 - Ver ranking
3 - Sair
```

Na opção **Jogar**, o programa solicita o nome do jogador e apresenta as perguntas individualmente.

O jogador deve informar uma alternativa entre **A e E**.

O programa:

1. Exibe a pergunta atual.
2. Mostra as cinco alternativas.
3. Lê a resposta do jogador.
4. Verifica se a resposta está correta.
5. Adiciona 10 pontos caso a resposta esteja correta.
6. Mostra a pontuação atual.
7. Utiliza recursividade para passar para a próxima pergunta.
8. Ao terminar todas as perguntas, apresenta o resultado final e cadastra o nome e a pontuação no ranking.

Na opção **Ver ranking**, as partidas realizadas na execução atual são ordenadas por pontuação e exibidas. A opção **Sair** libera todos os nós da lista encadeada antes de encerrar o programa.

O programa também verifica entradas inválidas. Caso o jogador digite algo diferente de uma alternativa entre A e E, o programa solicita uma nova resposta.

## Pontuação

Cada resposta correta vale **10 pontos**.

O jogo possui 10 perguntas, portanto a pontuação máxima é:

**100 pontos**

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
    ├── ranking.c
    ├── ranking.h
    ├── questions.c
    └── question.h
```

### Descrição dos arquivos

**main.c**

É o ponto de entrada do programa. Controla o menu, inicia partidas, cadastra resultados e libera a lista ao sair.

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

Contém as 10 perguntas do quiz, suas cinco alternativas e a resposta correta de cada pergunta.

**question.h**

Define a estrutura `Question`, a quantidade de perguntas e a quantidade de alternativas.

**ranking.c** e **ranking.h**

Definem a lista simplesmente encadeada de resultados e as operações para cadastrar, ordenar, exibir e liberar o ranking.

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
Pergunta 10
    ↓
Resultado final
```

A recursividade termina quando o índice atual chega ao total de perguntas.

## Como rodar no macOS

Com o GCC ou o Command Line Tools instalado, entre na pasta do projeto e execute:

```bash
make run
```

Ou compile manualmente:

```bash
gcc -Wall -Wextra -Wpedantic src/main.c src/game.c src/questions.c src/ranking.c -o quiz
```

Depois execute:

```bash
./quiz
```

## Como rodar no Linux

Com o GCC instalado, entre na pasta do projeto e execute:

```bash
make run
```

Ou compile e execute manualmente:

```bash
gcc -Wall -Wextra -Wpedantic src/main.c src/game.c src/questions.c src/ranking.c -o quiz
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
gcc -Wall -Wextra -Wpedantic src\main.c src\game.c src\questions.c src\ranking.c -o quiz.exe
```

### 3. Execute o jogo

```powershell
.\quiz.exe
```

## Exemplo de funcionamento

Ao iniciar:

```text
========================================
              MENU PRINCIPAL
========================================
1 - Jogar
2 - Ver ranking
3 - Sair
```

Após escolher `1`, informe o nome e responda às perguntas:

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

Após responder, o programa informa se a resposta está correta, mostra a pontuação atual e cadastra o resultado ao final da partida.

Ao finalizar todas as perguntas, o resultado final é apresentado:

```text
========================================
FINAL RESULT
========================================
Your score: 100 out of 100 points.
Excellent! You answered every question correctly!
```

Para consultar os resultados cadastrados, escolha a opção `2` no menu:

```text
RANKING DO QUIZ

1º Maria - 100 pontos
2º João - 90 pontos
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
