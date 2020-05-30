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
	cin.ignore(32767, '\n');//очищаем буфер если есть лишнее
	cout << "Введите скорость заражения вируса: ";
	cin >> startInvectionRate;
	if (cin.fail() || startInvectionRate < 0 ) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. \n";
		cout << "Введите параметры вируса заново. \n";
		introduceVirus();
	}
	cout << "Введите смертность вируса в процентах: ";
	cin >> mortality;
	if (cin.fail() || mortality < 0|| mortality > 100) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. Смертность не может быть меньше 0% или больше 100% \n";
		cout << "Введите параметры вируса заново. \n";
		introduceVirus();
	}
	cout << "Введите период болезни в днях: ";
	cin >> periodOfIllnes;
	if (cin.fail() || periodOfIllnes < 1) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. Период болезни не может быть меньше одного дня \n";
		cout << "Введите параметры вируса заново. \n";
		introduceVirus();
	}
	cout << "Введите сложность вируса" << endl;
	cout << "1 - Такой вирус уже был раньше, 2 - Вирус не очень сложный, 3 - Вирус средней сложности, 4 - очень сложный вирус: ";
	cin >> virusComplexity;
	if (cin.fail() || virusComplexity <= 0 || virusComplexity>=5) //Проверка ввода
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некоректный ввод. \n";
		cout << "Введите параметры вируса заново. \n";
		introduceVirus();
	}
}

void Virus::printVirus()
{
	cout <<"Название: "<< nameVirus <<"\t Скорость заражения: "<< startInvectionRate<<" человек в день\t Смертность: "<< mortality<<" %\t Период болезни: "<< periodOfIllnes<<" дней\t Сложность вируса: "<< virusComplexity<<endl;
}