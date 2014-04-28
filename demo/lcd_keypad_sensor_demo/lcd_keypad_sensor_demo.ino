#include <EEPROM.h>
#include <LiquidCrystal.h>                                       //this library is included in the Arduino IDE
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);                             //lcd connection pin numbers.                                     
int moisture_val;
const int buttonpin= 8;                                          // user setting button connected pin no.
const int button1= 11;                                           // sensor data button connected pin no.
int buttonState=0;                                               // button state
int buttonPushCounter1=0;                                        // button push counter
int addr = 0x01,addr1=0x02,addr2=0x11;                           // specified the address values.
int  thresouldsoilMoisture = 244,thresouldtemp=25,thresouldlight=150;     // thresould value specified
int readValue,readValue1,readValue2;
                       
int tempPin = 0;                                                  // temp sensor pin connected arduino
int lightPin = 1;                                                 // light sensor pin connected to arduino
int SoilPin = 2;                                                   // soil sensor pin connected to arduino
long last_read = 0;
char* list[] = {"sensor data",};              
byte index = 0;


                      
void setup() {                  
              pinMode(buttonpin,INPUT);                            // input pinmode of buttonpin and button1              
              pinMode(button1,INPUT); 
              lcd.begin(16,2);                                     // 16x2 lcd
              EEPROM.write(addr,thresouldsoilMoisture );           // thresouldsoilMoisture value write in EEPROM
              EEPROM.write(addr1,thresouldtemp);                   // thresouldtemp value write in EEPROM
              EEPROM.write(addr2,thresouldlight);                  // thresouldlight value write in EEPROM
              pinMode (10, OUTPUT);                                // output pin no. 10
              pinMode (12, OUTPUT);                                // output pin no. 12
              pinMode (13, OUTPUT);                                // output pin no. 13
              digitalWrite (10, HIGH);                             // specified pin no.10 as high
              digitalWrite (12, HIGH);                             // specified pin no.12 as high
              digitalWrite (13, HIGH);                             // specified pin no.13 as high
              lcd.print("Greenecosystem");
             
              }
void loop() 
            { 
               buttonState = digitalRead(buttonpin);
             {
              if (buttonState == HIGH){
              buttonPushCounter1++;
              switch(buttonPushCounter1)                             // switch case used
                  {
                    case 1 :   
                            lcd.clear();
                            lcd.print("User setting");
                            delay(500);
                    break;
                    case 2 :                                                 // set  thresould temperature value
                           lcd.clear();                                      // clears display
                           lcd.setCursor(0,0);                               // set lcd cursor
                           lcd.print( "Tempthresouldset= ");
                           lcd.setCursor(0,1);                                // set lcd cursor
                           if (readValue1 = EEPROM.read(addr1));             // read value from EEPROM
                                { digitalWrite (10, HIGH);                   // digitalWrite 10 pin high then LED off  
                                  delay(500);                                // delay
                                }
                         lcd.setCursor(5,1);                                 // set lcd cursor 
                         lcd.print(readValue1);                              // print value in lcd 
                 
                   break;
                   case 3 :                                                   //  set  thresould light value 
                         lcd.clear();                                         //  clears display
                         lcd.setCursor(0,0);                                  // set lcd cursor                                   
                         lcd.print( "Lthresould set = ");  
                         lcd.setCursor(0,1);                                  // set lcd cursor
                          if (readValue2 = EEPROM.read(addr2));               // read value from EEPROM          
                           { digitalWrite (12, LOW);                          // digitalWrite 12 pin high then LED on  
                            delay(500);                                       // delay 
                           }
                        lcd.setCursor(5,1);                                   // set lcd cursor
                        lcd.print(readValue2);                                // print  value  in lcd 
                 
                 break;
                 case 4 :                                                    //  set  thresould soilmoisture value
                        lcd.clear();                                         //  clears display
                        lcd.setCursor(0,0);                                   // set lcd cursor     
                        lcd.print( "Sthresould set = ");                      // lcd print
                        lcd.setCursor(0,1);                                   // set lcd cursor
                        if  (readValue = EEPROM.read(addr));                  // read value from EEPROM
                           { digitalWrite (13, LOW);                          // digitalWrite 13 pin high then LED on  
                             delay(500); 
                           }
                        lcd.setCursor(5,1);                                   // set lcd cursor
                        lcd.print(readValue);                                 // print in lcd 
                 
                break;
                case 5:
                      lcd.clear();                                        
                      lcd.setCursor(0,0);
                      lcd.print(" Thanks You set");
                      lcd.setCursor(0,1);
                      lcd.print(" thresould data"); 
                
                break;
                 }
               } else{
                       }
            
          }      
          
          {
              if(millis() - last_read > 200)
              {
                if(digitalRead(button1) == 1)
               {
                buttonClicked(button1);
               }
               last_read = millis();
             }
           }
          
          
}     
             
void buttonClicked(int btn) 
      {
        if (btn == button1==1)                                         // if BTN_2 pressed sensor data shown to display using below condition
         {
           lcd.clear();                     
           int tempReading = analogRead(tempPin);                      // read sensor data 
           float tempC =  ((5.0 * tempReading * 100.0)/1024.0);        // analog value from sensor converted in to the C value
           lcd.print("TempC");
           lcd.setCursor(5, 0);
           lcd.print(tempC);
            if (tempC < 20)
          {
            digitalWrite (10, LOW);                                   // digitalWrite 10 pin LOW then LED On  
            delay(2000);
          }
          if (tempC> 20)
            {
             digitalWrite (10, HIGH);                                  // digitalWrite 11 pin low then LED off
             delay(2000);
            }
           delay (1200);
    
           int lightReading = analogRead(lightPin);
           lcd.setCursor(11, 0);
           lcd.print("Light ");
           lcd .setCursor(0,1);
           lcd.print(lightReading);
           
            if (lightReading < 200)
          {
            digitalWrite (12, LOW);                                    // digitalWrite 12 pin low then LED on
            
          }
          if (lightReading> 200)
            {
             digitalWrite (12, HIGH);                                   // digitalWrite 12 pin HIGH then LED off 
            
            }
            
            delay(5000);
   
           int soilmoistureReading= analogRead(SoilPin);               // read sensor data
           lcd.setCursor(5,1);
           lcd.print("SoilMoi ");
           lcd.print(soilmoistureReading);                             
           
            if (soilmoistureReading < 500)
          {
            digitalWrite (13, LOW);                                    // digitalWrite 13pin high then LED on  
            delay(2000);
          }
          if (soilmoistureReading> 600)
            {
             
             digitalWrite (13, HIGH);                                 // digitalWrite 13 pin low then LED off 
             delay(2000);
            }
           delay (1200);
    
          
        }
  
  
printMenu(list[index]);
 }
 
void printMenu(String s)                                               // set up fucition call here
  {
   lcd.clear();                                                        // clear lcd 
   lcd.print("WELLCOME");                                              // print to lcd contineously
   lcd.setCursor(0,1);                                                 // set cursor to lcd 
   lcd.print(s);                                                       // print lcd as string s
}


     
    
     
    
    
    
    
    
    

