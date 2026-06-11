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

/*
 * get_line: read a line into s[] and return TRUE length.
 *
 * i   — index into s[]; only advances while the buffer has room
 * len — counts every character read even if they don't fit
 *
 * While loop keeps consuming input until '\n' or EOF even after
 * the buffer is full. This clears the input stream so the next
 * call starts cleanly on next line.
 */
int get_line(char s[], int lim) {
    int c;
    int i = 0;   // chars stored in buffer
    int len = 0; // true character count

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < lim - 1) // store char if room left
            s[i++] = c;
        ++len; // keeping counting regardless of buffer overflow
    }
    if (c == '\n') {
        if (i < lim - 1) // store '\n' if there's room left
            s[i++] = '\n';
        ++len;
    }

    s[i] = '\0';

    return len;
}
