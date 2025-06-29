/*Exercise 1-23: - Write a program to remove all comments
 *from a C program. Handle quoted strings and character constants
 *properly. C comments do not nest.*/
#include <stdio.h>

enum state {
    NORMAL,
    IN_STRING,
    IN_CHAR,
    IN_COMMENT_LINE,
    IN_COMMENT_BLOCK,
    MAYBE_COMMENT_START,
    MAYBE_COMMENT_END
};

int main() {
    int c, prev;
    enum state current_state = NORMAL;
    
    prev = 0;

    while ((c = getchar()) != EOF) {
        switch (current_state) {
            case NORMAL:
                if (c == '"') {
                    current_state = IN_STRING;
                    putchar(c);
                } else if (c == '\'') {
                    current_state = IN_CHAR;
                    putchar(c);
                } else if (c == '/' && prev != '\\') {
                    current_state = MAYBE_COMMENT_START;
                } else {
                    putchar(c);
                }
                break;
                
            case IN_STRING:
                putchar(c);
                if (c == '"' && prev != '\\') {
                    current_state = NORMAL;
                }
                break;
                
            case IN_CHAR:
                putchar(c);
                if (c == '\'' && prev != '\\') {
                    current_state = NORMAL;
                }
                break;
                
            case MAYBE_COMMENT_START:
                if (c == '/') {
                    current_state = IN_COMMENT_LINE;
                } else if (c == '*') {
                    current_state = IN_COMMENT_BLOCK;
                } else {
                    putchar('/');
                    putchar(c);
                    current_state = NORMAL;
                }
                break;
                
            case IN_COMMENT_LINE:
                if (c == '\n') {
                    putchar(c);
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
    
    return 0;
}