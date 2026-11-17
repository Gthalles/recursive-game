# Resumo — Ranking com Lista Encadeada

Este documento resume as alterações feitas para adicionar um ranking de partidas ao quiz. O foco é explicar a lista simplesmente encadeada, a alocação dinâmica e o uso de ponteiros.

## Visão geral

O ranking é mantido somente enquanto o programa está em execução. Cada partida concluída cria um novo registro de jogador na memória. Não são usados vetores para guardar os jogadores, arquivos ou banco de dados.

A lista é formada por nós. Cada nó armazena um jogador e o endereço do próximo nó:

```text
inicioRanking
     |
     v
+---------+------+-------+     +---------+------+-------+
| Maria   | 100  | prox  | --> | Joao    |  90  | NULL  |
+---------+------+-------+     +---------+------+-------+
```

`NULL` indica que não há próximo jogador; portanto, o nó é o último da lista.

## SPEC 01 — Estrutura de dados do ranking

Foram criados os arquivos `src/ranking.h` e `src/ranking.c`.

No cabeçalho foi definida a estrutura abaixo:

```c
typedef struct Jogador {
    char nome[50];
    int pontuacao;
    struct Jogador *prox;
} Jogador;
```

O campo `prox` é um ponteiro para outro `struct Jogador`. Ele conecta um nó ao seguinte e é o elemento que transforma registros separados em uma lista encadeada.

Também foi criado o ponteiro inicial da lista:

```c
Jogador *inicioRanking = NULL;
```

No início não existe nenhum jogador cadastrado, por isso o ponteiro recebe `NULL`.

## SPEC 02 — Cadastro de pontuações

Foi implementada a função:

```c
void adicionarJogador(Jogador **lista, char nome[], int pontuacao);
```

Ela recebe `Jogador **lista`, isto é, um **ponteiro para o ponteiro inicial**. Isso é necessário porque a função precisa alterar o início da lista do lado de fora da função.

Exemplo da chamada:

```c
adicionarJogador(&inicioRanking, nome, pontuacao);
```

O operador `&` envia o endereço de `inicioRanking`. Dentro da função, `*lista` representa o próprio `inicioRanking`.

O novo nó é criado dinamicamente:

```c
novoJogador = malloc(sizeof(Jogador));
```

`malloc` reserva memória suficiente para uma estrutura `Jogador` e devolve seu endereço. Se não houver memória disponível, ele devolve `NULL`; por isso a implementação verifica essa condição antes de acessar o nó.

A inserção é feita no início da lista:

```c
novoJogador->prox = *lista;
*lista = novoJogador;
```

Primeiro, o novo nó passa a apontar para o antigo primeiro nó. Depois, o ponteiro inicial passa a apontar para o novo nó. Essa ordem é importante: se o início fosse atualizado antes, o endereço do primeiro nó antigo seria perdido.

Exemplo de inserção de Pedro em uma lista que já começa com Maria:

```text
Antes:  inicio -> Maria -> NULL
Depois: inicio -> Pedro -> Maria -> NULL
```

São aceitos nomes repetidos e pontuações de 0 a 100. Cada chamada cria um novo nó; nenhum resultado anterior é sobrescrito.

## SPEC 03 — Ordenação e exibição do ranking

Foram implementadas as funções:

```c
void ordenarRanking(Jogador *lista);
void exibirRanking(Jogador *lista);
```

### Ordenação

`ordenarRanking` utiliza Bubble Sort em ordem decrescente. Dois nós vizinhos são comparados; se o da esquerda tiver menos pontos, os dados dos dois nós são trocados.

Os ponteiros `prox` **não são trocados**. Apenas `nome` e `pontuacao` mudam de nó. Assim, o encadeamento permanece válido durante toda a ordenação.

```text
Antes: [Ana, 70, prox] -> [Maria, 100, prox]
Depois: [Maria, 100, prox] -> [Ana, 70, prox]
```

Em caso de empate, não há troca, pois a comparação usa menor que (`<`), não menor ou igual a (`<=`). Isso mantém a ordem relativa dos registros empatados, tornando a ordenação estável.

### Exibição

`exibirRanking` verifica primeiro se o ponteiro recebido é `NULL`:

