#include <stdio.h>

int main(void) {
    int c;
    int line_count = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++line_count;

    printf("File contains: %d lines\n", line_count);
}