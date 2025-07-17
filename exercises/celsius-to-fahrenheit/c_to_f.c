/*Copyright (c) 2025 DannyBimma. All Rights Reserved.*/

#include <stdio.h>

void celsius_to_fahrenheit(float celsius, float *fahrenheit);

int main(void) {
  float c;
  float f;
  float lowerBound = 0;
  float upperBound = 300;

  // Temp output heading
  printf("CELSIUS TO FAHRENHEIT TABLE\n");
  printf("\n");

  for (c = lowerBound; c <= upperBound; c += 5)
    celsius_to_fahrenheit(c, &f);

  return 0;
}

void celsius_to_fahrenheit(float celsius, float *fahrenheit) {
  *fahrenheit = (celsius * 9.0 / 5.0) + 32;

  printf("%3.0f c\t=\t%6.1f f\n", celsius, *fahrenheit);
}
