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

Transaction TransactionManager::enterNewTransactionData(string typeOfTransaction)
{
    Transaction newTransaction;
    string loadedLine = "";


    if (typeOfTransaction == "income")
        newTransaction.setTransactionId(fileWithIncomes.getLastTransactionId()+1);
    else
        newTransaction.setTransactionId(fileWithExpenses.getLastTransactionId()+1);

    newTransaction.setUserId(LOGGED_IN_USER_ID);

    Date date;
    cout << "Podaj date w formacie rrrr-mm-dd: ";
    date.enterTheDate();
    newTransaction.setDate(date);
    cout << endl <<"Podaj Kwote: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newTransaction.setAmount(atof(loadedLine.c_str()));
    cout << endl <<"Podaj komentarz: ";
    loadedLine = AuxilliaryMethods::loadLine();
    newTransaction.setItem(loadedLine);

    return newTransaction;
}

int TransactionManager::addTransaction(string typeOfTransaction)
{
    Transaction newTransaction = enterNewTransactionData(typeOfTransaction);
    if (typeOfTransaction == "income")
    {
        incomes.push_back(newTransaction);
        fileWithIncomes.appendTransactionToFile(newTransaction);
        cout << "Dodano przychod." << endl;
    }
    else
    {
        expenses.push_back(newTransaction);
        fileWithExpenses.appendTransactionToFile(newTransaction);
        cout << "Dodano wydatek." << endl;
    }
    system ("pause");
    return newTransaction.getTransactionId();
}

