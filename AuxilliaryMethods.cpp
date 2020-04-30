#include "AuxilliaryMethods.h"

string AuxilliaryMethods::loadLine()
    {
        string line = "";
        cin.clear();
        cin.sync();
        getline(cin, line);
        return line;
    }

int AuxilliaryMethods::computeTheNumberOfDaysInMonth (int year, int month)
{
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            {
                if (isLeap(year))
                    return 29;
                else
                    return 28;
            }
    }
}

bool AuxilliaryMethods::isLeap (int year)
{
    if (year%4 == 0 && year%100!=0)
        return true;
    else if (year%100 == 0 && year%400 == 0)
        return true;
    else
        return false;
}

string AuxilliaryMethods::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxilliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxilliaryMethods::chooseOptionFromEditionMenu()
{
    char choice;

    cout << "---------------MENU EDYCJA---------------" << endl;
    cout << "1. Edytuj date. " << endl;
    cout << "2. Edytuj kwote. " << endl;
    cout << "3. Edytuj komentarz " << endl;

    choice = getch();
    return choice;
}

