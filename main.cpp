#include <iostream>
#include <vector>
#include "FamilyBudget.h"
#include "UserManager.h"

#include "FileWithTransactions.h"

using namespace std;

int main()
{
    FamilyBudget familyBudget;
    char choice;

    while (true)
    {
        if (!familyBudget.isUserLoggedIn())
        {
            system("cls");
            cout << "            >>> BUDZET RODZINNY <<<         \n\n";
            choice = AuxilliaryMethods::chooseOptionFromMainMenu();
            switch (choice)
            {
            case '1':
            {
                familyBudget.registerNewUser();
            }
            break;
            case '2':
            {
                familyBudget.login();
            }
            break;
            case '9':
            exit(0);
            break;
            }
        }
        else
        {
            system ("cls");
            choice = AuxilliaryMethods::chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
            {
                familyBudget.addIncome();
            }
            break;
            case '2':
            {
                familyBudget.addExpense();
            }
            break;
            case '3':
            {
                familyBudget.editIncome();
            }
            break;
            case '4':
            {
                familyBudget.editExpense();
            }
            break;
            case '5':
            {
                familyBudget.deleteIncome();
            }
            break;
            case '6':
            {
                familyBudget.deleteExpense();
            }
            break;
            case '7':
            {
                familyBudget.showStatementOfCurrentMonth();
            }
            break;
            case '8':
            {
                familyBudget.showStatementOfPreviousMonth();
            }
            break;
            case '9':
            {
                familyBudget.showStatementOfSpecifiedPeriod();
            }
            break;
            case '0':
            {
                familyBudget.changeLoggedInUserPassword();
            }
            break;
            case 27:
            {
                familyBudget.logOut();
            }
            break;
            }
        }
    }


    return 0;
}
