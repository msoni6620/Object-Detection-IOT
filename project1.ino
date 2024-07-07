//oled sck-d1
//scl-d2
//ultrasonic
//trig-d7
//echo-d6

#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET  -1
#define SCREEN_ADDRESS 0X3C
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,OLED_RESET);
const int pingPin=D7;
const int echoPin=D6;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS)){
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,inches,cm;
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);
   digitalWrite(pingPin,LOW);
   pinMode(echoPin,INPUT);
   duration=pulseIn(echoPin,HIGH);
   inches=microsecondsToInches(duration);
   cm=microsecondsToCentimeters(duration);
   Serial.print(inches);
    Serial.print("in, ");
     Serial.print(cm);
      Serial.print("cm");
       Serial.println();
   delay(100);
   display.clearDisplay();
   display.setTextSize(1);
   display.setCursor(0,20);
   display.print("Inches");
   display.print(inches);
   display.print("in");
   display.print("CM:");
   display.print(cm);
   display.display();
   delay(100);
   display.clearDisplay();
   
  

}
long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
  }

  long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
  }
