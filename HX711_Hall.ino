#include <HX711.h>

#define calibration_factor 190399 // This value depends on your specific setup and needs to be calibrated

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); // potentially causes some problems???
  scale.set_gain(128); // Set the gain (and choose the channel: A if =128 or =64 and B if =32)
}

void loop() {
  float voltage = (scale.get_value(1)); // Get the voltage reading
  Serial.print("Voltage: ");
  Serial.print(voltage, 8); // Print voltage with 2 decimal places
  Serial.println(" V");
  delay(100); // Wait for a second before reading again
}
