/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-4. In a two’s complement number representation,
 * our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to −(2wordsize−1). Explain why not.
 * Modify it to print that value correctly, regardless of the machine
 * on which it runs.*/

/*
 * The original itoa function fails for the largest negative number in two's
 * complement representation (INT_MIN = -2^(wordsize-1)) because when we try
 * to make it positive with n = -n, the result overflows. In two's complement,
 * the range goes from -2^(wordsize-1) to 2^(wordsize-1) - 1. The absolute value
 * of INT_MIN (2^(wordsize-1)) cannot be represented as a positive integer in
 * the same word size, causing undefined behaviour.
 *
 * My solution fix is to NOT negate n at all. Instead, I'll extract digits by
 * taking the absolute value of (n % 10) for each digit, which works correctly
 * even for INT_MIN. Then continue until n becomes 0, handling the sign
 * separately.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]) {
  int i, j;
  char c;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[]) {
  int i, sign;
  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while (n /= 10);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

int main() {
  char buffer[20];

  printf("Testing itoa function:\n\n");

  // Test regular positive number
  itoa(42069, buffer);
  printf("42069 -> \"%s\"\n", buffer);

  // Test regular negative number
  itoa(-69420, buffer);
  printf("-69420 -> \"%s\"\n", buffer);

  // Test zero
  itoa(0, buffer);
  printf("0 -> \"%s\"\n", buffer);

  // Test INT_MAX
  itoa(INT_MAX, buffer);
  printf("INT_MAX (%d) -> \"%s\"\n", INT_MAX, buffer);

  // Test INT_MIN (the problematic case)
  itoa(INT_MIN, buffer);
  printf("INT_MIN (%d) -> \"%s\"\n", INT_MIN, buffer);

  return 0;
}
