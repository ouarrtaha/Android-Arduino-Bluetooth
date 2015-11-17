// digital pin for LED
const int led = 12;
// Analog pin for the temperature sensor
const int tempSensor = A0;

// Sensor value variable
float sensorValue = 0;
// Char used for reading in Serial characters
char serialByte = 0;

void setup() {
  // Serial communication at 9600 bps
  Serial.begin(9600);
  // Sets LED as an output pin
  pinMode(led, OUTPUT);
  // Turns LED off
  digitalWrite(led, LOW);
}

void loop() {
  readSensorTemp();
  sendDataAndroid();
  
  // True if serial values have been received
  if(Serial.available() > 0) {
    serialByte = Serial.read();
    
    if(serialByte == '0') {
      digitalWrite(led, LOW);
    }
    if(serialByte == '1') {
      // Turns LED on
      digitalWrite(led, HIGH);
    }
  }
  
  // It will send data every two seconds
  delay(2000);
}

void readSensorTemp() {
  sensorValue = (5.0 * analogRead(tempSensor) * 100.0) / 1024;
}

void sendDataAndroid() {
  Serial.print(sensorValue);
  Serial.print('\n');
  delay(10);
}
