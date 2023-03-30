#include <stdio.h>
#include <string.h>

void Bin(int x)
{
    if (x > 0)
    {
        Bin(x / 2);
        printf("%d", x % 2);
    }
}

main()
{
    int b;
    printf("Enter the number: ");
    scanf("%d", &b);
    Bin(b);
    return 0;
}