/*
The entry has the form: Passenger's full name, the number of seats occupied by luggage, the total weight of things. Using the functions and menu mode:
a) create a file from N records;
b) view the file;
c) add a new entry to the end of the file;
d) find and delete from the file records of passengers whose total weight of things is less than 10 kg.
e) change the weight of the passenger's belongings by the given name.
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

// structure of passenger information
struct passengers
{
    string name;       // name variable
    string last_name;  // surname variable
    string patronymic; // patronymic variable
    int count;         // variable amount of luggage
    float weight;      // variable baggage weight
} pass;

// the function of creating and filling in the .dat file
void create(const char *name)
{
    // variable to continue the loop
    char token;

    // a pointer to our file
    FILE *file1;

    // opening a file for recording
    file1 = fopen(name, "wb");
    system("CLS");
    printf("--------Info about passengers--------\n");

    // file filling cycle
    do
    {
        puts("Last name: ");
        cin >> pass.last_name;
        puts("Name: ");
        cin >> pass.name;
        puts("Patronymic: ");
        cin >> pass.patronymic;
        puts("Amount of luggage: ");
        cin >> pass.count;
        puts("Total weight: ");
        cin >> pass.weight;

        // function of writing data from a structure to a file
        fwrite(&pass, sizeof(pass), 1, file1);
        /*Starting from the ptr address, count elements
        of the size size each are written to the file.
        The function returns the number of elements actually recorded.*/
        puts("Continue? y/n ");
        token = _getch();
    } while (token != 'n');
    fclose(file1);
}

// file content viewing function
void viewing(const char *name)
{
    int i;

    // a pointer to our file
    FILE *file1;

    // opening a file for reading
    file1 = fopen(name, "rb");
    system("CLS");
    i = 1;
    printf("--------Info about passengers--------\n");
    cout << "num\tLN\tN\tP\tAL\tTW\n";
    while (fread(&pass, sizeof(pass), 1, file1) /*the function of reading information from a file*/)
    /*
    Count elements of size size each are read from the file file1
    and written to the pass address.
    The function returns the number of elements actually read.*/
    {
        cout << i << "."
             << "\t"
             << pass.last_name << "\t"
             << pass.name << "\t"
             << pass.patronymic << "\t"
             << pass.count << "\t"
             << pass.weight << endl;
        i++;
    }
    fclose(file1);
    _getch();
}

// the function of adding information to the file
void add(const char *name)
{

    // variable to continue the loop
    char token;

    // a pointer to our file
    FILE *file1;

    // Appends information to the end of the binary file.
    file1 = fopen(name, "ab");
    system("CLS");
    printf("--------Info about passengers--------\n");
    do
    {
        puts("Last name: ");
        cin >> pass.last_name;
        puts("Name: ");
        cin >> pass.name;
        puts("Patronymic: ");
        cin >> pass.patronymic;
        puts("Amount of luggage: ");
        cin >> pass.count;
        puts("Total weight: ");
        cin >> pass.weight;

        // function of writing data from a structure to a file
        fwrite(&pass, sizeof(pass), 1, file1);
        puts("Continue? y/n ");
        token = _getch();
    } while (token != 'n');
    fclose(file1);
}

// key information search function
void find(const char *name)
{
    // variable to continue the loop
    char token;

    // variable key for search
    string info;

    // a pointer to our file
    FILE *file1;

    // Opens a binary file for reading/writing.
    file1 = fopen(name, "rb+");
    puts("Last name to find: ");
    cin >> info;
    while (fread(&pass, sizeof(pass), 1, file1)) /*the function of reading information from a file*/
    {
        if (pass.last_name == info)
        {
            printf("%20s", pass.last_name);
            printf("%20s", pass.name);
            printf("%20s", pass.patronymic);
            printf("%20d", pass.count);
            printf("%20f", pass.weight);
            puts("\nChange? y/n ");
            token = _getch();
            if (token == 'y')
            {
                puts("Total weight: ");
                cin >> pass.weight;

                // switching to one entry in the file
                fseek(file1, -(long long)(sizeof(pass)), 1);
                /*sets the position in the data stream specified by the stream argument.
                Data will be read and written relative to the set position.*/

                // output of the modified record to the file
                fwrite(&pass, sizeof(pass), 1, file1);

                // clearing Input/Output buffers
                fflush(file1);
                /*dumps the data in the buffer to the file associated with the data stream*/
            }
        }
    }
    fclose(file1);
}

void del(const char *name)
{

    // a pointer to our file
    FILE *file1;

    // Opens a binary file for reading/writing.
    file1 = fopen(name, "rb+");
    while (fread(&pass, sizeof(pass), 1, file1)) /*the function of reading information from a file*/
    {
        if (pass.weight < 10)
        {
            pass.name = " ";
            pass.last_name = " ";
            pass.patronymic = " ";
            pass.count = 0;
            pass.weight = 0;

            // switching to one entry in the file
            fseek(file1, -(long long)(sizeof(pass)), 1);

            // output of the modified record to the file
            fwrite(&pass, sizeof(pass), 1, file1);

            // clearing Input/Output buffers
            fflush(file1);
        }
    }
    fclose(file1);
}

int main()
{
    char choise;
    while (1)
    {
        system("CLS");
        puts("1 - Create new file");
        puts("2 - Viewing a file");
        puts("3 - Add info into a file");
        puts("4 - Search and change");
        puts("5 - Delete info");
        puts("0 - exit");
        choise = _getch();
        switch (choise)
        {
        case '1':
            create("passengers.dat");
            break;
        case '2':
            viewing("passengers.dat");
            break;
        case '3':
            add("passengers.dat");
            break;
        case '4':
            find("passengers.dat");
            break;
        case '5':
            del("passengers.dat");
            break;
        default:
            return 0;
        }
    }
}
