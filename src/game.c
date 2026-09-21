#include <stdio.h>
#include <ctype.h>

#include "game.h"

static void clearInputBuffer(void) {
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
    }
}

static char readAnswer(void) {
    char answer;

    printf("\nEnter your answer (A-E): ");

    if (scanf(" %c", &answer) != 1) {
        clearInputBuffer();
        printf("Invalid input. Please try again.\n");

        return readAnswer();
    }

    clearInputBuffer();

    answer = (char)toupper((unsigned char)answer);

    if (answer < 'A' || answer > 'E') {
        printf("Invalid choice. Enter a letter between A and E.\n");

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
    printf("QUESTION %d\n", questionNumber);
    printf("========================================\n");

    printf("%s\n\n", question->statement);

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

    if (index == totalQuestions) {
        return score;
    }

    showQuestion(&questions[index], index + 1);

    answer = readAnswer();

    if (answer == questions[index].correctAnswer) {
        printf("\nCorrect answer! +10 points.\n");
        score += 10;
    } else {
        printf("\nIncorrect answer.\n");
        printf(
            "The correct answer was: %c.\n",
            questions[index].correctAnswer
        );
    }

    printf("Current score: %d\n", score);

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
    printf("FINAL RESULT\n");
    printf("========================================\n");

    printf(
        "Your score: %d out of %d points.\n",
        score,
        maximumScore
    );

    if (score == maximumScore) {
        printf("Excellent! You answered every question correctly!\n");
    } else if (score >= maximumScore * 0.7) {
        printf("Well done! You got a good result.\n");
    } else if (score > 0) {
        printf("Good start, but you can still improve.\n");
    } else {
        printf("Study a little more and try again.\n");
    }
}
