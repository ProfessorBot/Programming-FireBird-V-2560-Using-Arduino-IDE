/*
  Reffer arduino pin mapping on fbv 2560 pdf
  For more details visit https://www.youtube.com/watch?v=uA5H5LBLHbQ&t=195s
 */
 
// Pin 34 has an BUZZER connected on FireBird v 2560 robot.
// give it a name:
int Buzzer = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(Buzzer, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(Buzzer, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(Buzzer, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
