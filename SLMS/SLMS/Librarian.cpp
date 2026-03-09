#include "Librarian.h"
#include <iostream>
#include <fstream>
#include <string>
Librarian::Librarian() {}

Librarian::Librarian(string id, string uname, string pass, string mail, string fullname) : User(id, uname, pass, mail, fullname, LIBRARIAN)
{
}

void Librarian::addBook()
{
    string id, title, author, genre;
    int pages;

    cout << "\n--- Add New Book ---\n";

    cout << "Book ID: ";
    cin >> id;

    cout << "Title: ";
    cin >> title;

    cout << "Author: ";
    cin >> author;

    cout << "Genre: ";
    cin >> genre;

    cout << "Page Count: ";
    cin >> pages;

    ofstream file("books.txt", ios::app);

    file << id << " "
        << title << " "
        << author << " "
        << genre << " "
        << pages << " "
        << "AVAILABLE" << endl;

    file.close();

    cout << "Book successfully added.\n";
}

void Librarian::deleteBook()
{
    string bookID;

    cout << "Enter Book ID to delete: ";
    cin >> bookID;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string id, title, author, genre, status;
    int pages;

    bool found = false;

    while (file >> id >> title >> author >> genre >> pages >> status)
    {
        if (id == bookID)
        {
            found = true;
            continue;
        }

        temp << id << " "
            << title << " "
            << author << " "
            << genre << " "
            << pages << " "
            << status << endl;
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "Book deleted.\n";
    else
        cout << "Book not found.\n";
}

void Librarian::updateBookStatus()
{
    string bookID;
    string newStatus;

    cout << "Enter Book ID: ";
    cin >> bookID;

    cout << "New Status (AVAILABLE/BORROWED/RESERVED): ";
    cin >> newStatus;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string id, title, author, genre, status;
    int pages;

    while (file >> id >> title >> author >> genre >> pages >> status)
    {
        if (id == bookID)
            status = newStatus;

        temp << id << " "
            << title << " "
            << author << " "
            << genre << " "
            << pages << " "
            << status << endl;
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    cout << "Book status updated.\n";
}

void Librarian::generateReport()
{
    ifstream file("borrowRecords.txt");

    string bookID, userID, borrowDate, dueDate, returnDate;

    cout << "\n--- Overdue Books ---\n";

    while (file >> bookID >> userID >> borrowDate >> dueDate >> returnDate)
    {
        if (returnDate == "NULL")
        {
            cout << "Book: " << bookID
                << " Borrower: " << userID
                << " Due: " << dueDate << endl;
        }
    }

    file.close();
}

void Librarian::menu()
{
    int choice;

    while (true)
    {
        cout << "\n===== LIBRARIAN MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Update Book Status\n";
        cout << "4. Generate Overdue Report\n";
        cout << "5. Logout\n";

        cin >> choice;

        if (choice == 1)
            addBook();

        else if (choice == 2)
            deleteBook();

        else if (choice == 3)
            updateBookStatus();

        else if (choice == 4)
            generateReport();

        else if (choice == 5)
            break;
    }
}