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
		cout << "��� ������ ��������� �����! ���� ��� ����� ����� � ���!" << endl;
		if (powerCoeficient < 0.95)
			cout << "����� ����� ��������!" << endl;
		return 0.95;
	}
	else if (infectionAll > 50 && infectionAll < 100)
	{
		if (powerCoeficient > 0.9)
		cout << "����� ������ ��������� �� ���������� ���������, ��������� �������� � �����������!" << endl;
		if (powerCoeficient < 0.9)
			cout << "�� ������ ��� ���� ����� ��������� �����!" << endl;
		return 0.9;
	}
	else if (infectionAll > 100 && infectionAll < 250)
	{
		if (powerCoeficient > 0.8)
		cout << "������������� �������, ������ ����� � ������� �����!" << endl;
		if (powerCoeficient < 0.8)
			cout << "������� ��������� ��� ���������� �����������!" << endl;
		return 0.8;
	}
	else if (infectionAll > 250 && infectionAll < 500)
	{
		if (powerCoeficient > 0.7)
		cout << "����������� ������������ �����, ������� ������ ���������� ����!" << endl;
		if (powerCoeficient < 0.7)
			cout << "� ������ ���� ��� ������ � ������ ����� ������� ���������!" << endl;
		return 0.7;
	}
	else if (infectionAll > 500 && infectionAll < 1000)
	{
		if (powerCoeficient > 0.6)
		cout << "����� ����� ���������� ��������� 500, �������� ������������ ���������!" << endl;
		if (powerCoeficient < 0.6)
			cout << "����� ����� �� ����!" << endl;
		return 0.6;
	}
	else if (infectionAll > 1000 && infectionAll < 5000)
	{
		if (powerCoeficient > 0.5)
		cout << "����������� ������� ������ 1000, �������� �����������!" << endl;
		if (powerCoeficient < 0.5)
			cout << "������� ���� ������������� �������, ����������� ��������� ���� ������������!" << endl;
		return 0.5;
	}
	else if (infectionAll > 5000)
	{
		if (powerCoeficient > 0.4)
		cout << "������ ����� ������������ ���� ������������" << endl;
		if (powerCoeficient < 0.4)
			cout << "������ ����� ���� �����������" << endl;
		return 0.4;
	}
	else if (infectionAll > 10000)
	{
		if (powerCoeficient != 0.35)
			cout << "��� �������� ����� ���� � ������� �� ��, ��� ����� ����� ��������" << endl;
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
		return 0.3;//�������� �������, ����� ������ ��������� �������� ��������������
	else if (developmentTime == thisDay)
	{
		cout << "������ �������� �������!!!" << endl;
		return 0.3;
	}
	else
		return 1;//������� ���, ��� �� ��������
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
		cout << "����� ���������� ������� �� ����� ���� �����������!!!" << endl;
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
	default: cout << "���������� ���������� ������� ��������" << endl;
		break;
	}
}

double mortalityCoefficient(int startMortality, double medicineCoef)
{
	double mortalityTransfer = static_cast<double>(startMortality) / 100;//��������� �� ��������� � �����
	return mortalityTransfer * medicineCoef;
}

void basicCalculation(double infectionRate, int developmentTime, double mortalityCoefficient, int population, int periodOfIllness, string nameVirus, string nameCity)
{
	cout << "������� ����������� ���� ��� ��������" << endl;
	int predictDay;//���������� �� ������� ���� ����� ������� �������
	cin >> predictDay;
	int* recovered = new int[predictDay];//������� ���������� ������ ��� ������������� �����
	int infectedToday;//����� ������� ���������
	int deadToday=0;
	int infectedAll=1;//������� ����� ������� ������ ������
	int deadAll=0;//������� ����� �������
	double imunoCaef;//���� ���������, ������� �����������, ���-��� ���� ������� ��� ������ �� ����� ����� ���������
	int recoveredAll=0;//������� ����� �������������
	double  powerCoefficient=1;//���������� ������� �����������, ��-�� �������� �������
	int infectedAfter=1;//���������� ������� ��������� ��� �������, �������, ��� ������� ����������� �� ���� ����� � �������� ������� �� �������� � ������ ������ �� ��������
	int casesOfInfection=1;//������� ��������� �����
	system("cls");
	cout<<"� ������ "<<nameCity<<" ��������������� ������ ������ ��������� ������� "<<nameVirus<<endl;
	for (int today = 1; today <= predictDay; today++)//���� ������ �������� �������, �� ������� ���� ����� �������
	{
		cout << "--------------------------------------------------------------" << endl;
		double vacineCheck = vaccineScreening(developmentTime, today);//������ ��� ��������� ������� �������
		imunoCaef = immunityCoefficient(deadAll, infectedAll, recoveredAll, population);//������ ��� ������� ����� ����������
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
		cout << "���� " << today << endl;
		cout << "���� �����: " << imunoCaef << endl;
		if (infectedToday > 0)//���� ������ ������ �������
			cout << "������� ����������: " << infectedToday << endl;
		else cout << "������� ��� ����������" << endl;
		if (infectedAll > 1)
			cout << "���������� �����: " << infectedAll << endl;
		else cout << "��� ���� �������� �������" << endl;
		cout << "������� �������: " << deadToday << endl;
		cout << "�������� �����: " << deadAll << endl;
		if(today> periodOfIllness)//������ ������ �������
		cout << "������������� �������: " << recovered[today- periodOfIllness] << endl;
		cout << "������������� �����: " << recoveredAll<<endl;
		infectedAfter = infectedToday;
		casesOfInfection = casesOfInfection + infectedToday;
		cout << "������������������ ������� ��������� �����: " << casesOfInfection<< endl;
		if (today > 1 && infectedAll < 1)//���� ����� ���������� �������� ����, �� ������ ������� �����������, �� ����� ����������
		{
			cout << "���������� ����� ��������, ��� ������� �����������" << endl<<endl;
			break;
		}
		
	}
	delete[] recovered;
	recovered=nullptr;
}