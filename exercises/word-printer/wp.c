/*Copyright (c) 2025 DannyBimma. All Rights Reserved.*/
#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  int chars = 0;
  int state = OUT;
  // Print each word in file on a new line
  for (int c_lit = getchar(); c_lit != EOF; c_lit = getchar(), ++chars) {
    if (c_lit != ' ' && c_lit != '\n' && c_lit != '\t') {
      char c = c_lit;
      printf("%c", c);
    }

    if (c_lit == ' ' || c_lit == '\n' || c_lit == '\t') {
      state = OUT;
      printf("\n");
    } else if (state == OUT)
      state = IN;
  }

  printf("\n");

  return 0;
}
