#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <limits>
#include "FileManager.h"
#include "Member.h"
#include "Librarian.h"
#include "Admin.h"
#include "Validation.h"

using namespace std;

User* login(vector<User*> users)
{
    string username;
    string password;

    cout << "\nUsername: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (User* user : users)
    {
        if (user->getUsername() == username && user->checkPassword(password))
        {
            return user;
        }
    }

    throw runtime_error("Invalid login.");
}

void createAccount()
{
    string id;
    string username;
    string password;
    string email;
    string name;
    string role;

    cout << "\n--- Create Account ---\n";

    cout << "User ID: ";
    cin >> id;

    do
    {
        cout << "Username (min 3 characters): ";
        cin >> username;

        if (username.length() < 3)
        {
            cout << "Username is too short.\n";
            continue;
        }

        if (usernameExists(username))
        {
            cout << "Username already exists.\n";
            username = "";
        }

    } while (username.length() < 3 || usernameExists(username));

    do
    {
        cout << "Password (min 5 characters): ";
        cin >> password;

        if (password.length() < 5)
        {
            cout << "Password too short.\n";
        }

    } while (password.length() < 5);

    do
    {
        cout << "Email: ";
        cin >> email;

        if (!isValidEmail(email))
        {
            cout << "Invalid email format.\n";
        }

    } while (!isValidEmail(email));

    cout << "Name: ";
    cin >> name;

    transform(role.begin(), role.end(), role.begin(), ::toupper);

    while (role != "MEMBER" && role != "LIBRARIAN" && role != "ADMIN")
    {
        cout << "Invalid role. Enter MEMBER, LIBRARIAN, or ADMIN: ";
        cin >> role;
        transform(role.begin(), role.end(), role.begin(), ::toupper);
    }



    ofstream file("users.txt", ios::app);

    file << id << " "
        << username << " "
        << password << " "
        << email << " "
        << name << " "
        << role << endl;

    file.close();

    cout << "Account created successfully.\n";
}

void mainMenu()
{
    cout << "\n===== CITY LIBRARY =====\n";
    cout << "1. Login\n";
    cout << "2. Create Account\n";
    cout << "3. Exit\n";
}

int main()
{
    vector<User*> users;

    int choice;

    while (true)
    {
        mainMenu();
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        try
        {
            if (choice == 1)
            {
                users = FileManager::loadUsers();

                User* currentUser = login(users);

                cout << "\nLogin successful.\n";

                currentUser->menu();
            }

            else if (choice == 2)
            {
                createAccount();
            }

            else if (choice == 3)
            {
                cout << "Exitting.\n";
                break;
            }

            else
            {
                cout << "Invalid choice.\n";
            }
        }
        catch (exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}