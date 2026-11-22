#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ranking.h"

/* A lista nao possui jogadores quando o programa inicia. */
Jogador *inicioRanking = NULL;

void adicionarJogador(Jogador **lista, char nome[], int pontuacao) {
    Jogador *novoJogador;

    if (lista == NULL || nome == NULL) {
        return;
    }

    if (pontuacao < 0 || pontuacao > 100) {
        return;
    }

    /* Reserva memoria para um novo no antes de alterar a lista. */
    novoJogador = malloc(sizeof(Jogador));

    if (novoJogador == NULL) {
        return;
    }

    strncpy(novoJogador->nome, nome, sizeof(novoJogador->nome) - 1);
    novoJogador->nome[sizeof(novoJogador->nome) - 1] = '\0';
    novoJogador->pontuacao = pontuacao;
    /* Insere no inicio: o proximo do novo no passa a ser o inicio anterior. */
    novoJogador->prox = *lista;
    *lista = novoJogador;
}

void ordenarRanking(Jogador *lista) {
    Jogador *atual;
    int houveTroca;
    int pontuacaoTemporaria;
    char nomeTemporario[50];

    if (lista == NULL) {
        return;
    }

    /* Repete as passagens ate que nao seja mais necessario trocar resultados. */
    do {
        houveTroca = 0;
        atual = lista;

        while (atual->prox != NULL) {
            if (atual->pontuacao < atual->prox->pontuacao) {
                pontuacaoTemporaria = atual->pontuacao;
                atual->pontuacao = atual->prox->pontuacao;
                atual->prox->pontuacao = pontuacaoTemporaria;

                strcpy(nomeTemporario, atual->nome);
                strcpy(atual->nome, atual->prox->nome);
                strcpy(atual->prox->nome, nomeTemporario);

                houveTroca = 1;
            }

            atual = atual->prox;
        }
    } while (houveTroca);
}

void exibirRanking(Jogador *lista) {
    Jogador *atual;
    int posicao;

    printf("\nRANKING DO QUIZ\n\n");

    if (lista == NULL) {
        printf("Nenhuma pontuação cadastrada.\n");
        return;
    }

    atual = lista;
    posicao = 1;

    while (atual != NULL) {
        printf(
            "%dº %s - %d pontos\n",
            posicao,
            atual->nome,
            atual->pontuacao
        );

        atual = atual->prox;
        posicao++;
    }
}

void liberarLista(Jogador **lista) {
    Jogador *atual;
    Jogador *proximo;

    if (lista == NULL) {
        return;
    }

    atual = *lista;

    /* Guarda o proximo no antes de liberar o atual para manter o percurso. */
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *lista = NULL;
}
