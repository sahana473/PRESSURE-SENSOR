/*Interfacing MPX4250 Pressure sensor to Arduino Uno
 * 
 * Hardware Component:
 * Arduino Uno
 * MPX4250 Pressure sensor 
 * 
 * Hardware Connection:
 * LCD connection
 *  LCD is configured to work with 4 bit mode
 *  LCD D4 pin to digital pin 5 of Arduino Uno
 *  LCD D5 pin to digital pin 4 of Arduino Uno
 *  LCD D6 pin to digital pin 3 of Arduino Uno
 *  LCD D7 pin to digital pin 2 of Arduino Uno
 *  LCD RS pin to digital pin 13 of Arduino Uno
 *  LCD EN pin to digital pin 12 of Arduino Uno
 *  LCD R/W pin to ground
 *  
 * Mpx4250 Pin connection 
 *  Vout is connected to A0 of Arduino
 *  Pin 3 is connected to Power
 *  Pin 2 is connected to Ground
 *   
 *   Author : Sahana B G
 *   Date   : 01 May 2021
 */

// Include the header file
#include <LiquidCrystal.h>
 
const int pressureSensorPin = A0;    // select the input pin for the potentiometer
static float pressureSensorValue ;  // variable to store the value coming from the sensor

// Initialize the library by associating any needed LCD interface pin
// with the Arduino Uno pin number it is connected to
const int RS = 13, EN = 12, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() 
{
  // Set up the LCD's number of columns and rows
  lcd.begin(16,2);

  // Set cursor column 0, and row 0
  lcd.setCursor(0,0);

  // Print message on LCD
  lcd.print("Pressure :");
}

void loop() 
{
  // Read the value from the sensor
  pressureSensorValue = ((analogRead(pressureSensorPin)*0.0048875)); // successive approximation precision of analogRead is 5 / 1023 = 0.0048875.
  pressureSensorValue = pressureSensorValue * 51.06209150326797;

  // Set cursor column 0,row 1
  lcd.setCursor(0,1);

  // Print value on LCD
  lcd.print(pressureSensorValue);
}
