/*
 * Routine: A Fahrenheit to Celsius temperature conversion table: from 0 to 420
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
  increment = 20;

  fahrenheit = lower_temp;

  printf("\n");
  printf("++=== THE ULTIMATE TEMPERATURE CONVERSION TABLE ===++");
  printf("\n");

  while (fahrenheit <= upper_temp) {
    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);

    printf("%3.0f °F %6.1f °C\n", fahrenheit, celsius);

    fahrenheit = fahrenheit + increment;
  }
}
