#include <stdio.h>

int main(void) {
    int n_white = 0, n_other = 0;
    int n_digit[10];
    int c;

    for (int i = 0; i < 10; i++)
        n_digit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c <= 9)
            ++n_digit[c-'0'];
        else if (c == '' || c == '\n' || c == '\t')
            ++n_white;
        else
            ++n_other;
    }
}