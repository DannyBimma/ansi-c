/*
 * Routine: A Celsius to Fahrenheit temperature conversion table: from 0 to 220
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
  float fahrenheit, celsius;
  int lower_temp, upper_temp, increment;

  lower_temp = 0;
  upper_temp = 420;
  increment = 10;

  celsius = lower_temp;

  printf("\n");
  printf("++=== THE ULTIMATE TEMPERATURE CONVERSION TABLE ===++");
  printf("\n");

  while (celsius <= upper_temp) {
    fahrenheit = (9.0 / 5.0) * celsius + 32.0;

    printf("%3.0f °C %6.1f °F\n", celsius, fahrenheit);

    celsius = celsius + increment;
  }
}
