#include <stdio.h>
 
 
#define E 10//точность
int main()
{
    double x;//сам х
    double cos = 1;//общая сумма
    
    int i;
    printf("Enter x: ");
    scanf("%lf", &x);
    
    double down = 1;//знаменатель(факториал)
    double up = -(x*x);//числитель(увеличение степени х на 2)
    
	for (i = 2; i < E; i+=2)//сразу с 2 и по 2 вбудущем
    {
        up *= (-1)*up;//контроль -1 и увеличение степени х
        down *= i; //факториал
        cos += up / down; //добавление следующего компонента
    }
    printf("result: %lf\n", x);
 
    return 0;
}