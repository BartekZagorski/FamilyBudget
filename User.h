#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
private:
    int userId;
    string firstName, lastName, login, password;
public:
    User(int = 0, string = "", string = "", string = "", string ="");
    int getUserId();
    string getFirstName();
    string getLastName();
    string getLogin();
    string getPassword();
    void setUserId(int userId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setLogin(string login);
    void setPassword(string password);
};

#endif // USER
