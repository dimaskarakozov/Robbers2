#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void ChangeStat(int* NRobbery, RobbersList* obj) {
	printf("\nПодсказка (Имена живых бандитов): ");
	for (int i = 0; i < *NRobbery; i++)
	{
		if (obj[i].IsAlife)
		{
			printf("%s, ", obj[i].Name);

		}
	}
	printf("\n---------------------------------------------------------------------------------------------------- ");

	char names[20];
	printf("\nВведите имя бандита,которому надо изменить веса: ");
	getchar();
	gets_s(names);
	int n = 0;
	for (int i = 0; i < *NRobbery; i++) {
		//printf("|%s|%s|", names, obj[i].Name);
		if (strcmp(names, obj[i].Name) == 0 && obj[i].IsAlife) {	
				printf("\nЦена лошади (%d): ", obj[i].NHorses);
				scanf("%d", &n); obj[i].NHorses = n;
				printf("\nЦена сабли (%d): ", obj[i].NKnifes);
				scanf("%d", &n); obj[i].NKnifes = n;
				printf("\nЦена рубина (%d): ", obj[i].NDiamonds);
				scanf("%d", &n); obj[i].NDiamonds = n;
				printf("\nЦена ожерелья (%d): ", obj[i].NDecorations);
				scanf("%d", &n); obj[i].NDecorations = n;
				printf("\nЦенность жены (%d): ", obj[i].NWifes);
				scanf("%d", &n); obj[i].NWifes = n;
				printf("\nИмущество было удачно изменено ");
				n = 33;
			i = 41;
			exit;
		}
		else {
			n++;
		}
		if (n == *NRobbery) {
			printf("Нет живого бандита с таким именем");
		}
	}

}