/*
  Reffer arduino pin mapping on fbv 2560 pdf
  For more details visit https://www.youtube.com/watch?v=k69CghLTXOA&t=123s
  */

int L_Speed = 46;
int L_Forward = 23;
int L_Back = 22;
int R_Speed = 45;
int R_Forward = 24;
int R_Back = 25;
void setup(){
  pinMode(L_Speed, OUTPUT);
  pinMode(L_Forward,OUTPUT);
  pinMode(L_Back,OUTPUT);
  pinMode(R_Speed, OUTPUT);
  pinMode(R_Forward,OUTPUT);
  pinMode(R_Back,OUTPUT);
}
void loop(){
  Forward(255);
  delay(2000);
  Stop();
  delay(2000);
  Reverse(150);
  delay(2000);
  Stop();
  delay(2000);
}
void Forward(int a)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,a);
  left_Forward();
  right_Forward();
}
void Reverse(int a)
{
  analogWrite(L_Speed,a);
  analogWrite(R_Speed,a);
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

