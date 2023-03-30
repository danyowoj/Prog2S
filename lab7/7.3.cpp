#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void FillRand(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }
}

void PrintMas(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i;
        while (j > 0 && temp > A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

void Search(int A[], int n, int key)
{
    int C = 0;
    for (int i = 0; i < n; i++)
    {
        C++;
        if (A[i] == key)
        {
            printf("%d", C);
            break;
        }
    }
}

int BSearch(int A[], int n, int key)
{
    int L = 0, R = n - 1, find = -1, m;
    int C = 0;
    // until the borders shrink
    while (L <= R)
    {
        // take the middle element
        m = (L + R) / 2;
        // increase the comparison counter by one
        // if this element is smaller than the desired one
        C++;
        if (A[m] == key)
        {
            // return the index of this element
            find = m;
            return find;
        }
        else
        {
            if (A[m] < key)
            {
                // move the left border
                L = m + 1;
            }
            // if this element is bigger than the desired one
            else
            {
                // move the right border
                R = m - 1;
            }
        }
    }
    // if this is the right element
    printf("%d", C);
    return find;
}

int main()
{
    srand(time(NULL));
    int key;

    int n = 100;
    int a[n];
    FillRand(a, n);
    InsertSort(a, n);
    key = a[rand() % n];
    printf("\nSearch: C = ");
    Search(a, n, key);
    printf("\nBSearch: C = ");
    BSearch(a, n, key);

    int N = 1000;
    int A[N];
    FillRand(A, N);
    InsertSort(A, N);
    key = A[rand() % N];
    printf("\n\nSearch: C = ");
    Search(A, N, key);
    printf("\nBSearch: C = ");
    BSearch(A, N, key);

    return 0;
}