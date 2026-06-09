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
    for (int i = 0; i < ALL_CHARS; ++i) {
        cc[i] = 0;
    }

    // Read from input and increment char ASCII slot in array
    while ((ch = getchar()) != EOF) {
        if (ch >= 0 && ch < ALL_CHARS)
            ++cc[ch];
    }
}
