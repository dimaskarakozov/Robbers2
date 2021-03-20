#ifndef _ROBBERS_H_
#define _ROBBERS_H_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Header.h"
#include <time.h>


int main()
{
	
	setlocale(LC_ALL, "Rus");
	printf("Created by Karakozov Dmitriy");
	printf("\nВ файле names.txt Вы можете дописать свои имена бандитов" );
	struct RobbersList obj[40],value;

	printf("\nЦифра в менюшке указывает на номер действия");

	value.NHorses = 15;
	value.NKnifes = 15;
	value.NDiamonds = 20;
	value.NDecorations = 10;
	value.NWifes = 100;
	value.NCoins = 1;
	int NRobbery = 0;
	FindNames();
	
	menushka(&NRobbery, obj,value);
	
	//RandomAddNRobbers(3,NRobbery, obj);
	
	return 0;
}
#endif