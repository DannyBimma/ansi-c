/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-10: - Rewrite the function lower, which
 * converts upper case letters to lower case, with a
 * conditional expression instead of if-else*/

#include <stdio.h>

int lower(int c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }

int main() {
  printf("Testing lower function:\n");
  printf("'A' -> '%c'\n", lower('A'));
  printf("'Z' -> '%c'\n", lower('Z'));
  printf("'M' -> '%c'\n", lower('M'));
  printf("'a' -> '%c'\n", lower('a'));
  printf("'z' -> '%c'\n", lower('z'));
  printf("'5' -> '%c'\n", lower('5'));
  printf("'@' -> '%c'\n", lower('@'));

  return 0;
}
