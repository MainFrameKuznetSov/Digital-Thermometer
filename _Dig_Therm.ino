/*
    Name:- MainFrame KuznetSov
    Prototype 3
    Digital Thermometer for Basic Electrical Engineering Project
*/
#include <LiquidCrystal.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define DPIN 7
#define DTYPE DHT22
#define pause 1000
DHT dht (DPIN,DTYPE);
float tempC,tempF;
void printCode(char str1[], char str2[])
{
  lcd.setCursor(0,0);
  lcd.print(str1);
  lcd.setCursor(0,1);
  lcd.print(str2);
}
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  printCode("Halfscore","Metacrats");
  delay(pause);
  lcd.clear();
  printCode("Basic Electrical","Engineering");
  delay(pause);
  lcd.clear();
  dht.begin();
}
void loop() 
{
  Serial.println();
  delay(1000);
  lcd.clear();
  tempC=dht.readTemperature();
  tempF=(tempC*1.8)+32;
  Serial.print("Temperature");
  Serial.print(tempC);
  Serial.print("C");
  Serial.println();
  Serial.print("Temperature");
  Serial.print(tempF);
  Serial.print("F");
  lcd.setCursor(0,0);
  lcd.print("C:- ");
  lcd.print(tempC);
  lcd.setCursor(9,0);
  lcd.write(0xdf);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("F:- ");
  lcd.print(tempF);
  lcd.setCursor(9,1);
  lcd.write(0xdf);
  lcd.print("F");
}