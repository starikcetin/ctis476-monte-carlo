#pragma once
#include "Soldier.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <iostream>
#include <math.h> 

#define M_PI       3.14159265358979323846

namespace CTIS476 {

	class Simulation
	{
	public:
		//constructor
		Simulation(std::list<Soldier*> blues, std::list<Soldier*> reds);
		//destructor
		~Simulation();

		//this methods is required for re-initializing simulation to its first status
		void initialize();

		//operate simulation models once
		void iterate();

		//return true if one side is annihilated
		bool isCompleted();

		//return alive numbers of each side
		void getNumberOfAlive(int& blue, int& red);

		//return number of survived soldiers
		//positive if blue wins
		//negative if red wins
		int getScore();

	private:
		std::list<Soldier*> blues;
		std::list<Soldier*> reds;

	private: 
		//get a random number
		float generateProbability() const;
		//helper print functios
		void writeWithTab(std::string val)
		{
#ifdef PRINT_LOGS	
			std::cout << "    " << val;
#endif
		}
		void write(std::string val)
		{
#ifdef PRINT_LOGS	
			std::cout << "" << val;
#endif
		}
		void writeln(std::string val = "")
		{
#ifdef PRINT_LOGS	
			std::cout << "" << val << std::endl;
#endif	
		}

		// custom implementations
	private:
		void soldierAct(Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies);
		bool tryShoot(const Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies);
		void tryKill(const Soldier* shooter, Soldier* target);
		void move(Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies);
		std::list<Soldier*> getAlives(const std::list<Soldier*> soldiers);
		bool isEradicated(const std::list<Soldier*> side) const;
		int getNumberOfAliveOnSide(const std::list<Soldier*> side) const;
		std::list<Soldier*> getInRange(const Soldier * actingSoldier, const std::list<Soldier*> enemies);

		template<typename T>
		int randomIndex(const std::list<T>& list) const;

		template<typename T>
		T randomItem(const std::list<T>& list) const;
	};

}