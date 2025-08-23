/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-5. Write the function any(s1,s2), which
 * returns the first location in the string s1 where
 * any character from the string s2 occurs, or −1 if
 * s1 contains no characters from s2.
 * (The standard library function strpbrk does the same
 * job but returns a pointer to the location.)
 */

#include <stdio.h>

// Macros to test and set bits in bitmap
#define SET_BIT(bitmap, c) ((bitmap)[(c) / 32] |= (1u << ((c) % 32)))
#define TEST_BIT(bitmap, c) ((bitmap)[(c) / 32] & (1u << ((c) % 32)))

int any(const char s1[], const char s2[]);

int main(void) {
  // Test case 1: match found
  printf("Test 1: any(\"hello world\", \"aeiou\")\n");
  printf("Result: %d (should be 1 - first vowel 'e')\n\n",
         any("hello world", "aeiou"));

  // Test case 2: no match found
  printf("Test 2: any(\"bcdfg\", \"aeiou\")\n");
  printf("Result: %d (should be -1 - no vowels)\n\n", any("bcdfg", "aeiou"));

  //* Test case 3: match at beginning
  printf("Test 3: any(\"apple\", \"xyz\")\n");
  printf("Result: %d (should be -1 - no x, y, or z)\n\n", any("apple", "xyz"));

  // Test case 4: empty s2 string
  printf("Test 4: any(\"hello\", \"\")\n");
  printf("Result: %d (should be -1 - empty search string)\n\n",
         any("hello", ""));

  return 0;
}

int any(const char s1[], const char s2[]) {
  unsigned char c_bitmap[32] = {0};

  // First loop: set bits for chars present in s2
  for (int i = 0; s2[i] != '\0'; i++)
    SET_BIT(c_bitmap, (unsigned char)s2[i]);

  // Second loop: check if any char from s1 has its bit set
  for (int i = 0; s1[i] != '\0'; i++)
    if (TEST_BIT(c_bitmap, (unsigned char)s1[i]))
      // Bit test = true
      return 1;

  // Bit test = false
  return -1;
}
