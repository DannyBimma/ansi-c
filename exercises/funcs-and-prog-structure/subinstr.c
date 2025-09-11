/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Write the function strrindex(s,t), which returns the
 * position of the rightmost occurrence of t in s, or
 * −1 if there is none.*/

#include <stdio.h>
#include <string.h>

int strrin(char s[], char t[]) {
  int i, j, k;
  int final_pos = -1; // Nothing found
  int slen = strlen(s);
  int tlen = strlen(t);

  // Validate substring
  if (tlen > slen)
    return final_pos;

  for (i = 0; i <= slen - tlen; i++) {
    // Check if pattern matches at position i
    for (j = i, k = 0; k < tlen && s[j] == t[k]; j++, k++)
      ;

    if (k == tlen)
      final_pos = i;
  }

  return final_pos;
}

int main(int argc, char *argv[]) {
  int result;

  if (argc != 3) {
    printf("Usage: %s <string> <pattern>\n", argv[0]);
    printf("Example: %s \"hello world hello\" \"hello\"\n", argv[0]);

    return 1;
  }

  result = strrin(argv[1], argv[2]);

  if (result == -1) {
    printf("Pattern \"%s\" not found in \"%s\"\n", argv[2], argv[1]);
  } else {
    printf("Rightmost occurrence of \"%s\" in \"%s\": Index %d\n", argv[2],
           argv[1], result);
  }

  return 0;
}
