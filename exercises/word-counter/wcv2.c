#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  // Declare variables to store counts
  int c, nl, nw, nc, flag;

  // Initialise variables
  flag = 0;
  nl = nw = nc = 0;

  // Loop over chars from stdin until EOF
  while ((c = getchar()) != EOF) {
    // increment for each char
    ++nc;
    // increment for each new line
    if (c == '\n')
      ++nl;
    // set sate flag if outside of word
    if (c == ' ' || c == '\n' || c == '\t')
      flag = OUT;
    else if (flag == OUT) {
      // if inside word increment for each word
      flag = IN;
      ++nw;
    }
  }
  // Print the new lines, new words, and new chars counted
  printf("%d %d %d\n", nl, nw, nc);
}
