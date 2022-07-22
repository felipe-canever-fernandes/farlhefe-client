#include <WiFi.h>

#include "wifi.hpp"

namespace wifi
{
	void connect(char ssid[], char const password[])
	{
		if (WiFi.status() == WL_CONNECTED)
			return;
		
		WiFi.begin(ssid, password);

		while (WiFi.status() != WL_CONNECTED);
	}
}
