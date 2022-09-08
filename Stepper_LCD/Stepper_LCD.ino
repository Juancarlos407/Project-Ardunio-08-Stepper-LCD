#include <Stepper.h>
#include <Wire.h>                 
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int Iint1=0;
int Iint2=1;
int anjian1=2;
int anjian2=3;
int motorSpeed;
const int stepsPerRevolution =200;
//   Here set the stepper motor rotation step how much is a circle
int dim=stepsPerRevolution;
//  Set the step motor number and pin
Stepper myStepper(stepsPerRevolution, 10,11,12,13);  
void setup()
{  
   lcd.begin(16, 2);
   lcd.print("speed:");
   
   lcd.setCursor(10,0);
   lcd.print("n/min");
   
   lcd.setCursor(0, 1);
   lcd.print("Direction:");
   //   Set the motor speed of 60 steps per minute

   myStepper.setSpeed(60);     
pinMode(anjian1,INPUT_PULLUP);
   pinMode(anjian2,INPUT_PULLUP);
   attachInterrupt(Iint1,counterclockwise,FALLING);
   attachInterrupt(Iint2,clockwise,FALLING);
   Serial.begin(9600);
}

void loop() 
 { 
   
   myStepper.step(dim);
   void Direction();
   //  Read the sensor values:
   int sensorReading = analogRead(A0);
  //  Map it to a range of 0-150:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 150);
  //  Set the motor speed:
   if (motorSpeed > 0) 
    {
        myStepper.setSpeed(motorSpeed);
        lcd.setCursor(6,0);
       lcd.print(float(float(motorSpeed)/float(200)));
    } 
  }
   
 void clockwise()
  { 
    //   clockwise rotation
     dim=stepsPerRevolution;
    lcd.setCursor(10, 1);
     lcd.print(">>>>>>");
  }
    

  void counterclockwise()
  {  
     // anti-clockwise
     dim=-stepsPerRevolution;
    lcd.setCursor(10, 1);
    lcd.print("<<<<<<");
  }
