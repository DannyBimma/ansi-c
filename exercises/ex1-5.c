/*
 * Routine: Modify the temperature conversion program to print the table in
 * reverse order, that is, from 300 degrees to 0.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
  int fahrenheit;

  // The associated example in the book used a for loop, so I did too
  for (fahrenheit = 300; fahrenheit >= 0; fahrenheit -= 20)
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
