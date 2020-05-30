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

double immunityCoefficient(double deadAll, double infectedAll, double recoveredAll, int population)
{
	return 1 - ((infectedAll + recoveredAll) / (population - deadAll));
}

double powerFactor(double infectionAll,double powerCoeficient, string nameVirus, string nameCity)
{
	if (infectionAll > 10 && infectionAll < 50)
	{
		if(powerCoeficient>0.95)
		cout << "СМИ начали обсуждать вирус! Мемы про вирус вошли в чат!" << endl;
		if (powerCoeficient < 0.95)
			cout << "Вирус почти отспупил!" << endl;
		return 0.95;
	}
	else if (infectionAll > 50 && infectionAll < 100)
	{
		if (powerCoeficient > 0.9)
		cout << "Месты власти собрались на экстренное совещание, избегайте контакта с зараженными!" << endl;
		if (powerCoeficient < 0.9)
			cout << "На улицах все чаще можно встретить людей!" << endl;
		return 0.9;
	}
	else if (infectionAll > 100 && infectionAll < 250)
	{
		if (powerCoeficient > 0.8)
		cout << "Авиасообщение закрыто, введен закон о ношения масок!" << endl;
		if (powerCoeficient < 0.8)
			cout << "Границы открылись для свободного перемещения!" << endl;
		return 0.8;
	}
	else if (infectionAll > 250 && infectionAll < 500)
	{
		if (powerCoeficient > 0.7)
		cout << "Закрываются общественные места, граждан просят оставатсья дома!" << endl;
		if (powerCoeficient < 0.7)
			cout << "С каждым днем все меньше и меньше новых случаев заражения!" << endl;
		return 0.7;
	}
	else if (infectionAll > 500 && infectionAll < 1000)
	{
		if (powerCoeficient > 0.6)
		cout << "Общее число заболевших превысило 500, вводится чрезвычайное положение!" << endl;
		if (powerCoeficient < 0.6)
			cout << "Вирус пошел на спад!" << endl;
		return 0.6;
	}
	else if (infectionAll > 1000 && infectionAll < 5000)
	{
		if (powerCoeficient > 0.5)
		cout << "Колличество больных больше 1000, больницы переполнены!" << endl;
		if (powerCoeficient < 0.5)
			cout << "Ученные дают благоприятный прогноз, продолжайте соблюдать меры самоизоляции!" << endl;
		return 0.5;
	}
	else if (infectionAll > 5000)
	{
		if (powerCoeficient > 0.4)
		cout << "Власти ввели максимальные меры безопасности" << endl;
		if (powerCoeficient < 0.4)
			cout << "Власти сняли меры безопасноти" << endl;
		return 0.4;
	}
	else if (infectionAll > 10000)
	{
		if (powerCoeficient != 0.35)
			cout << "Все граждане сидят дома в надежде на то, что вирус скоро отступит" << endl;
		return 0.35;
	}
	else return 1;
}

double securityCoefficient(int securityPercentage)
{
	double transfer = static_cast<double>(securityPercentage) / 100;
	return 1.1-transfer;
}

double vaccineScreening(int developmentTime, int thisDay)
{
	if (developmentTime < thisDay)
		return 0.3;//изобрели вакцину, нужно сильно уменьшить скорость распространени
	else if (developmentTime == thisDay)
	{
		cout << "Ученые изобрели вакцину!!!" << endl;
		return 0.3;
	}
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

void basicCalculation(double infectionRate, int developmentTime, double mortalityCoefficient, int population, int periodOfIllness, string nameVirus, string nameCity)
{
	cout << "Введите колличество дней для прогноза" << endl;
	int predictDay;//спрашивает на сколько дней нужно сделать прогноз
	cin >> predictDay;
	int* recovered = new int[predictDay];//создаем динмачиный массив для выздоровевших людей
	int infectedToday;//новых случаев заражения
	int deadToday=0;
	int infectedAll=1;//счетчик людей которые болеют сейчас
	int deadAll=0;//счетчик всего смертей
	double imunoCaef;//коэф имунитета, который уменьшается, так-как люди которые уже болели не могут снова заразится
	int recoveredAll=0;//счетчик всего выздоровевших
	double  powerCoefficient=1;//коэфициент который уменьшается, из-за действий властей
	int infectedAfter=1;//предыдущих случаев заражения для расчета, считаем, что болезнь проявляется на след сутки и граждане садятся на карантин и никого больше не заражают
	int casesOfInfection=1;//случаев заражения всего
	system("cls");
	cout<<"В городе "<<nameCity<<" Зарегистрирован первый случай заражения вирусом "<<nameVirus<<endl;
	for (int today = 1; today <= predictDay; today++)//цикл должен работать столько, на сколько дней нужен прогноз
	{
		cout << "--------------------------------------------------------------" << endl;
		double vacineCheck = vaccineScreening(developmentTime, today);//каждый раз проверяем наличие вакцины
		imunoCaef = immunityCoefficient(deadAll, infectedAll, recoveredAll, population);//каждый раз смотрим число зараженных
		powerCoefficient = powerFactor(infectedAll,powerCoefficient, nameVirus, nameCity);
		infectedToday = infectedAfter * infectionRate * vacineCheck*imunoCaef*powerCoefficient;
		deadToday = infectedToday * mortalityCoefficient * vacineCheck;
		recovered[today - 1] = infectedToday - deadToday;
		if (today > periodOfIllness )
		{
			infectedAll = infectedAll + infectedToday - deadToday - recovered[today - periodOfIllness + 1] - 1;
			recoveredAll = recoveredAll + recovered[today - periodOfIllness +1];
		}
		else
		{
			infectedAll = infectedAll + infectedToday - deadToday;
		}
		deadAll = deadAll + deadToday;
		cout << "День " << today << endl;
		cout << "Коэф имуны: " << imunoCaef << endl;
		if (infectedToday > 0)//если прошел период болезни
			cout << "Сегодня зараженных: " << infectedToday << endl;
		else cout << "Сегодня нет зараженных" << endl;
		if (infectedAll > 1)
			cout << "Зараженных всего: " << infectedAll << endl;
		else cout << "Все люди победили болезнь" << endl;
		cout << "Сегодня погибло: " << deadToday << endl;
		cout << "Погибших всего: " << deadAll << endl;
		if(today> periodOfIllness)//прошел период болезни
		cout << "Выздоровевших сегодня: " << recovered[today- periodOfIllness] << endl;
		cout << "Выздоровевших всего: " << recoveredAll<<endl;
		infectedAfter = infectedToday;
		casesOfInfection = casesOfInfection + infectedToday;
		cout << "Зарегистрированных случаев заражения всего: " << casesOfInfection<< endl;
		if (today > 1 && infectedAll < 1)//если число зараженных достигло нуля, не считая первого зараженного, то вирус закончился
		{
			cout << "Поздравляю вирус побежден, все больные выздоровели" << endl<<endl;
			break;
		}
		
	}
	delete[] recovered;
	recovered=nullptr;
}