/*
 * Routine: A program that prints a histogram of the length of words in
 *          its input.
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
    int wc = 0;
    int state = OUT;

    // Count the number of words in input
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++wc;
        }
    }
    printf("%d", wc);
}
