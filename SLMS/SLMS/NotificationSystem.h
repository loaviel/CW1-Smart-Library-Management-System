#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
#include "Enums.h"

using namespace std;

class NotificationSystem {

public:

    static void createMessage(NotificationType type, string recipientID, string message);

};

#endif