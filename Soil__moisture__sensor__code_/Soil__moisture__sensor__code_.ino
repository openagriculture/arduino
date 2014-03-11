int moistureSensor = 0;
int moisture_val;
void setup() {
Serial.begin(9600); //open serial port
pinMode (11, OUTPUT);
}

void loop() {

moisture_val = analogRead(moistureSensor); // read the value from the moisture sensor
Serial.print("moisture sensor reads ");
Serial.println( moisture_val );
if (moisture_val < 500)
{
Serial.println("turning on LED ");
digitalWrite (11, HIGH);
delay(2000);
}
if (moisture_val > 500)
{
Serial.println("turning off LED");
digitalWrite (11, LOW);
delay(2000);
}
}
