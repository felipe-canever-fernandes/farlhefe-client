#pragma once

#include <Arduino.h>

namespace petSensor
{
	extern uint8_t const pin;
	bool readPetIsNear();
}