```c
if (lista == NULL) {
    printf("Nenhuma pontuacao cadastrada.\n");
    return;
}
```

Se existir ao menos um nó, um ponteiro auxiliar percorre a lista:

```c
atual = lista;

while (atual != NULL) {
    /* usa atual->nome e atual->pontuacao */
    atual = atual->prox;
}
```

O ponteiro `atual` caminha de nó em nó sem alterar `inicioRanking`. A travessia termina quando `atual` chega a `NULL`.

## SPEC 04 — Integração com o quiz

O programa passou a ter o menu principal:

```text
1 - Jogar
2 - Ver ranking
3 - Sair
```

### Jogar

1. Solicita o nome do jogador.
2. Executa o quiz normalmente.
3. Mostra a pontuação final.
4. Chama `adicionarJogador(&inicioRanking, nome, finalScore)`.

Assim, cada partida cria um nó novo e a lista permanece disponível para as próximas partidas da mesma execução.

### Ver ranking

Ao escolher a opção 2, o programa chama:

```c
ordenarRanking(inicioRanking);
exibirRanking(inicioRanking);
```

O ranking é ordenado antes de ser mostrado. Depois disso, o programa volta ao menu, permitindo jogar novamente ou consultar o ranking outra vez.

### Sair e liberar memória

Foi criada a função:

```c
void liberarLista(Jogador **lista);
```

Ela percorre todos os nós, guarda o endereço do próximo nó e libera o nó atual:

```c
atual = *lista;

while (atual != NULL) {
    proximo = atual->prox;
    free(atual);
    atual = proximo;
}

*lista = NULL;
```

É obrigatório salvar `atual->prox` em `proximo` antes de chamar `free(atual)`. Depois de liberar um nó, seus campos não podem mais ser acessados.

Ao final, `*lista = NULL` impede que o ponteiro inicial fique apontando para uma área de memória que já foi liberada.

## Fluxo completo da aplicação

```text
Menu
 |
 +-- 1. Jogar --> ler nome --> executar quiz --> adicionarJogador
 |
 +-- 2. Ver ranking --> ordenarRanking --> exibirRanking --> Menu
 |
 +-- 3. Sair --> liberarLista --> fim do programa
```

## Pontos importantes para explicar ao professor

- Uma lista simplesmente encadeada é uma sequência de nós em que cada nó conhece somente o próximo.
- `inicioRanking` aponta para o primeiro nó. Quando a lista está vazia, seu valor é `NULL`.
- `prox` guarda o endereço do próximo jogador. O último nó aponta para `NULL`.
- `Jogador **lista` permite alterar o ponteiro inicial dentro de uma função.
- `malloc` cria cada jogador em tempo de execução, sem limite fixo de jogadores.
- Todo `malloc` deve ter uma verificação de `NULL`.
- Todo nó criado com `malloc` deve ser liberado com `free` quando não for mais necessário.
- Inserir no início da lista é eficiente: não é necessário percorrer os nós para cadastrar um resultado.
- Bubble Sort é aplicado diretamente nos nós: trocam-se os dados, não os ponteiros.
- A lista não é persistente: ao sair, os resultados são liberados da memória e deixam de existir.

## Perguntas que a equipe deve saber responder

**Por que usar `Jogador **lista` em `adicionarJogador`?**

Porque a função precisa alterar quem é o primeiro nó. Passar apenas `Jogador *lista` alteraria somente uma cópia local do ponteiro.

**Por que `novoJogador->prox = *lista` vem antes de `*lista = novoJogador`?**

Para manter o endereço do antigo início e não perder o restante da lista.

**Por que o último nó aponta para `NULL`?**

Porque `NULL` marca o fim da lista e permite que os laços de percurso saibam quando parar.

**Por que é necessário chamar `free`?**

Porque a memória reservada com `malloc` não é liberada automaticamente durante a execução. Sem `free`, ocorreria vazamento de memória.

**A ordenação muda os ponteiros da lista?**

Não. O Bubble Sort troca apenas nome e pontuação entre nós vizinhos. Os campos `prox` permanecem os mesmos.

**O que acontece se dois jogadores tiverem a mesma pontuação?**

Os dois registros permanecem na lista. Como não há troca no empate, a ordem relativa deles é mantida.
