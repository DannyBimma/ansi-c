#include <stdio.h>

#define IN 1
#define OUT 0


int main(void) {
    int chars = 0;
    int state = OUT;

    for (int c_lit = getchar(); c_lit != EOF; c_lit = getchar(), ++chars) {

        if (c_lit != ' ' && c_lit != '\n' && c_lit != '\t') {
            char c = c_lit;
            printf("%c", c);
            printf("\n");
        }

        if (c_lit == ' ' || c_lit == '\n' || c_lit == '\t')
            state = OUT;
        else if (state == OUT)
            state = IN;
    }
}