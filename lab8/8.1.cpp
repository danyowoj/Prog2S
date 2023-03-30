#include <stdio.h>
#include <stdlib.h>

struct school
{
    int number;
    int grad;
    int stud;
    float percent;
};

void IndexSort(school *schl, int n, int *p)
{
    float temp;
    // fill the array of pointers
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    // bubble sort array of pointers
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (schl[p[i]].percent < schl[p[j]].percent)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void struct_in(struct school *schl, int n)
{
    printf("\nEnter information about schools:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNumber: ");
        scanf("%d", &schl[i].number);
        printf("Amount of graduators: ");
        scanf("%d", &schl[i].grad);
        printf("Amount of students: ");
        scanf("%d", &schl[i].stud);
        schl[i].percent = ((float)schl[i].stud / (float)schl[i].grad) * 100;
        // error check
        if (schl[i].stud > schl[i].grad)
        {
            printf("Incorrect data entered! Try again.");
            i--;
        }
    }
}

void struct_out(struct school *schl, int n, int *p)
{
    // using array of pointers to structure's members
    for (int i = 0; i < n; i++)
    {
        printf("\nNumber: %d;", schl[p[i]].number);
        printf("   Amount of graduators: %d;", schl[p[i]].grad);
        printf("   Amount of students: %d;", schl[p[i]].stud);
        printf("  Percent of students: %3.2f", schl[p[i]].percent);
    }
}

int main()
{
    int n = printf("\nEnter amount of schools: ");
    scanf("%d", &n);

    school *schl = new school[n]; // array of stucture members
    int *p = new int[n];          // array of pointers

    struct_in(schl, n);
    IndexSort(schl, n, p);
    struct_out(schl, n, p);

    return 0;
}