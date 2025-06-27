#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
int getline(char line[], int maxline);

// White Book C: Exercise 1-19
int main() {
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0) {
    reverse(line);

    printf("%s", line);
  }

  return 0;
}

void reverse(char s[]) {
  int i, j;
  char temp;

  i = 0;
  while (s[i] != '\0')
    ++i;

  if (s[i - 1] == '\n')
    --i;

  j = 0;

  --i;

  while (j < i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    ++j;
    --i;
  }
}

int getline(char s[], int lim) {
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