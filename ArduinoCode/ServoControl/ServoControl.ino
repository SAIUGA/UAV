#include <Keyboard.h>
#include <Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

Servo servo;
int servoAngle;
const int groundpin = 18;
const int powerPin =

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(52);

}


void loop() {
  // put your main code here, to run repeatedly:

  servoAngle = random(1, 360);
  servo.write(servoAngle);
  Serial.println(servoAngle);

}
