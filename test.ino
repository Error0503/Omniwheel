#include <Wire.h>

char x = 0;

void setup() {
  Wire.begin(9);
  Wire.onReceive(asd); // Slave recieve
  Wire.onRequest(yeet); // Slave send
  Serial.begin(9600);
}

void asd(int b) { // Slave recieve
  while (Wire.available()) {
    x = Wire.read();
    Serial.print(x);
  }
  Serial.println();
}

void yeet() { // Slave send
  char* ch = "henlo";
  Wire.write(ch);
  Serial.println("Sending...");
}

void loop() {
  
}