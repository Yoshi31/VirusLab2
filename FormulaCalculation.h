#include <iostream>
using namespace std;
double infectionRate(double startInvectionRate, double densityCoefficient, double securityCoefficient);//������� �������� ��������� ����� ��������� �������� � �������� �� ���� ���������, �� ���� ������������ � �� ���� �������
double immunityCoefficient(double deadAll, double infectedAll, double recoveredAll, int population);//�� ��� ������� ��� ��������� ������� �� ����� ������ ��������, �� ������� ���� ������� �� ����� ���������
double densityCoefficient(int strength);//������� ���������� ��������� ���������(�������� 50000 ���=0.7(��� ��� ������ ���������)��� 10 ��� ���=1.4(��� ��� �������)
double securityCoefficient(int securityPercentage);//��� ����� ���� ���������� � ��������� � ������� �������(1.05-%)���� �������� �������(1(��� �����)2(�������)3(����)4(������)5(�������)� ������ �� ����� ��������� �����������
double vaccineScreening(int developmentTime, int thisDay);//��������� ���� �� �������, ���� ����, �� ������� 0.2, ���� ���, �� 1
int vaccineDevelopmentTime(int virusComplexity);//�������� �� ������ ��������� ������ � ���������� ������� ������� ����������� �� ���������� �������(���������� �����=30 ����, ����� ���������� ������=60 ����, ����������� �����=90 ����, ����� ������� �����=120 ����
double mortalityCoefficient(int startMortality, double medicineCoef);//������� ������� ���������� ������ �� ��������� ���������� � ���� ��������
double medicineCoefficient(int medicineLevel);//�������� ����� �� ������ ����������� ������ 1(�����),2(����),3(�������)� ������ �� �������� �������� ����
double powerFactor(double infectionAll,double powerCoeficient, string nameVirus, string nameCity);//������ ������ ���� �� �������� ��� �������������� ��������
void basicCalculation(double infectionRate, int developmentTime, double mortalityCoefficient, int population, int periodOfIllness, string nameVirus, string nameCity);//������� ��� �������� ��������
