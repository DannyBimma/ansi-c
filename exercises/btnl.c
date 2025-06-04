#include <stdio.h>

/*A program that tabulates blank-spaces, tabs, and new-lines*/

int main(void) {
    int c;
    int blank_count = 0;
    int tab_count = 0;
    int line_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blank_count;

        if (c == '\t')
            ++tab_count;

        if (c == '\n')
            ++line_count;
    }

    // printf formatting like a pro 😎
    printf("The file contains:\n %d blanks\n %d tabs\n %d new-lines\n", blank_count, tab_count, line_count);

    return 0;

}