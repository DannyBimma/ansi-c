/*
 * Routine: A program that prints a histogram of the frequencies of
 *          different characters in its input.
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

#define ALL_CHARS 256 // Total num of chars in the ASCII table

int main(void) {
    int ch;
    int cc[ALL_CHARS];

    // Zero out char count array
    for (int i = 0; i < ALL_CHARS; ++i)
        cc[i] = 0;

    // Read from input and increment char ASCII slot in array
    while ((ch = getchar()) != EOF) {
        if (ch >= 0 && ch < ALL_CHARS)
            ++cc[ch];
    }

    // Print histogram of printable chars from input
    printf("\n--- Histogram of Printable ASCII Characters ---\n");
    for (int i = 32; i < 126; ++i) {
        // Only print bars for chars that appeared
        if (cc[i] > 0) {
            // Print label for each bar of stars in histogram
            printf("%c: ", i);
            // Print a bar of stars (how many times this char appeared)
            for (int j = 0; j < cc[i]; ++j)
                putchar('*');

            putchar('\n');
        }
    }

    return 0;
}
