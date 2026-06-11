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
