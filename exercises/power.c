#include <stdio.h>

int power(int, int);

int main(void) {
    for (int i = 0; i < 10; ++i)
        printf("%d %d %d", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int exp) {
    int result = 1;

    for (int i = result; i <= exp; ++i)
        result *= base;

    return result;
}