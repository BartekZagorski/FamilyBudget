#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    FileWithUsers fileWithUsers;
    vector <User> users;

    bool doesLoginExist(string login);
    int getNewUserId();

public:
    UserManager(int = 0, string = "users.xml");
    int getLoggedInUserId();
    FileWithUsers getFileWithUsers();
};


#endif
