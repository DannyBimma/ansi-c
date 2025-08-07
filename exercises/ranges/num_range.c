/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 *
 * Exercise 2-1:
 *
 * A program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing
 * appropriate values from standard headers and by direct
 * computation.*/

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  printf("=== RANGES FROM STANDARD HEADERS ===\n\n");

  printf("char:\n");
  printf("  CHAR_MIN = %d\n", CHAR_MIN);
  printf("  CHAR_MAX = %d\n", CHAR_MAX);
  printf("  UCHAR_MAX = %u\n", UCHAR_MAX);

  printf("\nshort:\n");
  printf("  SHRT_MIN = %d\n", SHRT_MIN);
  printf("  SHRT_MAX = %d\n", SHRT_MAX);
  printf("  USHRT_MAX = %u\n", USHRT_MAX);

  printf("\nint:\n");
  printf("  INT_MIN = %d\n", INT_MIN);
  printf("  INT_MAX = %d\n", INT_MAX);
  printf("  UINT_MAX = %u\n", UINT_MAX);

  printf("\nlong:\n");
  printf("  LONG_MIN = %ld\n", LONG_MIN);
  printf("  LONG_MAX = %ld\n", LONG_MAX);
  printf("  ULONG_MAX = %lu\n", ULONG_MAX);

  printf("\nfloat:\n");
  printf("  FLT_MIN = %e\n", FLT_MIN);
  printf("  FLT_MAX = %e\n", FLT_MAX);
  printf("  FLT_EPSILON = %e\n", FLT_EPSILON);

  printf("\ndouble:\n");
  printf("  DBL_MIN = %e\n", DBL_MIN);
  printf("  DBL_MAX = %e\n", DBL_MAX);
  printf("  DBL_EPSILON = %e\n", DBL_EPSILON);

  printf("\nlong double:\n");
  printf("  LDBL_MIN = %Le\n", LDBL_MIN);
  printf("  LDBL_MAX = %Le\n", LDBL_MAX);
  printf("  LDBL_EPSILON = %Le\n", LDBL_EPSILON);

  // Direct floating-point computations
  printf("\n\n=== RANGES BY DIRECT COMPUTATION ===\n\n");

  printf("Signed char:\n");
  signed char sc = 1;
  while (sc > 0) {
    sc <<= 1;
  }
  printf("  Min: %d\n", sc);
  printf("  Max: %d\n", -(sc + 1));

  printf("\nUnsigned char:\n");
  unsigned char uc = ~0;
  printf("  Min: 0\n");
  printf("  Max: %u\n", uc);

  printf("\nSigned short:\n");
  signed short ss = 1;
  while (ss > 0) {
    ss <<= 1;
  }
  printf("  Min: %d\n", ss);
  printf("  Max: %d\n", -(ss + 1));

  printf("\nUnsigned short:\n");
  unsigned short us = ~0;
  printf("  Min: 0\n");
  printf("  Max: %u\n", us);

  printf("\nSigned int:\n");
  signed int si = 1;
  while (si > 0) {
    si <<= 1;
  }
  printf("  Min: %d\n", si);
  printf("  Max: %d\n", -(si + 1));

  printf("\nUnsigned int:\n");
  unsigned int ui = ~0;
  printf("  Min: 0\n");
  printf("  Max: %u\n", ui);

  printf("\nSigned long:\n");
  signed long sl = 1;
  while (sl > 0) {
    sl <<= 1;
  }
  printf("  Min: %ld\n", sl);
  printf("  Max: %ld\n", -(sl + 1));

  printf("\nUnsigned long:\n");
  unsigned long ul = ~0;
  printf("  Min: 0\n");
  printf("  Max: %lu\n", ul);

  printf("\nFloat ranges (computed):\n");
  float f = 1.0;
  float prev_f = f;
  while (f / 2.0 > 0.0) {
    prev_f = f;
    f /= 2.0;
  }
  printf("  Approximate minimum positive value: %e\n", prev_f);

  f = 1.0;
  prev_f = f;
  while (f * 2.0 < __builtin_inff()) {
    prev_f = f;
    f *= 2.0;
  }
  printf("  Approximate maximum value: %e\n", prev_f);

  return 0;
}
