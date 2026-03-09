#include "User.h"
#include <iostream>

User::User() {}

User::User(string id, string uname, string pass, string mail, string fullname, RoleType role) {

    userID = id;
    username = uname;
    password = pass;
    email = mail;
    name = fullname;
    this->role = role;

}

User::~User() {}

bool User::checkPassword(string pass) {

    return pass == password;

}

string User::getUsername() {
    return username;
}

string User::getUserID() {
    return userID;
}

RoleType User::getRole() {
    return role;
}

void User::viewProfile() {

    cout << "User ID: " << userID << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
}