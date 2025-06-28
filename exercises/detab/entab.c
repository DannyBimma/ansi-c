/*Exercise 1-21: - Write a program in C (entab.c) that
 *replaces strings of blanks with the minimum number of
 *tabs and blanks to achieve the same spacing. Use the
 *same tab stops as for detab.c*/
#include <stdio.h>

#define TABSIZE 8

int main() {
  int c, pos, spaces, tabs;

  pos = 0;
  spaces = 0;
  tabs = 0;

  // The mother of all while-loops
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (pos % TABSIZE != 0) {
        ++spaces;
      } else {
        spaces = 0;
        ++tabs;
      }
    } else {
      for (; tabs > 0; --tabs) {
        putchar('\t');
      }
      if (c == '\t') {
        spaces = 0;
      } else {
        for (; spaces > 0; --spaces) {
          putchar(' ');
        }
      }
      putchar(c);
      if (c == '\n') {
        pos = 0;
      } else if (c == '\t') {
        pos = pos + (TABSIZE - (pos % TABSIZE));
      } else {
        ++pos;
      }
    }
    if (c == ' ') {
      ++pos;
    }
  }

  return 0;
}