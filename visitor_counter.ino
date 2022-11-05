/*
  Hey Guys! Welcome to RENU ROBOTICS
  This is a Simple Project
  Bi - Directional Visitor Counter
  Hope you Like It!! 
*/

#include<LiquidCrystal.h>//Declaring the Library 

LiquidCrystal lcd(12,11,5,4,3,2);// Setting up lcd 

#define in 8  // Defining In Sensor
#define out 9 // Defining Out Sensor
#define bulb 10 //Defining Bulb(Relay)

int count = 0; // Declaring count Value

void setup()
{
  lcd.begin(16,2); // Beggining the lcd
  lcd.print("Visitor Counter"); // Printing "Visitor Counter" to the LCD
  delay(2000); // Delay of 2 seconds
  pinMode(in,INPUT); // Setting up In Sensor as INPUT 
  pinMode(out,INPUT); // Setting up Out Sensor as INPUT
  pinMode(bulb,OUTPUT); // Setting up Bulb(Relay) pin as OUTPUT  
  lcd.clear(); // Clearing/Erasing the String in LCD
  lcd.print("Person In Room:"); // Printing "Person in Room" to the LCD
  lcd.setCursor(0,1); // Setting Cursor to Print the Counting
  lcd.print(count); // Printing the Couting
}

void loop()
{  
  int in_value = digitalRead(in); // Setting Variables & Reading Values from In Sensor
  int out_value = digitalRead(out); // Setting Variables & Reading Values from Out Sensor
  
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }                                                        // Conditions
  
  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }                                                        // Conditions
 
  
  if(count==0)
  {
    lcd.clear();
    digitalWrite(bulb,HIGH);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light is Off");
    delay(200);
  }                                                       // Conditions
  
  else
  {
    digitalWrite(bulb,LOW);    
  }                                                      // Conditions
}
