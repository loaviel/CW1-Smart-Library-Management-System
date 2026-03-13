#include "FileManager.h"
#include "Member.h"
#include "Admin.h"
#include "Librarian.h"
#include <fstream>

vector<User*> FileManager::loadUsers()
{
    vector<User*> users;

    ifstream file("users.txt");

    string id, username, password, email, name, role;

    while (file >> id >> username >> password >> email >> name >> role)
    {
        if (role == "MEMBER")
            users.push_back(new Member(id, username, password, email, name));

        else if (role == "LIBRARIAN")
            users.push_back(new Librarian(id, username, password, email, name));

        else if (role == "ADMIN")
            users.push_back(new Admin(id, username, password, email, name));
    }

    return users;
}

void FileManager::saveUser(User* user)
{
    ofstream file("users.txt", ios::app);

    file << user->getUserID() << " "
        << user->getUsername() << " "
        << "password "
        << "email "
        << "name "
        << user->getRole()
        << endl;

    file.close();
}