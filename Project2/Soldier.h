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

	// also repurposed as a Vector2 in simulation code
	struct LocationStruct
	{
		LocationStruct(float x, float y) :x(x), y(y) {}
		LocationStruct() = default;
		float x;
		float y;

		LocationStruct operator-(const LocationStruct& rhs) const {
			return LocationStruct(x - rhs.x, y - rhs.y);
		}

		LocationStruct operator+(const LocationStruct& rhs) const {
			return LocationStruct(x + rhs.x, y + rhs.y);
		}

		LocationStruct operator*(const float rhs) const {
			return LocationStruct(x * rhs, y * rhs);
		}

		LocationStruct operator/(const float rhs) const {
			return LocationStruct(x / rhs, y / rhs);
		}

		float squaredDistanceTo(const LocationStruct& other) const {
			auto diff = *this - other;
			return (diff.x * diff.x) + (diff.y * diff.y);
		}

		float distanceTo(const LocationStruct& other) const {
			return sqrtf(this->squaredDistanceTo(other));
		}

		float squaredMagnitude() const {
			return (x * x) + (y * y);
		}

		float magnitude() const {
			return sqrtf(squaredMagnitude());
		}

		LocationStruct normalized() const {
			return *this / magnitude();
		}
	};

	class Soldier
	{
	private:
		LocationStruct initialLocation;
		float initialSpeed;
		float initialProbabilityOfKill;
		float initialRange;
		bool initialIsAlive;
		LocationStruct currentLocation;
		float currentSpeed;
		float currentProbabilityOfKill;
		float currentRange;
		bool currentIsAlive;
		LocationStruct provisionalLocation;
		bool provisionalIsAlive;

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

		// returns if the soldier was shot and killed this iteration 
		// in other words, returns if the soldier will be dead next iteration
		bool provisionalIsDead() const;

		//this method applies the provisional state to the current state
		//call at the end of each iteration
		void applyProvisionalState();
	};
}
