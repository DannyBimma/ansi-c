/*
 * Routine: A program that counts the lines from stdin (the keyboard)
 *          and outputs the total number of newline characters to
 *          stdout (the screen).
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
    int ch;
    int ln = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n')
            ++ln;
    }

    printf("%d\n", ln);

    return 0;
}
