//#include <SoftwareSerial.h>

// Defining button
int buttonpin = 0;

#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx

void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth
  Serial.begin(9600); 
  Serial1.begin(9600); 

  pinMode(buttonpin, OUTPUT);
}

void loop() {
// Process commands from bluetooth first.
  //if(Serial1.available() > 0){
  
    String str = Serial1.readString().substring(0); 
    Serial.println(str);

    // Checking if button is pushed to turn off alarm
    int button_status = digitalRead(buttonpin);
    Serial1.println(button_status);
    delay(2000);
    
    
    
}
