#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main(void) {
    int current_line_len;
    int current_max = 0;
    char current_line[MAXLINE];
    char longest_line[MAXLINE];

    while ((current_line_len = get_line(current_line, MAXLINE)) > 0) {
        if (current_line_len > current_max) {
            current_max = current_line_len;
            copy(longest_line, current_line);
        }

        if (current_max > 0)
            printf("%s", longest_line);
    }

    return 0;
}

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

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}