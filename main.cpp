#include <iostream>
#include <vector>
#include "FamilyBudget.h"
#include "Date.h"

using namespace std;

int main()
{
Date date;
date.mergedDate = date.enterTheDate();
cout<< date.mergedDate;

    return 0;
}
