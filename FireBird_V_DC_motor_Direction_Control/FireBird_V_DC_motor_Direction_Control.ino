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
  digitalWrite(L_Speed,HIGH);
  digitalWrite(R_Speed,HIGH);
}
void loop(){
  digitalWrite(L_Forward,HIGH);
  digitalWrite(L_Back,LOW);
  digitalWrite(R_Forward,HIGH);
  digitalWrite(R_Back,LOW);
  delay(2000);
  digitalWrite(L_Forward,HIGH);
  digitalWrite(L_Back,HIGH);
  digitalWrite(R_Forward,HIGH);
  digitalWrite(R_Back,HIGH);
  delay(2000);
  digitalWrite(L_Forward,LOW);
  digitalWrite(L_Back,HIGH);
  digitalWrite(R_Forward,LOW);
  digitalWrite(R_Back,HIGH);
  delay(2000);
  digitalWrite(L_Forward,HIGH);
  digitalWrite(L_Back,HIGH);
  digitalWrite(R_Forward,HIGH);
  digitalWrite(R_Back,HIGH);
  delay(2000);
}

