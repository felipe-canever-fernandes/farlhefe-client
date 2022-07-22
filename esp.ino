#include "Meal.hpp"
#include "foodScale.hpp"
#include "petSensor.hpp"
#include "wifi.hpp"

static uint8_t const ledPin{33};

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(petSensor::pin, INPUT);

	Serial.begin(115200);

	wifi::connect("", "");
}

void loop()
{
	static bool petWasNear{false};
	static meal::Meal meal{};

	bool const petIsNear{petSensor::readPetIsNear()};

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
