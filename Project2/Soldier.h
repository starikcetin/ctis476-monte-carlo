#pragma once
#include <exception>
#include <string>

//#define PRINT_LOGS

namespace CTIS476 {

	class SoldierException : public std::exception
	{
	private:
		std::string error;
	public:
		SoldierException(std::string error) :error{ error } {}
		const char* what() const throw()
		{
			return error.c_str();
		}
	};

	struct LocationStruct
	{
		LocationStruct(float x, float y) :x(x), y(y) {}
		LocationStruct() = default;
		float x;
		float y;
	};

	class Soldier
	{
	public:
		//constructor
		Soldier(LocationStruct location, float speed, float probabilityOfKill, float range);
		//destructor
		~Soldier();

		//this methods is required for re-initializing models to their first status
		void initialize();

		//getter methods
		const LocationStruct& getLocation() const;
		float getRange() const;
		float getProbabilityOfKill() const;
		float getSpeed() const;
		bool isDead() const;

		//action methods
		void kill();
		void setLocation(LocationStruct location) throw(SoldierException);
	};
}