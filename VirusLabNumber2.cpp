#include <iostream>
#include "Virus.h"
#include "InvectedItem.h"

using namespace std;


int menuSelect()
{
    int choice;
    while(true)
    {
        cout << "1)Посмотреть существующие вирусы. \n2)Добавить вирус. \n3)Посмотреть статистику на сегодняшний день.\n4)Спрогнозировать темп вируса. \n5)Выход. \n>";
       // int choice;
        cin >> choice;
        if (cin.fail() || choice < 0 || choice>6) //Проверка ввода
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
    switch (choice) {
    case 1: cout << "Смотрим существующие вирусы \n";
        break;
    case 2: cout << "Добавляем вирус \n";
        break;
    case 3: cout << "Смотрим статистику \n";
        break;
    case 4: cout << "Прогнозируем темп вируса \n";
        break;
    case 5: exit(0);
        return 0;
    }
}

