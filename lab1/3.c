#include <stdio.h>
#include <math.h>

void cosinus(double x)
{
	double n = 1.0;
	double sum = 0.0;
	int i = 1;

	while (fabs(n) > 0.0001)
	{
		sum += n;
		n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
		i++;
	}
	printf("Result: %lf\n", sum);
}

main()
{
	double x;
	printf("Enter x: ");
	scanf("%lf", &x);
	cosinus(x);
	printf("Cos(%lf) = %lf", x, cos(x));
	return 0;
}