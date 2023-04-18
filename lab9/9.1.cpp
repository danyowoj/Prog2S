/*
Form a single-linked list consisting of structures containing information:
the student's last name and 4 grades. Sort the list in ascending order (by last name).
 Output the resulting list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct student
{
    // surname variable
    char lname[20];

    // array of marks
    int marks[4];

    // a pointer to the next structure in the list
    student *next;
}
    // pointer to the head, current item, and tail of the list
    *head,
    *p, *tail;

// list filling function
student *enter()
{
    int flag;

    // memory allocation for head and tail
    head = tail = new student;

    // initializing the element reference after the tail
    tail->next = NULL;
    do
    {
        // allocation of memory for a list structure element
        p = new student;

        // filling in the structure
        printf("Last name: ");

        // accessing a structure element and writing information to it
        scanf("%s", p->lname);
        for (int i = 0; i < 4; i++)
        {
            printf("Mark: ");
            scanf("%d", &p->marks[i]);
        }
        // link to the next item after the tail in the list
        tail->next = p;

        // transferring the tail address to a new element
        tail = p;
        printf("Continue? (1/0): ");
        scanf("%d", &flag);
    } while (flag);

    // initializing the element reference after the tail
    tail->next = NULL;
    return head;
}

// list structures output function
void print(student *head)
{
    for (p = head->next; p; p = p->next)
    {
        printf("Last name: %s\tMarks: ", p->lname);
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", p->marks[i]);
        }
        printf("\n");
    }
}

// sorting function of list structures
void sort(student *head)
{
    int f;

    // creating new list pointers for sorting
    student *t1, *t2;
    do
    {
        f = 0;
        for (p = head; p->next->next; p = p->next)
        {
            // saving the address of the structure after p in t1
            t1 = p->next;

            // saving the address of the structure after t1 in t2
            t2 = t1->next;
            if (strcmp(t1->lname, t2->lname) > 0)
            {
                // link from p to t2
                p->next = t2;

                // link from t1 to t2 next
                t1->next = t2->next;

                // link from t2 to t1
                t2->next = t1;
                f = 1;
            }
        }
    } while (f);
}

// list clearing function
void free_student(student *head)
{
    student *q;
    q = p = head;
    while (p != NULL)
    {
        p = q->next;
        delete q;
        q = p;
    }
    head = NULL;
}

int main()
{
    // saving the address of the head of the list
    head = enter();
    printf("--------------\n");
    print(head);
    sort(head);
    printf("--------------\n");
    printf("Sorted list:\n");
    print(head);
    free_student(head);
    return 0;
}