/*Exercise 1-22: - Write a program to "fold" long lines
 *of input into two or more shorter lines after the last non-blank
 *character that occurs before the n-th column of input. Make sure
 *the program does something intelligent with very long lines, and
 *if there are no blanks before the specified column.*/
#include <stdio.h>

#define MAXLINE 1000
#define FOLD 80

int main() {
  char line[MAXLINE];
  int c, pos, last_blank;

  pos = 0;
  last_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar(c);
      pos = 0;
      last_blank = 0;
    } else if (c == ' ' || c == '\t') {
      line[pos] = c;
      last_blank = pos;
      ++pos;
      if (pos >= FOLD) {
        line[last_blank] = '\0';
        printf("%s\n", line);
        pos = pos - last_blank - 1;
        for (int i = 0; i < pos; ++i) {
          line[i] = line[last_blank + 1 + i];
        }
        last_blank = 0;
      }
    } else {
      line[pos] = c;
      ++pos;
      if (pos >= FOLD) {
        if (last_blank > 0) {
          line[last_blank] = '\0';
          printf("%s\n", line);
          pos = pos - last_blank - 1;
          for (int i = 0; i < pos; ++i) {
            line[i] = line[last_blank + 1 + i];
          }
          last_blank = 0;
        } else {
          line[pos] = '\0';
          printf("%s\n", line);
          pos = 0;
          last_blank = 0;
        }
      }
    }
  }

  if (pos > 0) {
    line[pos] = '\0';
    printf("%s\n", line);
  }

  return 0;
}