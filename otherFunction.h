#pragma once
int menuSelect();
void menu(string filenameVir, string filenameCity);
void addVirus(string filenameVir, string filenameCity);
void showVirus(string filenameVir, string filenameCity);
void addCity(string filenameVir, string filenameCity);
void showCity(string filenameVir, string filenameCity);
void searchVirus(Virus *virus, string filenameVir, string filenameCity);
void searchCity(InfectedItem* city, string filenameVir, string filenameCity);
void predictionCalculation(string filenameVir, string filenameCity);
void returnInMenu(string filenameVir, string filenameCity);