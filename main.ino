#include <Wire.h>

#define sensor = 1;
#define motor = 2;

static struct pt pt1, pt2;

void setup()
{
    Wire.begin(); // Master init
    Serial.begin(9600);
    PT_INIT(&pt1);
    PT_INIT(&pt2);
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
    Serial.println("Connecting...");
    Serial.println("Connect sensor node!");
    pingSans();
    Serial.println("Connect motor node!");
    pingMoto();
}

/**
 * Makes sure that the sensor node is connected
 */
void pingSans()
{
    while (true)
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
            break;
        }
        else
        {
            Serial.println("Connection failed - Recieved wrong answer");
            Serial.println("Trying again");
        }
    }
}

/**
 * Makes sure that the motor node is connected
 */
void pingMoto()
{
    while (true)
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
        }
        else
        {
            Serial.println("Connection failed - Recieved wrong answer");
            Serial.println("Trying again");
        }
    }
}
