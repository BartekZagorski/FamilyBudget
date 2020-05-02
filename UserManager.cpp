#include "UserManager.h"

UserManager::UserManager (string fileName, int loggedInUserId)
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
            cout << "Istnieje uzytkownik o takim loginie. Wpisz inny." << endl;
            system("pause");
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
        system("cls");
        cout << "Podaj login: ";
        loadedLine = AuxilliaryMethods::loadLine();
    }
    while (doesLoginExist(loadedLine));
    newUser.setLogin(loadedLine);
    cout << "Podaj Imie: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setFirstName(loadedLine);
    cout << "Podaj Nazwisko: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setLastName(loadedLine);
    cout << "Podaj Haslo: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newUser.setPassword(loadedLine);

    return newUser;
}

void UserManager::registerNewUser()
{
    User newUser = addDataOfNewUser();
    users.push_back(newUser);
    fileWithUsers.appendUserToFile(newUser);

    cout << "Konto zalozono pomyslnie." << endl;
    system ("pause");
}

int UserManager::login()
{
    string login = "";
    string password = "";

    cout << "Podaj login: ";
    login = AuxilliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "podaj haslo: ";
                password = AuxilliaryMethods::loadLine();
                if (users[i].getPassword() == password)
                {
                    cout << "zalogowales sie." << endl;
                    system ("pause");
                    loggedInUserId = users[i].getUserId();
                    return loggedInUserId;
                }
                else
                {
                    cout << "podane haslo jest nieprawidlowe." << endl;
                    system ("pause");
                }
            }
            cout << "3 razy podano bledne haslo." << endl;
            system ("pause");
            return 0;
        }
    }

    cout << "Nie istnieje uzytkownik o podanym loginie." <<endl;
    system ("pause");
    return 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

void UserManager::changeLoggedInUserPassword()
{
    string password = "";
    cout << "podaj nowe haslo: ";
    password = AuxilliaryMethods::loadLine();

    for (vector<User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedInUserId)
        {
            itr -> setPassword(password);
            fileWithUsers.changePasswordInXmlFile(*itr);
            cout << "haslo zostalo zmienione." <<endl;
            system ("pause");
            break;
        }
    }
}
