#include <stdio.h>

#define IN 1  // Flag for being inside word
#define OUT 0 // Flag for being outside word

/*Count lines, words, and chars from input file or stream*/
int main(void) {
    int ch;
    int nl = 0;
    int nw = 0;
    int nc = 0;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        ++nc;
        if (ch == '\n')
            ++nl;
        if (ch == ' ' || ch == '\n' || ch == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    putchar('\n');
    printf("Chars = %d\n", nc);
    printf("Words = %d\n", nw);
    printf("Lines = %d\n", nl);

    return 0;
}
