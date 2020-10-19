#include <Wire.h>

string x = "";

void setup()
{
    Wire.begin(1);
    Serial.begin(9600);
    Wire.onReceive(accept);
    Wire.onRequest(send);
    connect();
}

void loop()
{
}

void accept() {
    while (Wire.available()) {
        x += Wire.read();
    }
    Serial.println("Recieved " + x);
}

void send() {
    Wire.write(x);
    Serial.println("Sent");
}