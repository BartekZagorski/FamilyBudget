#include "Transaction.h"

Transaction::Transaction(int transactionId, int userId, int mergedDate, float amount, string item)
:date(mergedDate)
{
    this->transactionId = transactionId;
    this->userId = userId;
    this->amount = amount;
    this->item = item;
}

void Transaction::setTransactionId (int transactionId)
{
    this -> transactionId = transactionId;
}
void Transaction::setUserId (int userId)
{
    this -> userId = userId;
}
void Transaction::setDate (Date date)
{
    this -> date = date;
}
bool Transaction::setAmount (string amount)
{
    if (isAmountGood(amount))
    {
        this -> amount = atof(amount.c_str());
        return true;
    }
    else
    {
        cout << "Podana kwota jest nieprawidlowa." << endl;
        system ("pause");
        return false;
    }

}
void Transaction::setItem (string item)
{
    this -> item = item;
}
int Transaction::getTransactionId()
{
    return transactionId;
}
int Transaction::getUserId()
{
    return userId;
}
Date Transaction::getDate()
{
    return date;
}
float Transaction::getAmount()
{
    return amount;
}
string Transaction::getItem()
{
    return item;
}
bool Transaction::isAmountGood(string& loadedLine)
{
    if (loadedLine.length() == 0)
        return false;
    int numberOfSeparators = 0;
    for (int i = 0; i < loadedLine.length(); ++i)
    {
        if (numberOfSeparators > 1)
            return false;
        if (i == 0)
        {
            if (!isdigit(loadedLine[i]))
                return false;
        }
        else if (!isdigit(loadedLine[i]))
        {
            if (loadedLine[i] != ',' && loadedLine[i] != '.')
                return false;
            else
            {
                numberOfSeparators++;
                if (loadedLine[i] == ',')
                    loadedLine[i] = '.';
            }
        }
    }
    return true;
}
string Transaction::enterAmount()
{
    string amount = "";
    do
    {
        cout << "Podaj Kwote: ";
        amount = AuxilliaryMethods::loadLine();
    }
    while (!setAmount(amount));
    return amount;
}

