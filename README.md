# Quiz Recursivo de Estruturas de Dados

Um quiz de terminal em C sobre estruturas de dados. As perguntas são exibidas uma a uma por uma função recursiva; cada acerto vale 10 pontos.

## Estrutura

```text
.
├── Makefile
├── README.md
└── src/
    ├── main.c         # ponto de entrada
    ├── game.c/.h      # fluxo do quiz e resultado
    └── questions.c/.h # perguntas e respostas
```

## Como rodar (macOS/Linux)

Com o GCC instalado, execute:

```bash
make run
```

Ou compile manualmente:

```bash
gcc -Wall -Wextra -Wpedantic src/main.c src/game.c src/questions.c -o quiz
./quiz
```

## Como rodar no Windows (sem Makefile)

1. Instale o GCC, por exemplo pelo [MSYS2](https://www.msys2.org/), e abra um terminal que reconheça o comando `gcc`.
2. No terminal, entre na pasta do projeto:

   ```powershell
   cd caminho\para\recursive-game
   ```

3. Compile os arquivos fonte:

   ```powershell
   gcc -Wall -Wextra -Wpedantic src\main.c src\game.c src\questions.c -o quiz.exe
   ```

4. Execute o programa:

   ```powershell
   .\quiz.exe
   ```
