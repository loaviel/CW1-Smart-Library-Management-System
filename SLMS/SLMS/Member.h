#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"

class Member : public User {

private:

    int borrowLimit;
    int currentBorrowed;

public:

    Member();
    Member(string id, string uname, string pass, string email, string name);

    void searchBook();
    void borrowBook();
    void returnBook();
    void reserveBook();

    void menu() override;

};

#endif