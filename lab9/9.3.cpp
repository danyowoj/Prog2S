#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student
{
    char lname[20];
    int marks[4];
    student *l, *r;
};

void create(student *&p, char word[])
{
    if (p == NULL)
    {
        p = new student;
        strcpy(p->lname, word);
        for (int i = 0; i < 4; i++)
        {
            printf("Mark: ");
            scanf("%d", &p->marks[i]);
        }
        p->l = p->r = NULL;
        return;
    }
    if (strcmp(word, p->lname) > 0)
    {
        create(p->r, word);
    }
    else
    {
        create(p->l, word);
    }
}

void print_increase(student *current)
{
    if (!current)
        return;
    print_increase(current->l);
    printf("Last name: %s\tMarks: ", current->lname);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", current->marks[i]);
    }
    printf("\n");
    print_increase(current->r);
}

void print_decrease(student *current)
{
    if (!current)
        return;
    print_decrease(current->r);
    printf("Last name: %s\tMarks: ", current->lname);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", current->marks[i]);
    }
    printf("\n");
    print_decrease(current->l);
}

student *search(student *t, char name[])
{
    if (!t)
    {
        return NULL;
    }
    if (strcmp(name, t->lname) == 0)
    {
        return t;
    }
    if (strcmp(name, t->lname) > 0)
    {
        return search(t->r, name);
    }
    return search(t->l, name);
}

int main()
{
    student *current = NULL, *t;
    int count;
    char word[12], name[12];
    printf("How many entries: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("Last name: ");
        scanf("%s", &word);
        create(current, word);
    }
    printf("--------------\n");
    print_increase(current);
    printf("--------------\n");
    print_decrease(current);
    printf("--------------\n");
    printf("Last name we need to find: ");
    scanf("%s", &name);
    t = search(current, name);
    if (t)
    {
        printf("Last name: %s\tMarks: ", current->lname);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", current->marks[i]);
        }
    }
    else
    {
        printf("not found");
    }
}