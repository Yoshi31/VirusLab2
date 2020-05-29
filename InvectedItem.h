#pragma once
#include <string>
#include <iostream>
using namespace std;
//����� ���������� �� ���������� �����
class InfectedItem
{
private:
	string cityName;//�������� ������
	int populationDensity;//����������� ���������
	double secutiryLevel;//������� ������������ ������(����� ���, ��������� � �.�.)
	int levelOfMedicine;//������� ��������(������ �� ���������� � �� ����������������)
public:
	//�����������
	InfectedItem();
	//�������
	void setCityName(string name);
	void setPopulationDensity(int population);
	void setSecurityLevel(double percentSecurity);
	void setLevelOfMedicine(int medicine);
	//�������
	string getCityName();
	int getPopulationDensity();
	double getSecurityLevel();
	int getLevelOfMedicine();
	//���������� ������ ����������� ������ �������������
	void introduceCity();
	//������� ������ ������ � �������
	void printCity();
	//
	friend ostream& operator << (ostream& os, InfectedItem& city);
	friend istream& operator >> (istream& is, InfectedItem& city);
};

