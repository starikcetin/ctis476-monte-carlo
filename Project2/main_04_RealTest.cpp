#include <stdio.h>
#include <iostream>
#include <map> 
#include <windows.h>

#include "CommonHeader.h"
#define NUMBER_OF_RUNS 10000

//In this run sides are apart
//Every entity is out of range
//We are building a complete test  
//PoK is 0.1 which means every shot has a %10 probability to hit

int main(int argc, char *argv[])
{
	float redPok = 0.36f;

	std::cout << "red: " << redPok << "pok" << std::endl;
	std::list<Soldier*> blues;
	std::list<Soldier*> reds;
	LocationStruct loc1(0.0f, 0.0f);
	LocationStruct loc2(0.0f, 100.0f);

	for (int i = 0; i < 100; i++)
	{
		loc1.x++;
		blues.push_back(new Soldier(loc1, 5, 0.1f, 15.0f));
	}

	for (int i = 0; i < 60; i++)
	{
		loc2.x++;
		reds.push_back(new Soldier(loc2, 5, redPok, 15.0f));
	}

	Simulation s(blues, reds);

	runSimulation(s, NUMBER_OF_RUNS);

	system("Pause");

}