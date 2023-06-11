//Code for stopwatch do now
unsigned long time = 0; //this holds total time for program
int buttonPin = 2; //holds location of button
unsigned long duration = 0; //hold time between button presses

void setup()
{
  Serial.begin(9600);
}

void loop()
{
time = millis();
 
  if(digitalRead(buttonPin) == 1)
  {
   Serial.print("Total time for Program: ");
   Serial.print(time/1000);
   Serial.print(" Seconds");  //prints a nice format
   Serial.println("");          //for total time
   Serial.println("");
   
  duration = time - duration; //give us the time between last press and now!
  //print the difference
   Serial.print("Time since last button press: ");
   Serial.print(duration/1000);
   Serial.print(" Seconds");  //prints a nice format
   Serial.println("");          //for total time
   Serial.println("");
   //reset duration for next time
   duration = millis();
   delay(250);
  }

}
