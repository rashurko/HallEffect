#include <HX711.h>

#define calibration_factor 190399 // This value depends on your specific setup and needs to be calibrated

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

int A0_value = analogRead(A0);
int R = 1; // resistance in ohm

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); // potentially causes some problems???
  scale.set_gain(128); // Set the gain (and choose the channel: A if =128 or =64 and B if =32)
}

void loop() {
  float voltage_H = (scale.get_value(1)); // Get the voltage reading
  Serial.print("Voltage: ");
  Serial.print(voltage_H, 8); // Print voltage with 8 decimal places
  Serial.println(" V");

  float voltage = A0_value * (5.0 / 1023.0);
  float current = voltage / R;
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");
  delay(100); // Wait for 0.1 sec before reading again
}
