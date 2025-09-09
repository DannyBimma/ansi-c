/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-5. Write the function itob(n,s,b) that converts
 * the integer n into a base b character representation in the
 * string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s.*/

#include <stdio.h>
#include <string.h>

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
