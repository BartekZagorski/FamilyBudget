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
        {
            fileWithIncomes.setLastTransactionId(fileWithIncomes.getLastTransactionId()+1);
            newTransaction.setTransactionId(fileWithIncomes.getLastTransactionId());
        }
    else
        {
            fileWithExpenses.setLastTransactionId(fileWithExpenses.getLastTransactionId()+1);
            newTransaction.setTransactionId(fileWithExpenses.getLastTransactionId());
        }
    newTransaction.setUserId(LOGGED_IN_USER_ID);
    Date date;
    cout << "Czy chcesz dodac transakcje z dnia dzisiejszego? (t/n)";
    char choice;
    while (choice != 't' && choice != 'n' && choice != 'T' && choice != 'N')
    {
        choice = getch();
    }
    if (choice == 't' || choice == 'T')
        date.getTodayDate();
    else
        date.enterTheDate();
    newTransaction.setDate(date);
    loadedLine = newTransaction.enterAmount();
    system("cls");
    cout << "Podaj komentarz: ";
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
                string amount = "";
                amount = incomes[indexOfTransaction].enterAmount();
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
                string amount = "";
                amount = expenses[indexOfTransaction].enterAmount();
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

void TransactionManager::showAllIncomes()
{
    sortIncomesByDate();
    vector <Transaction>::iterator itr = incomes.begin();
    for (itr; itr < incomes.end(); ++itr)
    {
        cout << itr -> getTransactionId() <<
        endl << itr->getDate().convertDateFromIntegerToStringSeparatedByDashes()
        << endl << fixed << setprecision(2) << itr->getAmount() << endl << itr->getItem()
        << endl << endl;
    }
}

bool TransactionManager::compareByDate (Transaction first, Transaction second)
{
    return (first.getDate().getMergedDate() < second.getDate().getMergedDate());
}

void TransactionManager::sortIncomesByDate()
{
    sort(incomes.begin(), incomes.end(), TransactionManager::compareByDate);
}

void TransactionManager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end(), TransactionManager::compareByDate);
}

void TransactionManager::showStatementOfCurrentMonth()
{
    Date dateOfBegin, dateOfEnd;
    int numberOfIncomes = 0, numberOfExpenses = 0;
    float sumOfIncomes = 0, sumOfExpenses = 0, balance = 0;

    dateOfBegin.returnDateOfTheBeginningOfTheCurrentMonth();
    dateOfEnd.returnDateOfTheEndOfTheCurrentMonth();
    sortIncomesByDate();
    vector <Transaction>::iterator itr = incomes.begin();
    system ("cls");
    for (itr; itr < incomes.end(); ++itr)
    {
        if (itr->getDate().getMergedDate() >= dateOfBegin.getMergedDate()
            && itr->getDate().getMergedDate() <= dateOfEnd.getMergedDate())
        {
            if (numberOfIncomes == 0)
                cout << "Przychody w biezacym miesiacu: " << endl << endl;
            cout << "Lp. " << numberOfIncomes + 1 << endl
            << "Data transakcji: " << itr->getDate().convertDateFromIntegerToStringSeparatedByDashes()
            << endl << "Kwota transakcji: " << fixed << setprecision(2) << itr->getAmount() << endl
            << "Komentarz: " << itr->getItem() << endl
            << "ID przychodu: " << itr -> getTransactionId() << endl << endl;
            numberOfIncomes++;
            sumOfIncomes += itr->getAmount();
        }
    }
    if (numberOfIncomes == 0)
        cout << "Brak przychodow w biezacym miesiacu." << endl;
    cout << "----------------------------------------------------\n\n";

    sortExpensesByDate();
    itr = expenses.begin();
    for (itr; itr < expenses.end(); ++itr)
    {
        if (itr->getDate().getMergedDate() >= dateOfBegin.getMergedDate()
            && itr->getDate().getMergedDate() <= dateOfEnd.getMergedDate())
        {
            if (numberOfExpenses == 0)
                cout << "Wydatki w biezacym miesiacu: " << endl << endl;
            cout << "Lp. " << numberOfExpenses + 1 << endl
            << "Data transakcji: " << itr->getDate().convertDateFromIntegerToStringSeparatedByDashes()
            << endl << "Kwota transakcji: " << fixed << setprecision(2) << itr->getAmount() << endl
            << "Komentarz: " << itr->getItem() << endl
            << "ID wydatku: " << itr -> getTransactionId() << endl << endl;
            numberOfExpenses++;
            sumOfExpenses += itr->getAmount();
        }
    }
    if (numberOfExpenses == 0)
        cout << "Brak wydatkow w biezacym miesiacu." << endl;
    cout << "----------------------------------------------------\n\n";

    cout << "Suma przychodow w biezacym miesiacu: " << sumOfIncomes << endl;
    cout << "Suma wydatkow w biezacym miesiacu: " << sumOfExpenses << endl;
    balance = sumOfIncomes - sumOfExpenses;
    cout << "Saldo w biezacym miesiacu: " << balance << endl;
    system("pause");
}

