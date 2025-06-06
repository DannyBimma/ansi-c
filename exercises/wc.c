#include <stdio.h>

int main(void) {
    // Count chars, words, sentences, and lines from stream
    int chars, words, sentences, lines = 0;

    for (int c_lit = getchar(); c_lit != EOF; ++chars) {
        if (c_lit == ' ')
            ++words;

        if (c_lit == '.' || c_lit == '?' || c_lit == '!')
            ++sentences;

        if (c_lit == '\n')
            ++lines;
    }

    printf("Text stream contains:\n%d characters\n %d words\n %d lines\n\n", chars, words, lines);
}