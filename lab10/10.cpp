/*Create a text file of several lines, with several words in each line.
Task.
Read lines from a file. Split the lines into words. Sort the words alphabetically and output them to the second file.
Save words from a list or a dynamic array (the number of elements in the data structure must be equal to the number of words in the file)
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <string>
#include <time.h>

using namespace std;

typedef struct WordsList
{
    string word;
    struct WordsList *next;
    struct WordsList *prev;
} Words;

#define MAX_LEN 100

void listCheck(Words *head);
void free_list(Words *head);
void listSort(Words *head);

int main()
{
    FILE *pf, *pr;
    Words *head, *p, *tail;
    srand(time(NULL));
    char sep[10] = " \n\0";
    char text[MAX_LEN];
    string tmp;
    string words[] = {"ex", "clique", "belly", "shark", "boom", "representative", "talented", "tissue", "aware", "extension"};
    char *token;
    int i, j, n;

    pf = fopen("file1.txt", "w");

    for (i = 0; i < rand() % 10 + 10; i++)
    {
        tmp = "";
        for (j = 0; j < rand() % 6 + 1; j++)
            tmp += words[rand() % (sizeof(words) / sizeof(words[0]))] + " ";
        tmp += '\n';
        fputs(tmp.c_str(), pf);
    }
    cout << endl;
    fclose(pf);

    pf = fopen("file1.txt", "r");
    head = tail = new Words;
    head->next = head->prev = NULL;
    n = 0;
    while (!feof(pf))
    {
        if (fgets(text, MAX_LEN, pf) != NULL)
        {
            token = strtok(text, sep);
            while (token != NULL)
            {
                if (token != NULL)
                {
                    p = new Words;
                    p->word = token;
                    p->next = NULL;
                    p->prev = tail;
                    tail->next = p;
                    tail = p;
                    n++;
                }
                token = strtok(NULL, sep);
            }
        }
    }
    fclose(pf);

    listCheck(head);
    listSort(head);
    listCheck(head);

    pr = fopen("file2.txt", "w");
    p = head->next;
    while (p != NULL)
    {
        fputs(p->word.c_str(), pr);
        fputs("\n", pr);
        p = p->next;
    }
    fclose(pr);

    return 0;
}

void listCheck(Words *head)
{
    Words *p;
    p = head->next;
    cout << "\n\t OUR LIST " << endl;
    while (p != NULL)
    {
        cout << "\tp->word :" << p->word << endl;
        p = p->next;
    }
}

void listSort(Words *head)
{
    Words *p, *t1, *t2;
    int f = 0;

    do
    {
        f = 0;
        for (p = head; p->next->next; p = p->next)
        {
            t1 = p->next;
            t2 = t1->next;
            if (t1->word > t2->word)
            {
                p->next = t2;
                t1->next = t2->next;
                t2->next = t1;
                f = 1;
            }
        }
    } while (f);
}

void free_list(Words *head)
{
    Words *p, *q;
    q = p = head;
    while (p != NULL)
    {
        p = q->next;
        delete q;
        q = p;
    }
    head = NULL;
}
