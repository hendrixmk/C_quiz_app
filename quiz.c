#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "quiz.h"

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard leftover characters */
    }
}

void print_banner(void)
{
    printf("=====================================\n");
    printf("           C QUIZ APPLICATION         \n");
    printf("=====================================\n");
    printf("Answer each question by typing A, B, C, or D.\n\n");
}

/* Fisher-Yates shuffle so question order varies between runs */
void shuffle_questions(Question questions[], int count)
{
    srand((unsigned int)time(NULL));

    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

/* Displays one question, reads + validates input, returns the chosen letter */
char ask_question(const Question *q, int number, int total)
{
    char input[16];
    char answer = '\0';
    int valid = 0;

    printf("Question %d/%d: %s\n", number, total, q->question);
    printf("  A) %s\n", q->options[0]);
    printf("  B) %s\n", q->options[1]);
    printf("  C) %s\n", q->options[2]);
    printf("  D) %s\n", q->options[3]);

    while (!valid) {
        printf("Your answer: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        /* Find the first non-whitespace character the user typed */
        char raw = '\0';
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isspace((unsigned char)input[i])) {
                raw = input[i];
                break;
            }
        }

        answer = (char)toupper((unsigned char)raw);

        if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
            valid = 1;
        } else {
            printf("Invalid input. Please enter A, B, C, or D.\n");
        }
    }

    printf("\n");
    return answer;
}

/* Runs the full quiz loop, returns number of correct answers */
int run_quiz(Question questions[], int count)
{
    int score = 0;

    for (int i = 0; i < count; i++) {
        char user_answer = ask_question(&questions[i], i + 1, count);

        if (user_answer == questions[i].correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c) %s\n\n",
                   questions[i].correct_answer,
                   questions[i].options[questions[i].correct_answer - 'A']);
        }
    }

    return score;
}

/* Maps a percentage score to a letter grade */
char get_grade(double percentage)
{
    if (percentage >= 90.0) return 'A';
    if (percentage >= 75.0) return 'B';
    if (percentage >= 60.0) return 'C';
    if (percentage >= 40.0) return 'D';
    return 'F';
}

void show_result(int score, int total)
{
    double percentage = (total > 0) ? ((double)score / total) * 100.0 : 0.0;
    char grade = get_grade(percentage);

    printf("=====================================\n");
    printf("              QUIZ RESULTS            \n");
    printf("=====================================\n");
    printf("Score      : %d / %d\n", score, total);
    printf("Percentage : %.2f%%\n", percentage);
    printf("Grade      : %c\n", grade);

    if (percentage >= 90.0) {
        printf("Outstanding! You really know your stuff.\n");
    } else if (percentage >= 75.0) {
        printf("Great job! Solid understanding.\n");
    } else if (percentage >= 60.0) {
        printf("Good effort. A bit more practice will help.\n");
    } else if (percentage >= 40.0) {
        printf("You passed, but review the material again.\n");
    } else {
        printf("Keep studying and try again!\n");
    }
    printf("=====================================\n");
}
