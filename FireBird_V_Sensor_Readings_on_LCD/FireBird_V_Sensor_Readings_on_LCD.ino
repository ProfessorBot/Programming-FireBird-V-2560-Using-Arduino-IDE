/*
  For more details visit https://www.youtube.com/watch?v=1MGN-idZDAo&t=18s
  */
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
int RS = 37;
int RW = 36;
int EN = 35;
int DS4 = 33;
int DS5 = 32;
int DS6 = 31;
int DS7 = 30;
int LineSensorEN = 39;
int LS1 = A3;
int LS2 = A2;
int LS3 = A1;
int IRProxyEN = 6;
int IR1 = A4;
int IR2 = A5;
int IR3 = A6;
int IR4 = A7;
int IR5 = A8;

LiquidCrystal lcd(RS, EN, DS4, DS5, DS6, DS7);

void setup() {
  pinMode(RW,OUTPUT);
  pinMode(LineSensorEN,OUTPUT);
  pinMode(IRProxyEN,OUTPUT);
  
  digitalWrite(RW,LOW);
  digitalWrite(LineSensorEN,LOW);
  digitalWrite(IRProxyEN,LOW);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IR1 = ");
  lcd.print(analogRead(IR1));
  delay(250);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("IR2 = ");
  lcd.print(analogRead(IR2));
  delay(250);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IR3 = ");
  lcd.print(analogRead(IR3));
  delay(250);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("IR4 = ");
  lcd.print(analogRead(IR4));
  delay(250);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("IR5 = ");
  lcd.print(analogRead(IR5));
  delay(250);
}

