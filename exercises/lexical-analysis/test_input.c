#include <stdio.h>

/* This is a block comment
   that spans multiple lines */
int main() {
    // This is a line comment
    printf("This string contains /* not a comment */");
    char c = '/'; // Character with slash
    char d = '*'; /* Another comment */
    printf("Quote with \" and // inside");
    /* Block comment with // inside */
    return 0; // Final comment
}