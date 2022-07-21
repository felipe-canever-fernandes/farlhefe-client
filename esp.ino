static auto const ledPin = uint8_t(33);
static auto const lightSensorPin = uint8_t(32);

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(lightSensorPin, INPUT);

	Serial.begin(115200);
}

void loop()
{
	auto const lightSensorRead =
			static_cast<bool>(digitalRead(lightSensorPin));
	
	auto const isPetNear = !lightSensorRead;

	digitalWrite(ledPin, isPetNear);
}
