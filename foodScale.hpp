#pragma once

#include <Arduino.h>

namespace foodScale
{
	extern uint8_t const pin;

	using Weight = uint16_t;

	// Maximum food weight in g.
	extern Weight const maximumWeight;

	Weight readWeight();
}
