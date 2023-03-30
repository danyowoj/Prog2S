#include <stdio.h>
#include <conio.h>

int max(int, int); 	// прототип функции
// можно указывать только тип формальных параметров

main(){
	int x, y, z;
	printf("Input x, y: ");	scanf("%d%d", &x,&y);
	z = max(x, y);	// вызов функции с фактическими параметрами
	printf("x = %d	y = %d	z = %d", x, y, z);
	getch();
}

// заголовок функции с формальными параметрами
int max(int a, int b){
	int c;
	if (a > b) c = a;
	else c = b;
	return c;
}