#pragma once

#include <Arduino.h>
#include <PubSubClient.h>

namespace mqtt
{
	void connect
	(
		PubSubClient& client,
		String const& broker,
		String const& clientId
	);
}
