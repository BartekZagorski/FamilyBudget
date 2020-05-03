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
    cout << "3. Edytuj komentarz. " << endl;
    cout << "9. Powrot do Menu Uzytkownika. " << endl;

    do
    {
        choice = getch();
    }
    while (choice != '1' && choice != '2' && choice != '3' && choice != '9');

    return choice;
}

char AuxilliaryMethods::chooseOptionFromMainMenu()
{
    char choice;

    cout << "------------------MENU GLOWNE------------------" << endl;
    cout << "1. Rejestracja " << endl;
    cout << "2. Logowanie " << endl;
    cout << "9. Wyjscie" << endl;

    do
    {
        choice = getch();
    }
    while (choice != '1' && choice != '2' && choice != '9');
    return choice;
}

char AuxilliaryMethods::chooseOptionFromUserMenu()
{
    char choice;

    cout << "------------------MENU UZYTKOWNIKA------------------" << endl;
    cout << "1. Dodaj przychod " << endl;
    cout << "2. Dodaj wydatek " << endl;
    cout << "3. Edytuj przychod" << endl;
    cout << "4. Edytuj wydatek" << endl;
    cout << "5. Usun przychod" << endl;
    cout << "6. Usun wydatek" << endl;
    cout << "7. Pokaz bilans z biezacego miesiaca" << endl;
    cout << "8. Pokaz bilans z ubieglego miesiaca" << endl;
    cout << "9. Pokaz bilans z wybranego okresu" << endl;
    cout << "0. Zmien haslo" << endl;
    cout << "ESC. Wyloguj" << endl;

    do
    {
        choice = getch();
    }
    while ((choice < '0' || choice > '9') && choice != 27 );
    return choice;
}
