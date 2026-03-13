#include "NotificationSystem.h"
#include <fstream>
#include <ctime>

void NotificationSystem::createMessage(
    NotificationType type,
    string recipientID,
    string message)
{
    ofstream file("notifications.txt", ios::app);

    time_t now = time(0);

    file << recipientID << " "
        << message << " "
        << now << endl;

    file.close();
}