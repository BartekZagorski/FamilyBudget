#ifndef AUXILLIARYMETHODS_H
#define AUXILLIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxilliaryMethods
{
public:
    static string loadLine();
    static int computeTheNumberOfDaysInMonth (int year, int month);
    static bool isLeap (int year);
    static string convertFloatToString(float number);
    static string convertIntToString(int number);
};


#endif
