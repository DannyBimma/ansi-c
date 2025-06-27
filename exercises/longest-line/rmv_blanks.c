#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int remove_trailing_blanks(char s[]);

int main(void) {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        len = remove_trailing_blanks(line);

        if (len > 0)
            printf("%s", line);
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

int remove_trailing_blanks(char s[]) {
    int i;

    for (i = 0; s[i] != '\n' && s[i] != '\0'; ++i)
        ;

    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;

    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
        return i;
    } else {
        s[0] = '\0';
        return 0;
    }
}