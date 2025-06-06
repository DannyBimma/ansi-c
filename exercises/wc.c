#include <stdio.h>

int main(void) {
    // Count: chars, words, statements, and lines
    int chars, words, statements, lines = 0;

    for (int c_lit = getchar(); c_lit != EOF; c_lit = getchar(), ++chars) {
        if (c_lit == ' ')
            ++words;

        if (c_lit == '.' || c_lit == '?' || c_lit == '!')
            ++statements;

        if (c_lit == '\n')
            ++lines;
    }

    printf("Text stream contains:\n%d characters\n %d words\n %d statements\n %d lines\n\n", chars, words - 1, statements, lines);

    return 0;
}