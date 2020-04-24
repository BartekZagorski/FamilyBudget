#include "Date.h"

Date::Date(int date)
{
        this->mergedDate = date;
}

vector <int> Date::getDateFromSpecifiedFormat(string lineWithDateSeparatedByDashes)
{
    int year, month, day;
    string singleComponentOfDate = "";
    int numberOfSingleComponentOfDate = 1;

    for (int i = 0; i < lineWithDateSeparatedByDashes.length(); i++)
    {
        if (lineWithDateSeparatedByDashes[i] != '-')
        {
            singleComponentOfDate += lineWithDateSeparatedByDashes[i];
        }
        else
        {
            switch (numberOfSingleComponentOfDate)
            {
                case 1:
                    year = atoi(singleComponentOfDate.c_str());
                    break;
                case 2:
                    month = atoi(singleComponentOfDate.c_str());
                    break;
            }
            singleComponentOfDate = "";
            numberOfSingleComponentOfDate++;
        }
    }
    day = atoi(singleComponentOfDate.c_str());
    vector <int> date;
    date.push_back(year);
    date.push_back(month);
    date.push_back(day);
    return date;
}

bool Date::isDateFormatCorrect(string date)
{
    bool isCorrect = true;
    if (date.length()!=10)
        isCorrect = false;
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 4 || i == 7)
            {
                if ( date [i] != '-' )
                    isCorrect = false;
            }
            else if (!isdigit(date[i]))
            {
                isCorrect = false;
            }
        }
    }
    if (!isCorrect)
    {
        cout<<"Wprowadzono niepoprawny format daty"<<endl;
        system("pause");
    }
    return isCorrect;
}

bool Date::isDateCorrect(vector <int> date)
{
    int year, month, day;
    year = date[0];
    month = date[1];
    day = date[2];
    bool isCorrect = true;

    if ( year > 0)
    {
        if (month > 0 && month < 13)
        {
            if (day > 0 && day <= AuxilliaryMethods::computeTheNumberOfDaysInMonth(year, month))
                isCorrect = true;
            else
                isCorrect = false;
        }
        else
            isCorrect = false;
    }
    else
        isCorrect = false;
    if (!isCorrect)
    {
        cout << "Podana data jest nieprawidlowa."<<endl;
        system("pause");
    }
    return isCorrect;
}

bool Date::isDateGood(string dateSeparatedByDashes)
{
    if (!isDateFormatCorrect(dateSeparatedByDashes))
        return false;
    else
    {
        vector <int> dateSeparatedToYearMonthAndDay;
        dateSeparatedToYearMonthAndDay = getDateFromSpecifiedFormat(dateSeparatedByDashes);
        if (!isDateCorrect(dateSeparatedToYearMonthAndDay))
            return false;
        else
            return true;
    }
}

int Date::eliminateDashesFromDate(string lineWithDateSeparatedByDashes)
{
    lineWithDateSeparatedByDashes.erase(4, 1);
    lineWithDateSeparatedByDashes.erase(6, 1);
    return atoi(lineWithDateSeparatedByDashes.c_str());
}

int Date::enterTheDate()
{
    string dateGivenByUser = AuxilliaryMethods::loadLine();
    if (isDateGood(dateGivenByUser))
    {
        return eliminateDashesFromDate(dateGivenByUser);
    }
    else
        return 20000101;
}
