#include <stdio.h>
#include <conio.h>

void swap(float *a, float *b)
{
    float c;
    c = *a;
    *a = *b;
    *b = c;
}

main()
{
    float x, y;
    printf("\n Enter x and y:");
    scanf("%f%f", &x, &y);
    swap(&x, &y);
    printf("\n x = %4.2f \t y = %4.2f", x, y);
}