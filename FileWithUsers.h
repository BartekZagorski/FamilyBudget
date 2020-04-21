#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers(string = "");
    vector <User> loadUsersFromXmlFile();
    void appendUserToFile(User user);
};

#endif
