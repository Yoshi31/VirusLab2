#include "InvectedItem.h"
InfectedItem::InfectedItem()
{
	cityName = "Null";
	populationDensity = 0;
	secutiryLevel = 0.0;
	levelOfMedicine = 0;
}

void InfectedItem::setCityName(string name)
{
	cityName = name;
}

void InfectedItem::setPopulationDensity(int population)
{
	populationDensity = population;
}

void InfectedItem::setSecurityLevel(double percentSecurity)
{
	secutiryLevel = percentSecurity;
}

void InfectedItem::setLevelOfMedicine(int medicine)
{
	levelOfMedicine = medicine;
}

string InfectedItem::getCityName()
{
	return cityName;
}

int InfectedItem::getPopulationDensity()
{
	return populationDensity;
}

double InfectedItem::getSecurityLevel()
{
	return secutiryLevel;
}

int InfectedItem::getLevelOfMedicine()
{
	return levelOfMedicine;
}

void InfectedItem::introduceCity()
{
	cout << "������� �������� ������: " << endl;
	cin >> cityName;
	cin.ignore(32767, '\n');//������� ����� ���� ���� ������
	cout << "������� ����� ����� ����������� � ������: " << endl;
	cin >> populationDensity;
	if (cin.fail() || populationDensity < 0) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. ����� ������� �� ����� ���� �������������. \n";
		cout << "������� ��������� ������ ������. \n";
		introduceCity();
	}
	cout << "������� ������� ����� ������� ��������� ���������� �����: " << endl;
	cin >> secutiryLevel;
	if (cin.fail() || secutiryLevel < 0 || secutiryLevel > 100) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. ������� ����� �� ����� ���� ������ 0 ��� ������ 100. \n";
		cout << "������� ��������� ������ ������. \n";
		introduceCity();
	}
	cout << "������� ������� �������� ������:\n 1-����� ������ \n 2-������ \n 3-������� \n 4-������� \n 5-����� ������� \n";
	cin >> levelOfMedicine;
	if (cin.fail() || levelOfMedicine <= 0 || levelOfMedicine >= 6) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. \n";
		cout << "������� ��������� ������ ������. \n";
		introduceCity();
	}
}

void InfectedItem::printCity()
{
	cout << "��������: " << cityName << "\t ����������� ���������: " << populationDensity << "\t ������� ����� ����������� ���������� �����: " << secutiryLevel << "%\t ������ ������ ��������: " << levelOfMedicine << endl;
}