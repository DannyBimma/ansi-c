/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-3: Modify the temperature program to
 print a heading above the table. ✅
 */

#include <stdio.h>

int main(void) {
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  // Output heading
  printf("FAHRENHEIT TO CELSIUS TABLE\n");
  printf("\n");

  while (fahr <= upper) {
    celcius = (5.0 / 9.0) * (fahr - 32.0);

    printf("%3.0f\t%6.1f\n", fahr, celcius);

    fahr = fahr + step;
  }

  return 0;
}
