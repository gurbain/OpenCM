/*
 Display IR Sensor Data on LCD
 
 
 Created by ROBOTIS,.CO LTD. 14 Jan 2014
 */

#include <LiquidCrystal.h>
#include <OLLO.h>
OLLO myOLLO;

LiquidCrystal lcd(16, 17, 18, 19, 20, 21);

void setup() {
  lcd.begin(16, 2);
  lcd.print("OpenCM9.04");
  myOLLO.begin(1, IR_SENSOR);
  myOLLO.begin(2, TEMPERATURE_SENSOR);
  myOLLO.begin(3, COLOR_SENSOR);
}
void loop() {
  lcd.setCursor(0, 1);
  lcd.print(myOLLO.read(1, IR_SENSOR),DEC);
  lcd.print("  ");
  lcd.print(myOLLO.read(2, TEMPERATURE_SENSOR),DEC);
  lcd.print("  ");
  lcd.print(myOLLO.read(3, COLOR_SENSOR),DEC);
  lcd.print("  ");
  lcd.print(myOLLO.read(4, PIR_SENSOR),DEC);
  lcd.print("  ");
  delay(300);
}










