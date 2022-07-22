#include "mqtt.hpp"

namespace mqtt
{
	void connect
	(
		PubSubClient& client,
		String const& broker,
		String const& clientId
	)
	{
		if (client.connected())
			return;

		client.setServer(broker.c_str(), 1883);


		Serial.println("Connecting to MQTT broker...");
		while(!client.connect(clientId.c_str()));
		Serial.println("Connected to MQTT broker.");
	}
}
