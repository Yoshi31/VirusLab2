#include <iostream>
#include "FormulaCalculation.h"

double densityCoefficient(int strength)
{
	if (strength <= 10000)
		return 0.5;
	else if (strength > 10000 && strength <= 50000)
		return 0.6;
	else if (strength > 50000 && strength <= 100000)
		return 0.7;
	else if (strength > 100000 && strength <= 250000)
		return 0.8;
	else if (strength > 250000 && strength <= 500000)
		return 0.9;
	else if (strength > 500000 && strength <= 1000000)
		return 1;
	else if (strength > 1000000 && strength <= 2500000)
		return 1.1;
	else if (strength > 2500000 && strength <= 5000000)
		return 1.2;
	else if (strength > 5000000 && strength <= 10000000)
		return 1.3;	
	else if (strength > 10000000)
		return 1.4;
}

double securityCoefficient(int securityPercentage)
{
	double transfer = static_cast<double>(securityPercentage) / 100;
	return 1.1-transfer;
}

double vaccineScreening(int developmentTime, int thisDay)
{
	if (developmentTime <= thisDay)
		return 0.2;//изобрели вакцину, нужно сильно уменьшить скорость распространени
	else
		return 1;//вакцины нет, все по прежнему
}

int vaccineDevelopmentTime(int virusComplexity)
{
	switch (virusComplexity)
	{
	case 1: return 30;
	case 2: return 60;
	case 3: return 90;
	case 4: return 120;
	default:
		cout << "Время разработки вакцины не может быть определенно!!!" << endl;
		break;
	}
}

double infectionRate(double startInvectionRate, double densityCoefficient, double securityCoefficient)
{
	return startInvectionRate * densityCoefficient * securityCoefficient;
}

double medicineCoefficient(int medicineLevel)
{
	switch (medicineLevel)
	{
	case 1: return 1.1;
	case 2: return 1;
	case 3: return 0.9;
	case 4: return 0.8;
	case 5: return 0.7;
	default: cout << "Невозможно определить уровень медицины" << endl;
		break;
	}
}

double mortalityCoefficient(int startMortality, double medicineCoef)
{
	double mortalityTransfer = static_cast<double>(startMortality) / 100;//переводит из процентов в дробь
	return mortalityTransfer * medicineCoef;
}

void basicCalculation(double infectionRate, int developmentTime, double mortalityCoefficient)
{
	cout << "Введите колличество дней для прогноза" << endl;
	int predictDay;//спрашивает на сколько дней нужно сделать прогноз
	cin >> predictDay;
	int* recovered = new int[predictDay];//создаем динмачиный массив для выздоровевших людей
	float infectedToday = 0;//стартовое кол-во зараженных
	float deadToday=0;
	float infectedAll=1;
	float deadAll=0;
	for (int today = 1; today <= predictDay; today++)//цикл должен работать столько, на сколько дней нужен прогноз
	{
		double vacineCheck = vaccineScreening(developmentTime, today);//каждый раз проверяем наличие вакцины
		infectedToday = infectedAll * infectionRate * vacineCheck;
		deadToday = infectedToday * mortalityCoefficient * vacineCheck;
		recovered[today - 1] = infectedToday - deadToday;
		if (today > 5)
		{
			infectedAll = infectedAll + infectedToday - deadToday-recovered[today-5];
		}
		else
		{
			infectedAll = infectedAll + infectedToday - deadToday;
		}
		deadAll = deadAll + deadToday;
		/*numberOfInfected = numberOfInfected * infectionRate * vacineCheck;//подсчитывает кол-во зараженных сегодня
		deadToday = numberOfInfected * mortalityCoefficient * vacineCheck;//умерших сегодня
		deadAll =deadAll+ deadToday;
		infectedAll = infectedAll+numberOfInfected;*/
		cout << "День " << today << endl;
		cout << "Сегодня зараженных: " << static_cast<int>(infectedToday) << endl;
		cout << "Зараженных всего: " << static_cast<int>(infectedAll) << endl;
		cout << "Сегодня погибло: " << static_cast<int>(deadToday) << endl;
		cout << "Погибших всего: " << static_cast<int>(deadAll) << endl;
		if(today>5)
		cout << "Выздоровевших сегодня: " << recovered[today-5] << endl;
		//numberOfInfected=numberOfInfected - deadToday;

	}
	delete[]recovered;
}
