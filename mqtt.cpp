#include "mqtt.hpp"

namespace mqtt
{
	void connect(PubSubClient& client, String const& clientId)
	{
		if (client.connected())
			return;

		Serial.println("Connecting to MQTT broker...");
		while(!client.connect(clientId.c_str()));
		Serial.println("Connected to MQTT broker.");
	}
}
