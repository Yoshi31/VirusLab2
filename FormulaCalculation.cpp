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
	double vaccineRatio = vaccineScreening(30, 20);//постоянно проверяем наличие вакцины
	return startInvectionRate * densityCoefficient * securityCoefficient * vaccineRatio;
}