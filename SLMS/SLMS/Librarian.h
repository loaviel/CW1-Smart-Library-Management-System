#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

class Librarian : public User {

public:

    Librarian();
    Librarian(string id, string uname, string pass, string mail, string fullname);

    void addBook();
    void deleteBook();
    void updateBookStatus();

    void generateReport();

    void menu() override;

};

#endif