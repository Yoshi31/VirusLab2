#include <iostream>
using namespace std;
double infectionRate(double startInvectionRate, double densityCoefficient, double securityCoefficient);//находим скорость заражения берем стартовую скорость и умножаем на коэф плотности, на коэф безопасности и на коэф вакцины
double immunityCoefficient(double deadAll, double infectedAll, double recoveredAll, int population);//те кто заболел или переболел вирусом не может больше заболеть, мы нвходим этот процент от всего населения
double densityCoefficient(int strength);//находим коэфициент плотности населения(допустим 50000 чел=0.7(так как низкая плотность)или 10 млн чел=1.4(так как высокая)
double securityCoefficient(int securityPercentage);//Тут можно либо спрашивать в процентах и сделать формулу(1.05-%)либо спросить уровень(1(все плохо)2(терпимо)3(норм)4(хорошо)5(отлично)и исходя из этого присвоить коэфициенты
double vaccineScreening(int developmentTime, int thisDay);//проверяем есть ли вакцина, если есть, то выводим 0.2, если нет, то 1
int vaccineDevelopmentTime(int virusComplexity);//получаем из класса сложность вируса и определяем сколько времени понадобится на разработку вакцины(популярный вирус=30 дней, вирус встречался раньше=60 дней, неизвестный вирус=90 дней, очень сложный вирус=120 дней
double mortalityCoefficient(int startMortality, double medicineCoef);//находим процент смертности исходя из начальной смертности и коэф медицины
double medicineCoefficient(int medicineLevel);//получаем число из класса зараженного города 1(плохо),2(норм),3(отлично)и исходя из значения присваем коэф
double powerFactor(double infectionAll,double powerCoeficient, string nameVirus, string nameCity);//власти вводят меры со временем для предотвращения эпидемии
void basicCalculation(double infectionRate, int developmentTime, double mortalityCoefficient, int population, int periodOfIllness, string nameVirus, string nameCity);//функция для основных расчетов
