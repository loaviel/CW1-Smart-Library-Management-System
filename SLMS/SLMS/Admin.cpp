#include "Admin.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Validation.h"
#include <string>
Admin::Admin() {}

Admin::Admin(string id, string uname, string pass, string mail, string fullname) : User(id, uname, pass, mail, fullname, ADMINISTRATOR)
{
}

void Admin::createAccount()
{
    string id;
    string username;
    string password;
    string email;
    string name;
    string roleInput;
    string role;

    cout << "\n===== CREATE ACCOUNT =====\n";

    cout << "Enter User ID: ";
    cin >> id;

    cout << "Enter Full Name: ";
    cin >> name;

    do
    {
        cout << "Enter Username (min 3 characters): ";
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
        cout << "Enter Password (min 5 characters): ";
        cin >> password;

        if (password.length() < 5)
            cout << "Password must be at least 5 characters.\n";

    } while (password.length() < 5);

    do
    {
        cout << "Enter Email: ";
        cin >> email;

        if (!isValidEmail(email))
            cout << "Invalid email format.\n";

    } while (!isValidEmail(email));

    cout << "Enter role (ADMIN / LIBRARIAN / MEMBER): ";
    cin >> roleInput;

    transform(roleInput.begin(), roleInput.end(), roleInput.begin(), ::toupper);

    if (roleInput == "ADMIN")
        role = "ADMIN";
    else if (roleInput == "LIBRARIAN")
        role = "LIBRARIAN";
    else
        role = "MEMBER";

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

void Admin::deleteAccount()
{
    string username;

    cout << "Enter username to delete: ";
    cin >> username;

    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string id, u, p, e, n, r;

    bool found = false;

    while (file >> id >> u >> p >> e >> n >> r)
    {
        if (u == username)
        {
            found = true;
            continue;
        }

        temp << id << " "
            << u << " "
            << p << " "
            << e << " "
            << n << " "
            << r << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
        cout << "Account deleted.\n";
    else
        cout << "User not found.\n";
}
void Admin::assignRole()
{
    string username;
    string newRole;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter new role (MEMBER/LIBRARIAN/ADMIN): ";
    cin >> newRole;

    ifstream file("users.txt");
    ofstream temp("temp.txt");

    string id, u, p, e, n, r;

    while (file >> id >> u >> p >> e >> n >> r)
    {
        if (u == username)
            r = newRole;

        temp << id << " "
            << u << " "
            << p << " "
            << e << " "
            << n << " "
            << r << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");

    cout << "Role updated.\n";
}

void Admin::changeBorrowLimit()
{
    int newLimit;
    cout << "Enter new borrow limit for members: ";
    cin >> newLimit;

    ifstream infile("settings.txt");
    string line, content;
    bool updated = false;

    while (getline(infile, line))
    {
        if (line.find("BORROW_LIMIT") != string::npos)
        {
            content += "BORROW_LIMIT " + to_string(newLimit) + "\n";
            updated = true;
        }
        else
        {
            content += line + "\n";
        }
    }
    infile.close();

    if (!updated)
        content += "BORROW_LIMIT " + to_string(newLimit) + "\n";

    ofstream outfile("settings.txt");
    outfile << content;
    outfile.close();

    cout << "Borrow limit updated to " << newLimit << ".\n";
}

void Admin::changeLatePenalty()
{
    double newPenalty;
    cout << "Enter new late penalty fee: ";
    cin >> newPenalty;

    ifstream infile("settings.txt");
    string line, content;
    bool updated = false;

    while (getline(infile, line))
    {
        if (line.find("LATE_PENALTY") != string::npos)
        {
            content += "LATE_PENALTY " + to_string(newPenalty) + "\n";
            updated = true;
        }
        else
        {
            content += line + "\n";
        }
    }
    infile.close();

    if (!updated)
        content += "LATE_PENALTY " + to_string(newPenalty) + "\n";

    ofstream outfile("settings.txt");
    outfile << content;
    outfile.close();

    cout << "Late penalty updated to " << newPenalty << ".\n";
}
void Admin::menu()
{
    int choice;

    while (true)
    {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Delete Account\n";
        cout << "3. Assign Role\n";
        cout << "4. Change Borrow Limit\n";
        cout << "5. Change Late Penalty\n";
        cout << "6. Logout\n";

        cin >> choice;

        switch (choice)
        {
        case 1: createAccount(); break;
        case 2: deleteAccount(); break;
        case 3: assignRole(); break;
        case 4: changeBorrowLimit(); break;
        case 5: changeLatePenalty(); break;
        case 6: return;
        default: cout << "Invalid choice.\n";
        }
    }
}