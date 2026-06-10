/*A that raises an integer to the power of another integer*/

#include <stdio.h>

// Prototype
int power(int base, int exp);

int main(void) {
    for (int i = 0; i < 10; ++i)
        printf("%d %d %d", i, power(2, i), power(-3, i));

    putchar('\n');

    return 0;
}

int power(int base, int exp) {
    int res = 1;

    for (int i = 1; i <= exp; ++i)
        res *= base;

    return res;
}
