#include <stdio.h>
#include <conio.h>
#include <math.h>

float degree(float x, int n){
	int i;
	float y=0, one=1;
	if (n<0) n = n*(-1);
	for (i=0; i<n; i++){
		y = x*x;
	}
	return y;
}

main(){
	int n;
	float x, z;
	printf("Input number: ");	scanf("%f", &x);
	printf("Input degree: ");	scanf("%d", &n);
	z = degree(x, n);
	
	if (n>0) 	printf("Result: %f", z);
	if (n<0) 	printf("Result: %f", 1 / z);
	if (n==0) 	printf("Result: %d", 1);
	
	return 0;
}