#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_
struct RobbersList {
	char Name[20];
	bool IsAlife;
	int NHorses;
	int NKnifes;
	int NDiamonds;
	int NDecorations;
	int NWifes;
	int NCoins;
	int AllRiches;
};


void menushka(int *NRobbery, RobbersList *obj, RobbersList &value);
void RandomAddNRobbers(int n, int* NRobbery,  RobbersList *obj);
void AllStats(int* NRobbery, RobbersList* obj, RobbersList &value);
void AllStatsMoney(int* NRobbery, RobbersList* obj);
void AddNRobber(int* NRobbery, RobbersList* obj);
void KillOneBody(int* NRobbery, RobbersList* obj);
void FindNames();
void ChangeStat(int* NRobbery, RobbersList* obj);


#endif //_HEADER_H_
