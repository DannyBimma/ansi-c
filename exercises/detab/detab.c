/*Exercise 1-20: - Write a program in C (detab.c) that
 *replaces tabs in the input with the proper number of
 *blanks to space to the next tab stop. Assume a fixed
 *set of tab stops, every n columns.*/
#include <stdio.h>

#define TABSIZE 8

int main() {
  int c, pos, spaces;

  pos = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      spaces = TABSIZE - (pos % TABSIZE);
      while (spaces > 0) {
        putchar(' ');
        ++pos;
        --spaces;
      }
    } else if (c == '\n') {
      putchar(c);
      pos = 0;
    } else {
      putchar(c);
      ++pos;
    }
  }

  return 0;
}