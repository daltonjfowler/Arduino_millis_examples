//Code for intervals

#include <Servo.h>

unsigned long timeTotal = 0; //this holds total time for program
int interval = 5000; //how long we want to wait until the servo goes
unsigned long duration = 0; //hold time since last sweep

int motorPin = 5;
Servo motor;

void setup()
{
  Serial.begin(9600);
  motor.attach(motorPin);
}

void loop()
{
timeTotal = millis(); //get current time since board started
 
  if(interval < timeTotal - duration) //see if difference between last sweep and current time read is greater than our desired waiting period
  {
    motor.write(180);
    Serial.println("It's been at least the amount of time interval is set to");
    delay(250);
    duration = millis(); //save the time we last swept so we can do it again in 5 seconds
  }
  
//why do we do this? It's beneficial to use millis to control functions so we can plan when things will happen while doing other things.
//if we just used delays our code would be unable to do anything else, like print to an LCD, get readings, or really do anything.
//only using delays is bad!
}
