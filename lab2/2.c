#include <stdio.h>

int a[10], i, j;

void print(int j)
{
    if (a[j] < 0)
    {
        printf("%d; ", a[j]);
    }
    if (a[j] != 0)
        print(j + 1);
    if (a[j] > 0)
        printf("%d; ", a[j]);
}

main()
{
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    print(0);
    return 0;
}