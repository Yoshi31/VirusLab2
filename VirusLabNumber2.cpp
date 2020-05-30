#include <iostream>
#include <string>
#include "Virus.h"
#include "InvectedItem.h"
#include "FormulaCalculation.h"
#include "otherFunction.h"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Russian");
    cout << "Добро пожаловать в программу, которая поможет вам сымитировать модель вируса на конкретном городе!" << endl;
    menu(argv[1],argv[2]);
    return 0;
}

