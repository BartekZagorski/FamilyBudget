#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "XmlFile.h"
#include "Transaction.h"
#include "Markup.h"

using namespace std;

class FileWithTransactions : public XmlFile
{
    int lastTransactionId;

public:
    FileWithTransactions (string = "transactions.xml", int = 0);
    int getLastTransactionId();
    void setLastTransactionId(int lastTransactionId);
    void appendTransactionToFile(Transaction transaction);
    vector <Transaction> loadLoggedInUserTransactionFromFile(int loggedInUserId);
    void editTransactionInsideFile(Transaction transaction);
    void deleteTransactionFromFile(int transactionId);
};

#endif
