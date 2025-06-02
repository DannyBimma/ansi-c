#include <stdio.h>

int main(void)
{
    // get_char value
    if ((getchar()) != EOF == 0)
    {
        printf("It's Zero-chan!!\n");
    }
    else if ((getchar()) != EOF == 1)
    {
        printf("It's One-chan!!\n");
    }
    else
    {
        printf("ERROR!!");
    }
    return 0;
}