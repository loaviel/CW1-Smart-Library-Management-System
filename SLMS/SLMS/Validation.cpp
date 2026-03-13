#include "Validation.h"
#include <fstream>

using namespace std;

bool isValidEmail(string email)
{
    if (email.find('@') == string::npos) return false;
    if (email.find('.') == string::npos) return false;
    if (email.length() < 6) return false;

    return true;
}

bool usernameExists(string username)
{
    ifstream file("users.txt");

    string id, u, p, e, n, r;

    while (file >> id >> u >> p >> e >> n >> r)
    {
        if (u == username)
        {
            return true;
        }
    }

    return false;
}