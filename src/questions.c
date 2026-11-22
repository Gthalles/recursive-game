#include "question.h"

/* Banco de perguntas: cada item guarda enunciado, alternativas e gabarito. */
const Question questions[TOTAL_QUESTIONS] = {
    {
        "O que é uma estrutura de dados?",
        {
            "Um programa para criar sites",
            "Um tipo de computador",
            "Uma forma de organizar e armazenar dados",
            "Um sistema operacional",
            "Um banco de dados"
        },
        'C'
    },
    {
        "Qual estrutura de dados segue o princípio "
        "LIFO (último a entrar, primeiro a sair)?",
        {
            "Fila",
            "Lista",
            "Árvore",
            "Pilha",
            "Grafo"
        },
        'D'
    },
    {
        "Qual estrutura de dados segue o princípio "
        "FIFO (primeiro a entrar, primeiro a sair)?",
        {
            "Pilha",
            "Fila",
            "Árvore",
            "Grafo",
            "Vetor"
        },
        'B'
    },
    {
        "Em C, qual estrutura é utilizada para armazenar "
        "vários valores do mesmo tipo em posições "
        "consecutivas de memória?",
        {
            "Função",
            "Estrutura",
            "Vetor",
            "Ponteiro",
            "Condição"
        },
        'C'
    },
    {
        "Qual símbolo é usado para acessar o conteúdo "
        "apontado por um ponteiro em C?",
        {
            "&",
            "#",
            "%",
            "*",
            "@"
        },
        'D'
    },
    {
        "Qual estrutura de dados é formada por elementos "
        "que possuem uma relação hierárquica?",
        {
            "Pilha",
            "Fila",
            "Árvore",
            "Vetor",
            "Matriz"
        },
        'C'
    },
    {
        "Em uma fila, onde normalmente um novo elemento "
        "é inserido?",
        {
            "No início",
            "No meio",
            "No final",
            "Em qualquer posição",
            "Na posição zero obrigatoriamente"
        },
        'C'
    },
    {
        "Qual é a principal característica de uma "
        "lista encadeada?",
        {
            "Seus elementos precisam estar sempre em "
            "posições consecutivas da memória",

            "Seus elementos são ligados por referências "
            "ou ponteiros",

            "Ela só pode armazenar números",

            "Ela não permite remoção de elementos",

            "Ela possui tamanho obrigatoriamente fixo"
        },
        'B'
    },
    {
        "Qual algoritmo é utilizado para encontrar um "
        "elemento percorrendo uma lista do início ao fim?",
        {
            "Busca linear",
            "Busca binária",
            "Ordenação rápida",
            "Ordenação por intercalação",
            "Espalhamento"
        },
        'A'
    },
    {
        "Qual estrutura de dados é mais adequada para "
        "representar conexões entre cidades, computadores "
        "ou pessoas?",
        {
            "Pilha",
            "Fila",
            "Vetor",
            "Grafo",
            "Variável"
        },
        'D'
    }
};
