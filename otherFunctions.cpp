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

void addVirus()
{
    Virus *virus;
    virus = new Virus;
    virus->introduceVirus();
    virus->printVirus();
    fstream file;
    file.open("tekst.txt", fstream::app);
    if (!file)
    {
        cout << "Ошибка открытия файла";
        return;
    }
    else cout << "Файл открыт" << endl;
    file << *virus;
    cout << "Вирус успешно добавлен в базу данных!" << endl;
    file.close();
    delete virus;
}

void showVirus()
{
    Virus *virus;
    virus = new Virus;
    fstream file;
    file.open("tekst.txt", fstream::in);
    if (!file)
    {
        cout << "Ошибка работы с файлом"<<endl;
        return;
    }
    int fs=0, cs = 0;//переменные для хранения file size и current size
    file.seekg(0, ios_base::end);//открываем файл и переносим курсор в конец файла
    fs = file.tellg();//считываем полный размер файла
    file.seekg(0);//возвращаем курсор в начало файла
    do
    {
        file >> *virus;
        virus->printVirus();
        cs = file.tellg();//после каждого вируса измеряем пройденный размер файла
    } while (cs < fs - 5);//выполняем цикл пока текущий размер будет меньше полного размера файла минус размер символов конца строки
    file.close();
    delete virus;
}

void searchVirus(Virus *virus)
{
    string comparison;
    cout << "Введите название вируса" << endl;
    cin >> comparison;
    fstream fileVirus;
    fileVirus.open("tekst.txt", fstream::in);
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
}

void addCity()
{
    InfectedItem* city;
    city = new InfectedItem;
    city->introduceCity();
    city->printCity();
    fstream fileCity;
    fileCity.open("test.txt", fstream::app);
    if (!fileCity)
    {
        cout << "Ошибка работы с файлом!!!";
        return;
    }
    else cout << "файл открыт" << endl;
    fileCity << *city;
    cout << "Город успешно добавлен в базу данных" << endl;
    fileCity.close();
    delete city;
}

void showCity()
{
    InfectedItem* city;
    city = new InfectedItem;
    fstream fileCity;
    fileCity.open("test.txt", fstream::in);
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
}

void searchCity(InfectedItem* city)
{
    string comparison;
    cout << "Введите название города" << endl;
    cin >> comparison;
    fstream fileCity;
    fileCity.open("test.txt", fstream::in);
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
}

void predictionCalculation()
{
    string nvirus, ncity;
    int popul, med, period, complexity;
    double sir, mort, secur;
    Virus* virus;
    virus = new Virus;
    searchVirus(virus);
    nvirus = virus->getNameVirus();
    period = virus->getPeriodOfillnes();
    complexity = virus->getVirusComplexity();
    sir = virus->getStartInfectionRate();
    mort = virus->getMortality();
    InfectedItem* city;
    city = new InfectedItem;
    searchCity(city);
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
}