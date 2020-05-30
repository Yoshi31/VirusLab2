#include "Virus.h"
#include "InvectedItem.h"
#include "otherFunction.h"
#include "FormulaCalculation.h"

ostream& operator<<(ostream& os, Virus& virus)
{
    os << virus.nameVirus << " " << virus.startInvectionRate << " " << virus.mortality << " " << virus.periodOfIllnes << " " << virus.virusComplexity << endl;
    return os;
}

istream& operator>>(istream& is, Virus& virus)
{
    is >> virus.nameVirus >> virus.startInvectionRate >> virus.mortality >> virus.periodOfIllnes >> virus.virusComplexity;
    return is;
}

ostream& operator<<(ostream& os, InfectedItem& city)
{
    os << city.cityName << " " << city.populationDensity << " " << city.secutiryLevel << " " << city.levelOfMedicine << endl;
    return os;
}

istream& operator>>(istream& is, InfectedItem& city)
{
    is >> city.cityName >> city.populationDensity >> city.secutiryLevel >> city.levelOfMedicine;
    return is;
}

int menuSelect()
{
    int choice;
    while (true)
    {
        cout << "Выберите действие" << endl;
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

void menu(string filenameVir, string filenameCity)
{
    int choice;
    choice=menuSelect();
    switch (choice)
    {
    case 1: cout << "Смотрим существующие вирусы \n";
        showVirus(filenameVir, filenameCity);
        break;
    case 2: cout << "Добавляем вирус \n";
        addVirus(filenameVir, filenameCity);
        break;
    case 3: cout << "Смотрим городa \n";
        showCity(filenameVir, filenameCity);
        break;
    case 4: cout << "Добавляем город \n";
        addCity(filenameVir, filenameCity);
        break;
    case 5: cout << "Прогнозируем вирус \n";
        predictionCalculation(filenameVir, filenameCity);
        break;
    case 6: exit(0);
        return;
    }
}

void addVirus(string filenameVir, string filenameCity)
{
    Virus *virus;
    virus = new Virus;
    virus->introduceVirus();
    virus->printVirus();
    cout << "Вы уверены, что хотите добавить вирус в базу данных?\n1-Да\n2-нет\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        fstream file;
        file.open(filenameVir, fstream::app);
        if (!file)
        {
            cout << "Ошибка открытия файла";
            return;
        }
        else cout << "Файл открыт" << endl;
        file << *virus;
        cout << "Вирус успешно добавлен в базу данных!" << endl;
        file.close();
    }
    else if(choice==2)
    {
        cout << "Вирус не будет добавлен в базу данных!" << endl;
    }
    else
    {
        cout << "Неизвестная команда!" << endl;
        addVirus(filenameVir, filenameCity);
    }
    delete virus;
    returnInMenu(filenameVir, filenameCity);
}

void showVirus(string filenameVir, string filenameCity)
{
    system("cls");
    cout << "Существующие вирусы на данные момент: " << endl;
    Virus *virus;
    virus = new Virus;
    fstream fileVirus;
    fileVirus.open(filenameVir, fstream::in);
    if (!fileVirus)
    {
        cout << "Ошибка работы с файлом"<<endl;
        return;
    }
    int fs=0, cs = 0;//переменные для хранения file size и current size
    fileVirus.seekg(0, ios_base::end);//открываем файл и переносим курсор в конец файла
    fs = fileVirus.tellg();//считываем полный размер файла
    fileVirus.seekg(0);//возвращаем курсор в начало файла
    do
    {
        fileVirus >> *virus;
        virus->printVirus();
        cs = fileVirus.tellg();//после каждого вируса измеряем пройденный размер файла
    } while (cs < fs - 5);//выполняем цикл пока текущий размер будет меньше полного размера файла минус размер символов конца строки
    fileVirus.close();
    delete virus;
    cout << "\n";
    returnInMenu(filenameVir, filenameCity);
}

void searchVirus(Virus *virus, string filenameVir, string filenameCity)
{
    string comparison;
    cout << "Введите название вируса" << endl;
    cin >> comparison;
    fstream fileVirus;
    fileVirus.open(filenameVir, fstream::in);
    int fs=0, cs=0;
    if (!fileVirus)
    {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    fileVirus.seekg(0, ios_base::end);
    fs = fileVirus.tellg();
    fileVirus.seekg(0);
    do
    {
        fileVirus >> *virus;
        cs = fileVirus.tellg();
        if (virus->getNameVirus() == comparison)
        {
            virus->printVirus();
            fileVirus.close();
            return;
        }
    } while (cs < fs - 5);
    cout << "Вирус с таким названием в базе данных не найден!!!" << endl;
    fileVirus.close();
    cout << "1-Ввести название вируса заново\n2-Добавить вирус в базу данных\n3-Выйти в меню\n";
    int choice;
    cin >> choice;
    if (choice == 1)
        searchVirus(virus,filenameVir,filenameCity);
    else if (choice == 2)
        addVirus(filenameVir, filenameCity);
    else if (choice == 3)
        menu(filenameVir, filenameCity);
    else
    {
        cout << "Неизвестная команда!" << endl;
        returnInMenu(filenameVir, filenameCity);
    }
}

void addCity(string filenameVir, string filenameCity)
{
    InfectedItem* city;
    city = new InfectedItem;
    city->introduceCity();
    city->printCity();
    cout << "Вы уверены, что хотите добавить город в базу данных?\n1-Да\n2-Нет\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        fstream fileCity;
        fileCity.open(filenameCity, fstream::app);
        if (!fileCity)
        {
            cout << "Ошибка работы с файлом!!!";
            return;
        }
        else cout << "файл открыт" << endl;
        fileCity << *city;
        cout << "Город успешно добавлен в базу данных" << endl;
        fileCity.close();
    }
    else if (choice == 2)
    {
        cout << "Город не будет добавлен в базу данных" << endl;
    }
    else
    {
        cout << "Неизвестная команда!" << endl;
        addCity(filenameVir, filenameCity);
    }
    delete city;
    returnInMenu(filenameVir, filenameCity);
}

void showCity(string filenameVir, string filenameCity)
{
    system("cls");
    cout << "Города добавленные в базу данных: " << endl;
    InfectedItem* city;
    city = new InfectedItem;
    fstream fileCity;
    fileCity.open(filenameCity, fstream::in);
    if (!fileCity)
    {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    int fs, cs = 0;//переменные для хранения file size и current size
    fileCity.seekg(0, ios_base::end);//открываем файл и переносим курсор в конец файла
    fs = fileCity.tellg();//считываем полный размер файла
    fileCity.seekg(0);//возвращаем курсор в начало файла
    do
    {
        fileCity >> *city;
        city->printCity();
        cs = fileCity.tellg();//после каждого вируса измеряем пройденный размер файла
    } while (cs < fs - 5);//выполняем цикл пока текущий размер будет меньше полного размера файла минус размер символов конца строки
    fileCity.close();
    delete city;
    cout << "\n";
    returnInMenu(filenameVir, filenameCity);
}

void searchCity(InfectedItem* city, string filenameVir, string filenameCity)
{
    string comparison;
    cout << "Введите название города" << endl;
    cin >> comparison;
    fstream fileCity;
    fileCity.open(filenameCity, fstream::in);
    int fs = 0, cs = 0;
    if (!fileCity)
    {
        cout << "Ошибка работы с файлом" << endl;
        return;
    }
    fileCity.seekg(0, ios_base::end);
    fs = fileCity.tellg();
    fileCity.seekg(0);
    do
    {
        fileCity >> *city;
        cs = fileCity.tellg();
        if (city->getCityName() == comparison)
        {
            city->printCity();
            fileCity.close();
            return;
        }
    } while (cs < fs - 5);
    cout << "Город с таким названием в базе данных не найден!!!" << endl;
    fileCity.close();
    cout << "1-Ввести название города заново\n2-Добавить город в базу данных\n3-Выйти в меню\n";
    int choice;
    cin >> choice;
    if (choice == 1)
        searchCity(city, filenameVir, filenameCity);
    else if (choice == 2)
        addCity(filenameVir, filenameCity);
    else if (choice == 3)
        menu(filenameVir, filenameCity);
    else
    {
        cout << "Неизвестная команда!" << endl;
        returnInMenu(filenameVir, filenameCity);
    }
}

void predictionCalculation(string filenameVir, string filenameCity)
{
    string nvirus, ncity;
    int popul, med, period, complexity;
    double sir, mort, secur;
    Virus* virus;
    virus = new Virus;
    searchVirus(virus, filenameVir, filenameCity);
    nvirus = virus->getNameVirus();
    period = virus->getPeriodOfillnes();
    complexity = virus->getVirusComplexity();
    sir = virus->getStartInfectionRate();
    mort = virus->getMortality();
    InfectedItem* city;
    city = new InfectedItem;
    searchCity(city, filenameVir, filenameCity);
    ncity = city->getCityName();
    popul = city->getPopulationDensity();
    med = city->getLevelOfMedicine();
    secur = city->getSecurityLevel();
    double populCoef,securCoef, ir, mortCoef, medCoef;
    int vaccineTime;
    populCoef = densityCoefficient(popul);
    securCoef = securityCoefficient(secur);
    ir = infectionRate(sir, populCoef, securCoef);
    vaccineTime = vaccineDevelopmentTime(complexity);
    medCoef = medicineCoefficient(med);
    mortCoef = mortalityCoefficient(mort, medCoef);
    basicCalculation(ir, vaccineTime, mortCoef, popul, period, nvirus, ncity);
    delete virus;
    delete city;
    returnInMenu(filenameVir, filenameCity);
}
void returnInMenu(string filenameVir, string filenameCity)
{
    cout << "Нажмите 1 для возвращения в главное меню или любой другой символ для выхода из программы" << endl;
    char select;
    cin >> select;
    if (select == '1')
    {
        system("cls");
        menu(filenameVir, filenameCity);
    }
    else exit(0);
}