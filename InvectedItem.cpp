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
	cin.ignore(32767, '\n');//очищаем буфер если есть лишнее
	cout << "Введите число людей проживабщих в городе: " << endl;
	cin >> populationDensity;
	if (cin.fail() || populationDensity < 0) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. Число жителей не может быть отрицательным. \n";
		cout << "Введите параметры вируса заново. \n";
		introduceCity();
	}
	cout << "Введите процент людей которые соблюдают санитарные нормы: " << endl;
	cin >> secutiryLevel;
	if (cin.fail() || secutiryLevel < 0 || secutiryLevel > 100) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. Процент людей не может быть меньше 0 или больше 100. \n";
		cout << "Введите параметры вируса заново. \n";
		introduceCity();
	}
	cout << "Оцените уровень медицины города:\n 1-Очень низкий \n 2-Низкий \n 3-Средний \n 4-Высокий \n 5-Очень высокий \n";
	cin >> levelOfMedicine;
	if (cin.fail() || levelOfMedicine <= 0 || levelOfMedicine >= 6) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. \n";
		cout << "Введите параметры вируса заново. \n";
		introduceCity();
	}
}

void InfectedItem::printCity()
{
	cout << "Название: " << cityName << "\t Численность население: " << populationDensity << "\t Процент людей соблюдающих санитарные нормы: " << secutiryLevel << "%\t Оценка уровня медицины: " << levelOfMedicine << endl;
}