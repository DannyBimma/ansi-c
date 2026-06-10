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
float converter(float fah, float cel);

int main(void) {}

float converter(float fah, float cel) {
    fah = (9.0 / 5.0) * cel + 32.0;

    return fah;
}
