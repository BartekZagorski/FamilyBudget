#ifndef AUXILLIARYMETHODS_H
#define AUXILLIARYMETHODS_H

#include <iostream>

using namespace std;

class AuxilliaryMethods
{
public:
    static string loadLine();
    static int computeTheNumberOfDaysInMonth (int year, int month);
    static bool isLeap (int year);
};


#endif
