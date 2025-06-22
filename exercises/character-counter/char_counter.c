#include <stdio.h>

int main(void) {
    double count;

    for (count = 0; getchar() != EOF; ++count)
        ; // Null statement

    printf("%.0f\n", count);

    return 0;
}