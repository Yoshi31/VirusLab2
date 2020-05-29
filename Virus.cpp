#include "Virus.h"
Virus::Virus()
{
	nameVirus = "Null";
	startInvectionRate = 0.0;
	mortality = 0.0;
	periodOfIllnes = 0;
	virusComplexity = 0;
}

void Virus::setNameVirus(string name)
{
	nameVirus = name;
}

void Virus::setStartInfectionRate(double infectionRate)
{
	startInvectionRate = infectionRate;
}

void Virus::setMortality(double startMortality)
{
	mortality = startMortality;
}

void Virus::setPeriodOfIllnes(int periodIllnes)
{
	periodOfIllnes = periodIllnes;
}

void Virus::setVirusComplextiy(int complexity)
{
	virusComplexity = complexity;
}

string Virus::getNameVirus()
{
	return nameVirus;
}

double Virus::getStartInfectionRate()
{
	return startInvectionRate;
}

double Virus::getMortality()
{
	return mortality;
}

int Virus::getPeriodOfillnes()
{
	return periodOfIllnes;
}

int Virus::getVirusComplexity()
{
	return virusComplexity;
}

void Virus::introduceVirus()
{
	cout << "Введите название вируса: ";
	cin >> nameVirus;
	cout << "Введите скорость заражения вируса: ";
	cin >> startInvectionRate;
	cout << "Введите смертность вируса в процентах: ";
	cin >> mortality;
	cout << "Введите период болезни в днях: ";
	cin >> periodOfIllnes;
	cout << "Введите сложность вируса" << endl;
	cout << "1 - Такой вирус уже был раньше, 2 - Вирус не очень сложный, 3 - Вирус средней сложности, 4 - очень сложный вирус: ";
	cin >> virusComplexity;
}

void Virus::printVirus()
{
	cout <<"Название: "<< nameVirus <<" Скорость заражения: "<< startInvectionRate<<" Смертность: "<< mortality<<" Период болезни: "<< periodOfIllnes<<" Сложность вируса: "<< virusComplexity<<endl;
}