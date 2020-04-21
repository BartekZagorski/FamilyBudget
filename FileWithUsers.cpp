#include "FileWithUsers.h"

FileWithUsers::FileWithUsers (string fileName)
:XmlFile(fileName)
{};

vector <User> FileWithUsers::loadUsersFromXmlFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists) {}
    else
    {
        xml.FindElem("USERS");
        xml.IntoElem();
        while (xml.FindElem("USER"))
        {
            xml.IntoElem();
            xml.FindElem( "UserID" );
            user.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem( "firstName" );
            user.setFirstName(xml.GetData());
            xml.FindElem( "lastName" );
            user.setLastName(xml.GetData());
            xml.FindElem( "login" );
            user.setLogin(xml.GetData());
            xml.FindElem( "password" );
            user.setPassword(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::appendUserToFile(User user)
{
CMarkup xml;

bool fileExists = xml.Load( getFileName().c_str() );

if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("USERS");
    }

xml.FindElem();
xml.IntoElem();

xml.AddElem( "USER" );
xml.IntoElem();
xml.AddElem( "UserID", user.getUserId() );
xml.AddElem( "firstName", user.getFirstName() );
xml.AddElem( "lastName", user.getLastName() );
xml.AddElem( "login", user.getLogin() );
xml.AddElem( "password", user.getPassword() );

xml.Save(getFileName().c_str());
}
