#include<SoftwareSerial.h>
int sensorPin=A2;//tress
int sensorValue = 0;
int L1 = 7;
int L2 = 8;
int sensorPin2=A0;//fire
int sensorValue2 = 0;
int buzz = A1;
int led = 9;
int motor = 10; 
int sw1,sw2;
int a=0;
int i=0;
char inChar=0;
int j=13;
int k=11;

void setup() {
 pinMode(L1, INPUT_PULLUP);
pinMode(L2, INPUT_PULLUP);
 pinMode(motor, OUTPUT);
pinMode(buzz, OUTPUT);
pinMode(led, OUTPUT);
 Serial.begin(9600);

  digitalWrite(buzz,LOW);  
 digitalWrite(motor,LOW);
 digitalWrite(led,HIGH);
 delay (2000);
}
void loop() {
   
 Serial.begin(9600);
 sensorValue = analogRead(sensorPin); 
 sensorValue2 = analogRead(sensorPin2);
 sw1=digitalRead(L1);
 sw2=digitalRead(L2);
  
   if(sw1==LOW)
  {
   
  Serial.print("Gun sound, Location - 30.756,77.299");
     
    three(); 
  }
  
   if(sw2==LOW)
  {
   
  Serial.print("Deforestation sound, Location - 22.756,73.200");
     
    three(); 
  }
 
 if(sensorValue2 > 150)
 {
   Serial.print("Fire detected, Location - 34.987,73.734");
   digitalWrite(motor,HIGH);
  two();
   delay(500);
 }
 if(sensorValue < 200)
 {
   Serial.print("Animal detected, Location - 20.489,71.450");
 startss:  
 digitalWrite(led,LOW); 
 digitalWrite(buzz,HIGH);
 delay (500);
 digitalWrite(led,HIGH); 
 digitalWrite(buzz,LOW);
  delay (500);
  goto startss;
 }}

void one() {         //the function produces the first siren sound with ON/OFF led transition.
   starta:
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=11;i<=13;i++)
    digitalWrite(i,HIGH);
  }
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=11;i<=13;i++)
    {
      digitalWrite(i,LOW);
      digitalWrite(i+5,HIGH);
      }
  }
   goto starta;
  }
  

void two() {                   //this function produces the second siren sound with progressive led transition.
  start1:
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
     loopF(11,13,20);
     loopR(11,13,20);
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  } goto start1;
  }
void twoA() {                //this function produces third siren sound with led transition. 
   start3:
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
     loopF(11,k,20);
     loopR(13,j,20);
     k--;
     if(k==11)
     k=12;
     j++;
     if(j==13)
     j=3;
 
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  } goto start3;
  }
  void three() {   start4:           //This function produces the 3rd siren(AMBULANCE) sound with led transition.
  tone(buzz,440,200);
    delay(300);
  for(int i=11;i<=13;i++)
  digitalWrite(i,HIGH);
  noTone(buzz);
  tone(buzz,494,500);
  delay(300);
  for(int i=11;i<=13;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+6,HIGH);
  }
  noTone(buzz);
  tone(buzz,523,300);
   delay(200);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(8,HIGH);
  delay(50);
  noTone(buzz);
  goto start4;
}
  void threeA() {  start5:           //This function produces differnt transition on 3rd siren.
  tone(buzz,440,200);
    delay(100);
    loopF(5,10,20);
    loopR(10,5,20);
  noTone(buzz);
  for(int i=11;i<=13;i++){
  digitalWrite(i,HIGH);
  digitalWrite(i+8,HIGH);}
  tone(buzz,494,500);
  delay(300);
  noTone(buzz);
  for(int i=11;i<=13;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+8,LOW);
  }
  tone(buzz,523,300);
   delay(300);
  noTone(buzz);
  goto start5;
}
void four() {    start6:                          
for(int i=11;i<=13;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 440; hz < 1000; hz++){
    tone(buzz, hz, 50);
    delay(5);
  }
for(int i=11;i<=13;i+=2)
digitalWrite(i,LOW);
 for(int i=11;i<=13;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 1000; hz > 440; hz--){
    tone(buzz, hz, 50);
    delay(5);
    }  goto start6;
  }
    void loopF(int spin,int epin,int dela){   
    for(int i=spin;i<=epin;i++){
    digitalWrite(i,HIGH);
    delay(dela);
    low();
    if(spin==epin){
    spin=11;
    epin=13;}
    }}
  void loopR(int epin,int spin,int dela){      
    for(int i=epin;i>=spin;i--){
    digitalWrite(i,HIGH);
    delay(dela);
    low();
    if(spin==epin){
    spin=11;
    epin=13;}
    }}
  void low(){                                  
   for(int i=11;i<=13;i++)
  digitalWrite(i,LOW);
    }
