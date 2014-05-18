#include <EEPROM.h>
#include <LiquidCrystal.h>                                       //this library is included in the Arduino IDE
#include <stdlib.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);                             //lcd connection pin numbers.                                     
                     
char display_row1[16]     = "    WELCOME    "; /* Default Value, 15 char + 1 null */
char display_row2[16]     = "GREEN ECOSYSTEM";
char display_blankrow[16] = "               ";

int analog_in_pin[] = {0, 1, 2, 3, 4, 5}; /* define analog pins */

int temp_in = analog_in_pin[0]; /* temp sensor pin connected arduino */
int light_in = analog_in_pin[1]; /* light sensor pin */

void print_welcome(); /* Print welcome message at power ON */
void print_temp();
 
void setup() {                  
	lcd.begin(16,2); /* 16x2 lcd */
	print_welcome(); /* Print Welcome message while booting */
}

void loop() {
	printMenu();
}     
             
void print_welcome() {
	lcd.clear(); /* clear lcd */
	lcd.print(display_row1);
	lcd.setCursor(0,1);
	lcd.print(display_row2);
	delay(1000); /* wait for 1000ms = 1 Sec */
}

void print_temp() {
	char temp_char[6]; // buffer for temp incl. decimal point & possible minus sign

	int tempReading = analogRead(temp_in); /* Read analog temp. sensor data */
	float temp_float =  ((5.0 * tempReading * 100.0)/1024.0); /* Convert to deg cen. */
	
	dtostrf(temp_float, 6, 2, temp_char); /* Convert Float to String */

	strcpy(display_row1,  "Temp.=");
	strcat(display_row1, temp_char);
	strcat(display_row1,  " deg");
	lcd.print(display_row1);
}

void print_light() {
	char cstr[5];
	int lightReading = analogRead(light_in);
	String lightString = String(lightReading);
	lightString.toCharArray(cstr,5);
	strcpy(display_row2, "Light.= ");
	strcat(display_row2, cstr); 
	lcd.print(display_row2);
}

void printMenu() {
	lcd.clear();
	print_temp(); /* Print temp on first row */
	lcd.setCursor(0,1);
	print_light(); /* Print light value on second row */
	delay(1000); /* wait for 1000ms = 1 Sec */
}
