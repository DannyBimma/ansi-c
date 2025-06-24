#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main(void) {
    int current_line_len;
    int current_max = 0;
    char current_line[MAXLINE];
    char longest_line[MAXLINE];
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