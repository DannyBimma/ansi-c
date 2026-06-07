/*
 * Routine: A program that prints its input to stdout one word per line.
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

#define IN 1  // Flag for being inside word
#define OUT 0 // Flag for being outside word

int main(void) {
    int ch;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            state = IN;
            putchar(ch);
        } else
            state = OUT;

        if (state == OUT)
            putchar('\n');
    }

    return 0;
}
