#pragma once
#include "Simulation.h"

using namespace CTIS476;

void printSizes(int b, int r)
{
#ifdef PRINT_LOGS
	std::cout << "    Blues:" << b << " - Reds:" << r << std::endl;
#endif
}

void runSimulation(Simulation& s, int numOfRuns)
{
	int occurences[201];
	for (int i = 0; i < 201; i++)
	{
		occurences[i] = 0;
	}

	int blueWins = 0;
	int redWins = 0;
	int draws = 0;

	std::cout << "-------------STARTING " << numOfRuns << " RUNS------------" << std::endl;
	for (int i = 0; i < numOfRuns; i++)
	{
		//ready for the first run
#ifdef PRINT_LOGS	
		std::cout << "--Run:" << i + 1 << " started\n";
#endif
		s.initialize();
		do {
			s.iterate();

			int b = 0;
			int r = 0;
			s.getNumberOfAlive(b, r);
			printSizes(b, r);
		} while (s.isCompleted() == false);

		auto res = s.getScore();
		occurences[res + 100]++;

		if (res == 0)
		{
#ifdef PRINT_LOGS	
			std::cout << "--Run Ended:" << " DRAW\n";
#endif	
			draws++;
		}
		else if (res > 0)
		{
#ifdef PRINT_LOGS	
			std::cout << "--Run Ended:" << " BLUE WON\n";
#endif	
			blueWins++;
		}
		else
		{
#ifdef PRINT_LOGS	
			std::cout << "--Run Ended:" << " RED WON\n";
#endif	
			redWins++;
		}

#ifndef PRINT_LOGS
		auto runsLeft = numOfRuns - i - 1;
		auto secondsLeft = runsLeft / 16;
	std::cout << "Finished: " << i + 1 << "\tLeft: " << numOfRuns - i - 1 << "\tETA: " << secondsLeft/3600 << ":" << (secondsLeft/60)%60 << ":" << secondsLeft%60 << "				\r";
#endif // !PRINT_LOGS

	}

	std::cout << "-----------------DISTRIBUTIONS----------------------" << std::endl;
	for (int i = 0; i < 201; i++)
	{
		std::cout << i - 100 << " " << occurences[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-----------------WINS----------------------" << std::endl;
	std::cout << "Blue:" << (float)blueWins / (float)numOfRuns << std::endl;
	std::cout << "Red :" << (float)redWins / (float)numOfRuns << std::endl;
	std::cout << "Draw:" << (float)draws / (float)numOfRuns << std::endl;
}