#include "BorrowRecord.h"

bool BorrowRecord::isOverdue()
{
    if (returnDate == "NULL")
    {
        return true;
    }

    return false;
}

double BorrowRecord::calculateFine()
{
    return 5.0;
}