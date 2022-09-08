#include <Wire.h>    // SDA pin A4 SDL pin A5             
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()  
{ 
lcd.begin(16,2);// Indicamos medidas de LCD   
lcd.setCursor(0,0); 
lcd.print("Velocidad Giro");
lcd.setCursor(0,1);    
lcd.print(">>>>>>>>> 33rpm");
}

void loop() {

}



