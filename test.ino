#include <Wire.h>

char x = 0;

void setup() {
  Wire.begin(9);
  Wire.onReceive(asd);
  Wire.onRequest(yeet);
  Serial.begin(9600);
}

void asd(int b) {
  while (Wire.available()) {
    x = Wire.read();
    Serial.print(x);
  }
  Serial.println();
}

void yeet() {
  char* ch = "henlo";
  Wire.write(ch);
  Serial.println("Sending...");
}

void loop() {
  
}