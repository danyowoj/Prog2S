#include <stdio.h>
#include <conio.h>
#include <math.h>

void EasterDate(int YearNum){
	int a, b, c, d, e, f;
	a = YearNum % 19;
	b = YearNum % 4;
	c = YearNum % 7;
	d = (19*a + 15) % 30;
	e = (2*b + 4*c + 6*d + 6) % 7;
	f = d + e;
	if (f <= 26) printf("Easter date is %d of April", 4+f);
	else printf("Easter date is %d of May", f-26);
}

int main(){
	int YearNum;
	printf("Inpur year number: ");	scanf("%d", &YearNum);
	EasterDate(YearNum);
	return 0;
}