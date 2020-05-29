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
	cout << "������� �������� ������: ";
	cin >> nameVirus;
	cout << "������� �������� ��������� ������: ";
	cin >> startInvectionRate;
	cout << "������� ���������� ������ � ���������: ";
	cin >> mortality;
	cout << "������� ������ ������� � ����: ";
	cin >> periodOfIllnes;
	cout << "������� ��������� ������" << endl;
	cout << "1 - ����� ����� ��� ��� ������, 2 - ����� �� ����� �������, 3 - ����� ������� ���������, 4 - ����� ������� �����: ";
	cin >> virusComplexity;
}

void Virus::printVirus()
{
	cout <<"��������: "<< nameVirus <<" �������� ���������: "<< startInvectionRate<<" ����������: "<< mortality<<" ������ �������: "<< periodOfIllnes<<" ��������� ������: "<< virusComplexity<<endl;
}