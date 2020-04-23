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

void UserManager::setLoggedInUserId(int loggedInUserId)
{
    this->loggedInUserId = loggedInUserId;
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
            cout << endl << "Istnieje uzytkownik o takim loginie. Wpisz inny." << endl;
            system("pause");
            system("cls");
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

User UserManager::addDataOfNewUser()
{
    User newUser;
    string loadedLine="";

    newUser.setUserId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        loadedLine = AuxilliaryMethods::loadLine();
    }
    while (doesLoginExist(loadedLine));
    newUser.setLogin(loadedLine);
    cout << endl <<"Podaj Imie: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setFirstName(loadedLine);
    cout << endl <<"Podaj Nazwisko: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setLastName(loadedLine);
    cout << endl <<"Podaj Haslo: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setPassword(loadedLine);

    return newUser;
}

void UserManager::registerNewUser()
{
    User newUser = addDataOfNewUser();
    users.push_back(newUser);
    fileWithUsers.appendUserToFile(newUser);

    cout << "Konto zalozono pomyslnie.";
    system ("pause");
}
