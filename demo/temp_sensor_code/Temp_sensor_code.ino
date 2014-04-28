int tempSensor = 1;
float tempC;
void setup()
{
Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
pinMode (2, OUTPUT);
}
void loop()
{
Serial.print("Temperature in C : ");
tempC = analogRead(tempSensor);              //read the value from the sensor
tempC = ((5.0 * tempC * 100.0)/1024.0);  //convert the analog data to temperature
Serial.print(tempC);                    //send the data to the computer
if (tempC < 25)
{
Serial.println("turning on low-temperature LED");   
digitalWrite (2, HIGH);                          //digitalwrite pin 2 high then low-temperature LED on
delay(2000);
}
if (tempC > 25)
{
Serial.println("turning off low-temperature LED"); 
digitalWrite (2, LOW); ////digitalwrite pin 2 high then low-temperature LED on
delay(2000);
}
}

