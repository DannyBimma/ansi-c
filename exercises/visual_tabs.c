#include <stdio.h>

int main(void) {
    int c;

    for (c = getchar(); c != EOF; c = getchar()) {
        if (c == '\t')
            printf("\\t\n");

        if (c == '\b')
            printf("\\b\n");

        if (c == '\\')
            printf("\\\n");
    }

    return 0;
}