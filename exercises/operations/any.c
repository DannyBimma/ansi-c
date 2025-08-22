/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 2-5. Write the function any(s1,s2), which
 * returns the first location in the string s1 where
 * any character from the string s2 occurs, or −1 if
 * s1 contains no characters from s2.
 * (The standard library function strpbrk does the same
 * job but returns a pointer to the location.)
 */

#include <stdio.h>

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
  printf("Test 5: any(\"hello\", \"\")\n");
  printf("Result: %d (should be -1 - empty search string)\n\n",
         any("hello", ""));

  return 0;
}

int any(const char s1[], const char s2[]) { unsigned char c_bitmap[32] = {0}; }
