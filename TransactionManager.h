#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "FileWithTransactions.h"

using namespace std;

class TransactionManager
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    FileWithTransactions fileWithIncomes;
    FileWithTransactions fileWithExpenses;

    public:
    TransactionManager(string, string, int = 0);
    int getLoggedInUserId();

};

#endif
