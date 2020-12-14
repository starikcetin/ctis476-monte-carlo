#include "Soldier.h"

using namespace CTIS476;

Soldier::Soldier(LocationStruct location, float speed, float probabilityOfKill, float range)
{
	//initialize your model data
	this->initialLocation = location;
	this->initialSpeed = speed;
	this->initialProbabilityOfKill = probabilityOfKill;
	this->initialRange = range;
	this->initialIsAlive = true;

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
		this->currentLocation = location;
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
		this->currentIsAlive = false;
	}
}

const LocationStruct& Soldier::getLocation() const
{
	//return location of the model
	return this->currentLocation;
}

float Soldier::getRange() const
{
	//return range of the object
	return this->currentRange;
}

float Soldier::getProbabilityOfKill() const
{
	//return PoK of the object
	return this->currentProbabilityOfKill;
}

float Soldier::getSpeed() const
{
	//return speed of the object
	return this->currentSpeed;
}

bool Soldier::isDead() const
{
	//return true if the soldier is dead
	return !(this->currentIsAlive);
}

void Soldier::initialize()
{
	//do initialization to return everything to its initial status
	this->currentLocation = this->initialLocation;
	this->currentSpeed = this->initialSpeed;
	this->currentProbabilityOfKill = this->initialProbabilityOfKill;
	this->currentRange = this->initialRange;
	this->currentIsAlive = this->initialIsAlive;
}
