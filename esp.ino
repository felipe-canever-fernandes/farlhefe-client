#include "petSensor.hpp"
#include "foodScale.hpp"

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

	auto const petIsNear = petSensor::readPetIsNear();

	if (petIsNear == petWasNear)
		return;

	digitalWrite(ledPin, petIsNear ? HIGH : LOW);

	if (!petIsNear)
		Serial.printf("Remaining food: %i g\n", foodScale::readWeight());

	petWasNear = petIsNear;
}
