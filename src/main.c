#include <stdio.h>

#include "question.h"
#include "game.h"

int main(void) {
    int finalScore;

    printf("========================================\n");
    printf("          DATA STRUCTURES QUIZ\n");
    printf("========================================\n");
    printf("Each correct answer is worth 10 points.\n");

    finalScore = runQuiz(
        questions,
        0,
        TOTAL_QUESTIONS,
        0
    );

    showResult(finalScore, TOTAL_QUESTIONS);

    return 0;
}
