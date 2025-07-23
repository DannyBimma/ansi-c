#include <stdio.h>

int main(void)
{
    float c;
    float f;
    float upperBound = 300;
    float lowerBound = 0;
    float increment = 5;

    // Table heading
    printf("CALSIUS TO FAHRENHEIT TABLE\n");
    printf("\n");

    for(c = upperBound; c >= lowerBound; c -= increment)
    {
        f = (c * 9.0/5.0) + 32;
        printf("%3.0f c\t=\t%6.1f f\n", c, f);
    }
    return 0;
}