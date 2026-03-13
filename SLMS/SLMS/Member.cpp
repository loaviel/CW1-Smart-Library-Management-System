#include "Member.h"
#include <iostream>
#include "NotificationSystem.h"
#include <fstream>
#include "Book.h"

using namespace std;

Member::Member() {}

Member::Member(string id, string uname, string pass, string email, string name) : User(id, uname, pass, email, name, MEMBER)
{
    borrowLimit = 5;
    currentBorrowed = 0;
}

void Member::searchBook()
{
    string search;
    cout << "Enter title or author: ";
    cin >> search;

    ifstream file("books.txt");

    string id, title, author, genre, statusStr;
    int pages;

    bool found = false;

    while (file >> id >> title >> author >> genre >> pages >> statusStr)
    {
        if (title == search || author == search)
        {
            Book b(id, title, author, genre, pages);

            if (statusStr == "AVAILABLE")
                b.setStatus(BookStatus::AVAILABLE);
            else if (statusStr == "BORROWED")
                b.setStatus(BookStatus::BORROWED);
            else if (statusStr == "RESERVED")
                b.setStatus(BookStatus::RESERVED);

            b.displayBook();
            found = true;
        }
    }

    if (!found)
        cout << "No books found.\n";

    file.close();
}

void Member::borrowBook()
{
    string bookID;

    cout << "Enter Book ID: ";
    cin >> bookID;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string id, title, author, genre, status;
    int pages;

    bool found = false;

    while (file >> id >> title >> author >> genre >> pages >> status)
    {
        if (id == bookID && status == "AVAILABLE")
        {
            status = "BORROWED";
            found = true;

            ofstream record("borrowRecords.txt", ios::app);

            record << bookID << " "
                << userID << " "
                << "2024-01-01 "
                << "2024-01-14 "
                << "NULL" << endl;

            record.close();

            NotificationSystem::createMessage(
                DUEDATE,
                userID,
                "Book borrowed. Due in 14 days."
            );
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
        cout << "Book borrowed successfully.\n";
    else
        cout << "Book unavailable.\n";
}

void Member::returnBook()
{
    string bookID;

    cout << "Enter Book ID: ";
    cin >> bookID;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string id, title, author, genre, status;
    int pages;

    while (file >> id >> title >> author >> genre >> pages >> status)
    {
        if (id == bookID)
        {
            status = "AVAILABLE";
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

    cout << "Book returned.\n";
}

void Member::reserveBook()
{
    string bookID;

    cout << "Enter Book ID: ";
    cin >> bookID;

    ofstream file("reservations.txt", ios::app);

    file << bookID << " "
        << userID << " "
        << "2024-01-01 "
        << "2024-01-04" << endl;

    file.close();

    NotificationSystem::createMessage(
        RESERVATION,
        userID,
        "Reservation placed."
    );

    cout << "Book reserved.\n";
}

void Member::menu()
{
    int choice;

    while (true)
    {
        cout << "\n===== MEMBER MENU =====\n";
        cout << "1. Search Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Reserve Book\n";
        cout << "5. View Profile\n";
        cout << "6. Logout\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            searchBook();
            break;
        case 2:
            borrowBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            reserveBook();
            break;
        case 5:
            viewProfile();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}