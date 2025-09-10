/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-5. Write the function itob(n,s,b) that converts
 * the integer n into a base b character representation in the
 * string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

void itob(int n, char s[], int b) {
  int i, sign, remainder;
  char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    remainder = n % b;
    s[i++] = digits[remainder];
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main(int argc, char *argv[]) {
  char buffer[100];
  int number, base;

  if (argc != 3) {
    printf("Usage: %s <number> <base>\n", argv[0]);
    printf("Example: %s 255 16\n", argv[0]);

    return 1;
  }

  number = atoi(argv[1]);
  base = atoi(argv[2]);

  if (base < 2 || base > 36) {
    printf("Error: Da faq is you trying to do!? Base must be between 2 and 36, "
           "please and thanks\n");

    return 1;
  }

  itob(number, buffer, base);
  printf("%s\n", buffer);

  return 0;
}
