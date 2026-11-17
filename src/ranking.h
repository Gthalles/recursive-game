#ifndef RANKING_H
#define RANKING_H

typedef struct Jogador {
    char nome[50];
    int pontuacao;
    struct Jogador *prox;
} Jogador;

/* Inicio da lista simplesmente encadeada de resultados. */
extern Jogador *inicioRanking;

/* Adiciona um jogador no inicio da lista de resultados. */
void adicionarJogador(Jogador **lista, char nome[], int pontuacao);

/* Ordena os resultados por pontuacao, da maior para a menor. */
void ordenarRanking(Jogador *lista);

/* Exibe todos os resultados cadastrados no ranking. */
void exibirRanking(Jogador *lista);

/* Libera todos os nos e atualiza o inicio da lista para NULL. */
void liberarLista(Jogador **lista);

#endif
