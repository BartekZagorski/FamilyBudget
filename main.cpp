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
    f1.showStatementOfCurrentMonth();
   // f1.addIncome();
   // f1.showAllIncomes();
   f1.showStatementOfPreviousMonth();



    return 0;
}
