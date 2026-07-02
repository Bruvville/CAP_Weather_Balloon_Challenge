#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_DPS310.h>

Adafruit_DPS310 dps;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); // Wait for Serial Monitor to open

  Serial.println("--- XIAO ESP32-S3 DPS310 Test ---");

  // Initialize I2C using default XIAO pins (D4 = SDA, D5 = SCL)
  Wire.begin();

  // Initialize the DPS310 over I2C (Default address is usually 0x77)
  if (!dps.begin_I2C()) {
    Serial.println("Could not find a valid DPS310 sensor, check wiring!");
    while (1);
  }
  
  Serial.println("DPS310 found!");

  // Configure highest precision instrumentation settings
// Configure sample rate (16 Hz) and oversampling (64 samples / 8 samples)
  dps.configurePressure(DPS310_16HZ, DPS310_64SAMPLES);
  dps.configureTemperature(DPS310_16HZ, DPS310_8SAMPLES);
}

void loop() {
  sensors_event_t temp_event, pressure_event;
  
  // Fetch fresh readings from the sensor
  if (dps.getEvents(&temp_event, &pressure_event)) {
    Serial.print("Temperature = ");
    Serial.print(temp_event.temperature);
    Serial.print(" *C | ");

    Serial.print("Pressure = ");
    Serial.print(pressure_event.pressure);
    Serial.println(" hPa");
  } else {
    Serial.println("Failed to read sensor events :(");
  }

  delay(1000); // 1-second interval matching your logging target
}