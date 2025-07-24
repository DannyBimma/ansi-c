/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-4: Modify the temperature program to
 print a heading above the table. ✅
 */

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20
#define CALCULATION (celcius * 9.0 / 5.0) + 32.0

int main(void) {
  float fahr, celcius;
  int lower, upper, step;

  celcius = LOWER;

  // Output heading
  printf("CELSIUS TO FAHR TABLE\n");
  printf("\n");

  while (celcius <= UPPER) {
    fahr = CALCULATION;

    printf("%3.0f\t%6.1f\n", celcius, fahr);

    celcius += STEP;
  }

  return 0;
}
