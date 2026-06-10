/*
 * Routine: A Celsius to Fahrenheit temperature conversion table: from 0 to 220.
 *          From Section 1.2 of K&R, rewritten to use a function for conversion.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

// Prototype
float converter(float cel);

int main(void) {
    float fahrenheit, celsius;
    int lower_temp, upper_temp, increment;

    lower_temp = 0;
    upper_temp = 420;
    increment = 10;

    celsius = lower_temp;

    printf("\n");
    printf("++=== THE ULTIMATE TEMPERATURE CONVERSION TABLE V2 ===++");
    printf("\n");

    while (celsius <= upper_temp) {
        fahrenheit = converter(celsius);
        printf("%3.0f C  %6.1f F\n", celsius, fahrenheit);

        celsius = celsius + increment;
    }

    return 0;
}

float converter(float cel) { return (9.0 / 5.0) * cel + 32.0; }
