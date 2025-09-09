/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Write a version of itoa that accepts three arguments
 * instead of two. The third argument is a minimum
 * field width; the converted number must be padded with
 * blanks on the left if necessary to make it wide enough.*/

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int width) {
  int i, sign, len, padding;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  len = i;

  if (len < width) {
    padding = width - len;

    for (int j = 0; j < padding; j++)
      s[i++] = ' ';
  }

  s[i] = '\0';

  reverse(s);
}
