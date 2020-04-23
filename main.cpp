#include <iostream>
#include <vector>
#include "FamilyBudget.h"

using namespace std;

int main()
{
FamilyBudget familyBudget("users.xml");
familyBudget.registerNewUser();

    return 0;
}
