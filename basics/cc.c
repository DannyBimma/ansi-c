/*
 A program that counts the number of occurrences of each digit,
 of white space characters (blanks, tabs, newline), and of all
 other characters. Theses counts will be stored in an array because
 K&R said it's more convenient that way innit!?
 */

#include <stdio.h>

int main(void) {
    int ch;
    int i;
    int nwhite = 0;
    int nother = 0;
    int ndigit[10];

    for (int i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((ch = getchar()) != EOF) {
        // check if the current char is a digit
        if (ch >= '0' && ch <= '9')
            // convert the char code back into it's numerical value, and
            // increment count
            ++ndigit[ch - '0'];
        else if (ch == ' ' || ch == '\n' || ch == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits=");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
