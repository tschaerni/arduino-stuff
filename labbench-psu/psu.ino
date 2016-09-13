//code by Sam Zeloof under creative commons/open source blah blah use it for whatever you want

#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 4, 3, 1, 2, 0);
int voltageSense = A6;
int currentSense = A7;
int logicVoltage = 0;
int logicCurrent = 0;
int voltage = 0;
int current = 0;
char voltageUnit = 'V';
char currentUnit = 'A';
int voltageFactor = 26.69; //set this for yourself 
int currentFactor = 81.70; //set this for yourself 

void setup() {
  lcd.begin(16, 2);
  lcd.print(" Variable CV/CC ");
  lcd.setCursor(0, 1);
  lcd.print("  Power Supply  ");
  delay(2500);
  lcd.clear();
}
void loop() {
  float logicVoltage = analogRead(voltageSense);
  float logicCurrent = analogRead(currentSense);
  float voltage = logicVoltage / voltageFactor;
  float current = logicCurrent / currentFactor;
  lcd.setCursor(0, 0);
  lcd.print("Volts");
  lcd.setCursor(6, 0);
  lcd.print(voltage);
  lcd.setCursor(11, 0);
  lcd.print(voltageUnit);
  lcd.setCursor(0, 1);
  lcd.print("Amps");
  lcd.setCursor(6, 1);
  lcd.print(current);
  lcd.setCursor(11,1);
  lcd.print(currentUnit);
  delay(100);
  lcd.clear();
}
