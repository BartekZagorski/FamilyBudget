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

void TransactionManager::editTransaction(string typeOfTransaction)
{
    int idGivenByUser = 0;
    int indexOfTransaction = 0;
    cout << "podaj ID przychodu, ktory chcesz edytowac. ";
    cin >> idGivenByUser;
    indexOfTransaction = findIndexOfTransaction(idGivenByUser, "income");
    char choice = AuxilliaryMethods::chooseOptionFromEditionMenu();

    switch (choice)
    {
    case '1':
    {
        Date date;
        incomes[indexOfTransaction].setDate(date.enterTheDate());
        fileWithIncomes.editTransactionInsideFile(incomes[indexOfTransaction]);
        cout << "edycja zakonczona pomyslnie" << endl;
        system ("pause");
        break;
    }
    case '2':
    {
        float amount = 0;
        cout << "podaj kwote: ";
        cin >> amount;
        incomes[indexOfTransaction].setAmount(amount);
        fileWithIncomes.editTransactionInsideFile(incomes[indexOfTransaction]);
        cout << "edycja zakonczona pomyslnie" << endl;
        system ("pause");
        break;
    }

    }
}

int TransactionManager::findIndexOfTransaction (int transactionId, string typeOfTransaction)
{
    if (typeOfTransaction == "income")
    {
        for (int i = 0; i < incomes.size(); i++)
        {
            if (incomes[i].getTransactionId() == transactionId)
                return i;
        }
    }
    else
    {
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getTransactionId() == transactionId)
                return i;
        }
    }


}
