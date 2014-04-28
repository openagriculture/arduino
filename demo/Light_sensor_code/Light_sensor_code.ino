int lightSensor = 1;
int light_val;
void setup() {
Serial.begin(9600); //open serial port
pinMode (7, OUTPUT);
}
void loop() {
light_val = analogRead(lightSensor); // read the value from the photosensor
Serial.print("light sensor reads ");
Serial.println( light_val );
if (light_val < 650)
{
Serial.println("turning on lights"); 
digitalWrite (7, HIGH);               // digitalwrite pin 7 high then light are on 
delay(2000);
}
if (light_val > 650)
{
Serial.println("turning off lights"); 
digitalWrite (7, LOW);              // digitalwrite pin 7 low  then light are off
delay(2000);
}
}
