#include "TransactionManager.h"

TransactionManager::TransactionManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int loggedInUserId)
:
fileWithIncomes(nameOfFileWithIncomes),
fileWithExpenses(nameOfFileWithExpenses),
LOGGED_IN_USER_ID(loggedInUserId)
{
    incomes = fileWithIncomes.loadLoggedInUserTransactionFromFile(LOGGED_IN_USER_ID);
    expenses = fileWithExpenses.loadLoggedInUserTransactionFromFile(LOGGED_IN_USER_ID);
}

int TransactionManager::getLoggedInUserId()
{
    return LOGGED_IN_USER_ID;
}
