#ifndef USER_H
#define USER_H

#include <string>
#include "Enums.h"

using namespace std;

class User {

protected:

    string userID;
    string username;
    string password;
    string email;
    string name;
    RoleType role;

public:

    User();
    User(string id, string uname, string pass, string email, string name, RoleType role);

    virtual ~User();

    string getUsername();
    string getUserID();
    RoleType getRole();

    bool checkPassword(string pass);

    virtual void viewProfile();

    virtual void menu() = 0;

};

#endif