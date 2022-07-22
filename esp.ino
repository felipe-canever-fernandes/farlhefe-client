#include "petSensor.hpp"

using FoodWeight = uint16_t;
// Maximum food weight in g.
static auto const maximumFoodWeight = FoodWeight(1000);

static auto const ledPin = uint8_t(33);
static auto const potentiometerPin = uint8_t(34);

auto readFoodWeight() -> FoodWeight;

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
		Serial.printf("Remaining food: %i g\n", readFoodWeight());

	petWasNear = petIsNear;
}

auto readFoodWeight() -> FoodWeight
{
	static auto const factor = maximumFoodWeight / 4095.0f;
	auto const potentiometerReading = analogRead(potentiometerPin);
	return static_cast<FoodWeight>(potentiometerReading * factor);
}
