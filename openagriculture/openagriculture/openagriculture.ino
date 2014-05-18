#include <EEPROM.h>
#include <LiquidCrystal.h>                                       //this library is included in the Arduino IDE
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);                             //lcd connection pin numbers.                                     
                     
char display_row1[16] = "    WELCOME    "; /* Default Value, 15 char + 1 null */
char display_row2[16] = "GREEN ECOSYSTEM";

void print_welcome(); /* Print welcome message at power ON */
 
void setup() {                  
	lcd.begin(16,2); /* 16x2 lcd */
}

void loop() {
	print_welcome();
//	printMenu(); 
}     
             
void print_welcome() {
	lcd.clear(); /* clear lcd */
	lcd.print(display_row1);
	lcd.setCursor(0,1);
	lcd.print(display_row2);
	delay(1000); /* wait for 1000ms = 1 Sec */
}
 
void printMenu() {
}
