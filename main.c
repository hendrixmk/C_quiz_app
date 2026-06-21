#include <stdio.h>
#include <ctype.h>
#include "quiz.h"

int main(void)
{
    Question questions[MAX_QUESTIONS];
    int total;
    char play_again = 'Y';

    int count = load_questions(questions, MAX_QUESTIONS);

    if (count <= 0) {
        printf("No questions available. Exiting.\n");
        return 1;
    }

    while (play_again == 'Y') {
        Question round_questions[MAX_QUESTIONS];
        for (int i = 0; i < count; i++) {
            round_questions[i] = questions[i];
        }
        total = count;

        print_banner();
        shuffle_questions(round_questions, total);

        int score = run_quiz(round_questions, total);
        show_result(score, total);

        printf("\nPlay again? (Y/N): ");
        char input[16];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            play_again = (char)toupper((unsigned char)input[0]);
        } else {
            play_again = 'N';
        }
        printf("\n");
    }

    printf("Thanks for playing. Goodbye!\n");
    return 0;
}
