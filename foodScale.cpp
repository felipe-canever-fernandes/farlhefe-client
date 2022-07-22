#include "foodScale.hpp"

namespace foodScale
{
	uint8_t const pin{34};

	Weight const maximumWeight{1000};

	Weight readWeight()
	{
		static float const factor{maximumWeight / 4095.0f};
		uint16_t const reading{analogRead(pin)};
		return static_cast<Weight>(reading * factor);
	}
}
