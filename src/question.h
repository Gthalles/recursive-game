#ifndef QUESTION_H
#define QUESTION_H

#define TOTAL_QUESTIONS 10
#define TOTAL_CHOICES 5

/* Conceito: struct agrupa enunciado, alternativas e resposta em um tipo. */
typedef struct {
    char statement[200];
    char choices[TOTAL_CHOICES][100];
    char correctAnswer;
} Question;

/* Conceito: array externo, definido em questions.c e usado em outros arquivos. */
/* A tabela e definida em questions.c e compartilhada com os demais arquivos. */
extern const Question questions[TOTAL_QUESTIONS];

#endif
