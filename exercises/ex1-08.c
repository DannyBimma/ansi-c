/*
 * Routine: A program that counts blanks, tabs, and newlines from the
 *          standard input stream (stdin/keyboard) and outputs the total
 *          number of characters to the standard output stream (stdout/screen).
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
    int ch;
    int bl = 0;
    int tb = 0;
    int nl = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ')
            ++bl;

        if (ch == '\t')
            ++tb;

        if (ch == '\n')
            ++nl;
    }

    printf("Blanks = %d\n", bl);
    printf("Tabs = %d\n", tb);
    printf("Newlines = %d\n", nl);

    return 0;
}
