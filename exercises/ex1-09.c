/*
 * Routine: A program that copies its input to its output, replacing
 *          each string of one or more blanks by a single blank.
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
    int ch;
    int prev_ch = EOF;

    while ((ch = getchar()) != EOF) {
        // If the current char OR previous char is NOT a blank, then print it
        if (ch != ' ' || prev_ch != ' ')
            putchar(ch);

        prev_ch = ch;
    }

    return 0;
}
