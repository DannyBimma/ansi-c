/*
 * Routine: A program that counts the characters from stdin (the keyboard)
 *          and outputs the total number of characters to stdout (the screen).
 *
 * Author:  DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
    long c = 0;

    while (getchar() != EOF) {
        ++c;
    }

    printf("%ld\n", c);

    return 0;
}
