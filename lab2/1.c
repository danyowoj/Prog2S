#include <stdio.h>

void PosNums(){
    int n;
    printf("Enter the number: ");   scanf("%d", &n);
    if (n != 0){
        if (n > 0){
            printf("\n  Number %d is positive\n\n", n);
            
        }
        PosNums();
    }
    else printf("\nThe sequence is over");
}

main(){
    PosNums();
    return 0;
}