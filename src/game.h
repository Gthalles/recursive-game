#ifndef GAME_H
#define GAME_H

#include "question.h"

int runQuiz(
    const Question questions[],
    int index,
    int totalQuestions,
    int score
);

void showResult(int score, int totalQuestions);

#endif
