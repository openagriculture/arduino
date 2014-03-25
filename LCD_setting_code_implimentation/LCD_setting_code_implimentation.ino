#include <LiquidCrystal.h> //this library is included in the Arduino IDE
 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 
const int BTN_LEFT = 9;

const int BTN_CONFIRM = 10;

int tempPin = 0;
int lightPin = 1;
int SoilPin = 2;
float tempset,thresould = 25;
float soilmoistureset,soilthresould =500;
float lightset,lightthresould = 300;
long last_read = 0;
 
char* list[] = {"sensor data",};
byte index = 0;
 
void setup() {
pinMode(BTN_LEFT,INPUT);

pinMode(BTN_CONFIRM,INPUT);

lcd.begin(16,2);
Serial.begin(9600);
printMenu(list[index]);
}
 
void loop() {
  
if(digitalRead(BTN_LEFT) == 1) {
  lcd.clear();
  lcd.print("User setting");
   delay(500);
   tempset= thresould;
    lcd.clear();
    lcd.setCursor(0,0);  //clears display
    lcd.print( "Tempthresould ");
    lcd.setCursor(0,1);
    lcd.print(thresould);
    delay(5000);
  
    soilmoistureset = soilthresould;
    lcd.clear();
    lcd.setCursor(0,0);  //clears display
    lcd.print( "Sthresould set = ");
    lcd.setCursor(0,1);
    lcd.print(soilthresould);
    delay(5000);
    
   lightset = lightthresould;
    lcd.clear();
    lcd.setCursor(0,0);  //clears display
    lcd.print( "Lthresould set = ");
    lcd.setCursor(0,1);
    lcd.print(lightthresould);
    delay(5000);

   
}else {
  
}
  
  
  
  
  
  
  
if(millis() - last_read > 200) {
if(digitalRead(BTN_LEFT) == 1) {
buttonClicked(BTN_LEFT);
}

if(digitalRead(BTN_CONFIRM) == 1) {
buttonClicked(BTN_CONFIRM);
}
last_read = millis();
}
}
 
void buttonClicked(int btn) {
if(btn == BTN_LEFT && index > 0 ) {
--index;

} else if (btn == BTN_CONFIRM==1) {
  
     lcd.clear();                     //Display Temperature in F
    int tempReading = analogRead(tempPin);
    float tempVolts = tempReading * 5.0 / 1024.0;
    float tempC = (tempVolts - 0.5) * 100.0;
    float tempF = tempC * 9.0 / 5.0 + 32.0;
    lcd.print("TempF ");
    lcd.setCursor(5, 0);
    lcd.print(tempF);
    delay (1200);
    
    
                                                   // Display Light value
  int lightReading = analogRead(lightPin);
    lcd.setCursor(11, 0);
    lcd.print("Light ");
    lcd .setCursor(0,1);
    lcd.print(lightReading);
    delay(1200);
                                                // Dissplay Soilmoisture value
    int soilmoistureReading= analogRead(SoilPin);
    lcd.setCursor(5,1);
    lcd.print("SoilMoi ");
    lcd.print(soilmoistureReading);
    delay(2500);
 
    
  }
  
  
printMenu(list[index]);
}
 
void printMenu(String s) {
lcd.clear();
lcd.print("WELLCOME");
lcd.setCursor(0,1);
lcd.print(s);
}
