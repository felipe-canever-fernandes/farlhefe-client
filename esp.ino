static auto const ledPin = uint8_t(33);
static auto const lightSensorPin = uint8_t(32);
static auto const potentiometerPin = uint8_t(34);

auto readPetIsNear() -> bool;

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(lightSensorPin, INPUT);

	Serial.begin(115200);
}

void loop()
{
	static auto petWasNear = false;

	auto const petIsNear = readPetIsNear();

	if (petIsNear == petWasNear)
		return;
	
	digitalWrite(ledPin, petIsNear ? HIGH : LOW);

	if (!petIsNear)
	{
		auto const potentiometerReading = analogRead(potentiometerPin);
		Serial.println(potentiometerReading);
	}

	petWasNear = petIsNear;
}

auto readPetIsNear() -> bool
{
	auto const lightSensorReading = digitalRead(lightSensorPin);
	delay(50);
	return lightSensorReading == LOW;
}
