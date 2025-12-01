#include <Arduino.h>

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  Serial.println("Movement Chain Firmware - ESP32-S3");
  Serial.println("Initializing...");

  // TODO: Add initialization code here
}

void loop() {
  // TODO: Add main loop code here
  delay(1000);
}
