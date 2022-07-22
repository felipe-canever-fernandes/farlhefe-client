#include "petSensor.hpp"
#include "foodScale.hpp"
#include "Meal.hpp"

static auto const ledPin = uint8_t(33);

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(petSensor::pin, INPUT);

	Serial.begin(115200);
}

void loop()
{
	static auto petWasNear = false;
	static auto meal = meal::Meal{};

	auto const petIsNear = petSensor::readPetIsNear();

	if (petIsNear == petWasNear)
		return;

	digitalWrite(ledPin, petIsNear ? HIGH : LOW);

	if (petIsNear)
	{
		meal.quantity = foodScale::readWeight();
		meal.duration = millis();
	}
	else
	{
		meal.quantity -= foodScale::readWeight();
		meal.duration = millis() - meal.duration;

		meal.print(Serial);
	}

	petWasNear = petIsNear;
}
