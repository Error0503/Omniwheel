#include <Wire.h>
#include <thread>

#define sensor = 1;
#define motor = 2;

void setup()
{
    Wire.begin(); // Master init
    Serial.begin(9600);
    connect();
}

void loop()
{
}

void recieve()
{
}

void send()
{
}

/**
 * Connects the nodes
 */
void connect()
{
    Seral.println("Connecting...");
    std::thread t1(pingSans);
    std::thread t2(pingMoto);

    t1.join();
    Serial.println("First thread finished!");
    t2.join();
    Serial.println("Second thread finished!");
    Serial.println("\"Everything is connected\"");
    
}

/**
 * Makes sure that the sensor node is connected
 */
void pingSans()
{
    Wire.beginTransmission(sensor);
    short w = 0;
    Wire.write(w);
    Wire.endTransmission(sensor);
    Wire.requestFrom(sensor, 1);
    int r;
    while (Wire.available())
    {
        r = Wire.read();
    }
    if (r = w)
    {
        Serial.println("Connected to sensor!");
    } else {
        Serial.println("Connection failed - Recieved wrong answer");
    }
}

/**
 * Makes sure that the motor node is connected
 */
void pingMoto()
{
    Wire.beginTransmission(sensor);
    short w = 1;
    Wire.write(w);
    Wire.endTransmission(sensor);
    Wire.requestFrom(sensor, 1);
    int r;
    while (Wire.available())
    {
        r = Wire.read();
    }
    if (r = w)
    {
        Serial.println("Connected to motor!");
    } else {
        Serial.println("Connection failed - Recieved wrong answer");
    }
}