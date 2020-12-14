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
	{
		soldier->initialize();
	}

	for (Soldier* soldier : reds)
	{
		soldier->initialize();
	}
}

void Simulation::iterate()
{
	//iterate simulation with a single step
	//the modeling behaviour must be implemented as described in class
	//BEWARE: Model execution order problem

	auto const aliveReds = getAlives(reds);
	auto const aliveBlues = getAlives(blues);

	for (Soldier* blue: aliveBlues)
	{
		soldierAct(blue, aliveReds);
	}

	for (Soldier* red : aliveReds)
	{
		soldierAct(red, aliveBlues);
	}
}

void Simulation::soldierAct(Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies)
{
	auto const didShoot = tryShoot(actingSoldier, aliveEnemies);

	if (false == didShoot)
	{
		move(actingSoldier, aliveEnemies);
	}
}

// if there are targets in range, shoots one of them at random and returns true
// if there are no targets in range returns false
bool Simulation::tryShoot(const Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies)
{
	auto const enemiesInRange = getInRange(actingSoldier, aliveEnemies);

	if (enemiesInRange.size() <= 0) 
	{
		return false;
	}

	auto const selectedTarget = randomItem(enemiesInRange);
	tryKill(actingSoldier, selectedTarget);
	return true;
}

// shotoer shoots at the target. if killed, target is marked dead
void Simulation::tryKill(const Soldier* shooter, Soldier* target)
{
	auto const shooterProbOfKill = shooter->getProbabilityOfKill();
	auto const randNum = generateProbability();

	if (randNum <= shooterProbOfKill) 
	{
		target->kill();
	}
}

// moves the soldier towards an enemy selected randomly
void Simulation::move(Soldier* actingSoldier, const std::list<Soldier*> aliveEnemies) 
{
	auto const target = randomItem(aliveEnemies);

	auto const targetLoc = target->getLocation();
	auto const loc = actingSoldier->getLocation();
	auto const speed = actingSoldier->getSpeed();

	auto const moveDelta = (targetLoc - loc).normalized() * speed;
	actingSoldier->setLocation(loc + moveDelta);
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

// returns enemies that are in range of the soldier
std::list<Soldier*> getInRange(const Soldier* actingSoldier, const std::list<Soldier*> enemies)
{
	std::list<Soldier*> inRange;

	auto const squaredRange = powf(actingSoldier->getRange(), 2);
	auto const soldierLoc = actingSoldier->getLocation();

	for (Soldier* it : enemies)
	{
		auto const itLoc = it->getLocation();
		auto const sqDist = soldierLoc.squaredDistanceTo(itLoc);

		if (sqDist <= squaredRange)
		{
			inRange.push_back(it);
		}
	}

	return inRange;
}

// returns alive soldiers in the given list
std::list<Soldier*> getAlives(const std::list<Soldier*> soldiers)
{
	std::list<Soldier*> alives;

	for (Soldier* soldier : soldiers)
	{
		if (!soldier->isDead()) {
			alives.push_back(soldier);
		}
	}

	return alives;
}

template<typename T>
int randomIndex(const std::list<T>& list)
{
	return rand() % list.size();
}

template<typename T>
T randomItem(const std::list<T>& list)
{
	return list[randomIndex(list)];
}
