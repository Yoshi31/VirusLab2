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
	cout << "Введите название города: " << endl;
	cin >> cityName;
	cout << "Введите число людей проживабщих в городе: " << endl;
	cin >> populationDensity;
	cout << "Введите процент людей которые соблюдают санитарные нормы: " << endl;
	cin >> secutiryLevel;
	cout << "Оцените уровень медицины города:\n 1-Очень низкий \n 2-Низкий \n 3-Средний \n 4-Высокий \n 5-Очень высокий \n";
	cin >> levelOfMedicine;
}

void InfectedItem::printCity()
{
	cout << "Название: " << cityName << " Численность население: " << populationDensity << " Процент людей соблюдающих санитарные нормы: " << secutiryLevel << "% Оценка уровня медицины: " << levelOfMedicine << endl;
}