#include "petSensor.hpp"

namespace petSensor
{
	uint8_t const pin = 32;

	auto readPetIsNear() -> bool
	{
		auto const reading = digitalRead(pin);
		delay(50);
		return reading == LOW;
	}
}
