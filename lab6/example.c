#include <stdio.h>
#include <stdlib.h>

void prim(int *x)
{
    *x = 10;
}

int main()
{
    int z = 5;
    prim(&z);
    printf("z = %d", z);
}