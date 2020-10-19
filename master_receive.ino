#include <Wire.h>
char *x = "szijasimon";
char z;
void setup()
{
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{

  Wire.requestFrom(9, 5); // request 6 bytes from slave device #8

  while (Wire.available())
  {                  // slave may send less than requested
    z = Wire.read(); // receive a byte as character
    Serial.print(z); // print the character
  }
  delay(500);
  Serial.println();
}
