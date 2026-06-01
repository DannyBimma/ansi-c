/*
 * Routine: Verify that the expression "getchar() != EOF" is 0 or 1.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
    int c = getchar() != EOF;

    printf("The expression \"getchar() != EOF\" is %d.\n", c);
}
