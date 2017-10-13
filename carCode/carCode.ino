// Required libraries for motor shield/controller
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
// Define sensors, variables, and motors
const int portSensor = A2;
const int starboardSensor = A0;
int sensorPortValue = 0;
int sensorStarboardValue = 0;
int motorPortValue = 0;
int motorStarboardValue = 0;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *portMotor = AFMS.getMotor(1);
Adafruit_DCMotor *starboardMotor = AFMS.getMotor(2);

int counter = 0;
bool record = false;
char buffer;

void setup() {
  // put your setup code here, to run once:
  // start the controller
  AFMS.begin();
  Serial.begin(9600);
  Serial.println ("Log? (y/n):");
  while (Serial.available() == 0) {}
  buffer = Serial.read();
  char Str[2] = {buffer};
  if (buffer == 'y') {
    record = true;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor values
  sensorPortValue = analogRead(portSensor);
  sensorStarboardValue = analogRead(starboardSensor);
  // map the sensor value to motor values
  portMotor->setSpeed(30);
  starboardMotor->setSpeed(30);
  if (record) {
    Serial.print(sensorPortValue);
    Serial.print(",");
    Serial.print(sensorStarboardValue);
    Serial.print(",");
  }
  if (sensorPortValue > 800) {
    portMotor->run(BACKWARD);
    if (record) {
      Serial.print("-1");
    }
  }
  else {
    portMotor->run(FORWARD);
    if (record) {
      Serial.print("1");
      Serial.print(",");
    }
  }

  if (sensorStarboardValue > 800) {
    starboardMotor->run(BACKWARD);
    if (record) {
      Serial.print("-1");
    }
  }

  else {
    starboardMotor->run(FORWARD);
    if (record) {
      Serial.print("1");
      Serial.println();
    }
  }
}
