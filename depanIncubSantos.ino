
// variable to store the value coming from the sensor
int sensorPin;    // select the input pin for the potentiometer
int RelaisPin;
int sensorValue;
float tempe;
 

void setup() {
  Serial.begin(9600);
  sensorPin = 0;
  RelaisPin = 2; // assign pin for Mc
  tempe = 0.0;

  // defin type of pin
  pinMode(RelaisPin, OUTPUT);
  digitalWrite(RelaisPin, LOW);
}

void loop() {
  delay(1000);
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  tempe = ((961 - sensorValue)/11.0)+1 ;
  Serial.println(tempe);

  //Controller of Relais
  if(tempe >= 37.7){
    digitalWrite(RelaisPin, LOW);
  }

  else if (tempe <= 37,3){
    digitalWrite(RelaisPin, HIGH);
  }
}
