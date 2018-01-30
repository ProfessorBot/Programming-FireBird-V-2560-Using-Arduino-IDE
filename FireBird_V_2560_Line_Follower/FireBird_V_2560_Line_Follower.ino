/*
  For more details visit https://www.youtube.com/watch?v=Llg3DkrbPTQ
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
int LS_Left = 0;
int LS_Right = 0;
int LS_Center = 0;

int IRProxyEN = 6;
int IR1 = A4;
int IR2 = A5;
int IR3 = A6;
int IR4 = A7;
int IR5 = A8;

int L_Speed = 46;
int L_Forward = 23;
int L_Back = 22;
int R_Speed = 45;
int R_Forward = 24;
int R_Back = 25;

LiquidCrystal lcd(RS, EN, DS4, DS5, DS6, DS7);

void setup() {
  pinMode(RW,OUTPUT);
  pinMode(LineSensorEN,OUTPUT);
  pinMode(IRProxyEN,OUTPUT);
  pinMode(L_Speed, OUTPUT);
  pinMode(L_Forward,OUTPUT);
  pinMode(L_Back,OUTPUT);
  pinMode(R_Speed, OUTPUT);
  pinMode(R_Forward,OUTPUT);
  pinMode(R_Back,OUTPUT);
  
  digitalWrite(RW,LOW);
  digitalWrite(LineSensorEN,LOW);
  digitalWrite(IRProxyEN,LOW);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  LS_Left = analogRead(LS1);
  LS_Center = analogRead(LS2);
  LS_Right = analogRead(LS3);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.print("LS1  ");
  lcd.print("LS2  ");
  lcd.print("LS3  ");
  
  lcd.setCursor(0,1);
  
  lcd.print(LS_Left);
  lcd.print("  ");
  lcd.print(LS_Center);
  lcd.print("  ");
  lcd.print(LS_Right);
  
  if ((LS_Center<350)||(LS_Left<350)||(LS_Right<350))
  {
    if (LS_Left<350)
    {
      Forward(50,150);
    }
    else if (LS_Right<350)
    {
      Forward(150,50);
    }
    else if ((LS_Left>350)&&(LS_Right>350))
    {
      Forward(150,150);
    }
  }
  else {
    Stop();
  }
  
  delay(50);
}


void Forward(int a,int b)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,b);
  left_Forward();
  right_Forward();
}
void Reverse(int a,int b)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,b);
  left_Reverse();
  right_Reverse();
}
void Stop()
{
  left_Stop();
  right_Stop();
}
void Left_Turn(int a)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,a);
  left_Reverse();
  right_Forward();
}
void Right_Turn(int a)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,a);
  right_Reverse();
  left_Forward();
}

void left_Forward()
{
  digitalWrite(L_Forward,HIGH);
  digitalWrite(L_Back,LOW);
}
void left_Reverse()
{
  digitalWrite(L_Forward,LOW);
  digitalWrite(L_Back,HIGH);
}
void left_Stop()
{
  digitalWrite(L_Forward,HIGH);
  digitalWrite(L_Back,HIGH);
}
void right_Forward()
{
  digitalWrite(R_Forward,HIGH);
  digitalWrite(R_Back,LOW);
}
void right_Reverse()
{
  digitalWrite(R_Forward,LOW);
  digitalWrite(R_Back,HIGH);
}
void right_Stop()
{
  digitalWrite(R_Forward,HIGH);
  digitalWrite(R_Back,HIGH);
}

