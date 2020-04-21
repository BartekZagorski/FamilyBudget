#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsers.h"

using namespace std;

int main()
{
    User user1(1, "Bartek", "Zagorski", "zagora17", "123456");
    User user2 (2, "Emilka", "Zagorska", "emilia91", "654321");
    FileWithUsers file("users.xml");
    file.appendUserToFile(user1);
    file.appendUserToFile(user2);
    vector <User> users;
    users = file.loadUsersFromXmlFile();
    for (vector<User>::iterator itr = users.begin(); itr < users.end(); ++itr)
    {
        cout << itr->getUserId() << endl << itr->getFirstName() << endl << itr->getLastName() <<
        endl << itr->getLogin() << endl << itr->getPassword()<<endl<<endl;
    }
    return 0;
}
