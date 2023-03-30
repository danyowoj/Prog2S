#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
    float *p;   // указатель на вещественные числа
    int i, n;   // размер массива n заранее известен, т.е. n - не константа
    printf("\n Array's size: ");
    scanf("%d", &n);
    p = (float *) malloc(n*sizeof(float));
    // выделяем память под n вещественных чисел
    // фукнция sizeof(<тип>) определяет размер типа в байтах
    if (p == NULL){     // если не удалось выделить память
        printf("Не удалось выделить память");
        return 1;   // выход по ошибке, код ошибки 1
    }
    for (i=0; i<n; i++){
        printf("p[%d] = ", i);
        scanf("%f", &p[i]);
    }
    for (i=0; i<n; i++){
        printf("\t p[%d] = %8.2f", i, p[i]);
    }
    free(p);
    p = NULL;
    getch();
    return 0;
}