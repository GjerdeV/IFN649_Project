#include "DHT.h"
//#include <SoftwareSerial.h>

// Humidity sensor
#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

// Defininf buzzer
int buzzer = 14;

DHT dht(DHTPIN, DHTTYPE);

#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx

void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth
  Serial.begin(9600); 
  Serial1.begin(9600);  

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();

  // Setup for buzzer
  pinMode(buzzer, OUTPUT);
}

void loop() {
// Process commands from bluetooth first.
  //if(Serial1.available() > 0){
    String str = Serial1.readString().substring(0); 
    // Serial1.println(str);

    if(str == "ALARM_ON"){
      while (Serial1.readString().substring(0)!= "ALARM_OFF"){
        analogWrite(buzzer, 10);
        delay(200);
        analogWrite(buzzer, 0);
      }
    }
    if(str == "ALARM_OFF"){
      analogWrite(buzzer, 0);
    }
    


    // Fetching humidity sensor data
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
    
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);  
    
        Serial.println(t);
    
        Serial1.println(t);
        
        delay(2000);
    
      }
