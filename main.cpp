#include <iostream>
#include <vector>
#include "FamilyBudget.h"
#include "UserManager.h"

#include "FileWithTransactions.h"

using namespace std;

int main()
{
    FamilyBudget f1;
    f1.login();
    f1.deleteExpense();





    //Transaction t1(3,1,20000101,150.51,"proba");
    //FileWithTransactions file1("incomes.xml");
    //file1.appendTransactionToFile(t1);
    //file1.deleteTransactionFromFile(1);
    /*vector <Transaction> v1;
    v1 = file1.loadLoggedInUserTransactionFromFile(0);
    vector<Transaction>::iterator itr = v1.begin();
    for (itr; itr<v1.end();itr++)
    {
        cout << itr->getTransactionId() << endl
        << itr->getUserId() << endl
        << itr->getDate().getMergedDate() << endl
        << itr->getAmount() << endl
        << itr->getItem() << endl;
    }*/
    return 0;
}
