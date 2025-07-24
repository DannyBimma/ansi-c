/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-3: Modify the temperature program to
 print a heading above the table. ✅
 */

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20
#define CALCULATION (5.0 / 9.0) * (fahr - 32.0)

int main(void) {
  float fahr, celcius;

  fahr = LOWER;

  // Output heading
  printf("FAHRENHEIT TO CELSIUS TABLE\n");
  printf("\n");

  while (fahr <= UPPER) {
    celcius = CALCULATION;

    printf("%3.0f\t%6.1f\n", fahr, celcius);

    fahr += STEP;
  }

  return 0;
}
