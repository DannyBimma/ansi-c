#include <stdio.h>

int main(void) {

    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c == '\t')
            printf("\\t\n");

        if (c == '\b')
            printf("\\b\n");

        if (c == '\\')
            printf("\\\n");
    }

    return 0;
}