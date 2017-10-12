// Required libraries for motor shield/controller
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
// Define sensors, variables, and motors
const int portSensor = A0;
const int starboardSensor = A1;
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
  if (counter < 5000) {
    sensorPortValue = analogRead(portSensor);
    sensorStarboardValue = analogRead(starboardSensor);
    // map the sensor value to motor values
    motorPortValue = map(sensorPortValue, 100, 300, 0, 150);
    motorStarboardValue = map(sensorStarboardValue, 100, 300, 0, 150);
    // set the motor values
    portMotor->setSpeed(motorPortValue);
    starboardMotor->setSpeed(motorStarboardValue);
    // run the motors
    portMotor->run(FORWARD);
    starboardMotor->run(FORWARD);
    delay(2);
    counter++;
  } else {
    portMotor->setSpeed(0);
    starboardMotor->setSpeed(0);
    portMotor->run(FORWARD);
    starboardMotor->run(FORWARD);
  }
  
}
