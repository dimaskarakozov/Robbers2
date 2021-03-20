#ifndef _MENU_H_
#define _MENU_H_
#include <iostream>
#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS

void menushka(int *NRobbery, RobbersList* obj, RobbersList &value) {
	int action=-2;
	int n;
	printf("\n\n\n==================================================================================================== ");
	printf("\nМенюха:");

	printf("\n0)Добавить в банду бандита со своими значениями");
	printf("\n1)Добавить в банду n бандитов с рандомными значениями");
	printf("\n2)Убить первого попавшего бандита(с нужным именем)");
	printf("\n3)Посмотреть таблицу имущества бандитов или изменить таблицу весов ");
	printf("\n4)Изменить имущество бандита");

	printf("\n");
	scanf_s("%d", &action);

	switch (action)
	{
	case 0: {
		AddNRobber(NRobbery, obj);
		break;
	}
	case 1: {
		printf("Введите число бандитов ");
		scanf_s("%d", &n); 
		while (n <= 0 || n+*NRobbery>40) {
			printf("Вы ввели неправильное число, попробуйте еще раз \n(общее число бандитов не может превышать 40,\n а также нельзя добавить отрицательных бандитов)  ");
			scanf_s("%d", &n);
		}
		RandomAddNRobbers(n, NRobbery, obj);

		break;
	}
	case 2: {
		KillOneBody(NRobbery,obj);
		break;
	}
	case 3: {
		AllStats(NRobbery, obj,value);
		break;
	}
	case 4: {
		ChangeStat(NRobbery, obj);
		break;
	}

	}
	menushka(NRobbery, obj,value);
}
#endif