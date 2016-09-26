/*
 Voltage reading - a small test and proof of concept

  The circuit:
 * LCD RS pin to digital pin 10
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Based on the following work:

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 26 Sep 2016
 by Robin Cerny (rcerny, robin@cerny.li)

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // print the Names for the values:
  lcd.setCursor(0, 0);
  lcd.print("Akku:");
  lcd.setCursor(10, 0);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("VCC:");
  lcd.setCursor(10, 1);
  lcd.print("V");
}

void loop() {
  // read voltage of the 3.7V (4.2V max) Lithium cell:
  int cellvalue = analogRead(A0);
  float voltagecell = cellvalue * (5.0 / 1023.0);
  // set the lcd cursor at the right spot:
  lcd.setCursor(6, 0);
  // print voltage of the cell:
  lcd.print(voltagecell);

  // read voltage of the VCC (in my case a little boostconverter):
  int boostvalue = analogRead(A1);
  float voltageboost = 2 * boostvalue * (5.0 / 1023.0);
  // set the lcd cursor at the right spot:
  lcd.setCursor(6, 1);
  // print voltage of VCC:
  lcd.print(voltageboost);
  // a little delay
  delay(250);
}
