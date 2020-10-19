#include <Wire.h>
char *x = "szijasimon";
void setup()
{
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);             // sends x
  Wire.endTransmission();    // stop transmitting
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission();
  delay(500);
}
