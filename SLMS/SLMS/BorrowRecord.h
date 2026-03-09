#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <string>

using namespace std;

class BorrowRecord {

private:

    string recordID;
    string bookID;
    string borrowerID;
    string borrowDate;
    string dueDate;
    string returnDate;

public:

    BorrowRecord();

    bool isOverdue();

    double calculateFine();

};

#endif