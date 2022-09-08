#include <Wire.h>                 
#include <LiquidCrystal_I2C.h>    
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <Stepper.h>

int motorPin1 = 8;    // Azul   - 28BYJ48 pin 1 motor
int motorPin2 = 9;    // Rosa   - 28BYJ48 pin 2 motor
int motorPin3 = 10;    // Amarillo - 28BYJ48 pin 3 motor
int motorPin4 = 11;    // Naranja - 28BYJ48 pin 4 motor
                        // Rojo   - 28BYJ48 pin 5 (VCC) motor
int motorSpeed = 1200;  //variable para fijar la velocidad del motor (el retraso entre cada secuencia)
int count = 0;          // cuenta de los pasos dados
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

int estado = 0; 
int salida = 0;
int estadoAnterior = 0;
int p1 = 3;
int p2 = 2;

int value = 0;

void setup()  
{ 
pinMode(p1, INPUT);
pinMode(p2, INPUT);
lcd.begin(16,2);// Indicamos medidas de LCD  
{
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}      
}

void loop() 
{
  
  
  
  estado = digitalRead(p1);

lcd.clear();

if((estado == HIGH) && (estadoAnterior == LOW))
{
  salida = 1 - salida;
  delay(30);
}
estadoAnterior = estado;

if(salida == 1) {lcd.clear();//Elimina todos los simbolos del LCD
lcd.setCursor(0,0);//Posiciona la primera letra despues del segmento 5 en linea 1             
lcd.print("Velocidad");
}
else {lcd.clear();
lcd.setCursor(0,1);//Posiciona la primera letra despues del segmento 6 en linea 2            
lcd.print("33rpm");
}

}
 

void setOutput(int out) //función secuencia giro
{
 for(int i = 7; i >= 0; i--)
{
 setOutput(i);
 delayMicroseconds(motorSpeed);
}


{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}}
