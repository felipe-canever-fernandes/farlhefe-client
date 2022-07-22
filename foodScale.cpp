#include "foodScale.hpp"

namespace foodScale
{
	uint8_t const pin = 34;

	Weight const maximumWeight = 1000;

	auto readWeight() -> Weight
	{
		static auto const factor = maximumWeight / 4095.0f;
		auto const reading = analogRead(pin);
		return static_cast<Weight>(reading * factor);
	}
}
