#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


void KillOneBody(int* NRobbery, RobbersList* obj) {
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
	printf("\nВведите имя умирающего ");
	getchar();
	gets_s(names);
	int n=0;
	for (int i = 0; i < *NRobbery; i++) {
		//printf("|%s|%s|", names, obj[i].Name);
		if (strcmp(  names , obj[i].Name)==0 && obj[i].IsAlife) {
			obj[i].IsAlife = false;
			printf("Бандита успешно умертвили");
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