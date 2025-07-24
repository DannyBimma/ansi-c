/*Copyright (c) 2025 ANSI C. All Rights Reserved.

 *Prints Fahrenheit to Celsius table

 *Exercise 1-5: Print the temp conversion in
 reverse order. ✅
 */

#include <stdio.h>

int main(void) {
  int fahr;

  // Output heading
  printf("FAHRENHEIT TO CELSIUS TABLE\n");
  printf("\n");

  for (fahr = 300; fahr >= 0; fahr -= 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }

  return 0;
}
