/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-4: Modify the temperature program to
 print a heading above the table. ✅
 */

#include <stdio.h>

int main(void) {
  float fahr, celcius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celcius = lower;

  // Output heading
  printf("CELSIUS TO FAHR TABLE\n");
  printf("\n");

  while (celcius <= upper) {
    fahr = (celcius * 9.0 / 5.0) + 32.0;

    printf("%3.0f\t%6.1f\n", celcius, fahr);

    celcius = celcius + step;
  }

  return 0;
}
