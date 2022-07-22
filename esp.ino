#include <PubSubClient.h>
#include <WiFi.h>

#include "Meal.hpp"
#include "foodScale.hpp"
#include "mqtt.hpp"
#include "petSensor.hpp"
#include "wifi.hpp"

static uint8_t const ledPin{33};

static WiFiClient wifiClient{};
static PubSubClient mqttClient{wifiClient};

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(petSensor::pin, INPUT);

	Serial.begin(115200);

	wifi::connect("", "");
	mqtt::connect(mqttClient, "mqtt.eclipseprojects.io", "farlhefe-client");
}

void loop()
{
	static bool petWasNear{false};
	static meal::Meal meal{};

	bool const petIsNear{petSensor::readPetIsNear()};

	if (petIsNear == petWasNear)
		return;

	digitalWrite(ledPin, petIsNear ? HIGH : LOW);

	if (petIsNear)
	{
		meal.quantity = foodScale::readWeight();
		meal.duration = millis();
	}
	else
	{
		meal.quantity -= foodScale::readWeight();
		meal.duration = millis() - meal.duration;

		meal.print(Serial);
	}

	petWasNear = petIsNear;
}
