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

const int digital_in_pin[] = {8, 11};
const int setting_mode_key = digital_in_pin[0]; /* User setting key */

/* Global array for int to string */
char cstr[5];

int key_state = 0;

/* Eeprom address */
int temp_thrld_addr = 0x01;
int light_thrld_addr = 0x02;

void print_welcome(); /* Print welcome message at power ON */
void print_temp();
void print_on_display();
 
void init_pins() {
	pinMode(setting_mode_key,INPUT); /* input pinmode for setting mode key */
}

/* User setting mode, will be enabled only when user
   presses key, while power ON 
*/

void setting_mode() {
	lcd.clear();
	strcpy(display_row1,  "   ENTERING    ");
	strcpy(display_row2,  " SETTING MODE  ");
	print_on_display();

	delay(500); /* wait for showing next screen */
	/* Implement a mechanism to change threadshould value */

	/* do factory reset */
	reset_values();
	
	read_temp_threadshold();
	read_light_threadshold();

	print_on_display();

	delay(5000); /* wait before coming out of settings mode */
}

float read_temp_threadshold() {
        char *t_str;
	int temp_thrld = EEPROM.read(temp_thrld_addr);     /* threadshouldtemp read in EEPROM */
	t_str = int_to_string(temp_thrld);
        strcpy(display_row1,  "TEMP Thr.= ");
	strcat(display_row1, t_str);
}

int read_light_threadshold() {
        char *t_str;
        int light_thrld = EEPROM.read(light_thrld_addr);     /* threadshould light sensor value */
	t_str = int_to_string(light_thrld);
        strcpy(display_row2,  "LIGHT Thr.= ");
	strcat(display_row2, t_str);
}

/* Use this function to do factory reset 
   to default valuses */
void reset_values() {
        EEPROM.write(temp_thrld_addr, 30); /* default reset temp to 30 deg */
        EEPROM.write(light_thrld_addr, 140); /* default reset light to 140 */
}

void setup() {
	init_pins();                  
	lcd.begin(16,2); /* 16x2 lcd */
	print_welcome(); /* Print Welcome message while booting */
	
	/* Check if we need to go to setting mode while power on
	   Key pressed */
	if ((key_state = digitalRead(setting_mode_key)) == HIGH)
		setting_mode();
}

void loop() {
	printMenu();
}     

/* ################# ALL Display Print Code #####################
##############################################################
*/
void print_on_display() {
	lcd.clear(); /* clear lcd */
	lcd.print(display_row1);
	lcd.setCursor(0,1);
	lcd.print(display_row2);
	delay(1000); /* wait for 1000ms = 1 Sec */
}
             
void print_welcome() {
	print_on_display();
}

float read_temp() {
	int tempReading = analogRead(temp_in); /* Read analog temp. sensor data */
	float temp_deg =  ((5.0 * tempReading * 100.0)/1024.0); /* Convert to deg cen. */
	return temp_deg;
}

void print_temp() {
	char temp_char[6]; // buffer for temp incl. decimal point & possible minus sign
	
	float temp_float = read_temp();
	dtostrf(temp_float, 6, 2, temp_char); /* Convert Float to String */

	strcpy(display_row1,  "Temp.=");
	strcat(display_row1, temp_char);
	strcat(display_row1,  " deg");
	lcd.print(display_row1);
}

int read_light() {
	int light_sensor_reading = analogRead(light_in);
	return (light_sensor_reading);
}

char *int_to_string(int val) {
	String str = String(val);
	str.toCharArray(cstr,5);
	return cstr;
}

void print_light() {
	char *t_str;
	int lightReading = read_light();
	t_str = int_to_string(lightReading);	
	strcpy(display_row2, "Light.= ");
	strcat(display_row2, t_str); 
	lcd.print(display_row2);
}

void printMenu() {
	lcd.clear();
	print_temp(); /* Print temp on first row */
	lcd.setCursor(0,1);
	print_light(); /* Print light value on second row */
	delay(1000); /* wait for 1000ms = 1 Sec */
}

/* ############################################################### 
*/
