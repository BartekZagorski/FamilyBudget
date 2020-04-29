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
    if (typeOfTransaction == "income")
    {
        cout << "podaj ID przychodu, ktory chcesz edytowac. ";
        cin >> idGivenByUser;
        indexOfTransaction = findIndexOfTransaction(idGivenByUser, "income");
        if (indexOfTransaction == -1)
            return;
        char choice = AuxilliaryMethods::chooseOptionFromEditionMenu();

        switch (choice)
        {
        case '1':
            {
                Date date;
                incomes[indexOfTransaction].setDate(date.enterTheDate());
                fileWithIncomes.editTransactionInsideFile(incomes[indexOfTransaction]);
                break;
            }
        case '2':
            {
                float amount = 0;
                cout << "podaj kwote: ";
                cin >> amount;
                incomes[indexOfTransaction].setAmount(amount);
                fileWithIncomes.editTransactionInsideFile(incomes[indexOfTransaction]);
                break;
            }
        case '3':
            {
                string item = "";
                cout << "podaj komentarz: ";
                item = AuxilliaryMethods::loadLine();
                incomes[indexOfTransaction].setItem(item);
                fileWithIncomes.editTransactionInsideFile(incomes[indexOfTransaction]);
                break;
            }
        }
        cout << "edycja zakonczona pomyslnie" << endl;
        system ("pause");
    }
    else
    {
        cout << "podaj ID wydatku, ktory chcesz edytowac. ";
        cin >> idGivenByUser;
        indexOfTransaction = findIndexOfTransaction(idGivenByUser, "expense");
        if (indexOfTransaction == -1)
            return;
        char choice = AuxilliaryMethods::chooseOptionFromEditionMenu();

        switch (choice)
        {
        case '1':
            {
                Date date;
                expenses[indexOfTransaction].setDate(date.enterTheDate());
                fileWithExpenses.editTransactionInsideFile(expenses[indexOfTransaction]);
                break;
            }
        case '2':
            {
                float amount = 0;
                cout << "podaj kwote: ";
                cin >> amount;
                expenses[indexOfTransaction].setAmount(amount);
                fileWithExpenses.editTransactionInsideFile(expenses[indexOfTransaction]);
                break;
            }
        case '3':
            {
                string item = "";
                cout << "podaj komentarz: ";
                item = AuxilliaryMethods::loadLine();
                expenses[indexOfTransaction].setItem(item);
                fileWithExpenses.editTransactionInsideFile(expenses[indexOfTransaction]);
                break;
            }
        }
        cout << "edycja zakonczona pomyslnie" << endl;
        system ("pause");
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
    cout << "Nie odnaleziono podanego ID."<<endl;
    system("pause");
    return -1;
}

int TransactionManager::deleteTransaction(string typeOfTransaction)
{
    int idGivenByUser = 0;
    int indexOfTransaction = 0;
    if (typeOfTransaction == "income")
    {
        cout << "Podaj ID przychodu, ktory chcesz usunac: ";
        cin >> idGivenByUser;
        indexOfTransaction = findIndexOfTransaction(idGivenByUser, "income");
        if (indexOfTransaction == -1)
            return fileWithIncomes.getLastTransactionId();
        char choice;
        do
        {
            system("cls");
            cout << "czy na pewno usunac przychod o ID " << idGivenByUser << "? (t/n) ";
            choice = getch();
        }
        while (choice != 't' && choice != 'n' && choice != 'T' && choice != 'N');
        if (choice == 't' || choice == 'T')
        {
            incomes.erase(incomes.begin() + indexOfTransaction);
            fileWithIncomes.deleteTransactionFromFile(idGivenByUser);
            cout << endl << "usunieto przychod. " << endl;
            system("pause");
            return fileWithIncomes.getLastTransactionId();
        }
        else
        {
            cout << endl << "przychod nie zostal usuniety. " << endl;
            system("pause");
            return fileWithIncomes.getLastTransactionId();
        }
    }
    else
    {
        cout << "Podaj ID wydatku, ktory chcesz usunac: ";
        cin >> idGivenByUser;
        indexOfTransaction = findIndexOfTransaction(idGivenByUser, "expense");
        if (indexOfTransaction == -1)
            return fileWithExpenses.getLastTransactionId();
        char choice;
        do
        {
            system("cls");
            cout << "czy na pewno usunac wydatek o ID " << idGivenByUser << "? (t/n) ";
            choice = getch();
        }
        while (choice != 't' && choice != 'n' && choice != 'T' && choice != 'N');
        if (choice == 't' || choice == 'T')
        {
            expenses.erase(expenses.begin() + indexOfTransaction);
            fileWithExpenses.deleteTransactionFromFile(idGivenByUser);
            cout << endl << "usunieto wydatek. " << endl;
            system("pause");
            return fileWithExpenses.getLastTransactionId();
        }
        else
        {
            cout << endl << "wydatek nie zostal usuniety. " << endl;
            system("pause");
            return fileWithExpenses.getLastTransactionId();
        }
    }
}
