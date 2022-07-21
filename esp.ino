static auto const led_pin = uint8_t(33);
static auto const light_sensor_pin = uint8_t(32);

void setup()
{
	pinMode(led_pin, OUTPUT);
	pinMode(light_sensor_pin, INPUT);

	Serial.begin(115200);
}

void loop()
{
	auto const light_sensor_read =
			static_cast<bool>(digitalRead(light_sensor_pin));
	
	auto const is_pet_near = !light_sensor_read;

	digitalWrite(led_pin, is_pet_near);
}
