#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    struct card
    {
        char author[40];
        char title[40];
        int year;
        float price;
    };
    struct card Book;
    strcpy(Book.author, "Kentaka Iwamura");
    strcpy(Book.title, "Berserk");
    Book.year = 1989;
    Book.price = 9999;
    printf("%s \t %s \t %d year coasts %5.2f", Book.title, Book.author, Book.year, Book.price);
    return 0;
}