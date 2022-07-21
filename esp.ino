static auto const led_pin = uint8_t(33);

void setup()
{
	pinMode(led_pin, OUTPUT);
	Serial.begin(115200);
}

void loop()
{
	static auto led_state = static_cast<bool>(digitalRead(led_pin));

	led_state = !led_state;
	digitalWrite(led_pin, led_state);

	delay(1000);
}
