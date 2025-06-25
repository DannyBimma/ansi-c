#include <stdio.h>
#include <stdint.h>

#define MAXLINE 6666

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
  }

  if (current_max > 0) {
    printf("Length: %d\n", current_max);
    printf("Text: %s", longest_line);

    if (current_max >= MAXLINE) {
      printf("... (line truncated)\n");
    } else {
      printf("\n");
    }
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  // Push the limits. Go beyond, PLUS ULTRA!!
  if (c != '\n' && c != EOF) {
    while ((c = getchar()) != EOF && c != '\n')
      ++i;
  }

  // Only store newline if there's space
  if (c == '\n') {
    if (i < lim - 1) {
      s[i] = c;
    }
    ++i;
  }

  s[(i < lim - 1) ? i : lim - 1] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}