// Required libraries for motor shield/controller
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
// Define sensors, variables, and motors
const int leftSensor = A0;
const int rightSensor = A1;
int sensorLeftValue = 0;
int sensorRightValue = 0;
int motorLeftValue = 0;
int motorRightValue = 0;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  // start the controller
  AFMS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor values
  if (counter < 1000) {
    sensorLeftValue = analogRead(leftSensor);
    sensorRightValue = analogRead(rightSensor);
    // map the sensor value to motor values
    motorLeftValue = map(sensorLeftValue, 100, 300, 0, 150)
    motorRightValue = map(sensorRigthValue, 100, 300, 0 150)
    // set the motor values
    leftMotor->setSpeed(motorLeftValue)
    rightMotor->setSpeed(motorRightValue)
    // run the motors
    leftMotor->run(FORWARD)
    rightMotor->run(FORWARD)
    delay(2)
    counter++
  } else {
    leftMotor->setSpeed(0)
    rightMotor->setSpeed(0)
    leftMotor->run(FORWARD)
    rightMotor->run(FORWARD)
  }
  
}
