#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "question.h"
#include "game.h"
#include "ranking.h"

static void limparEntradaRestante(void) {
    int caractere;

    /* Conceito: leitura e limpeza de entrada. */
    /* Descarta o restante da linha para nao contaminar a proxima leitura. */
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

static int lerNomeJogador(char nome[], size_t tamanho) {
    size_t ultimoCaractere;

    do {
        printf("Digite seu nome: ");

        if (fgets(nome, (int)tamanho, stdin) == NULL) {
            return 0;
        }

    /* Conceitos: vetor de caracteres e validação de entrada. */
        /* Remove a quebra de linha; nomes longos tem o restante descartado. */
        ultimoCaractere = strcspn(nome, "\n");

        if (nome[ultimoCaractere] == '\n') {
            nome[ultimoCaractere] = '\0';
        } else {
            limparEntradaRestante();
        }

        if (nome[0] == '\0') {
            printf("O nome não pode ficar vazio.\n");
        }
    } while (nome[0] == '\0');

    return 1;
}

static void exibirMenu(void) {
    printf("\n========================================\n");
    printf("              MENU PRINCIPAL\n");
    printf("========================================\n");
    printf("1 - Jogar\n");
    printf("2 - Ver ranking\n");
    printf("3 - Sair\n");
    printf("Escolha uma opção: ");
}

static int lerOpcaoMenu(int *opcao) {
    char entrada[20];
    char caractereExtra;

    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return 0;
    }

    if (strchr(entrada, '\n') == NULL) {
        limparEntradaRestante();
    }

    /* Conceito: validação de entrada. */
    /* O segundo campo detecta texto extra, como "1abc", junto ao numero. */
    if (sscanf(entrada, "%d %c", opcao, &caractereExtra) != 1) {
        return -1;
    }

    return 1;
}

static void jogarPartida(void) {
    int finalScore;
    char nome[50];
    Jogador *inicioAnterior;

    printf("\n========================================\n");
    printf("       QUIZ DE ESTRUTURAS DE DADOS\n");
    printf("========================================\n");
    printf("Cada questão equivale a 10 pontos\n");

    if (!lerNomeJogador(nome, sizeof(nome))) {
        printf("Não foi possível ler o nome do jogador.\n");
        return;
    }

    /* Conceito: array de perguntas passado para a funcao do quiz. */
    /* Inicia o quiz na primeira pergunta, com pontuacao zero. */
    finalScore = runQuiz(
        questions,
        0,
        TOTAL_QUESTIONS,
        0
    );

    showResult(finalScore, TOTAL_QUESTIONS);

    inicioAnterior = inicioRanking;
    adicionarJogador(&inicioRanking, nome, finalScore);

    if (inicioRanking == inicioAnterior) {
        printf("Não foi possível cadastrar o resultado.\n");
    } else {
        printf("Resultado de %s cadastrado com sucesso.\n", nome);
    }
}

int main(void) {
    int executando = 1;
    int opcao;
    int leitura;

    setlocale(LC_ALL, ".UTF8");

    /* Conceito: repeticao com while para manter o menu ativo. */
    /* Mantem o menu ativo ate o jogador escolher sair ou encerrar a entrada. */
    while (executando) {
        exibirMenu();
        leitura = lerOpcaoMenu(&opcao);

        if (leitura == 0) {
            printf("\nEntrada encerrada.\n");
            break;
        }

        if (leitura == -1) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                jogarPartida();
                break;

            case 2:
                ordenarRanking(inicioRanking);
                exibirRanking(inicioRanking);
                break;

            case 3:
                executando = 0;
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    liberarLista(&inicioRanking);
    printf("Programa encerrado.\n");

    return 0;
}
