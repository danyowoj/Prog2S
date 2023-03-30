#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
	system("cls");
	system("chcp 1251");
	srand(time(NULL));
	int i, n;
	float *a, c, **b, *temp;

	// ввод данных
	cout << "Length of mass -> ";
	cin >> n;
	cout << "Float numbers to... -> ";
	cin >> c;

	// создание массива a и массива указателей b
	a = new float[n];
	b = new float *[n];

	// вывод ошибки
	if (a == NULL || b == NULL)
	{
		return 1;
	}

	// запорлнение массивов
	for (i = 0; i < n; i++)
	{
		a[i] = ((float)rand() / (float)(RAND_MAX)) * c;
		b[i] = &(a[i]);
	}

	// SelectSort массива указателей
	for (i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*b[i] > *b[j])
			{
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	// выовд a
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i];
		cout << "\n";
	}

	// осовобождение памяти из-под a
	delete a;
	a = NULL;

	// выовд b
	cout << "---------------\n";
	for (i = 0; i < n; i++)
	{
		cout << "b[" << i << "] = " << *b[i];
		cout << "\n";
	}
	
	// осовобождение памяти из-под b
	delete b;
	b = NULL;

	_getch();
	return 0;
}