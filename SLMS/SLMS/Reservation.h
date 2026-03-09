#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

class Reservation {

private:

    string reservationID;
    string bookID;
    string reservedBy;
    string reserveDate;
    string expiryDate;

public:

    bool hasExpired();

    bool extendReservation();

};

#endif