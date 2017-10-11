// Required libraries for motor shield/controller
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
// Define sensors, variables, and motors
const int portSensor = A0;
const int starboardSensor = A1;
int sensorLeftValue = 0;
int sensorRightValue = 0;
int motorLeftValue = 0;
int motorRightValue = 0;
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
    sensorLeftValue = analogRead(portSensor);
    sensorRightValue = analogRead(starboardSensor);
    // map the sensor value to motor values
    motorLeftValue = map(sensorLeftValue, 100, 300, 0, 150);
    motorRightValue = map(sensorRightValue, 100, 300, 0, 150);
    // set the motor values
    portMotor->setSpeed(motorLeftValue);
    starboardMotor->setSpeed(motorRightValue);
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
