#include <stdio.h>
#include <ctype.h>

#include "game.h"

static void clearInputBuffer(void) {
    int character;

    /* Remove caracteres restantes para que nao virem respostas seguintes. */
    while ((character = getchar()) != '\n' && character != EOF) {
    }
}

static char readAnswer(void) {
    char answer;

    printf("\nDigite sua resposta (A-E): ");

    if (scanf(" %c", &answer) != 1) {
        clearInputBuffer();
        printf("Entrada inválida. Tente novamente.\n");

        /* Conceito: recursividade para pedir novamente uma entrada inválida. */
        return readAnswer();
    }

    clearInputBuffer();

    /* Aceita letras minusculas convertendo a resposta para maiuscula. */
    answer = (char)toupper((unsigned char)answer);

    if (answer < 'A' || answer > 'E') {
        printf("Opção inválida. Digite uma letra entre A e E.\n");

        /* Conceito: recursividade para repetir a leitura até receber A-E. */
        return readAnswer();
    }

    return answer;
}

static void showQuestion(
    const Question *question,
    int questionNumber
) {
    int i;

    printf("\n========================================\n");
    printf("QUESTÃO %d\n", questionNumber);
    printf("========================================\n");

    printf("%s\n\n", question->statement);

    /* Conceitos: array de alternativas e repetição com for. */
    /* As alternativas sao exibidas na mesma ordem em que estao armazenadas. */
    for (i = 0; i < TOTAL_CHOICES; i++) {
        printf(
            "%c) %s\n",
            'A' + i,
            question->choices[i]
        );
    }
}

int runQuiz(
    const Question questions[],
    int index,
    int totalQuestions,
    int score
) {
    char answer;

    /* Conceito: recursividade; este é o caso base que encerra as chamadas. */
    /* Caso base: todas as perguntas foram respondidas, entao retorna a pontuacao. */
    if (index == totalQuestions) {
        return score;
    }

    /* Conceitos: acesso a um elemento do array e uso de ponteiro. */
    showQuestion(&questions[index], index + 1);

    answer = readAnswer();

    if (answer == questions[index].correctAnswer) {
        printf("\nResposta correta! +10 pontos.\n");
        score += 10;
    } else {
        printf("\nResposta incorreta.\n");
        printf(
            "A resposta correta era: %c.\n",
            questions[index].correctAnswer
        );
    }

    printf("Pontuação atual: %d\n", score);

    /* Conceito: chamada recursiva para avançar até a próxima pergunta. */
    /* Avanca recursivamente uma pergunta, levando a pontuacao acumulada. */
    return runQuiz(
        questions,
        index + 1,
        totalQuestions,
        score
    );
}

void showResult(int score, int totalQuestions) {
    int maximumScore = totalQuestions * 10;

    printf("\n========================================\n");
    printf("RESULTADO FINAL\n");
    printf("========================================\n");

    printf(
        "Sua pontuação: %d de %d pontos.\n",
        score,
        maximumScore
    );

    if (score == maximumScore) {
        printf("Excelente! Você acertou todas as questões!\n");
    } else if (score >= maximumScore * 0.7) {
        printf("Muito bem! Você teve um bom resultado.\n");
    } else if (score > 0) {
        printf("Bom começo, mas você ainda pode melhorar.\n");
    } else {
        printf("Estude mais um pouco e tente novamente.\n");
    }
}
