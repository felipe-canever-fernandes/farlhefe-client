#pragma once

#include <Arduino.h>
#include "foodScale.hpp"

namespace meal
{
	struct Meal
	{
		foodScale::Weight quantity;
		int duration;

		auto print(HardwareSerial& serial) const -> size_t;
	};
}
