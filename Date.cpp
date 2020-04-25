#include "Date.h"

Date::Date(int date)
{
        this->mergedDate = date;
}

int Date::getMergedDate()
{
    return mergedDate;
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

int Date::getTodayDate()
{
    time_t rawtime;
    time(&rawtime);
    tm* ptr;
    ptr = localtime(&rawtime);
    mergedDate = (ptr->tm_year+1900)*10000+(ptr->tm_mon+1)*100+ptr->tm_mday;
    return mergedDate;
}

int Date::returnDateOfTheEndOfTheCurrentMonth()
{
    mergedDate = getTodayDate();
    mergedDate -= mergedDate%100;
    mergedDate += AuxilliaryMethods::computeTheNumberOfDaysInMonth(mergedDate/10000,(mergedDate/100)%100);
    return mergedDate;
}

int Date::returnDateOfTheBeginningOfTheCurrentMonth()
{
    mergedDate = getTodayDate();
    mergedDate -= mergedDate%100;
    mergedDate++;
    return mergedDate;
}

int Date::returnDateOfTheEndOfPreviousMonth()
{
    mergedDate = getTodayDate();
    int currentMonth = (mergedDate/100)%100;
    if (currentMonth == 1)
        mergedDate = mergedDate - 10000 + 1100;
    else
        mergedDate -= 100;
    mergedDate -= mergedDate%100;
    mergedDate += AuxilliaryMethods::computeTheNumberOfDaysInMonth(mergedDate/10000,(mergedDate/100)%100);
    return mergedDate;
}

int Date::returnDateOfTheBeginningOfPreviousMonth()
{
    mergedDate = getTodayDate();
    int currentMonth = (mergedDate/100)%100;
    if (currentMonth == 1)
        mergedDate = mergedDate - 10000 + 1100;
    else
        mergedDate -= 100;
    mergedDate -= mergedDate%100;
    mergedDate++;
    return mergedDate;
}

string Date::convertDateFromIntegerToStringSeparatedByDashes()
{
    string dateSeparatedByDashes = AuxilliaryMethods::convertIntToString(mergedDate);
    dateSeparatedByDashes.insert(6, "-");
    dateSeparatedByDashes.insert(4, "-");
    return dateSeparatedByDashes;
}
