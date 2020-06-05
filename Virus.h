#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Virus
{
private:
	string nameVirus;//Название вируca
	double startInvectionRate;//Стартовая скорость заражения
	double mortality;//Смертность
	int periodOfIllnes;//период болезни
	int virusComplexity;//с помощью этого пункта определяем на сколько быстро получим вакцину
public:
	//конструктор
	Virus();
	//сеттеры
	void setNameVirus(string name);
	void setStartInfectionRate(double infectionRate);
	void setMortality(double startMortality);
	void setPeriodOfIllnes(int periodIllnes);
	void setVirusComplextiy(int complexity);
	//геттеры
	string getNameVirus();
	double getStartInfectionRate();
	double getMortality();
	int getPeriodOfillnes();
	int getVirusComplexity();
	//заполнение класса пользователем
	void introduceVirus();
	//вывод в консоль
	void printVirus();
	//Перегрузка операторов ввода и вывода
	friend ostream& operator << (ostream& os, Virus& virus);
	friend istream& operator >> (istream& is, Virus& virus);
};
