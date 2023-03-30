#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
    int *b, i, j = 0, l = 0, n, *c, m = 0, *d, k = 0;
    printf("\nArray's size: ");
    scanf("%d", &n);

    // создание массива b[n]
    b = (int *)malloc(n * sizeof(int));

    // вывод ошибки
    if (b == NULL)
    {
        printf("No memory allocated");
        return 1;
    }

    // заполнение массива b[n] рандомными числами
    for (i = 0; i < n; i++)
    {
        b[i] = rand() * (50 + 50) / RAND_MAX - 50;
    }

    // вывод исходного массива b[n]
    printf("\nOriginal array:");
    for (i = 0; i < n; i++)
    {
        printf("\nb[%d] = %d", i, b[i]);
    }
    printf("\n");

    // подсчет положительных и отрицательных элементов m и k
    for (i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            m++;
        }
        if (b[i] < 0)
        {
            k++;
        }
    }

    // создание массива c[m]
    c = (int *)malloc(m * sizeof(int));

    // создание массива d[k]
    d = (int *)malloc(k * sizeof(int));

    // заполнение массивов c[m] и d[k]
    for (i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            c[j] = b[i];
            j++;
        }
        if (b[i] < 0)
        {
            d[l] = b[i];
            l++;
        }
    }

    // вывод массива c[m]
    printf("\nArray of positive numbers:");
    for (i = 0; i < m; i++)
    {
        printf("\nc[%d] = %d", i, c[i]);
    }
    printf("\n");

    // вывод массива d[k]
    printf("\nArray of negative numbers:");
    for (i = 0; i < k; i++)
    {
        printf("\nd[%d] = %d", i, d[i]);
    }
    printf("\n");

    // освобождение памяти из-под b[n]
    free(b);
    b = NULL;

    // освобождение памяти из-под c[m]
    free(c);
    c = NULL;

    // освобождение памяти из-под d[k]
    free(d);
    d = NULL;

    return 0;
}