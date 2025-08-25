/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Main program to test bitwise operations functions
 */

#include <stdio.h>
#include <stdlib.h>

// Functions for output test
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void print_binary(unsigned n);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <unsigned_integer>\n", argv[0]);

    return 1;
  }

  unsigned input = (unsigned)atoi(argv[1]);

  printf("Input: %u\n", input);
  printf("Input binary: ");
  print_binary(input);
  printf("\n\n");

  printf("=== INVERT TEST (invert bits 7-4, n=4) ===\n");
  unsigned inverted = invert(input, 7, 4);
  printf("Original: %u, Binary: ", input);
  print_binary(input);
  printf("\n");
  printf("Inverted: %u, Binary: ", inverted);
  print_binary(inverted);
  printf("\n\n");

  printf("=== RIGHT ROTATE TEST (rotate right by 4) ===\n");
  unsigned rotated = rightrot(input, 4);
  printf("Original: %u, Binary: ", input);
  print_binary(input);
  printf("\n");
  printf("Rotated:  %u, Binary: ", rotated);
  print_binary(rotated);
  printf("\n\n");

  printf("=== SETBITS TEST (set bits 7-4 to rightmost 4 bits of 15) ===\n");
  unsigned y = 15;
  unsigned setbits_result = setbits(input, 7, 4, y);
  printf("Original: %u, Binary: ", input);
  print_binary(input);
  printf("\n");
  printf("Y value:  %u, Binary: ", y);
  print_binary(y);
  printf("\n");
  printf("Result:   %u, Binary: ", setbits_result);
  print_binary(setbits_result);
  printf("\n");

  return 0;
}

void print_binary(unsigned n) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
    if (i % 4 == 0 && i != 0)
      printf(" ");
  }
}
