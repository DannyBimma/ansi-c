/*A program that tracks the maximum input line size*/

#include <stdio.h>

#define MAX 1000

// Prototypes
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len;           // Current line length
    int max = 0;       // Maximum line length
    char line[MAX];    // Current input line
    char longest[MAX]; // Longest line saved

    while ((len = get_line(line, MAX)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("Longest line: %s\n", longest);

    return 0;
}

// Read a line into s and return its length
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

// Copy "from" into "to" and assume that "to" is big enough
void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
