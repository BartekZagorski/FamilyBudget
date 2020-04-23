#ifndef FAMILYBUDGET_H
#define FAMILYBUDGET_H

#include <iostream>
#include <vector>
#include "UserManager.h"

using namespace std;

class FamilyBudget
{
    UserManager userManager;

public:
    FamilyBudget(string = "users.xml");
    void registerNewUser();
};

#endif
