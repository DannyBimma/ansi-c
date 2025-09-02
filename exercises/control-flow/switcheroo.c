/*Copyright (c) 2025 Author DannyBimma. All Rights Reserved.
 * Write a function escape(s,t) that converts characters like
 * newline and tab into visible escape sequences like \n and
 * \t as it copies the string t to s. Use a switch. Write a
 * function for the other direction as well, converting escape
 * sequences into the real characters test tests.*/

#include <stdio.h>

void escape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\r':
      s[j++] = '\\';
      s[j++] = 'r';
      break;
    case '\b':
      s[j++] = '\\';
      s[j++] = 'b';
      break;
    case '\f':
      s[j++] = '\\';
      s[j++] = 'f';
      break;
    case '\\':
      s[j++] = '\\';
      s[j++] = '\\';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j] = '\0';
}

void capture(char s[], char t[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++) {
    if (t[i] == '\\' && t[i + 1] != '\0') {
      switch (t[++i]) {
      case 'n':
        s[j++] = '\n';
        break;
      case 't':
        s[j++] = '\t';
        break;
      case 'r':
        s[j++] = '\r';
        break;
      case 'b':
        s[j++] = '\b';
        break;
      case 'f':
        s[j++] = '\f';
        break;
      case '\\':
        s[j++] = '\\';
        break;
      default:
        s[j++] = '\\';
        s[j++] = t[i];
        break;
      }
    } else {
      s[j++] = t[i];
    }
  }
  s[j] = '\0';
}

int main(void) {
  char original[] = "Hello\tWorld\nThis is a test\rWith backslash\\";
  char escaped[200];
  char unescaped[200];

  printf("Original string: ");
  printf("%s", original);
  printf("\n\n");

  escape(escaped, original);
  printf("After escape(): %s\n\n", escaped);

  capture(unescaped, escaped);
  printf("After capture(): ");
  printf("%s", unescaped);
  printf("\n\n");

  char test_escape[] = "Line 1\\nLine 2\\tTabbed\\rCarriage return";
  char test_result[200];

  printf("Test escape sequence: %s\n", test_escape);
  capture(test_result, test_escape);
  printf("After capture(): ");
  printf("%s", test_result);
  printf("\n");

  return 0;
}
