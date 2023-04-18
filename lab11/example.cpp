#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct tov
{
    char name[10];
    float c;
    int kol;
} t1;

void input(char *name); // creating new file
void print(char *name); // looking through file
void app(char *name);   // adding file
void find(char *name);  // seracing and changing

int main()
{
    char c;
    while (1)
    {
        system("CLS");
        puts("1 - create a new file");
        puts("2 - look through file");
        puts("3 - add to file");
        puts("4 - search and edit");
        puts("0 - exit");

        c = _getch();
        switch (c)
        {
        case '1':
            input("file1.dat");
            break;
        case '2':
            print("file1.dat");
            break;
        case '3':
            app("file1.dat");
            break;
        case '4':
            find("file1.dat");
            break;
        case '0':
            return 0;
        default:
            puts("wrong input");
        }
    }
}

void input(char *name)
{
    char ch;
    FILE *tf;

    tf = fopen(name, "wb"); // open binary file to write into
    printf("\nEnter products:\n");
    do
    {
        printf("\n name: ");
        scanf("%s", &t1.kol);
        printf("\n coast: ");
        scanf("%s", &t1.c);
        printf("\namount: ");
        scanf("%s", &t1.kol);
        fwrite(&t1, sizeof(t1), 1, tf); // write into file a f1 structure
        printf("\n Continue? y/n ");
        ch = _getch();
    } while (ch != 'n');
    fclose(tf);
}

void print(char *name)
{
    int i;
    FILE *tf;

    tf = fopen(name, "rb"); // open binary file to read
    i = 1;
    while (fread(&t1, sizeof(t1), 1, tf))
    {
        printf("\n %3d product %10s coast %6.2f amount %4d", i, t1.name, t1.c, t1.kol);
        i++;
    }
    fclose(tf);
    _getch();
}

void app(char *name)
{
    char ch;
    FILE *tf;
    tf = fopen(name, "ab"); // открытие бинарного файла для добавления
    system("CLS");
    printf("\n  Ввод товаров \n");
    do
    {
        printf("\n название: ");
        scanf("%s", &t1.name);
        printf(" цена: ");
        scanf("%f", &t1.c);
        printf(" количество: ");
        scanf("%d", &t1.kol);
        fwrite(&t1, sizeof(t1), 1, tf);
        printf(" Закончить?  y/n ");
        ch = _getch();
    } while (ch != 'y');
    fclose(tf);
}

void find(char *name)
{
    char c, tov[10];
    FILE *tf;
    long int i;
    tf = fopen("file1.dat", "rb+"); // открытие файла для чтения и записи
    puts(" товар для поиска: ");
    gets(tov);
    while (fread(&t1, sizeof(t1), 1, tf))
    {
        if (strcmp(t1.name, tov) == 0)
        {
            printf(" tovar %10s cena %6.2f kolic %d", t1.name, t1.c, t1.kol);
            printf("\n èçìåíèòü? y/n ");
            c = _getch();
            if (c == 'y')
            {
                printf("\n количество: ");
                scanf("%d", &t1.kol);
                printf("\n цена: ");
                scanf("%f", &t1.c);
                fseek(tf, -sizeof(t1), 1);      // переход на одну запись в файле
                fwrite(&t1, sizeof(t1), 1, tf); // вывод в файл измененной записи
                fflush(tf);                     // очистка буферов ввода-вывода
            }
        }
    }
    fclose(tf);
}
