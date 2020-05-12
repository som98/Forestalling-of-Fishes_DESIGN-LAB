#include <OneWire.h>
#include <Servo.h>
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
Servo Servo1;
Servo Servo2;
int servoPin =9 ;
int servoPin2 =11 ;
int water_level;
int water_sensor_pin = A5;
int count=0;
void setup()
{
Serial.begin(9600);
Servo1.attach(servoPin);
Servo2.attach(servoPin2);

}
void loop()
{
water_level=analogRead(water_sensor_pin);
Serial.println(water_level);
if(water_level>=300)
{
if(count==0)
{
for(int i=0;i<=180;i++)
{
Servo1.write(i);
Servo2.write(i);
delay(30);
}
count=1;
}
}


if(water_level<300 && count==1)
{
for(int i=180;i>=0;i--)
{
Servo1.write(i);
Servo2.write(i);
delay(30);
}
count=0;
}
}
