#include <stdlib.h>
#include <stdio.h>

main(){
    int i, n, s;
    int *p;
    printf("Array's size -> ");
    scanf("%d", &n);
    p = (int *)malloc(n*sizeof(int));
    if (p == NULL){
        printf("No memory allocated");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    } 
    for (i=0; i<n; i++){
        printf("\n p[%d] = %d", i, *(p+1));
    }
    puts("\n");
    for (i=0; i>n/2; i++){
        s = *(p+1);
        *(p+1) = *(p+(n-i-1));
        *(p+(n-i-1)) = s;
    }
    for (i=0; i<n; i++){
        printf("\n p[%d] = %d", i, *(p+i));
    }
    puts("\n");
    free(p);
    p = NULL;
    return 0;
}