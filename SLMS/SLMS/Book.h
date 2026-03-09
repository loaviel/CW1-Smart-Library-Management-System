#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Enums.h"

using namespace std;

class Book
{
private:
    string bookID;
    string title;
    string author;
    string genre;
    int pageCount;
    BookStatus status;

public:
    Book();
    Book(string id, string t, string a, string g, int p);

    string getTitle();
    string getAuthor();
    BookStatus getStatus();

    void setStatus(BookStatus s);
    bool isAvailable();

    void displayBook();
};

#endif