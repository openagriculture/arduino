#include <LiquidCrystal.h>
     
    int tempPin = 0;
    int lightPin = 1;
     int SoilPin = 2;
     
    // BS E D4 D5 D6 D7
    LiquidCrystal lcd(2,4,8,9,10,11);
     
    void setup()
    {
    lcd.begin(16, 2);
    }
     
    void loop()
    {
    // Display Temperature in C
    {
    int tempReading = analogRead(tempPin);
    float tempVolts = tempReading * 5.0 / 1024.0;
    float tempC = (tempVolts - 0.5) * 100.0;
    float tempF = tempC * 9.0 / 5.0 + 32.0;
    // ----------------
    lcd.print("TempF ");
    lcd.setCursor(6, 0);
    lcd.print(tempF);
    delay(5000);
    }
    // Display Light
    {
    int lightReading = analogRead(lightPin);
    ;
    lcd.autoscroll();
    // ---------------
    lcd.setCursor(9, 0);
    lcd.print("Light ");
    
    lcd.print(lightReading);
    delay(5000);
    }
    
    {
      int soilmoistureReading= analogRead(SoilPin);
      lcd.autoscroll();
     ;
      lcd.print("SoilMoi ");
      
      lcd.print(soilmoistureReading);
      delay(5000);
    }
   
                                             
  lcd.noAutoscroll();      // turn off automatic scrolling
 
  lcd.clear();           // clear screen for the next loop
}

      
