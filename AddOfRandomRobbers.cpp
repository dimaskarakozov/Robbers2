//#ifndef _ADD_H_
//#define _ADD_H_
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <string>
//extern struct RobbersList  obj[]; 
#include "Header.h"
//void FindNames();
char names[40][40] = { NULL };
int NNames = 1;
void RandomAddNRobbers(int n,int *NRobbery, RobbersList *obj){
	
	
	srand(static_cast<unsigned int>(time(0)));
	printf("\nБыли добавлены следующие бандиты ");
	for (int i = *NRobbery; i < n + *NRobbery; i++)
	{
		
		obj[i] = {"", true, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 3, rand() % 50+150, NULL };
		strcpy(obj[i].Name,names[rand() % NNames]);
	//	while (obj[i].Name == NULL) {
	//		names[rand() % NNames];
	//	}
		
		// 
			printf("\nИмя: %s, ", obj[i].Name);
			if (obj[i].IsAlife)
			{
				printf("Живой, ");

			}
			else {
				printf("Мертвый, ");
			}
			printf("Лошадей: %d, ", obj[i].NHorses);
			printf("Саблей: %d, ", obj[i].NKnifes);
			printf("Рубины: %d, ", obj[i].NDiamonds);
			printf("Ожерелья: %d, ", obj[i].NDecorations);
			printf("Жены: %d, ", obj[i].NWifes);
			printf("Динаров: %d, ", obj[i].NCoins);
			printf("\n---------------------------------------------------------------------------------------------------- ");
		//

	}
	*NRobbery += n;
}


void FindNames() {
	char mas[255] = {NULL};
	using namespace std;
	int n = 0;
	int m = 0;
	int i=0;
	// знаю что std и string использовать нельзя, но я перепробовал много способов ,но так и не смог записать в файл используя инструменты си, у меня VS 2019 обновленный и он жалуется на то,что я использую устаревшие методы и во время работы в этом месте пишет ошибку, хотя при компиляции все гладко(
	using namespace std;

		string str;
		ifstream file("names.txt", ios::in);
		
			getline(file, str);
		//	cout << str << endl;
		
		file.close();

		
		strcpy(mas, str.c_str());


		printf("\nВсе имена : %s", mas);
	while (mas[i]!= '.') {
		if (mas[i] != ' ' ) {
			names[n][m] = mas[i];
			m++;
		//	printf("\nm++;");
		}
		else {
			n++;
			m = 0;
			NNames++;
		//	printf("\nn++;");
		}
		i++;

	}
	printf("\nимен :%d", NNames);
}


//#endif