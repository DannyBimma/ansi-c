#include <stdio.h>

int power(int, int);

int main(void) {
    for (int i = 0; i < 10; ++i)
        printf("%d %d %d", i, power(2, i), power(-3, i));

    return 0;
}