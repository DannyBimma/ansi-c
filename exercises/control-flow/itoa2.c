/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Write a version of itoa that accepts three arguments
 * instead of two. The third argument is a minimum
 * field width; the converted number must be padded with
 * blanks on the left if necessary to make it wide enough.*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

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

  printf("Testing itoa function with field width:\n");
  printf("---------------------------------------\n");

  itoa(69, buffer, 3);
  printf("'%s' (69 with width 3)\n", buffer);

  itoa(420, buffer, 3);
  printf("'%s' (420 with width 3)\n", buffer);

  itoa(100, buffer, 1);
  printf("'%s' (100 with width 1)\n", buffer);

  itoa(-444, buffer, 10);
  printf("'%s' (-444 with width 10)\n", buffer);

  itoa(-666, buffer, 4);
  printf("'%s' (-666 with width 4)\n", buffer);

  itoa(0, buffer, 5);
  printf("'%s' (0 with width 5)\n", buffer);

  itoa(747, buffer, 0);
  printf("'%s' (747 with width 0)\n", buffer);

  return 0;
}
