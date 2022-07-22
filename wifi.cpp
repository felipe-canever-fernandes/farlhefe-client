#include <WiFi.h>

#include "wifi.hpp"

namespace wifi
{
	auto connect(char ssid[], char const password[]) -> void
	{
		if (WiFi.status() == WL_CONNECTED)
			return;
		
		WiFi.begin(ssid, password);

		while (WiFi.status() != WL_CONNECTED);
	}
}
