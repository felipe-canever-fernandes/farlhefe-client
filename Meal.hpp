#pragma once

#include <Arduino.h>

#include "foodScale.hpp"

namespace meal
{
	struct Meal
	{
		foodScale::Weight quantity;
		int duration;

		size_t print(HardwareSerial& serial) const;
	};
}
