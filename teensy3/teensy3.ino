//#include <SoftwareSerial.h>

int greenpin = 0;
int yellowpin = 1;
int redpin = 2;

#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx

void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth
  Serial.begin(9600); 
  Serial1.begin(9600); 

  // Setup for LEDpins
  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(redpin, OUTPUT);
}

void loop() {
// Process commands from bluetooth first.
//  if(Serial1.available() > 0){
    String str = Serial1.readString().substring(0);
    
    if(str == "HOT"){
      digitalWrite(redpin, HIGH);
      digitalWrite(yellowpin, LOW);
      digitalWrite(greenpin, LOW);
    }
    else if(str == "MODERATE"){
      digitalWrite(redpin, LOW);
      digitalWrite(yellowpin, HIGH);
      digitalWrite(greenpin, LOW);
    }
    else if(str == "COLD"){
      digitalWrite(redpin, LOW);
      digitalWrite(yellowpin, LOW);
      digitalWrite(greenpin, HIGH);
    }
  }
//}
