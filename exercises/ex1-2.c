/*
 * Routine: Experiment to find out what happens when printf's arg string
 * contains \c, where c is an unknown character
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

#include <stdio.h>

int main(void) {
  printf("Hello, world!\c");

  return 0;
}
