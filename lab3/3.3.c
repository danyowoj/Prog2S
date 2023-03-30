#include <stdio.h>

int main()
{
     int i, j, n, *a, p = 1;
     printf("Enter number n: ");
     scanf("%d", &n);

     // создание массива с числами от 2 до n
     a = (int *)malloc(n * sizeof(int));

     // заполнение массива a
     for (i = 2; i <= n; i++)
     {
          a[i] = i;
     }

     // вывод исходного массива a
     printf("\nOriginal array:\n");
     for (i = 2; i <= n; i++)
     {
          printf("%d; ", a[i]);
     }

     // цикл решета Эратосфена
     for (j = 0; j < n; j++)
     {
          // поис первого ненулевого p после предыдущего
          for (i = p + 1; i <= n; i++)
          {
               if (a[i] != 0)
               {
                    p = a[i];
                    break;
               }
          }

          // удаление из массива чисел кратных p
          for (i = 0; i <= n; i += p)
          {
               if (a[i] % p == 0 && a[i] != p)
                    a[i] = 0;
          }
     }

     // вывод массива a
     printf("\n\nArray of prime numbers from 2 to %d:\n", n);
     for (i = 2; i <= n; i++)
     {
          if (a[i] != 0)
               printf("%d; ", a[i]);
     }

     // осовбождение памяти из-под a
     free(a);
     a = NULL;

     return 0;
}