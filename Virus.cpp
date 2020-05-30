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
	cin.ignore(32767, '\n');//������� ����� ���� ���� ������
	cout << "������� �������� ��������� ������: ";
	cin >> startInvectionRate;
	if (cin.fail() || startInvectionRate < 0 ) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. \n";
		cout << "������� ��������� ������ ������. \n";
		introduceVirus();
	}
	cout << "������� ���������� ������ � ���������: ";
	cin >> mortality;
	if (cin.fail() || mortality < 0|| mortality > 100) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. ���������� �� ����� ���� ������ 0% ��� ������ 100% \n";
		cout << "������� ��������� ������ ������. \n";
		introduceVirus();
	}
	cout << "������� ������ ������� � ����: ";
	cin >> periodOfIllnes;
	if (cin.fail() || periodOfIllnes < 1) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. ������ ������� �� ����� ���� ������ ������ ��� \n";
		cout << "������� ��������� ������ ������. \n";
		introduceVirus();
	}
	cout << "������� ��������� ������" << endl;
	cout << "1 - ����� ����� ��� ��� ������, 2 - ����� �� ����� �������, 3 - ����� ������� ���������, 4 - ����� ������� �����: ";
	cin >> virusComplexity;
	if (cin.fail() || virusComplexity <= 0 || virusComplexity>=5) //�������� �����
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "����������� ����. \n";
		cout << "������� ��������� ������ ������. \n";
		introduceVirus();
	}
}

void Virus::printVirus()
{
	cout <<"��������: "<< nameVirus <<"\t �������� ���������: "<< startInvectionRate<<" ������� � ����\t ����������: "<< mortality<<" %\t ������ �������: "<< periodOfIllnes<<" ����\t ��������� ������: "<< virusComplexity<<endl;
}