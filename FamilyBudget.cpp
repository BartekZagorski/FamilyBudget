#include "FamilyBudget.h"

FamilyBudget::FamilyBudget(string nameOfFileWithUsers)
: userManager(nameOfFileWithUsers)
{};

void FamilyBudget::registerNewUser()
{
    userManager.registerNewUser();
}
