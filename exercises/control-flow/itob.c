/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-5. Write the function itob(n,s,b) that converts
 * the integer n into a base b character representation in the
 * string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s.*/

#include <stdio.h>
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

int main() {
  char buffer[100];

  printf("Testing itob function:\n");
  printf("----------------------\n");

  itob(69, buffer, 16);
  printf("69 in base 16: %s\n", buffer);

  itob(420, buffer, 2);
  printf("420 in base 2:  %s\n", buffer);

  itob(42, buffer, 8);
  printf("42 in base 8:  %s\n", buffer);

  itob(16, buffer, 16);
  printf("16 in base 16: %s\n", buffer);

  itob(-255, buffer, 16);
  printf("-255 in base 16: %s\n", buffer);

  itob(1000, buffer, 7);
  printf("1000 in base 7:   %s\n", buffer);

  itob(0, buffer, 10);
  printf("0 in base 10:    %s\n", buffer);

  return 0;
}
