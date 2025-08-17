/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 *
 * Exercise 2-3: Converts hexadecimal strings to integers
 * with the following features:

  - Handles optional "0x" or "0X" prefix
  - Accepts digits 0-9, lower-case a-f, and upper-case A-F
  - Stops processing at invalid characters*/

#include <stdio.h>

int htoi(char s[]);

int main(void) {
  // Hex sex
  printf("01A4 = %d\n", htoi("01A4"));
  printf("0045 = %d\n", htoi("0045"));
  printf("123 = %d\n", htoi("123"));
  printf("ABC = %d\n", htoi("ABC"));
  printf("0xabc = %d\n", htoi("0xabc"));

  return 0;
}

// The magic
int htoi(char s[]) {
  int i = 0;
  int res = 0;
  int digit;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    i = 2;

  while (s[i] != '\0') {
    res <<= 4;

    if (s[i] >= '0' && s[i] <= '9')
      digit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      digit = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      digit = s[i] - 'A' + 10;
    else
      break;

    res |= digit;
    i++;
  }

  return res;
}
