#ifndef QUIZ_H
#define QUIZ_H

#define MAX_QUESTIONS   50
#define MAX_QUESTION_LEN 256
#define MAX_OPTION_LEN  128
#define NUM_OPTIONS     4

typedef struct {
    char question[MAX_QUESTION_LEN];
    char options[NUM_OPTIONS][MAX_OPTION_LEN];
    char correct_answer;   /* 'A', 'B', 'C', or 'D' */
} Question;

/* quiz_data.c */
int load_questions(Question questions[], int max_questions);

/* quiz.c */
void print_banner(void);
void shuffle_questions(Question questions[], int count);
char ask_question(const Question *q, int number, int total);
int run_quiz(Question questions[], int count);
void show_result(int score, int total);
char get_grade(double percentage);
void clear_input_buffer(void);

#endif /* QUIZ_H */
