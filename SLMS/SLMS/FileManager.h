#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "User.h"

class FileManager {

public:

    static vector<User*> loadUsers();

    static void saveUser(User* user);

};

#endif