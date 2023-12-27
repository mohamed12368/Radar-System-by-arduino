//Mhmd_Lotfy
#include <Servo.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(6,7,8,9,10,11);
const int trigPin = 4;
const int echoPin = 5;

long duration;
int distance;
Servo myServo; 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  lcd.begin(16,2);
  myServo.attach(2);
 lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Dark storm ");
lcd.setCursor(0,1);
lcd.print(" Radar system ");
delay(9000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Initializing....");
lcd.setCursor(0,1);
lcd.print("Getting Data...."); 
delay(5000);
}
void loop() {
  
  
  // rotates the servo motor from 20 to 160 degrees
  for(int i=20;i<=160;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
   lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle=");
lcd.setCursor(6,0);
lcd.print(i);
lcd.setCursor(10,0);
lcd.print("Degree");
lcd.setCursor(0,1);
lcd.print("Distance=");
lcd.setCursor(10,1);
lcd.print(distance);
lcd.setCursor(14,1);
lcd.print("cm");

  }
  
  // Repeats the previous lines from 160 to 20 degrees
  for(int i=160;i>20;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle=");
lcd.setCursor(6,0);
lcd.print(i);
lcd.setCursor(10,0);
lcd.print("Degree");
lcd.setCursor(0,1);
lcd.print("Distance=");
lcd.setCursor(10,1);
lcd.print(distance);
lcd.setCursor(14,1);
lcd.print("cm");


  }
}
//****************** calculating the distance measured by the Ultrasonic sensor ****************
int calculateDistance(){   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
