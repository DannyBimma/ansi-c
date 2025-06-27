#include <stdio.h>
#include <stdint.h>

#define MAXLINE 6666
#define MINLENGTH 80

int get_line(char s[], int lim);

int main(void) {
  int current_line_len;
  char current_line[MAXLINE];

  while ((current_line_len = get_line(current_line, MAXLINE)) > 0) {
    if (current_line_len > MINLENGTH) {
      printf("%s", current_line);

      if (current_line_len >= MAXLINE) {
        printf("... (line truncated)\n");
      } else if (current_line[current_line_len - 1] != '\n') {
        printf("\n");
      }
    }
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  // Read truncated lines
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