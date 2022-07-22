#pragma once

#include "Meal.hpp"

namespace meal
{
	size_t Meal::print(HardwareSerial& serial) const
	{
		int const durationInSeconds{duration / 1000};

		return serial.printf
		(
			"%d g eaten in %d s\n",
			quantity,
			durationInSeconds
		);
	}
}
