/*
 * Routine: A highly complex computer program, designed to run on all major
 * operating systems, that outputs the legendary phrase "Hello, world." to the
 * terminal with a processed new line.
 *
 * Author: DannyBimma
 *
 * Copyright (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 *
 */

// Link the entire C standard library, just so you can use one single function
// defined in it
#include <stdio.h>

// Define the function that will be the main entry point to this program
int main(void) {
  // call from main: a standard library function that will output the console,
  // the sequence of chars passed to it as an argument
  printf("Hello, world!\n");

  // Return exit code 0 from main to indicate great success 👍🏾
  return 0;
}
