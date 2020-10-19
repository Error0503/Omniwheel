#include <Wire.h>

char x = 0;

void setup()
{
  Wire.begin(); // Master init
  Serial.begin(9600);
}

void asd(int b)
{ // Slave recieve
  while (Wire.available())
  {
    x = Wire.read();
    Serial.print(x);
  }
  Serial.println();
}

void yeet()
{ // Slave send
  char *ch = "henlo";
  Wire.write(ch);
  Serial.println("Sending...");
}

void sendData()
{
}

string recieveData(int ezMiAFasznakKell)
{
  string data = "";
  while (Wire.available())
  {
    data += Wire.read();
  }
}

void loop()
{
}