#include "Soldier.h"

using namespace CTIS476;

Soldier::Soldier(LocationStruct location, float speed, float probabilityOfKill, float range)
{
	//initialize your model data

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
	}
}

const LocationStruct& Soldier::getLocation() const
{
	//return location of the model
	return LocationStruct();
}
float Soldier::getRange() const
{
	//return range of the object
	return 10.0f;
}
float Soldier::getProbabilityOfKill() const
{
	//return PoK of the object
	return 1.0f;
}
float Soldier::getSpeed() const
{
	//return speed of the object
	return 5.0f;
}
bool Soldier::isDead() const
{
	//return true if the soldier is dead
	return true;
}
void Soldier::initialize()
{
	//do initialization to return everything to its initial status
}