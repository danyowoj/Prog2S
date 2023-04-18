#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch, sl[50];
    char text[] = "one two three four";
    FILE *pf, *pr;               // pointers on files
    pf = fopen("new1.txt", "w"); // creating new file
    system("CLS");
    fputs(text, pf); // writing text string in the file
    fclose(pf);      // close pf file

    pf = fopen("new1.txt", "r");   // open file pf to read
    pr = fopen("new2.txt", "w");   // creating new file
    while ((ch = getc(pf)) != EOF) // reding ch symbol from pf file
    {
        if (ch != ' ')
        {
            putc(ch, pr); // writing ch symbol in the pf file
        }
    }
    fclose(pr);         // close pr file
    rewind(pf);         // return pointer to the beggining of pf file
    fgets(sl, 50, pf);  // reading string from pf file into sl variable
    printf("%s\n", sl); // sl string output

    pr = fopen("new2.txt", "r"); // open pr file to read
    fgets(sl, 50, pr);           // // reading string from pr file into sl variable
    printf("%s\n", sl);          // sl string output

    fclose(pf);
    fclose(pr);

    return 0;
}