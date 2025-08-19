/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-4:
 * An alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in
 * the string s2*/

#include <stdio.h>

// Helper func to find chars in a string
int c_in_s(char c, char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return 1;
  }

  return 0;
}

// Refactored squeeze (of deez nuts 🤭)
void squeeze(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!c_in_s(s1[i], s2))
      s1[j++] = s1[i];
  }

  s1[j] = '\0';
}
