#include <Wire.h>
#include <SoftwareSerial.h>
#define trigPin 12
#define echoPin 9

SoftwareSerial bluetooth(0, 1);

void setup() {
  // Initiate serial communication at 9600 baud rate.
  Serial.begin(9600);

  // Initiate Bluetooth communication at 9600 baud rate.
  bluetooth.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  long duration, distance;
  
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delay(500);

  // Set the trigPin on for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(500);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, and calculate the duration in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  if(distance<=20){
    Serial.print("Warning!");
    Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
    bluetooth.print("Warning!");
    bluetooth.print("Distance: ");
  bluetooth.print(distance);
  bluetooth.println(" cm");
    delay(500);
  }else{
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  bluetooth.print("Distance: ");
  bluetooth.print(distance);
  bluetooth.println(" cm");
  if(distance<=20){
    Serial.print("Warning!");
    Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
    bluetooth.print("Warning!");
    bluetooth.print("Distance: ");
  bluetooth.print(distance);
  bluetooth.println(" cm");
    delay(500);
  }
  }

  
  }



