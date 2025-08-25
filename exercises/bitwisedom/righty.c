/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-8: Write a function rightrot(x,n) that
 * returns the value of the integer x rotated to the
 * right by n bit positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
  int word_length = sizeof(unsigned) * 8;
  n = n % word_length;

  return (x >> n) | (x << (word_length - n));
}
