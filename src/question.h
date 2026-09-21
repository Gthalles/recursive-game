#ifndef QUESTION_H
#define QUESTION_H

#define TOTAL_QUESTIONS 3
#define TOTAL_CHOICES 5

typedef struct {
    char statement[200];
    char choices[TOTAL_CHOICES][100];
    char correctAnswer;
} Question;

/*
 * extern declares that these variables exist,
 * but are defined in another file.
 */
extern const Question questions[TOTAL_QUESTIONS];

#endif
