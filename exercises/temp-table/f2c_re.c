/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-5: Print the temp conversion in
 reverse order. ✅
 */

#define UPPER 300
#define LOWER 0
#define STEP 20
#define CALCULATION (5.0 / 9.0) * (fahr - 32))

#include <stdio.h>

int main(void) {
  int fahr;

  // Output heading
  printf("FAHRENHEIT TO CELSIUS TABLE\n");
  printf("\n");

  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d %6.1f\n", fahr, CALCULATION;
  }

  return 0;
}
