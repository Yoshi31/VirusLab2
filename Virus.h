#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Virus
{
private:
	string nameVirus;//�������� ����ca
	double startInvectionRate;//��������� �������� ���������
	double mortality;//����������
	int periodOfIllnes;//������ �������
	int virusComplexity;//� ������� ����� ������ ���������� �� ������� ������ ������� �������
public:
	//�����������
	Virus();
	//�������
	void setNameVirus(string name);
	void setStartInfectionRate(double infectionRate);
	void setMortality(double startMortality);
	void setPeriodOfIllnes(int periodIllnes);
	void setVirusComplextiy(int complexity);
	//�������
	string getNameVirus();
	double getStartInfectionRate();
	double getMortality();
	int getPeriodOfillnes();
	int getVirusComplexity();
	//���������� ������ �������������
	void introduceVirus();
	//����� � �������
	void printVirus();
	//���������� ���������� ����� � ������
	friend ostream& operator << (ostream& os, Virus& virus);
	friend istream& operator >> (istream& is, Virus& virus);
};

