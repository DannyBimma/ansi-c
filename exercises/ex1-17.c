/*
 * Routine: A program that prints all input lines that are longer than 80
 *          characters.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

#define MAX 1000 // buffer size
#define LONG 80  // minimum length to print

int get_line(char s[], int lim);

int main(void) {
    int len;
    char line[MAX];

    while ((len = get_line(line, MAX)) > 0)
        if (len > LONG)
            printf("%s", line);

    return 0;
}

// Read a line into s and return its length (not including the newline)
int get_line(char s[], int lim) {
    int c;
    int i = 0;
    int len = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < lim - 1)
            s[i++] = c;
        ++len; // count even if not stored
    }
    if (c == '\n') {
        if (i < lim - 1)
            s[i++] = '\n'; // stored if there's but not counted
    }

    s[i] = '\0';

    return len;
}
