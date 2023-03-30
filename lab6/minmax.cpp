#include <stdio.h>
#include <conio.h>

void MinMax(int a, int b, int &min, int &max)
{
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
}

main()
{
    int a, b, min, max;
    printf("\nEnter two numbers:");
    scanf("%d%d", &a, &b);
    MinMax(a, b, min, max);
    printf("Min number is %d\nMax number is %d\n", min, max);
}