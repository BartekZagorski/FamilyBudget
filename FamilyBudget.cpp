#include "FamilyBudget.h"

FamilyBudget::FamilyBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
:
userManager(nameOfFileWithUsers),
NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),
NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
{
    transactionManager = NULL;
}

FamilyBudget::~FamilyBudget()
{
    delete transactionManager;
    transactionManager = NULL;
}

void FamilyBudget::registerNewUser()
{
    userManager.registerNewUser();
}
