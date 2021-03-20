#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void AddNRobber(int* NRobbery, RobbersList* obj) {
	char names[20];

	printf("\nВведите имя:(на английском) ");
	//scanf_s("%19s", &names);
	getchar();
	gets_s(names);

	strcpy(obj[*NRobbery].Name, names);
	obj[*NRobbery].IsAlife = true;

	printf("\nЛошадей: ");
	scanf_s("%d", &obj[*NRobbery].NHorses);

	printf("\nСаблей: " );
	scanf_s("%d", &obj[*NRobbery].NKnifes);

	printf("\nРубины: ");
	scanf_s("%d", &obj[*NRobbery].NDiamonds);

	printf("\nОжерелья: ");
	scanf_s("%d", &obj[*NRobbery].NDecorations);

	printf("\nЖены: ");
	scanf_s("%d", &obj[*NRobbery].NWifes);

	printf("\nДинаров: ");
	scanf_s("%d", &obj[*NRobbery].NCoins);


		//obj[i] = { "", true, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 5, rand() % 50, NULL };
	


	
	*NRobbery += 1;
}