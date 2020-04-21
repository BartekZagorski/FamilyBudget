#include <iostream>
#include "User.h"

User::User(int userId, string firstName, string lastName, string login, string password)
{
    this->userId = userId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->login = login;
    this->password = password;
}

int User::getUserId()
{
    return userId;
}
string User::getFirstName()
{
    return firstName;
}
string User::getLastName()
{
    return lastName;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
void User::setUserId(int userId)
{
    this->userId = userId;
}
void User::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void User::setLastName(string lastName)
{
    this->lastName = lastName;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setPassword(string password)
{
    this->password = password;
}
