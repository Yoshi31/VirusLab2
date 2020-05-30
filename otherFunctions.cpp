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
        cout << "�������� ��������" << endl;
        cout << "1)���������� ������������ ������. \n2)�������� �����. \n3)���������� ������ �� ����� ������.\n4)�������� ����� � ���� ������. \n5)��������������� ������� ������ �� �����. \n6)�����. \n>";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice>7) //�������� �����
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����������� ����. \n";
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
    case 1: cout << "������� ������������ ������ \n";
        showVirus(filenameVir, filenameCity);
        break;
    case 2: cout << "��������� ����� \n";
        addVirus(filenameVir, filenameCity);
        break;
    case 3: cout << "������� �����a \n";
        showCity(filenameVir, filenameCity);
        break;
    case 4: cout << "��������� ����� \n";
        addCity(filenameVir, filenameCity);
        break;
    case 5: cout << "������������ ����� \n";
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
    cout << "�� �������, ��� ������ �������� ����� � ���� ������?\n1-��\n2-���\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        fstream file;
        file.open(filenameVir, fstream::app);
        if (!file)
        {
            cout << "������ �������� �����";
            return;
        }
        else cout << "���� ������" << endl;
        file << *virus;
        cout << "����� ������� �������� � ���� ������!" << endl;
        file.close();
    }
    else if(choice==2)
    {
        cout << "����� �� ����� �������� � ���� ������!" << endl;
    }
    else
    {
        cout << "����������� �������!" << endl;
        addVirus(filenameVir, filenameCity);
    }
    delete virus;
    returnInMenu(filenameVir, filenameCity);
}

void showVirus(string filenameVir, string filenameCity)
{
    system("cls");
    cout << "������������ ������ �� ������ ������: " << endl;
    Virus *virus;
    virus = new Virus;
    fstream fileVirus;
    fileVirus.open(filenameVir, fstream::in);
    if (!fileVirus)
    {
        cout << "������ ������ � ������"<<endl;
        return;
    }
    int fs=0, cs = 0;//���������� ��� �������� file size � current size
    fileVirus.seekg(0, ios_base::end);//��������� ���� � ��������� ������ � ����� �����
    fs = fileVirus.tellg();//��������� ������ ������ �����
    fileVirus.seekg(0);//���������� ������ � ������ �����
    do
    {
        fileVirus >> *virus;
        virus->printVirus();
        cs = fileVirus.tellg();//����� ������� ������ �������� ���������� ������ �����
    } while (cs < fs - 5);//��������� ���� ���� ������� ������ ����� ������ ������� ������� ����� ����� ������ �������� ����� ������
    fileVirus.close();
    delete virus;
    cout << "\n";
    returnInMenu(filenameVir, filenameCity);
}

void searchVirus(Virus *virus, string filenameVir, string filenameCity)
{
    string comparison;
    cout << "������� �������� ������" << endl;
    cin >> comparison;
    fstream fileVirus;
    fileVirus.open(filenameVir, fstream::in);
    int fs=0, cs=0;
    if (!fileVirus)
    {
        cout << "������ ������ � ������" << endl;
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
    cout << "����� � ����� ��������� � ���� ������ �� ������!!!" << endl;
    fileVirus.close();
    cout << "1-������ �������� ������ ������\n2-�������� ����� � ���� ������\n3-����� � ����\n";
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
        cout << "����������� �������!" << endl;
        returnInMenu(filenameVir, filenameCity);
    }
}

void addCity(string filenameVir, string filenameCity)
{
    InfectedItem* city;
    city = new InfectedItem;
    city->introduceCity();
    city->printCity();
    cout << "�� �������, ��� ������ �������� ����� � ���� ������?\n1-��\n2-���\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        fstream fileCity;
        fileCity.open(filenameCity, fstream::app);
        if (!fileCity)
        {
            cout << "������ ������ � ������!!!";
            return;
        }
        else cout << "���� ������" << endl;
        fileCity << *city;
        cout << "����� ������� �������� � ���� ������" << endl;
        fileCity.close();
    }
    else if (choice == 2)
    {
        cout << "����� �� ����� �������� � ���� ������" << endl;
    }
    else
    {
        cout << "����������� �������!" << endl;
        addCity(filenameVir, filenameCity);
    }
    delete city;
    returnInMenu(filenameVir, filenameCity);
}

void showCity(string filenameVir, string filenameCity)
{
    system("cls");
    cout << "������ ����������� � ���� ������: " << endl;
    InfectedItem* city;
    city = new InfectedItem;
    fstream fileCity;
    fileCity.open(filenameCity, fstream::in);
    if (!fileCity)
    {
        cout << "������ ������ � ������" << endl;
        return;
    }
    int fs, cs = 0;//���������� ��� �������� file size � current size
    fileCity.seekg(0, ios_base::end);//��������� ���� � ��������� ������ � ����� �����
    fs = fileCity.tellg();//��������� ������ ������ �����
    fileCity.seekg(0);//���������� ������ � ������ �����
    do
    {
        fileCity >> *city;
        city->printCity();
        cs = fileCity.tellg();//����� ������� ������ �������� ���������� ������ �����
    } while (cs < fs - 5);//��������� ���� ���� ������� ������ ����� ������ ������� ������� ����� ����� ������ �������� ����� ������
    fileCity.close();
    delete city;
    cout << "\n";
    returnInMenu(filenameVir, filenameCity);
}

void searchCity(InfectedItem* city, string filenameVir, string filenameCity)
{
    string comparison;
    cout << "������� �������� ������" << endl;
    cin >> comparison;
    fstream fileCity;
    fileCity.open(filenameCity, fstream::in);
    int fs = 0, cs = 0;
    if (!fileCity)
    {
        cout << "������ ������ � ������" << endl;
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
    cout << "����� � ����� ��������� � ���� ������ �� ������!!!" << endl;
    fileCity.close();
    cout << "1-������ �������� ������ ������\n2-�������� ����� � ���� ������\n3-����� � ����\n";
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
        cout << "����������� �������!" << endl;
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
    cout << "������� 1 ��� ����������� � ������� ���� ��� ����� ������ ������ ��� ������ �� ���������" << endl;
    char select;
    cin >> select;
    if (select == '1')
    {
        system("cls");
        menu(filenameVir, filenameCity);
    }
    else exit(0);
}