#include <LiquidCrystal.h>
     
    int tempPin = 0;
    int lightPin = 1;
    int SoilPin = 2;
   
   LiquidCrystal lcd(2,4,8,9,10,11);              //  LCD connected pin BS E D4 D5 D6 D7 
  
    void setup()
    {
    lcd.begin(16, 2);
    }
     
    void loop()
    {
                                                  //Display Temperature in F
    int tempReading = analogRead(tempPin);
    float tempVolts = tempReading * 5.0 / 1024.0;
    float tempC = (tempVolts - 0.5) * 100.0;
    float tempF = tempC * 9.0 / 5.0 + 32.0;
    lcd.print("TempF ");
    lcd.setCursor(5, 0);
    lcd.print(tempF);
    delay (5000);
    
    
                                                   // Display Light value
    int lightReading = analogRead(lightPin);
    lcd.setCursor(11, 0);
    lcd.print("Light ");
    lcd .setCursor(0,1);
    lcd.print(lightReading);
    delay(5000);
                                                // Dissplay Soilmoisture value
    int soilmoistureReading= analogRead(SoilPin);
    lcd.setCursor(5,1);
    lcd.print("SoilMoi ");
    lcd.print(soilmoistureReading);
    delay(5000);
    
    }
   
 


