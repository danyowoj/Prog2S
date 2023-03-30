#include <stdio.h>
#include <math.h>

int exist(int a, int b, int c)
{
    if ((a + b) > c && (a + c) > b && (b + c) > a)
        return 1;
    else
        return 0;
}

float perimeter(int a, int b, int c, float *P)
{
    *P = a + b + c;
    return *P;
}

float area(int a, int b, int c, float *S)
{
    float P, p = perimeter(a, b, c, &P) / 2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
    return *S;
}

int main()
{

    float P, S, a, b, c;

    printf("Enter sides of the triangle:\n");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    if (exist(a, b, c) == 1)
    {
        printf("For triangle with a = %f, b = %f, c = %f:\n", a, b, c);
        perimeter(a, b, c, &P);
        printf("P = %f\n", P);
        area(a, b, c, &S);
        printf("S = %f\n", S);
    }

    else
    {
        printf("Triangle with a = %f, b = %f, c = %f does not exist", a, b, c);
    }

    return 0;
}