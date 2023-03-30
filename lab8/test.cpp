#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dormitory
{
    int number;
    float area;
    char faculty[20];
    int people;
};

void struct_in(dormitory *dorm, int n)
{
    printf("\nEnter info about dorm's rooms: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nRoom number: ");
        scanf("%d", &dorm[i].number);
        printf("Room area: ");
        scanf("%f", &dorm[i].area);
        printf("Faculty: ");
        scanf("%s", &dorm[i].faculty);
        printf("People amount: ");
        scanf("%d", &dorm[i].people);
    }
}

void struct_out(dormitory *dorm, int n, int *index_arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nRoom number: %3d;\t", dorm[i].number);
        printf("Room area: %3.2f;\t", dorm[i].area);
        printf("Faculty: %10s;\t", dorm[i].faculty);
        printf("People amount: %2d", dorm[i].people);
    }
}

void sort(dormitory *dorm, int n, int *index_arr)
{
    // creating array of indexes
    for (int i = 0; i < n; i++)
    {
        index_arr[i] = i;
    }
    // sorting the array via Select Sort
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(dorm[index_arr[i]].faculty, dorm[index_arr[j]].faculty) > 0)
            {
                temp = index_arr[i];
                index_arr[i] = index_arr[j];
                index_arr[j] = temp;
            }
        }
    }
}

void faculties(dormitory *dorm, int n, int *index_arr)
{
    // creating array of indexes
    for (int i = 0; i < n; i++)
    {
        index_arr[i] = i;
    }
    // searching for different faculties
    int *fac_index = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (dorm[i].faculty == dorm[index_arr[i]].faculty)
        {
            fac_index[i] = i;
            printf("%s; ", dorm[fac_index[i]]);
        }
    }
}

int main()
{
    int n = printf("\nEnter amount of rooms in dormitory: ");
    scanf("%d", &n);

    dormitory *dorm = new dormitory[n];
    int *index_arr = new int[n];

    struct_in(dorm, n);
    puts("\n");
    faculties(dorm, n, index_arr);
    puts("\n");
    struct_out(dorm, n, index_arr);

    return 0;
}