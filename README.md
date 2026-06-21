# C Quiz Application

A terminal-based multiple-choice quiz application written in C. Built as a
small, dependency-free educational tool demonstrating core C fundamentals:
loops, conditionals, functions, structs, and arrays.

## Features

- Multiple-choice questions (A/B/C/D) loaded from a separate data module
- Input validation (rejects anything that isn't A, B, C, or D and re-prompts)
- Randomized question order each run (Fisher-Yates shuffle)
- Automatic score calculation
- Final result screen with score, percentage, and letter grade (A–F)
- Replay option without restarting the program

## Project Structure

```
quiz-app/
├── main.c        # Entry point, game loop (play again logic)
├── quiz.c        # Core logic: asking questions, scoring, shuffling, results
├── quiz.h        # Shared struct definitions and function prototypes
├── quiz_data.c   # Question bank (edit this file to add/change questions)
├── Makefile
├── LICENSE
└── README.md
```

The question bank is intentionally kept in its own file (`quiz_data.c`)
separate from the quiz engine (`quiz.c`), so you can add or edit questions
without touching any logic.

## Build & Run

Requires `gcc` (or any C11-compatible compiler) and `make`.

```bash
git clone https://github.com/<your-username>/quiz-app.git
cd quiz-app
make
./quiz
```

Or build manually without `make`:

```bash
gcc -Wall -Wextra -std=c11 -o quiz main.c quiz.c quiz_data.c
./quiz
```

To clean build artifacts:

```bash
make clean
```

## Sample Run

```
=====================================
           C QUIZ APPLICATION
=====================================
Answer each question by typing A, B, C, or D.

Question 1/10: Which data structure uses LIFO (Last In First Out)?
  A) Queue
  B) Stack
  C) Linked List
  D) Tree
Your answer: B
Correct!

...

=====================================
              QUIZ RESULTS
=====================================
Score      : 8 / 10
Percentage : 80.00%
Grade      : B
Great job! Solid understanding.
=====================================
```

## Adding Your Own Questions

Open `quiz_data.c` and add a new entry to the `bank[]` array inside
`load_questions()`:

```c
{
    "Your question text here?",
    { "Option A", "Option B", "Option C", "Option D" },
    'B'   /* correct answer letter */
},
```

`MAX_QUESTIONS` (in `quiz.h`) caps the total number of questions the array
in `main()` can hold — raise it if you add more than 50 questions.

## Why This Project

Built as a foundational piece of educational software, and as a practical
exercise applying core C concepts (loops, conditionals, functions, structs)
to a small but complete, working program.

## License

MIT — see [LICENSE](LICENSE).
