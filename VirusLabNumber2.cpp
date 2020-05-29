#include <iostream>
#include <string>
#include "Virus.h"
#include "InvectedItem.h"
#include "FormulaCalculation.h"
#include "otherFunction.h"

using namespace std;


int menuSelect()
{
    int choice;
    while(true)
    {
        cout << "1)Посмотреть существующие вирусы. \n2)Добавить вирус. \n3)Посмотреть города из баззы данных.\n4)Добавить город в базу данных. \n5)Спрогнозировать влияние вируса на город. \n6)Выход. \n>";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice>7) //Проверка ввода
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некоректный ввод. \n";
        }
        else
        {
            cin.ignore(32767, '\n');
            return choice;
        }
    }

}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int choice;//для выбора пункта в меню
    choice = menuSelect();
    switch  (choice) 
    {
    case 1: cout << "Смотрим существующие вирусы \n";
        showVirus();
        break;
    case 2: cout << "Добавляем вирус \n";
        addVirus();
        break;
    case 3: cout << "Смотрим город \n";
        showCity();
        break;
    case 4: cout << "Добавляем город \n";
        addCity();
        break;
    case 5: cout << "Прогнозируем вирус \n";
        predictionCalculation();
        break;
    case 6: exit(0);
        return 0;
    }
}

