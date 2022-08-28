//DANU AZHAR HIDAYAT
//201811046
//RANCANG BANGUN ALAT PEMILAH SAMPAH OTOMATIS DENGAN KONSEP BINARY TREE

#include <Servo.h>
#include "U8glib.h"
U8GLIB_ST7920_128X64 u8g(16, 15, 14, U8G_PIN_NONE);
Servo servologam;
Servo servoOrganic;
Servo servoDoor;
const int trigPin1 = A0;
const int echoPin1 = A1;
const int trigPin2 = A2;
const int echoPin2 = A3;
const int trigPin3 = A4;
const int echoPin3 = A5;
const int trigPin4 = A6;
const int echoPin4 = A7;
const int trigPin5 = A8;
const int echoPin5 = A9;
const int trigPin6 = A10;
const int echoPin6 = A11;
long duration1, cm1, duration2, cm2, duration3, cm3, duration4, cm4, duration5, cm5, duration6, cm6; 

const int limitswitch1 = 4;
const int limitswicth2 = 5;

const int LEDlogam      = 22;
const int LEDorganik    = 24;
const int LEDanorganik  = 26;
const int alarm         = 6;


void draw1(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 40, 22, "Alat");
  u8g.drawStr( 22, 42, "Pemilah");
  u8g.drawStr (22, 62,"Sampah");
}
void draw2(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 30, 42, "Logam");
}
void draw3(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 22, 42, "Organik");
}
void draw4(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 12, 42, "Anorganik");
}
void draw5(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 30, 42, "Logam");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw6(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 22, 42, "Organik");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw7(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Sampah");
  u8g.drawStr( 12, 42, "Anorganik");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw8(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 30, 22, "Logam");
  u8g.drawStr( 22, 42, "Organik");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw9(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 30, 22, "Logam");
  u8g.drawStr( 12, 42, " Anorganik");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw10(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Organik");
  u8g.drawStr( 12, 42, "Anorganik");
  u8g.drawStr( 29, 64, "Penuh");
}
void draw11(void){
  u8g.setFont(u8g_font_ncenB14);
  u8g.drawStr( 22, 22, "Semua");
  u8g.drawStr( 29, 42, "Penuh");
}
void setup(void) {
  Serial.begin(115200);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  } 
  pinMode(limitswitch1,INPUT);
  pinMode(limitswicth2,INPUT);

  servologam.attach(9);
  servoOrganic.attach(10); 
  servoDoor.attach(8);
 
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
  pinMode(echoPin6, INPUT);

  pinMode(LEDlogam, OUTPUT);
  pinMode(LEDorganik, OUTPUT);
  pinMode(LEDanorganik, OUTPUT);
  pinMode(alarm, OUTPUT);

  u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() );
}


void loop(void) {  
//ultrasonic pemilah logam
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH); 
  cm1 = (duration1/2) / 29.1;
  
  Serial.print("Ultrasonic logam: ");
  Serial.println(cm1);

  delayMicroseconds(2);
  
//Ultrasonic pemilah Organik
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH); 
  cm2 = (duration2/2) / 29.1;
  
  Serial.print("Ultrasonic organic: ");
  Serial.println(cm2);

  delayMicroseconds(2);

  //Ultrasonic Pintu
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin3, LOW);
  
  duration3 = pulseIn(echoPin3, HIGH); 
  cm3 = (duration3/2) / 29.1;
  
  Serial.print("Ultrasonic Pintu: ");
  Serial.println(cm3);

  delayMicroseconds(2);

//Ultrasonic Alert penuh Logam
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin4, LOW);
  
  duration4 = pulseIn(echoPin4, HIGH); 
  cm4 = (duration4/2) / 29.1;
  
  Serial.print("Ultrasonic Alert Logam: ");
  Serial.println(cm4);

  delayMicroseconds(2);
  
//Ultrasonic Alert penuh Organik
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin5, LOW);
  
  duration5 = pulseIn(echoPin5, HIGH); 
  cm5 = (duration5/2) / 29.1;
  
  Serial.print("Ultrasonic Alert organic: ");
  Serial.println(cm5);

  delayMicroseconds(2);

//Ultrasonic Alert Penuh Anorganik
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(2); 
  digitalWrite(trigPin6, LOW);
  
  duration6 = pulseIn(echoPin6, HIGH); 
  cm6 = (duration6/2) / 29.1;
  
  Serial.print("Ultrasonic Alert anorganic: ");
  Serial.println(cm6);

  
  delay(1000);

//Kerja Servo
//Servo Door
  if(cm3>=20){
    servoDoor.write(86); 
    delay(100);  
  }
  else{
    servoDoor.write(180);     
    delay(100);  
  }

