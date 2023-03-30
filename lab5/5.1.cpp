#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int m, n, k, p = 0;
    printf("Enter size of array 'a': ");
    scanf("%d", &m);
    int *a;
    a = new int[m];

    printf("Array 'a':\n");
    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter k < m: ");
    scanf("%d", &k);

    n = m / k;
    // printf("%d\n", n);
    if (m % k)
    {
        n++;
    }
    // printf("%d\n", n);

    int **b = new int *[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = new int[k]();
    }
    if (b == NULL)
    {
        return 1;
    }

    printf("Matrix b:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (p < m)
            {
                b[i][j] = a[p++];
            }
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    delete[] a;
    for (int i = 0; i < n; i++)
        delete[] b[i];
    delete[] b;
    return 0;
}