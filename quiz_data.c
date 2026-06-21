#include <string.h>
#include "quiz.h"

/*
 * Hardcoded question bank.
 * To add a question: increase the count and fill in a new entry below.
 * correct_answer must be 'A', 'B', 'C', or 'D'.
 */
int load_questions(Question questions[], int max_questions)
{
    Question bank[] = {
        {
            "What does CPU stand for?",
            { "Central Process Unit",
              "Central Processing Unit",
              "Computer Personal Unit",
              "Central Processor Underline" },
            'B'
        },
        {
            "Which data structure uses LIFO (Last In First Out)?",
            { "Queue", "Stack", "Linked List", "Tree" },
            'B'
        },
        {
            "In C, which function is used to allocate memory dynamically?",
            { "alloc()", "malloc()", "new()", "create()" },
            'B'
        },
        {
            "What is the time complexity of binary search?",
            { "O(n)", "O(n^2)", "O(log n)", "O(1)" },
            'C'
        },
        {
            "Which header file is required for printf() in C?",
            { "<stdlib.h>", "<string.h>", "<stdio.h>", "<conio.h>" },
            'C'
        },
        {
            "What does OS stand for?",
            { "Operating System", "Output Software", "Operational Sequence", "Order System" },
            'A'
        },
        {
            "Which protocol is used to send email?",
            { "HTTP", "FTP", "SMTP", "SNMP" },
            'C'
        },
        {
            "What is the default value of a global variable in C?",
            { "Garbage value", "0", "1", "NULL" },
            'B'
        },
        {
            "Which keyword is used to define a constant in C?",
            { "var", "let", "const", "static" },
            'C'
        },
        {
            "What does the 'sizeof' operator return in C?",
            { "Memory address", "Size in bits", "Size in bytes", "Data type" },
            'C'
        }
    };

    int total = (int)(sizeof(bank) / sizeof(bank[0]));
    if (total > max_questions) {
        total = max_questions;
    }

    for (int i = 0; i < total; i++) {
        questions[i] = bank[i];
    }

    return total;
}
