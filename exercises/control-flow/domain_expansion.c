/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-3. Write a function expand(s1,s2) that
 * expands shorthand notations like a-z in the string
 * s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be
 * prepared to handle cases like a-b-c and a-z0−9 and
 * -a-z. Arrange that a leading or trailing - is taken
 *  literally.*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {
  // Indices
  int i = 0; // for input
  int j = 0; // for output
  int c;

  // Process input string
  while ((c = s1[i]) != '\0') {
    // Range pattern check
    if (s1[i + 1] == '-' && s1[i + 2] != '\0') {
      // Pattern validation: must be alphanumeric and same type
      if ((isalnum(c) && isalnum(s1[i + 2])) &&
          ((islower(c) && islower(s1[i + 2])) ||
           (isupper(c) && isupper(s1[i + 2])) ||
           (isdigit(c) && isdigit(s1[i + 2])))) {

        // Only expand if range is ascending
        if (c <= s1[i + 2]) {
          while (c <= s1[i + 2])
            s2[j++] = c++;
          // Skip range pattern
          i += 3;
        } else {
          // Invalid order
          s2[j++] = s1[i++];
        }
      } else {
        // Invalid pattern
        s2[j++] = s1[i++];
      }
    } else {
      // Ain't no pattern found
      s2[j++] = s1[i++];
    }
  }
  // end scene
  s2[j] = '\0';
}
