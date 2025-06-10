#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
    // Count: chars, words, statements, and lines
    int chars = 0, words = 0, statements = 0, lines = 0;
    int state;

    for (int c_lit = getchar(); c_lit != EOF; c_lit = getchar()) {
        ++chars;

        if (c_lit == '\n')
            ++lines;

        if (c_lit == '.' || c_lit == '?' || c_lit == '!')
            ++statements;

        if (c_lit == ' ' || c_lit == '\n' || c_lit == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++words;
        }
    }
    printf("Text stream contains:\n%d characters\n %d words\n %d statements\n %d lines\n\n", chars, words, statements, lines);

    return 0;
}