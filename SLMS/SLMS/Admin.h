#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {

public:

    Admin();
    Admin(string id, string uname, string pass, string mail, string fullname);

    void createAccount();
    void deleteAccount();
    void assignRole();

    void changeBorrowLimit();

    void changeLatePenalty();
    void menu() override;

};

#endif