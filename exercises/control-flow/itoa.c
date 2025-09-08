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
