#include "UserManager.h"

UserManager::UserManager (int loggedInUserId, string fileName)
: fileWithUsers(fileName)
{
    this->loggedInUserId = loggedInUserId;
    users = fileWithUsers.loadUsersFromXmlFile();
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}
FileWithUsers UserManager::getFileWithUsers()
{
    return fileWithUsers;
}
bool UserManager::doesLoginExist(string login)
{
    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}
