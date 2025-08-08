/* Copyright (c) 2025 DannyBimma. All Rights Reserved.
 *
 * Exercise 1-24: - Write a program to check a C program
 * for rudimentary errors like unbalanced parens, brackets,
 * and braces. Remember quotes, both single and double,
 * escape sequences, and comments.*/

#include <stdio.h>

#define MAXSTACK 1000

enum state {
  NORMAL,
  IN_STRING,
  IN_CHAR,
  IN_COMMENT_LINE,
  IN_COMMENT_BLOCK,
  MAYBE_COMMENT_START,
  MAYBE_COMMENT_END,
  ESCAPE_STRING,
  ESCAPE_CHAR
};

char stack[MAXSTACK];
int stack_top = -1;

void push(char c);
char pop(void);
int is_matching(char open, char close);

int main() {
  int c, prev;
  enum state current_state = NORMAL;
  int line_num = 1;
  int errors = 0;

  prev = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      line_num++;
    }

    switch (current_state) {
    case NORMAL:
      if (c == '"') {
        current_state = IN_STRING;
      } else if (c == '\'') {
        current_state = IN_CHAR;
      } else if (c == '/' && prev != '\\') {
        current_state = MAYBE_COMMENT_START;
      } else if (c == '(' || c == '[' || c == '{') {
        push(c);
      } else if (c == ')' || c == ']' || c == '}') {
        char open = pop();
        if (open == '\0') {
          printf("Error: Unmatched '%c' at line %d\n", c, line_num);
          errors++;
        } else if (!is_matching(open, c)) {
          printf("Error: Mismatched '%c' and '%c' at line %d\n", open, c,
                 line_num);
          errors++;
        }
      }
      break;

    case IN_STRING:
      if (c == '\\') {
        current_state = ESCAPE_STRING;
      } else if (c == '"') {
        current_state = NORMAL;
      }
      break;

    case IN_CHAR:
      if (c == '\\') {
        current_state = ESCAPE_CHAR;
      } else if (c == '\'') {
        current_state = NORMAL;
      }
      break;

    case ESCAPE_STRING:
      current_state = IN_STRING;
      break;

    case ESCAPE_CHAR:
      current_state = IN_CHAR;
      break;

    case MAYBE_COMMENT_START:
      if (c == '/') {
        current_state = IN_COMMENT_LINE;
      } else if (c == '*') {
        current_state = IN_COMMENT_BLOCK;
      } else {
        if (prev == '(' || prev == '[' || prev == '{') {
          push(prev);
        } else if (prev == ')' || prev == ']' || prev == '}') {
          char open = pop();
          if (open == '\0') {
            printf("Error: Unmatched '%c' at line %d\n", prev, line_num);
            errors++;
          } else if (!is_matching(open, prev)) {
            printf("Error: Mismatched '%c' and '%c' at line %d\n", open, prev,
                   line_num);
            errors++;
          }
        }

        if (c == '(' || c == '[' || c == '{') {
          push(c);
        } else if (c == ')' || c == ']' || c == '}') {
          char open = pop();
          if (open == '\0') {
            printf("Error: Unmatched '%c' at line %d\n", c, line_num);
            errors++;
          } else if (!is_matching(open, c)) {
            printf("Error: Mismatched '%c' and '%c' at line %d\n", open, c,
                   line_num);
            errors++;
          }
        }
        current_state = NORMAL;
      }
      break;

    case IN_COMMENT_LINE:
      if (c == '\n') {
        current_state = NORMAL;
      }
      break;

    case IN_COMMENT_BLOCK:
      if (c == '*') {
        current_state = MAYBE_COMMENT_END;
      }
      break;

    case MAYBE_COMMENT_END:
      if (c == '/') {
        current_state = NORMAL;
      } else if (c != '*') {
        current_state = IN_COMMENT_BLOCK;
      }
      break;
    }
    prev = c;
  }

  if (current_state == IN_STRING) {
    printf("Error: Unterminated string\n");
    errors++;
  } else if (current_state == IN_CHAR) {
    printf("Error: Unterminated character constant\n");
    errors++;
  } else if (current_state == IN_COMMENT_BLOCK ||
             current_state == MAYBE_COMMENT_END) {
    printf("Error: Unterminated comment\n");
    errors++;
  }

  while (stack_top >= 0) {
    printf("Error: Unmatched '%c'\n", pop());
    errors++;
  }

  if (errors == 0) {
    printf("No syntax errors found.\n");
  } else {
    printf("Found %d syntax error(s).\n", errors);
  }

  return errors > 0 ? 1 : 0;
}

void push(char c) {
  if (stack_top < MAXSTACK - 1) {
    stack[++stack_top] = c;
  } else {
    printf("Error: Stack overflow\n");
  }
}

char pop(void) {
  if (stack_top >= 0) {
    return stack[stack_top--];
  }
  return '\0';
}

int is_matching(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}
