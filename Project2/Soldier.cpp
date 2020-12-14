#include "Soldier.h"

using namespace CTIS476;

Soldier::Soldier(LocationStruct location, float speed, float probabilityOfKill, float range)
{
	//initialize your model data
	initialLocation = location;
	initialSpeed = speed;
	initialProbabilityOfKill = probabilityOfKill;
	initialRange = range;
	initialIsAlive = true;

	initialize();
}

Soldier::~Soldier()
{
}

void Soldier::setLocation(LocationStruct location) throw(SoldierException)
{
	if (isDead())
	{
		throw new SoldierException("Soldier is Dead");
	}
	else
	{
		//set location
		currentLocation = location;
	}
}
void Soldier::kill()
{
	if (isDead())
	{
		throw new SoldierException("Soldier is Dead");
	}
	else
	{
		//set alive status
		currentIsAlive = false;
	}
}

const LocationStruct& Soldier::getLocation() const
{
	//return location of the model
	return currentLocation;
}

float Soldier::getRange() const
{
	//return range of the object
	return currentRange;
}

float Soldier::getProbabilityOfKill() const
{
	//return PoK of the object
	return currentProbabilityOfKill;
}

float Soldier::getSpeed() const
{
	//return speed of the object
	return currentSpeed;
}

bool Soldier::isDead() const
{
	//return true if the soldier is dead
	return !(currentIsAlive);
}

void Soldier::initialize()
{
	//do initialization to return everything to its initial status
	currentLocation = initialLocation;
	currentSpeed = initialSpeed;
	currentProbabilityOfKill = initialProbabilityOfKill;
	currentRange = initialRange;
	currentIsAlive = initialIsAlive;
}
