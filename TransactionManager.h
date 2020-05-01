#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
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

    Transaction enterNewTransactionData(string typeOfTransaction);
    int findIndexOfTransaction (int transactionId, string typeOfTransaction);
    static bool compareByDate (Transaction first, Transaction second);
    void sortIncomesByDate();
    void sortExpensesByDate();

    public:
    TransactionManager(string = "incomes.xml", string = "expenses.xml", int = 0);
    int getLoggedInUserId();
    int addTransaction(string typeOfTransaction);
    void editTransaction(string typeOfTransaction);
    int deleteTransaction(string typeOfTransaction);
    void showAllIncomes();
    void showStatementOfCurrentMonth();
    void showStatementOfPreviousMonth();

};

#endif
