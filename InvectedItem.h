#pragma once
#include <string>
#include <iostream>
using namespace std;
//класс отвечающий за зараженный город
class InfectedItem
{
private:
	string cityName;//название города
	int populationDensity;//колличество населения
	double secutiryLevel;//уровень безопасности города(мытье рук, санитария и т.д.)
	int levelOfMedicine;//уровень медицины(влияет на смертность и на выздоравлиемость)
public:
	//конструктор
	InfectedItem();
	//сеттеры
	void setCityName(string name);
	void setPopulationDensity(int population);
	void setSecurityLevel(double percentSecurity);
	void setLevelOfMedicine(int medicine);
	//геттеры
	string getCityName();
	int getPopulationDensity();
	double getSecurityLevel();
	int getLevelOfMedicine();
	//заполнения класса зараженного города пользователем
	void introduceCity();
	//выводит данные класса в консоль
	void printCity();
	//
	friend ostream& operator << (ostream& os, InfectedItem& city);
	friend istream& operator >> (istream& is, InfectedItem& city);
};

