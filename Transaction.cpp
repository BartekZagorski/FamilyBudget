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
void Transaction::setAmount (float amount)
{
    this -> amount = amount;
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
