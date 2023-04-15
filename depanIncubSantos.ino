
// variable to store the value coming from the sensor
int sensorPin;    // select the input pin for the potentiometer
int RelaisPin;
int sensorValue;
float tempe;
unsigned long read_time;
 

void setup() {
  Serial.begin(9600);
  sensorPin = 0;
  RelaisPin = 2; // assign pin for Mc
  tempe = 0.0;

  // defin type of pin
  pinMode(RelaisPin, OUTPUT);
  digitalWrite(RelaisPin, LOW);
  read_time = millis();
}

void loop() {
  if((millis() - read_time) >= 4000){
    read_time = millis();
    
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  tempe = ((961 - sensorValue)/11.0)-1.3 ;
  Serial.println(tempe);  
  }

  //Controller of Relais
  if(tempe >= 37.7){
    digitalWrite(RelaisPin, LOW);
  }

   if (tempe <= 37.4){
    digitalWrite(RelaisPin, HIGH);
  }
}
