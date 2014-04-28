#include <LiquidCrystal.h>
#define BUTTON_PIN A5                       // The number of the push-button pin.
#define LCD_LIGHT_PIN A4                   // The number of the pin where anode of the display backlight is.
#define LCD_LIGHT_ON_TIME 60000             // How long (in milliseconds) should lcd light stay on?
 
unsigned int currentLcdLightOnTime = 0;
unsigned long lcdLightOn_StartMillis;     // For calculating the lcd light on time.
 
boolean isLcdLightOn;
 
int buttonState = 0;                       // For checking push-button state.
 
LiquidCrystal lcd(8, 9, 5, 6, 7, 3);        // Initialize the LiquidCrystal library with the numbers of the interface pins.
                                            // LiquidCrystal(rs, e, d4, d5, d6, d7)
void setup(){
 lcd.begin(16, 2);                        // Set the lcd number of columns and rows
 lcd.print("hello, world!");               // Print a message to the LCD.
 Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. 
  }
 

  pinMode(BUTTON_PIN, INPUT);              // Set the push-button pin as an input.
  pinMode(LCD_LIGHT_PIN, OUTPUT);          // Set the lcd display backlight anode pin as an output.
  digitalWrite(LCD_LIGHT_PIN, LOW);         // Set the lcd display backlight anode pin to low - lcd light off.
  isLcdLightOn = false;
}
 
void loop(){
  
  buttonState = digitalRead(BUTTON_PIN);  // Check the state of the push-button.
   if (buttonState == HIGH){
    Serial.println("Button pressed - HIGH");   // Button pressed.
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = true;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
  }
  else{
     if(isLcdLightOn){
      currentLcdLightOnTime = millis() - lcdLightOn_StartMillis;    // Button not pressed.
      if(currentLcdLightOnTime > LCD_LIGHT_ON_TIME){
        isLcdLightOn = false;
        digitalWrite(LCD_LIGHT_PIN, LOW);
      }
    }
  }
 
  Serial.print("Lcd light on time: ");
  delay(500);
  Serial.println(currentLcdLightOnTime);
}
