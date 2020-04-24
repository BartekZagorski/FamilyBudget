#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include "AuxilliaryMethods.h"

using namespace std;

class Date
{
    int mergedDate;

    vector <int> getDateFromSpecifiedFormat(string lineWithDateSeparatedByDashes);
    bool isDateFormatCorrect(string date);
    bool isDateCorrect(vector <int> date);
    bool isDateGood(string dateSeparatedByDashes);
    int eliminateDashesFromDate(string lineWithDateSeparatedByDashes);

public:

    Date(int = 20000101);
    int getMergedDate();
    int enterTheDate();
    int getTodayDate();
    int returnDateOfTheEndOfTheCurrentMonth();
    int returnDateOfTheBeginningOfTheCurrentMonth();
    int returnDateOfTheEndOfPreviousMonth();
    int returnDateOfTheBeginningOfPreviousMonth();

};

#endif
