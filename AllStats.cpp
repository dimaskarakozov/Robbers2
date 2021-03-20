#pragma once
#define NOMINMAX

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include "Header.h"
#include "rlutil.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#undef min
#undef max
using namespace sf;
void graphic(int* NRobbery, RobbersList* obj, int Richer, int AllAllRiches);
void AllStats(int *NRobbery, RobbersList* obj, RobbersList &value) {

	printf("\t31)Инфо по всем бандитам");
	printf("\n\t32)Поиск по имени");
	printf("\n\t33)Изменить веса\n");
	int n=0;
	scanf("%d", &n);
	while (n != 31 && n != 32 && n != 33)
	{
		printf("\nВы ввели не правильноое число,давайте попробуем еще раз: ");
		scanf("%d", &n);

	}


	int Richer=0;
	int AllAlife=0,AllHorses=0, AllKnifes=0, AllDiamonds=0,AllDecorations=0,AllWifes=0,AllCoins=0,AllAllRiches=0, AllPeople=0;
	char names[20];

	if (n == 33) {
		printf("\nЦена лошади (%d): ",value.NHorses);
		scanf("%d", &n); value.NHorses = n;
		printf("\nЦена сабли (%d): ", value.NKnifes);
		scanf("%d", &n); value.NKnifes = n;
		printf("\nЦена рубина (%d): ", value.NDiamonds);
		scanf("%d", &n); value.NDiamonds = n;
		printf("\nЦена ожерелья (%d): ", value.NDecorations);
		scanf("%d", &n); value.NDecorations = n;
		printf("\nЦенность жены (%d): ", value.NWifes);
		scanf("%d", &n); value.NWifes = n;
		printf("\nЦены были удачно изменены ");
		n = 33;
	}

	if (n == 32) {
		

		printf("\nВведите имя:(на английском) ");
		//scanf_s("%19s", &names);
		getchar();
		gets_s(names);
		n =34;
	}

	if (n == 31 || n == 34) {
		printf("Белым в скобках обозначено колличество штук, ");
		rlutil::setColor(14);
		printf("а желтым колличество денег  ");
		rlutil::setColor(15);
		for (int i = 0; i < *NRobbery; i++)
		{
			if (n == 31 || strcmp(names, obj[i].Name) == 0) {
				printf("\nИмя: %s, ", obj[i].Name);
				AllPeople++;
				if (obj[i].IsAlife)
				{
					printf("Живой, ");
					AllAlife += 1;
					AllHorses += obj[i].NHorses;
					AllKnifes += obj[i].NKnifes;
					AllDiamonds += obj[i].NDiamonds;
					AllDecorations += obj[i].NDecorations;
					AllWifes += obj[i].NWifes;
					AllCoins += obj[i].NCoins;
					obj[i].AllRiches = (obj[i].NHorses * value.NHorses) + obj[i].NKnifes * value.NKnifes + obj[i].NDiamonds * value.NDiamonds + obj[i].NDecorations * value.NDecorations - obj[i].NWifes * value.NWifes + obj[i].NCoins;
					AllAllRiches += obj[i].AllRiches;
					if (obj[i].AllRiches > obj[Richer].AllRiches) {
						//printf("%d %d",obj[i].AllRiches , Richer);
						Richer = i;
					}
					printf("Лошадей:");
					rlutil::setColor(14); printf(" %d ", obj[i].NHorses * value.NHorses); rlutil::setColor(15);
					printf(" (%d), ", obj[i].NHorses);
					printf("Саблей:");
					rlutil::setColor(14); printf(" %d ", obj[i].NKnifes * value.NKnifes); rlutil::setColor(15);
					printf(" (%d), ", obj[i].NKnifes);
					printf("Рубины:");
					rlutil::setColor(14); printf(" %d ", obj[i].NDiamonds * value.NDiamonds); rlutil::setColor(15);
					printf(" (%d), ", obj[i].NDiamonds);
					printf("Ожерелья:");
					rlutil::setColor(14); printf(" %d ", obj[i].NDecorations * value.NDecorations); rlutil::setColor(15);
					printf(" (%d), ", obj[i].NDecorations);
					printf("Жены:");
					rlutil::setColor(14); printf(" %d ", obj[i].NWifes * value.NWifes); rlutil::setColor(15);
					printf(" (%d), ", obj[i].NWifes);
					printf("Динаров:");
					rlutil::setColor(14); printf(" %d ", obj[i].NCoins); rlutil::setColor(15);
					rlutil::setColor(14); printf("Стоимость всего богатства: %d ", obj[i].AllRiches); rlutil::setColor(15);

				}
				else {
					rlutil::setColor(1);
					printf("Мертвый, ");
					printf("Лошадей:");
					printf(" %d ", obj[i].NHorses * value.NHorses);
					printf(" (%d), ", obj[i].NHorses);
					printf("Саблей:");
					printf(" %d ", obj[i].NKnifes * value.NKnifes);
					printf(" (%d), ", obj[i].NKnifes);
					printf("Рубины:");
					printf(" %d ", obj[i].NDiamonds * value.NDiamonds);
					printf(" (%d), ", obj[i].NDiamonds);
					printf("Ожерелья:");
					printf(" %d ", obj[i].NDecorations * value.NDecorations);
					printf(" (%d), ", obj[i].NDecorations);
					printf("Жены:");
					printf(" %d ", obj[i].NWifes * value.NWifes);
					printf(" (%d), ", obj[i].NWifes);
					printf("Динаров:");
					printf(" %d ", obj[i].NCoins);
					printf("Стоимость всего богатства: %d ", obj[i].AllRiches);
					rlutil::setColor(15);
				}
				printf("\n---------------------------------------------------------------------------------------------------- ");
				
			}		
		}
	
			printf("\n---------------------------------------------------------------------------------------------------- ");
			printf("\n---------------------------------------------------------------------------------------------------- ");
			printf("\nВсего людей: %d, ", AllPeople);
			printf("Живых: %d, ", AllAlife);
			printf("Лошадей: %d (%d), ", value.NHorses * AllHorses, AllHorses);
			printf("Саблей: %d (%d), ", value.NKnifes * AllKnifes, AllKnifes);
			printf("Рубины: %d (%d), ", value.NDiamonds * AllDiamonds, AllDiamonds);
			printf("Ожерелья: %d (%d), ", value.NDecorations * AllDecorations, AllDecorations);
			printf("Жены: %d (%d), ", value.NWifes * AllWifes, AllWifes);
			printf("Динаров: %d (%d), ", value.NCoins * AllCoins, AllCoins);
			printf("ИТОГО: %d, ", AllAllRiches);
			printf("\n---------------------------------------------------------------------------------------------------- ");
			rlutil::setColor(14);
			printf("\nТаблица текущих весов: ");
			printf("Лошадь: %d, ", value.NHorses);
			printf("Сабля: %d, ", value.NKnifes);
			printf("Рубин: %d, ", value.NDiamonds);
			printf("Ожерелье: %d, ", value.NDecorations);
			printf("Жена: %d, ", value.NWifes);
			printf("Динар: Всегда 1 к 1:) ");
			rlutil::setColor(15);
			printf("\n---------------------------------------------------------------------------------------------------- ");
		

			
			if (obj[Richer].AllRiches > 0) {
				printf("\nСамый богатый: Имя: %s, ", obj[Richer].Name);
				printf("Живой, ");
				printf("Лошадей:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NHorses * value.NHorses); rlutil::setColor(15);
				printf(" (%d), ", obj[Richer].NHorses);
				printf("Саблей:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NKnifes * value.NKnifes); rlutil::setColor(15);
				printf(" (%d), ", obj[Richer].NKnifes);
				printf("Рубины:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NDiamonds * value.NDiamonds); rlutil::setColor(15);
				printf(" (%d), ", obj[Richer].NDiamonds);
				printf("Ожерелья:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NDecorations * value.NDecorations); rlutil::setColor(15);
				printf(" (%d), ", obj[Richer].NDecorations);
				printf("Жены:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NWifes * value.NWifes); rlutil::setColor(15);
				printf(" (%d), ", obj[Richer].NWifes);
				printf("Динаров:");
				rlutil::setColor(14); printf(" %d ", obj[Richer].NCoins); rlutil::setColor(15);
				rlutil::setColor(14); printf("Стоимость всего богатства: %d ", obj[Richer].AllRiches); rlutil::setColor(15);
			}
			else {
				printf("\nУ Вас нет бандитов без долгов:)\nПоэтому не будет строчки с самым богатым бандитом");
			}
	}

	if (n == 31) {
		graphic(NRobbery, obj, obj[Richer].AllRiches,  AllAllRiches);
	}
}

void graphic(int* NRobbery, RobbersList* obj,  int Richer, int AllAllRiches)
{
	//printf("|%d|",AllAllRiches);
	Font font;
	font.loadFromFile("font.otf");
	Text text("", font, 20);
	//text.setColor(Color::Red);
	
	bool IsRed=true;

	float StartPos = 50;
	float StartPosCircle = 0;
	float StartPosCircleBefore = 0;
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 500), "Robbers");


	// Установка цвета фона
	window.clear(Color::Black);

	CircleShape circle(250.f);
	circle.setFillColor(Color::Red);
	circle.move(500, 0);
	window.draw(circle);

	for (int i = 0; i < *NRobbery; i++) {
		//printf("*");
		if (obj[i].IsAlife) {
			//printf("-");
			RectangleShape rectangle(Vector2f( 500.f/(*NRobbery) , 500.f / Richer * obj[i].AllRiches));
			//     
			//rectangle.setRotation(90);
			// Перемещаем его в нижний ряд справа от многоугольника
			rectangle.move( 500.f *i /(*NRobbery) , 0);
		//	rectangle.setOrigin(Vector2f(50.f, 400.f / AllAllRiches * obj[i].AllRiches));
			if (IsRed) {
				rectangle.setFillColor(Color::Red);
			}
			else {
				rectangle.setFillColor(Color::Blue);
			}
			IsRed = !IsRed;
			
			// Отрисовка прямоугольника
			window.draw(rectangle);

			StartPos = StartPos +( 500.f / Richer) * obj[i].AllRiches;
			//printf( "'%f'", 400.f / AllAllRiches * obj[i].AllRiches );

			//"%s", obj[i].Name
			text.setString(obj[i].Name);
			text.setPosition( 500.f / (*NRobbery) * (i+1), 25);
			text.setRotation(90);
			window.draw(text);




			
			    printf("|%f|", StartPosCircle);

				RectangleShape Polosa(Vector2f(250.f, 5.f));
				Polosa.setFillColor(Color::Blue);
				Polosa.setRotation(  -StartPosCircle  );
				Polosa.setPosition(750, 250);
				window.draw(Polosa);

				
				StartPosCircleBefore = StartPosCircle;
				StartPosCircle += 360.f / AllAllRiches * obj[i].AllRiches;
				
				text.setString(obj[i].Name);

				text.setPosition( cos(-(StartPosCircle+ StartPosCircleBefore +20)/2* 3.14159265359/180)*50+750, sin(-(StartPosCircle + StartPosCircleBefore+20) / 2 * 3.14159265359 / 180)*50+250);
				
				text.setRotation(-(StartPosCircle + StartPosCircleBefore) / 2);
				window.draw(text);

				
				
				
		}


		
	}
	// Отрисовка окна
	window.display();


	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close(); // тогда закрываем его
		}

	}
	printf("\n График отправлен...");
}