void TransactionManager::showStatementOfPreviousMonth()
{
    Date dateOfBegin, dateOfEnd;
    int numberOfIncomes = 0, numberOfExpenses = 0;
    float sumOfIncomes = 0, sumOfExpenses = 0, balance = 0;

    dateOfBegin.returnDateOfTheBeginningOfPreviousMonth();
    dateOfEnd.returnDateOfTheEndOfPreviousMonth();
    sortIncomesByDate();
    vector <Transaction>::iterator itr = incomes.begin();
    system ("cls");
    for (itr; itr < incomes.end(); ++itr)
    {
        if (itr->getDate().getMergedDate() >= dateOfBegin.getMergedDate()
            && itr->getDate().getMergedDate() <= dateOfEnd.getMergedDate())
        {
            if (numberOfIncomes == 0)
                cout << "Przychody w poprzednim miesiacu: " << endl << endl;
            cout << "Lp. " << numberOfIncomes + 1 << endl
            << "Data transakcji: " << itr->getDate().convertDateFromIntegerToStringSeparatedByDashes()
            << endl << "Kwota transakcji: " << fixed << setprecision(2) << itr->getAmount() << endl
            << "Komentarz: " << itr->getItem() << endl
            << "ID przychodu: " << itr -> getTransactionId() << endl << endl;
            numberOfIncomes++;
            sumOfIncomes += itr->getAmount();
        }
    }
    if (numberOfIncomes == 0)
        cout << "Brak przychodow w poprzednim miesiacu." << endl;
    cout << "----------------------------------------------------\n\n";

    sortExpensesByDate();
    itr = expenses.begin();
    for (itr; itr < expenses.end(); ++itr)
    {
        if (itr->getDate().getMergedDate() >= dateOfBegin.getMergedDate()
            && itr->getDate().getMergedDate() <= dateOfEnd.getMergedDate())
        {
            if (numberOfExpenses == 0)
                cout << "Wydatki w poprzednim miesiacu: " << endl << endl;
            cout << "Lp. " << numberOfExpenses + 1 << endl
            << "Data transakcji: " << itr->getDate().convertDateFromIntegerToStringSeparatedByDashes()
            << endl << "Kwota transakcji: " << fixed << setprecision(2) << itr->getAmount() << endl
            << "Komentarz: " << itr->getItem() << endl
            << "ID wydatku: " << itr -> getTransactionId() << endl << endl;
            numberOfExpenses++;
            sumOfExpenses += itr->getAmount();
        }
    }
    if (numberOfExpenses == 0)
        cout << "Brak wydatkow w poprzednim miesiacu." << endl;
    cout << "----------------------------------------------------\n\n";

    cout << "Suma przychodow w poprzednim miesiacu: " << sumOfIncomes << endl;
    cout << "Suma wydatkow w poprzednim miesiacu: " << sumOfExpenses << endl;
    balance = sumOfIncomes - sumOfExpenses;
    cout << "Saldo w poprzednim miesiacu: " << balance << endl;
    system("pause");
}
