#include "FileWithTransactions.h"

FileWithTransactions::FileWithTransactions (string fileName, int lastTransactionId)
:XmlFile(fileName)
{
    this -> lastTransactionId = lastTransactionId;
}

int FileWithTransactions::getLastTransactionId()
{
    return lastTransactionId;
}
void FileWithTransactions::setLastTransactionId(int lastTransactionId)
{
    this -> lastTransactionId = lastTransactionId;
}

void FileWithTransactions::appendTransactionToFile(Transaction transaction)
{
CMarkup xml;

bool fileExists = xml.Load( getFileName().c_str() );

if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("TRANSACTIONS");
    }

xml.FindElem();
xml.IntoElem();

xml.AddElem( "TRANSACTION" );
xml.IntoElem();
xml.AddElem( "TransactionID", transaction.getTransactionId() );
xml.AddElem( "UserID", transaction.getUserId() );
xml.AddElem( "date", transaction.getDate().convertDateFromIntegerToStringSeparatedByDashes() );
xml.AddElem( "amount", AuxilliaryMethods::convertFloatToString(transaction.getAmount()) );
xml.AddElem( "item", transaction.getItem() );

xml.Save(getFileName().c_str());
}

vector <Transaction> FileWithTransactions::loadLoggedInUserTransactionFromFile(int loggedInUserId)
{
    Transaction transaction;
    vector <Transaction> transactions;
    CMarkup xml;

    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists) {}
    else
    {
        xml.FindElem("TRANSACTIONS");
        xml.IntoElem();
        while (xml.FindElem("TRANSACTION"))
        {
            xml.FindChildElem("TransactionID");
            lastTransactionId = atoi(xml.GetChildData().c_str());
            xml.FindChildElem("UserID");
            if (atoi(xml.GetChildData().c_str()) == loggedInUserId)
            {
                xml.IntoElem();
                xml.ResetMainPos();
                xml.FindElem("TransactionID");
                transaction.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem( "UserID" );
                transaction.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem( "date" );
                transaction.setDate(Date::eliminateDashesFromDate(xml.GetData().c_str()));
                xml.FindElem( "amount" );
                transaction.setAmount(atof(xml.GetData().c_str()));
                xml.FindElem( "item" );
                transaction.setItem(xml.GetData());
                xml.OutOfElem();
                transactions.push_back(transaction);
            }
        }
    }
    return transactions;
}

void FileWithTransactions::editTransactionInsideFile(Transaction transaction)
{
    CMarkup xml;

    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists) {}
    else
    {
        xml.FindElem("TRANSACTIONS");
        xml.IntoElem();
        while (xml.FindElem("TRANSACTION"))
        {
            xml.FindChildElem("TransactionID");
            if (atoi(xml.GetChildData().c_str()) == transaction.getTransactionId())
            {
                xml.IntoElem();
                xml.ResetMainPos();
                xml.FindElem("TransactionID");
                xml.SetData(transaction.getTransactionId());
                xml.FindElem( "UserID" );
                xml.SetData(transaction.getUserId());
                xml.FindElem( "date" );
                xml.SetData(transaction.getDate().convertDateFromIntegerToStringSeparatedByDashes());
                xml.FindElem( "amount" );
                xml.SetData(AuxilliaryMethods::convertFloatToString(transaction.getAmount()));
                xml.FindElem( "item" );
                xml.SetData(transaction.getItem());
                break;
            }
        }
    xml.Save(getFileName().c_str());
    }
}

void FileWithTransactions::deleteTransactionFromFile(int transactionId)
{
    CMarkup xml;

    bool fileExists = xml.Load( getFileName().c_str() );

    if (!fileExists) {}
    else
    {
        xml.FindElem("TRANSACTIONS");
        xml.IntoElem();
        while (xml.FindElem("TRANSACTION"))
        {
            xml.FindChildElem("TransactionID");
            if (atoi(xml.GetChildData().c_str()) == transactionId)
            {
                xml.RemoveElem();
                break;
            }
        }
        xml.Save(getFileName().c_str());
    }
}
