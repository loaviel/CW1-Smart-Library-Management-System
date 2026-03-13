#ifndef ENUMS_H
#define ENUMS_H

enum RoleType {
    MEMBER,
    LIBRARIAN,
    ADMINISTRATOR
};

enum BookStatus {
    AVAILABLE,
    BORROWED,
    RESERVED
};

enum NotificationType {
    DUEDATE,
    OVERDUE,
    RESERVATION
};

#endif