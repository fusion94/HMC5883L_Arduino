/*
 * Compass Module 3-Axis HMC5883L
 * https://github.com/fusion94/HMC5883L_Arduino
 
 * Read the Compass Module 3-Axis HMC5883L and prints them over the serial connection to the computer.
   
   The circuit:
    * SDA (Data) output of compass to analog pin 4
    * SCL (Clock) output of compass to analog pin 5
    * +V of accelerometer to +5V
    * GND of accelerometer to ground

 *
 * Copyright 2011-2013, http://fusion94.org
 * Licensed under the Mozilla Public License Version 2.0
*/

#include 
HMC5883L_Arduino
#define Addr 0x1E               // 7-bit address of HMC5883 comHMC5883L_Arduinopass

void setup() {
  Serial.begin(9600);
  delay(100);                   // Power up delay
  Wire.begin();
  
  // Set operating mode to continuous
  Wire.beginTransmission(Addr); 
  Wire.write(byte(0x02));
  Wire.write(byte(0x00));
  Wire.endTransmission();
}

void loop() {
  int x, y, z;

  // Initiate communications with compass
  Wire.beginTransmission(Addr);
  Wire.write(byte(0x03));       // Send request to X MSB register
  Wire.endTransmission();

  Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
  if(Wire.available()
