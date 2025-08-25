/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-8: Write a function rightrot(x,n) that
 * returns the value of the integer x rotated to the
 * right by n bit positions.
 */

#include <stdio.h>

#define WORD_LENGTH (sizeof(unsigned) * 8)

unsigned rightrot(unsigned x, int n) {
  n = n % WORD_LENGTH;

  return (x >> n) | (x << (WORD_LENGTH - n));
}
