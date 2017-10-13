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

void setup() {
  // put your setup code here, to run once:
  // start the controller
  AFMS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor values
  sensorPortValue = analogRead(portSensor);
  sensorStarboardValue = analogRead(starboardSensor);
  // map the sensor value to motor values
  motorPortValue = map(sensorPortValue, 0, 1024, -65, 65);
  motorStarboardValue = map(sensorStarboardValue, 0, 1024, -65, 65);
  // set the motor values
  portMotor->setSpeed(abs(motorPortValue));
  starboardMotor->setSpeed(abs(motorStarboardValue));
  // run the motors
  portMotor->run(motorPortValue < 0 ? BACKWARD: FORWARD);
  starboardMotor->run(motorStarboardValue < 0 ? BACKWARD: FORWARD);
}
