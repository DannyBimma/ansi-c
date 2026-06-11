/*
 * Routine: A revision of the "longest line" program to correctly print the
 *          length of arbitrarily long input lines, and as much as possible
 *          of the text.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>
#define MAX 1000

// Prototypes
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len;
    int max = 0;
    char line[MAX];
    char longest[MAX];

    while ((len = get_line(line, MAX)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Length: %d\n", max); // True arbitrary length, even if > MAX
        printf("Longest line: %s\n",
               longest); // As much text as buffer holds
    }

    return 0;
}
