#include <stdio.h>

int main(void) {
    // Count chars, words, sentences, and lines from stream
    int c;
    int state;
    int lines, words, chars = 0;

    while ((c = getchar()) != EOF) {
        ++chars;

        if (c == '\n')
            ++lines;

        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++words;
        }

    }
    printf("Text stream contains:\n%d characters\n %d words\n %d lines\n\n", chars, words, lines);
}