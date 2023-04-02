#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student
{
    char lname[20];
    int marks[4];

    // pointer to the next and previous structure in the list
    student *next, *prev;
} *head, *current, *tail;

student *create_list(void)
{
    int flag;
    head = tail = new student;
    head->next = head->prev = NULL;
    do
    {
        current = new student;
        printf("Last name: ");
        scanf("%s", current->lname);
        for (int i = 0; i < 4; i++)
        {
            printf("Mark: ");
            scanf("%d", &current->marks[i]);
        }
        current->next = NULL;
        current->prev = tail;
        tail->next = current;
        tail = current;
        printf("Continue? (1/0) ");
        scanf("%d", &flag);
    } while (flag);
    tail->next = NULL;
    return head;
}

// function deleting the desired structure
void removal(student *head)
{
    student *t;
    for (current = head->next; current;)
    {
        for (int i = 0; i < 4; i++)
        {
            if (current->marks[i] < 3)
            {
                if (current == tail)
                {
                    t = tail;
                    tail = tail->prev;
                    tail->next = NULL;
                    delete (t);
                    return;
                }
                else
                {
                    t = current;
                    current = current->next;
                    t->next->prev = t->prev;
                    t->prev->next = t->next;
                    delete (t);
                }
            }
        }
        current = current->next;
    }
}

void print(student *head)
{
    for (current = head->next; current; current = current->next)
    {
        printf("Last name: %s\tMarks: ", current->lname);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", current->marks[i]);
        }
        printf("\n");
    }
}

void free_student(student *head)
{
    student *q;
    q = current = head;
    while (current != NULL)
    {
        current = q->next;
        delete q;
        q = current;
    }
    head = NULL;
}

int main()
{
    head = create_list();
    printf("--------------\n");
    print(head);
    removal(head);
    printf("--------------\n");
    printf("New list:\n");
    print(head);
    free_student(head);
    return 0;
}