/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
#define trigger 10
#define echo 11
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
   long duration, distance;
   digitalWrite(trigger, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigger, LOW);
   duration = pulseIn(echo, HIGH);
  distance = (duration) / 58.2;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
     if (distance <= 50 ){
    tone(4,900,500);
    delay(distance*3.5);
     }
  }
  delay(500);
} 
