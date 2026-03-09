#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() {}

Book::Book(string id, string t, string a, string g, int p)
{
    bookID = id;
    title = t;
    author = a;
    genre = g;
    pageCount = p;

    status = BookStatus::AVAILABLE;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

BookStatus Book::getStatus()
{
    return status;
}

void Book::setStatus(BookStatus s)
{
    status = s;
}

bool Book::isAvailable()
{
    return status == BookStatus::AVAILABLE;
}

void Book::displayBook()
{
    cout << "---------------------------------" << endl;
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Pages: " << pageCount << endl;

    cout << "Status: ";

    if (status == BookStatus::AVAILABLE)
        cout << "Available";
    else if (status == BookStatus::BORROWED)
        cout << "Borrowed";
    else if (status == BookStatus::RESERVED)
        cout << "Reserved";

    cout << endl;
    cout << "---------------------------------" << endl;
}