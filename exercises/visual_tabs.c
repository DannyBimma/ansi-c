#include <stdio.h>

int main(void) {
    int c;

    for (c = getchar(); c != EOF; c = getchar()) {
        if (c == '\t') {
            c = "\t";
            printf("%d", c);
        }
    }
    return 0;
    
}