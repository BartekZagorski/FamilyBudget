#ifndef FAMILYBUDGET_H
#define FAMILYBUDGET_H

#include <iostream>
#include <vector>
#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class FamilyBudget
{
    UserManager userManager;
    TransactionManager* transactionManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    FamilyBudget(string = "users.xml", string = "incomes.xml", string = "expenses");
    ~FamilyBudget();
    void registerNewUser();
    void login();
};

#endif
