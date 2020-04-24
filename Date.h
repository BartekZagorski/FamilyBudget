#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "AuxilliaryMethods.h"

using namespace std;

class Date
{
    public:
    int mergedDate;

    vector <int> getDateFromSpecifiedFormat(string lineWithDateSeparatedByDashes);
    bool isDateFormatCorrect(string date);
    bool isDateCorrect(vector <int> date);
    bool isDateGood(string dateSeparatedByDashes);
    int eliminateDashesFromDate(string lineWithDateSeparatedByDashes);

public:

    Date(int = 20000101);
    int enterTheDate();

};

#endif
