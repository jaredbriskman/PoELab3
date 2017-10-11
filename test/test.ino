const int pSensePin = A0;  // Starboard Sensor
const int sSensePin = A1;  // Port Sensor

int pSenseValue = 0;        // value read from the port sensor
int sSenseValue = 0;        // value read from the starboard sensor

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  pSenseValue = analogRead(pSensePin);
  sSenseValue = analogRead(sSensePin);
  // print the results to the Serial Monitor:
  Serial.print(pSenseValue);
  Serial.print('x');
  Serial.println(sSenseValue);
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
