#include<SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define trigPin1 A1
#define echoPin1 A0
#define trigPin2 A3
#define echoPin2 A2
#define trigPin3 A5
#define echoPin3 A4

int ALARM = 2;
long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;
int tempSensor = A6;

void setup()
{ 
  
lcd.begin(20,4);
Serial.begin (9600);

  //for relay trigger
pinMode(4,OUTPUT);
pinMode(11,INPUT_PULLUP);
pinMode(12,OUTPUT);
pinMode(10,INPUT_PULLUP);
pinMode(8,OUTPUT);
pinMode(9,INPUT_PULLUP);
pinMode(7,OUTPUT);
pinMode(6,INPUT_PULLUP);





lcd.clear(); 
  // for ultrasonic sensors
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(ALARM, OUTPUT);
  
digitalWrite(ALARM, LOW);

  //for Pir sensor
pinMode(3,INPUT);  // pir signal pin connected on digital pin or arduino


//lcd.setCursor(0,0);
lcd.print("Interfacing ");
Serial.print("Interfacing ");
lcd.print("of Multiple ");
Serial.print("of Multiple ");
delay(1000);
//////lcd.clear();  
//lcd.setCursor(0,0);
lcd.print("3 HC - SR04 ");
Serial.print("3 HC - SR04 ");
//lcd.setCursor(0,1);
lcd.print("Ultrasonic  ");
Serial.print("Ultrasonic  ");
delay(1000);
//////lcd.clear();
//lcd.setCursor(0,0);
lcd.print("SensorS With ");
Serial.print("SensorS With ");
//lcd.setCursor(0,1);
lcd.print("Arduino ");
Serial.print("Arduino ");
//delay(1000);
//////lcd.clear();
}

void loop() 
{
 
  

/////////////////////////////////////////////////////// 
 int tempSensor = digitalRead(A6);
 int Temperature = tempSensor / 2.048;
  Serial.print("Temperature:");
  Serial.println(Temperature);
  delay(0);

  // pir part
if(digitalRead(3) == HIGH){
tone(2, 400);
delay(300);
noTone(2);
delay(300);
tone(2, 400);
delay(300);
}
else {
noTone(2);
 }
  // ultrasonic part
SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;
SonarSensor(trigPin3, echoPin3);
THIRDSensor = distance;
/////////////////////////////////////////////////////////////
digitalWrite(ALARM, LOW);
//////////////////////////////////////////////////////////////////////////////////////
Serial.print("S1:")
;Serial.println(FIRSTSensor);
delayMicroseconds(10);
Serial.print("S2:");
Serial.println(SECONDSensor);
delayMicroseconds(10);
Serial.print("S3:");
Serial.println(THIRDSensor);
delayMicroseconds(10);
///////////////////////////////////////////////////////////////////////////////////////
//lcd.setCursor(0,0);
lcd.print("S1:");
//lcd.setCursor(4,0);
lcd.print(FIRSTSensor);
///lcd.setCursor(9,0);
lcd.print("S2:");
//lcd.setCursor(12,0);
lcd.print(SECONDSensor);
//lcd.setCursor(0,1);
lcd.print("S3:");
//lcd.setCursor(4,1);
lcd.print(THIRDSensor);
delay(1000);
//////lcd.clear();
///////////////////////////////////////////////////////
if((FIRSTSensor >= 10) & (FIRSTSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
if((SECONDSensor >= 10) & (SECONDSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////
if((THIRDSensor >= 10) & (THIRDSensor <= 50)) 
{digitalWrite(ALARM, HIGH);delay(500);}
///////////////////////////////////////////////////////



if(digitalRead(11) == LOW)         // If button is pressing
    digitalWrite(4, HIGH); // turn on LED
  else                           // otherwise, button is not pressing
    digitalWrite(4, LOW);  // turn off LED
  
  if(digitalRead(10) == LOW)         // If button is pressing
    digitalWrite(12, HIGH); // turn on LED
  else                           // otherwise, button is not pressing
    digitalWrite(12, LOW);
   
  if(digitalRead(9) == LOW)         // If button is pressing
    digitalWrite(8, HIGH); // turn on LED
  else                           // otherwise, button is not pressing
    digitalWrite(8, LOW);

  if(digitalRead(6) == LOW)         // If button is pressing
    digitalWrite(7, HIGH); // turn on LED
  else                           // otherwise, button is not pressing
    digitalWrite(7, LOW); 

    
}
/////////////////////////////////////////////////////////////////////////////////
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
