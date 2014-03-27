#include <LiquidCrystal.h> //this library is included in the Arduino IDE
 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);          // lcd connection pin numbers.

const int BTN_1= 9;                           // push button1 pin no.connected arduino
const int BTN_2 = 10;                        // push button2 pin no.connected arduino
int tempPin = 0;                             // temp sensor pin connected arduino
int lightPin = 1;                             // light sensor pin connected to arduino
int SoilPin = 2;
float tempset,thresould = 25;                 // set thresould temperature variable.
float soilmoistureset,soilthresould =500;     // set thresould soilmoisture  variable.
float lightset,lightthresould = 300;          //set thresould light  variable.
long last_read = 0;
 
char* list[] = {"sensor data",};              
byte index = 0;
 
void setup() {
           pinMode(BTN_1,INPUT);              //set BTN_1 as input

          pinMode(BTN_2,INPUT);               //set BTN_2 as input

          lcd.begin(16,2);                    // lcd setup
          Serial.begin(9600);                
          printMenu(list[index]);            
            }
 
void loop() {
            if(digitalRead(BTN_1) == 1)                // if BTN_1 is long pressed below condition occured
                {
                 lcd.clear();
                 lcd.print("User setting");
                 delay(500);
                 
                 tempset= thresould;                   // set  thresould temperature value
                 lcd.clear();
                 lcd.setCursor(0,0);  //clears display
                 lcd.print( "Tempthresould ");
                 lcd.setCursor(0,1);
                 lcd.print(thresould);
                 delay(5000);
  
                 soilmoistureset = soilthresould;       //  set  thresould soilmoisture value
                 lcd.clear();
                 lcd.setCursor(0,0);  //clears display
                 lcd.print( "Sthresould set = ");
                 lcd.setCursor(0,1);
                 lcd.print(soilthresould);
                 delay(5000);
    
                 lightset = lightthresould;             //  set  thresould light value 
                 lcd.clear();
                 lcd.setCursor(0,0);  //clears display
                 lcd.print( "Lthresould set = ");
                 lcd.setCursor(0,1);
                 lcd.print(lightthresould);
                 delay(5000);

   
              }else {
  
                    }
                    
          if(millis() - last_read > 200)
              {
                if(digitalRead(BTN_1) == 1)
                {
                buttonClicked(BTN_1);
                }

               if(digitalRead(BTN_1) == 1)
               {
                buttonClicked(BTN_2);
               }
               last_read = millis();
             }
           }
 
    void buttonClicked(int btn) 
      {
        if(btn == BTN_1 && index > 0 ) {
           --index;
         } 
        else if (btn == BTN_2==1)                                     // if BTN_2 pressed sensor data shown to display using below condition
         {
           lcd.clear();                     
           int tempReading = analogRead(tempPin);
           float tempVolts = tempReading * 5.0 / 1024.0;
           float tempC = (tempVolts - 0.5) * 100.0;
           float tempF = tempC * 9.0 / 5.0 + 32.0;
           lcd.print("TempF ");
           lcd.setCursor(5, 0);
           lcd.print(tempF);
           delay (1200);
    
    
           int lightReading = analogRead(lightPin);
           lcd.setCursor(11, 0);
           lcd.print("Light ");
           lcd .setCursor(0,1);
           lcd.print(lightReading);
           delay(1200);
                                                
           int soilmoistureReading= analogRead(SoilPin);
           lcd.setCursor(5,1);
           lcd.print("SoilMoi ");
           lcd.print(soilmoistureReading);
           delay(2500);
        }
  
  
printMenu(list[index]);
 }
 
void printMenu(String s)            //   set up fucition call here
  {
   lcd.clear();                     // clear lcd 
   lcd.print("WELLCOME");           // print to lcd contineously
   lcd.setCursor(0,1);              // set cursor to lcd 
   lcd.print(s);                    // print lcd as string s
}
