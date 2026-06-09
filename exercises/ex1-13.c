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

#define IN 1   // Flag for being inside a word
#define OUT 0  // Flag for being outside a word
#define MAX 26 // Ignore words longer than the entire alphabet

int main(void) {
    int ch;
    int state = OUT;
    int cwl = 0; // Length of current word
    int wl[MAX]; // Frequency array for histogram

    // Zero out histogram array elements to 0
    for (int i = 0; i < MAX; ++i) {
        wl[i] = 0;
    }

    // Get words in input
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (state == IN) {
                // Record word lengths
                if (cwl < MAX) {
                    ++wl[cwl];
                }
                cwl = 0; // Reset for next word
                state = OUT;
            }
        } else {
            state = IN;
            ++cwl;
        }
    }

    // Print histogram
    printf("\n--- Word Length Histogram ---\n");
    for (int i = 1; i < MAX; ++i) {
        // Print label for each bar of stars in histogram
        printf("%2d: ", i);

        // Print a bar of stars (representing how many words had this length)
        for (int j = 0; j < wl[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
