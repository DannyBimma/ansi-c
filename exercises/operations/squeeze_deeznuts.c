/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-4:
 * An alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in
 * the string s2*/

#include <stdio.h>

int c_in_s(char c, char s[]);
void squeeze(char s1[], char s2[]);

int main() {
  // Example 1: Rm vowels from string
  char test1[] = "Hello World Programming";
  char vowels[] = "aeiouAEIOU";

  printf("Original string: \"%s\"\n", test1);
  printf("Characters to remove: \"%s\"\n", vowels);
  squeeze(test1, vowels);
  printf("After squeeze: \"%s\"\n\n", test1);

  // Example 2: Rm digits from string
  char test2[] = "abc123def456ghi";
  char digits[] = "0123456789";

  printf("Original string: \"%s\"\n", test2);
  printf("Characters to remove: \"%s\"\n", digits);
  squeeze(test2, digits);
  printf("After squeeze: \"%s\"\n\n", test2);

  // Example 3: Rm space
  char test3[] = "i Am The Man Who Will Become King Of The Pirate's";
  char chars_to_remove[] = " ";

  printf("Original string: \"%s\"\n", test3);
  printf("Characters to remove: \"%s\"\n", chars_to_remove);
  squeeze(test3, chars_to_remove);
  printf("After squeeze: \"%s\"\n\n", test3);

  return 0;
}

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
