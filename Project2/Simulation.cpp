#include "Simulation.h"

using namespace CTIS476;

Simulation::Simulation(std::list<Soldier*> blues, std::list<Soldier*> reds)
{
	this->blues = blues;
	this->reds = reds;
	//random number initialization
	srand(time(NULL));
}

Simulation::~Simulation()
{
	// do your memory deallocation
	// memory management is important
}

void Simulation::initialize()
{
	for (Soldier* soldier : blues)
		soldier->initialize();
	for (Soldier* soldier : reds)
		soldier->initialize();
}
void Simulation::iterate()
{
	//iterate simulation with a single step
	//the modeling behaviour must be implemented as described in class
	//BEWARE: Model execution order problem

}
bool Simulation::isCompleted()
{
	return true;
}

void Simulation::getNumberOfAlive(int& blue, int& red)
{
	blue = 0;
	red = 0;
	//calculate the number of survivors in each side
}

int Simulation::getScore()
{
	//calculate the score
	//look header explanations
	return 0;
}

float Simulation::generateProbability() const
{
	float random = (float)(rand() % 1000) / 1000.0f;
	return random;
}
