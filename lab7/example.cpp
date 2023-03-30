#include <stdio.h>
#include <stdlib.h>

int Sum(int A[], int N)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < N; i++)
        sum += A[i];
    return sum;
}

main()
{
    const int n = 20, m = 30;
    int i, s, A[n], B[m];

    printf("Array A\n");
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 10;
        printf("%5d", A[i]);
    }

    printf("\n\nArray B\n");
    for (i = 0; i < m; i++)
    {
        B[i] = rand() % 10;
        printf("%5d", B[i]);
    }

    s = Sum(A, n);
    printf("\nSum A = %d, Sum B = %d", s, Sum(B, m));
    return 0;
}