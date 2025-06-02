#include <stdio.h>

int main(void)
{
    float c;
    float f;
    float lowerBound = 0;
    float upperBound = 300;

    // Temp output heading
    printf("CELCIUS TO FAHRENHEIT TABLE\n");
    printf("\n");

    for(c = lowerBound; c <= upperBound; c += 5)
    {
        f = (c * 9.0/5.0) + 32;
        printf("%3.0f c\t=\t%6.1f f\n", c, f);
    }
    return 0;
}