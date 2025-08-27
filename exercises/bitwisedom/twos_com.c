/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 *
 * Exercise 2-9: Make bitcount based by using x &= (x-1)
 *
 * In a two's complement machine, x &= (x-1) deletes the rightmost 1-bit in x.
 * The reason for this:
 *
 * 1. When 1 is subtracted from x, all trailing 0s become 1s, and the rightmost
 *    1-bit becomes 0... like so:
 *    x     = 1100 (binary)
 *    x-1   = 1011 (binary)
 *
 * 2. When x is ANDed with (x-1), the rightmost 1-bit in x becomes 0 because
 *    it's ANDed with 0 from (x-1), I know that sounds fucking stupid, but
 *    just trust and believe that all bits to the right remain 0:
 *    x     = 1100
 *    x-1   = 1011
 *    x&(x-1) = 1000
 *
 * So with all that, I can count only the 1-bits directly, so that the loop
 * executes only as many times as there are 1-bits, rather than examining every
 * little bit.*/

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x - 1))
    b++;

  return b;
}
