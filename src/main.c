#include <stdio.h>
#include <string.h>

#include "question.h"
#include "game.h"
#include "ranking.h"

static void limparEntradaRestante(void) {
    int caractere;

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

        ultimoCaractere = strcspn(nome, "\n");

        if (nome[ultimoCaractere] == '\n') {
            nome[ultimoCaractere] = '\0';
        } else {
            limparEntradaRestante();
        }

        if (nome[0] == '\0') {
            printf("O nome nao pode ficar vazio.\n");
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
    printf("Escolha uma opcao: ");
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
    printf("          DATA STRUCTURES QUIZ\n");
    printf("========================================\n");
    printf("Cada questao equivale a 10 pontos\n");

    if (!lerNomeJogador(nome, sizeof(nome))) {
        printf("Nao foi possivel ler o nome do jogador.\n");
        return;
    }

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
        printf("Nao foi possivel cadastrar o resultado.\n");
    } else {
        printf("Resultado de %s cadastrado com sucesso.\n", nome);
    }
}

int main(void) {
    int executando = 1;
    int opcao;
    int leitura;

    while (executando) {
        exibirMenu();
        leitura = lerOpcaoMenu(&opcao);

        if (leitura == 0) {
            printf("\nEntrada encerrada.\n");
            break;
        }

        if (leitura == -1) {
            printf("Opcao invalida. Tente novamente.\n");
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
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    liberarLista(&inicioRanking);
    printf("Programa encerrado.\n");

    return 0;
}
