/*
 * Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 4-2:
 * Extend atof to handle scientific notation of the form 123.45e-6
 * where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

#include <ctype.h>
#include <stdio.h>

static double pow10_int(int n) {
  // Raise 10 to the power of n using exponentiation by squaring
  double result = 1.0;
  double base = 10.0;
  int exp = n;

  if (exp < 0)
    exp = -exp;

  // Check if exp is odd, multiply by current base, and bitwise divide
  while (exp > 0) {
    if (exp & 1)
      result *= base;

    base *= base;
    exp >>= 1;
  }

  return (n < 0) ? 1.0 / result : result;
}

double my_atof(const char s[]) {
  const unsigned char *p = (const unsigned char *)s;
  int sign = 1;
  double val = 0.0;
  double power = 1.0;

  // Skip leading white space
  while (*p && isspace(*p))
    p++;

  // Optional sign
  if (*p == '+' || *p == '-') {
    if (*p == '-')
      sign = -1;

    p++;
  }

  // Integer part
  while (*p && isdigit(*p)) {
    val = 10.0 * val + (*p - '0');
    p++;
  }

  // Fractional part
  if (*p == '.') {
    p++;
    while (*p && isdigit(*p)) {
      val = 10.0 * val + (*p - '0');
      power *= 10.0;
      p++;
    }
  }

  // Build the base value
  val = sign * (val / power);

  // Optional scientific exponent
  if (*p == 'e' || *p == 'E') {
    int exp_sign = 1;
    int exp_val = 0;

    p++;

    if (*p == '+' || *p == '-') {
      if (*p == '-')
        exp_sign = -1;

      p++;
    }

    // Read exponent digits; if none, treat as no exponent
    if (*p && isdigit(*p)) {
      while (*p && isdigit(*p)) {
        exp_val = 10 * exp_val + (*p - '0');
        p++;
      }

      val *= pow10_int(exp_sign * exp_val);
    }
  }

  return val;
}

int main(int argc, char *argv[]) {
  int i;

  if (argc > 1) {
    for (i = 1; i < argc; ++i) {
      double x = my_atof(argv[i]);
      printf("input: %-16s -> %.10g\n", argv[i], x);
    }
    return 0;
  }

  // If no args, read from stdin
  {
    char buf[256];
    while (fgets(buf, sizeof buf, stdin) != 0) {
      double x = my_atof(buf);
      printf("input: %-16s -> %.10g\n", buf, x);
    }
  }

  return 0;
}
