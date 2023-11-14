#include "DHT.h"
#include <LiquidCrystal_I2C.h>


#define DHTPIN 6 
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int sensorValue;
int cosensorValue;
int AQI ;
int sa;
int sd;
int coa;
int cod;
int ppm;
LiquidCrystal_I2C lcd(0x27,16,2);


 void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
 lcd.setCursor(0,0);*/
  Serial.begin(9600); // sets the serial port to 9600
  dht.begin();
  pinMode(1,OUTPUT);
  pinMode(3,INPUT);
  pinMode(12,OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  String output = "temperature "+ String(t) +"°C or "+String(f) +"°F and humidity"+ String(h) + "%";
  Serial.println(output);
 lcd.setCursor(0,0);
 lcd.print("T="+String(t)+"C "+"h:"+String(h)+"%");
  delay(2000);
  coa = analogRead(1);//read analog input pin 0 co
  cod = digitalRead(3);
  if(coa<200)
  {
    digitalWrite(12,LOW);
    Serial.println(coa);
    int percentage=map(coa,100,200,0,100);
    Serial.println(percentage);
    Serial.println("co level is normal");
    delay(2000);
 }
  else if (cosensorValue>200)
{}
    digitalWrite(12,HIGH);
    Serial.println(cosensorValue,DEC);
    Serial.println("co level is HARMFULL");
    delay(2000);

  }

  sa = analogRead(0); // read analog input pin 0
  sd = digitalRead(2);
 ppm = (sensorValue)/3;
  if (sensorValue < 500)
  {
    digitalWrite(13, HIGH);
  Serial.println(sa); // prints the value read
 Serial.println( "AQI: "+String(ppm));
 int percentage=map(sa,100,450,0,100);
Serial.println(percentage);
 Serial.println("the air quality is normal");
 lcd.setCursor(0,1);
  lcd.print("good air quality");
  delay(2000); // wait 100ms for next reading
 } }
 
  else if(sensorValue>500)
  {
    digitalWrite(13, HIGH);
    Serial.println("the air quality is harmfull");
    lcd.setCursor(0,1);
    lcd.print("bad air quality");
    delay(2000);
  }
}
int sensorValue;
int cosensorValue;
int AQI ;
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// void setup()
// { 
//   //  lcd.begin(16, 2)
// lcd.init();
//   lcd.clear();
//   lcd.backlight();
//  lcd.setCursor(0,0);
// Serial.begin(9600);
// pinMode(2, INPUT);                            // sets the serial port to 9600
//  }
// void loop(){sensorValue = analogRead(0);       // read analog input pin 0
// cosensorValue = analogRead(1);

// Serial.print("co=");
// Serial.print(cosensorValue,DEC);
// Serial.print(" ppm ");
// Serial.print("AirQua=");
// Serial.print(sensorValue, DEC);               // prints the value read
// Serial.println(" PPM");
//  int percentage=map(sensorValue,100,1000,10,500);
// Serial.println(percentage);
// lcd.setCursor(0,0);


// lcd.print("ArQ=");
// lcd.print(percentage,DEC);
// lcd.print(" PPM");
// lcd.println("       "); 
// lcd.print("  ");
// delay(1000); 
// if(percentage>100){  //&& percentageo>10){
// Serial.println("aqi is bad ") ;
// lcd.setCursor(0,1);
// lcd.print("bad air ");
// }

// else
//  Serial.println("aqi is good");
//  lcd.setCursor(0,1);
//  lcd.print("good air ");
//                                 // wait 100ms for next reading
// }
