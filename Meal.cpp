#pragma once

#include "Meal.hpp"

namespace meal
{
	auto Meal::print(HardwareSerial& serial) const -> size_t
	{
		auto const durationInSeconds = duration / 1000;

		return serial.printf
		(
			"%d g eaten in %d s\n",
			quantity,
			durationInSeconds
		);
	}
}
