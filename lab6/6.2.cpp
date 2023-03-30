#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f = f * i;
    return f;
}

int C(int n, int m)
{
    return factorial(n) / factorial(m) / factorial(n - m);
}

float pd(int n, int m, float p, float q)
{
    return C(n, m) * pow(p, m) * pow(q, n - m);
}

float pm(int n, int m, float p, float q)
{
    return C(n, m) * pow(q, m) * pow(p, n - m);
}

int main()
{
    float p = 0.45, q = 1 - p;
    int n = 10, m = 2;
    printf("pd = %f\n", pd(n, m, p, q));
    printf("pm = %f\n", pm(n, m, p, q));
    return 0;
}