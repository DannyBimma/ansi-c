/*Copyright (c) 2025 ANSI C. All Rights Reserved.
 *Prints Fahrenheit to Celsius table*/

#include <stdio.h>

int main(void) {
  int fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while (fahr <= upper) {
    celcius = 5 * (fahr - 32) / 9;

    printf("%3d\t%6d\n", fahr, celcius);

    fahr = fahr + step;
  }
}
