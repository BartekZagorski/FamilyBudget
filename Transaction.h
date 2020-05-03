#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <math.h>
#include "Date.h"

using namespace std;

class Transaction
{
    int transactionId;
    int userId;
    Date date;
    float amount;
    string item;

public:

    Transaction(int = 0, int = 0, int = 20000101, float = 0, string = "komentarz");
    void setTransactionId (int transactionId);
    void setUserId (int userId);
    void setDate (Date date);
    bool setAmount (string amount);
    void setItem (string item);
    int getTransactionId();
    int getUserId();
    Date getDate();
    float getAmount();
    string getItem();
    bool isAmountGood(string& loadedLine);
    string enterAmount ();

};

#endif
