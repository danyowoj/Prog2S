#include <stdio.h>
#include <string.h>

#define n 10

int main()
{
    int i, k;
    float sum;
    struct tov
    {
        char name[10];
        float c;
        int kol;
    } t;
    struct tov mag[n];
    char nazv[10];
    printf("\nEnter information about the product: ");
    for (i = 0; i < n; i++)
    {
        printf("\nname, price, amount: ");
        scanf("%s%f%d", &t.name, &t.c, &t.kol);
        mag[i] = t;
    }
    printf("\nEnter product to search: ");
    scanf("%s", &nazv);
    for (i = 0, sum = 0, k = 0; i < n; i++)
    {
        if (strcmp(mag[i].name, nazv) == 0)
        {
            sum += mag[i].c * mag[i].kol;
            k++;
        }
    }
    printf("There are %d products called %s, their price is %5.2f", k, nazv, sum);
    return 0;
}