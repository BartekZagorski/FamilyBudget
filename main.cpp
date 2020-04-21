#include <iostream>
#include "User.h"

using namespace std;

int main()
{
    User user;
    user.setUserId(3);
    cout<<user.getUserId();
    return 0;
}
