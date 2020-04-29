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

void FamilyBudget::login()
{
    userManager.login();
    if (userManager.isUserLoggedIn())
    {
        transactionManager = new TransactionManager("incomes.xml", "expenses.xml", userManager.getLoggedInUserId());
    }
}
void FamilyBudget::logOut()
{
    userManager.setLoggedInUserId(0);
    delete transactionManager;
    transactionManager = NULL;
}

void FamilyBudget::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

void FamilyBudget::addIncome()
{
    transactionManager -> addTransaction("income");
}
void FamilyBudget::addExpense()
{
    transactionManager -> addTransaction("expense");
}
void FamilyBudget::editIncome()
{
    transactionManager -> editTransaction("income");
}
void FamilyBudget::editExpense()
{
    transactionManager -> editTransaction("expense");
}
void FamilyBudget::deleteIncome()
{
    transactionManager -> deleteTransaction("income");
}
void FamilyBudget::deleteExpense()
{
    transactionManager -> deleteTransaction("expense");
}
