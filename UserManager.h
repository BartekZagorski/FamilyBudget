#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxilliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    FileWithUsers fileWithUsers;
    vector <User> users;

    bool doesLoginExist(string login);
    int getNewUserId();


public:
    UserManager(string = "users.xml", int = 0);
    int getLoggedInUserId();
    void setLoggedInUserId(int loggedInUserId);
    FileWithUsers getFileWithUsers();
    User addDataOfNewUser();
    void registerNewUser();
    int login();
    bool isUserLoggedIn();
};


#endif
