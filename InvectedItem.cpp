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
	cout << "������� ����� ����� ����������� � ������: " << endl;
	cin >> populationDensity;
	cout << "������� ������� ����� ������� ��������� ���������� �����: " << endl;
	cin >> secutiryLevel;
	cout << "������� ������� �������� ������:\n 1-����� ������ \n 2-������ \n 3-������� \n 4-������� \n 5-����� ������� \n";
	cin >> levelOfMedicine;
}

void InfectedItem::printCity()
{
	cout << "��������: " << cityName << " ����������� ���������: " << populationDensity << " ������� ����� ����������� ���������� �����: " << secutiryLevel << "% ������ ������ ��������: " << levelOfMedicine << endl;
}