//Servo pemilah1
  int val = digitalRead(limitswitch1);
  if(val == 0 && (cm1>=30||cm1<=13)){  //logam
    servologam.write(180);
    u8g.firstPage();  
    do {
      draw2(); 
    } while( u8g.nextPage() ); 
    delay(100);
  }
  else if (val == 0 && (cm1<=30||cm1>=13)){ //stand by
    servologam.write(90);
    u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() ); 
    delay(100); 
  }
  else if (val == 1 && (cm1>=30||cm1<=13)){ //nonlogam
    servologam.write(20);
    u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() ); 
    delay(100);
  }
  else if (val == 1 && (cm1<=30||cm1>=13)){ //standby
    servologam.write(90);
     u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() );
   delay(100);
  }
  delay(1200);
  
//Servo pemilah2
  int valcap = digitalRead(limitswicth2);
  if((valcap == 0) && (cm2>=30||cm2<=20)){  //organik
    servoOrganic.write(0);
    u8g.firstPage();  
    do {
      draw3(); 
    } while( u8g.nextPage() ); 
    delay(100);
  }
  else if(valcap == 0 && (cm2<=30||cm2>=20)){ //standby
    servoOrganic.write(90);
     u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() );
   delay(100);    
  }
  else if(valcap == 1 && (cm2>=30||cm2<=20)){ //anorganik
    servoOrganic.write(180);
     u8g.firstPage();  
    do {
      draw4(); 
    } while( u8g.nextPage() );
   delay(100);       
  }
  else if (valcap == 1 && (cm2<=30||cm2>=20)) { //standby
    servoOrganic.write(90);
     u8g.firstPage();  
    do {
      draw1(); 
    } while( u8g.nextPage() );
   delay(100);       
  } 
delay(1000);

//ALERT PENUH

//Logam Penuh
  if (cm4>=6){
    digitalWrite(LEDlogam, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
  else{
    digitalWrite(alarm, HIGH);
    delay(1000);
    digitalWrite(LEDlogam, HIGH);
     u8g.firstPage();  
    do {
      draw5(); 
    } while( u8g.nextPage() );
    delay(100);  
  }
delay(100);
//Organik Penuh
 if (cm5<=6){
    digitalWrite(alarm, HIGH);
    delay(1000);
    digitalWrite(LEDorganik, HIGH);
     u8g.firstPage();  
    do {
      draw6(); 
    } while( u8g.nextPage() );
    delay(100);  
  } 
  else{
    digitalWrite(LEDorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
delay(100);
//anorganik Penuh
 if (cm6<=6){
   digitalWrite(LEDanorganik, HIGH);
   digitalWrite(alarm, HIGH);
  
    u8g.firstPage();  
    do {
      draw7(); 
    } while( u8g.nextPage() );
   delay(100); 
  }
  else{
    digitalWrite(LEDanorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
delay(100);
//logam penuh dan organik penuh
 if ((cm4<=6) && (cm5<=6)){
   digitalWrite(LEDlogam, HIGH);
   digitalWrite(LEDorganik, HIGH);
   digitalWrite(alarm, HIGH);
  
    u8g.firstPage();  
    do {
      draw8(); 
    } while( u8g.nextPage() );
    delay(100); 
  }
  else{
    digitalWrite(LEDlogam, LOW);
    digitalWrite(LEDorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
delay(100);
//logam penuh dan Anorganik penuh
 if ((cm4<=6) && (cm6<=6)){
   digitalWrite(LEDlogam, HIGH);
   digitalWrite(LEDanorganik, HIGH);
   digitalWrite(alarm, HIGH);
   
    u8g.firstPage();  
    do {
      draw9(); 
    } while( u8g.nextPage() );
   delay(100);  
  }
  else{
    digitalWrite(LEDlogam, LOW);
    digitalWrite(LEDanorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
delay(100);
//Organik penuh dan Anorganik penuh
 if ((cm5<=6) && (cm6<=6)){
   digitalWrite(LEDorganik, HIGH);
   digitalWrite(LEDanorganik, HIGH);
   digitalWrite(alarm, HIGH);
  
    u8g.firstPage();  
    do {
      draw10(); 
    } while( u8g.nextPage() );
    delay(100);  
  }
  else{
    digitalWrite(LEDorganik, LOW);
    digitalWrite(LEDanorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  }
delay(100);
//Semua Penuh
  if((cm4<=6 && cm5<=6) && (cm6<=6)){
    digitalWrite(LEDlogam, HIGH);
    digitalWrite(LEDorganik, HIGH);
    digitalWrite(LEDanorganik, HIGH);
    digitalWrite(alarm, HIGH);
    
     u8g.firstPage();  
    do {
      draw11(); 
    } while( u8g.nextPage() );
    delay(100);
  }
  else{
    digitalWrite(LEDlogam, LOW);
    digitalWrite(LEDorganik, LOW);
    digitalWrite(LEDanorganik, LOW);
    digitalWrite(alarm, LOW);
    delay(100);
  } 
delay(100);
} 
