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
    FamilyBudget(string = "users.xml", string = "incomes.xml", string = "expenses.xml");
    ~FamilyBudget();
    void registerNewUser();
    void login();
    void logOut();
    void changeLoggedInUserPassword();
    void addIncome();
    void addExpense();
    void editIncome();
    void editExpense();
    void deleteIncome();
    void deleteExpense();
    void showAllIncomes();
};

#endif
