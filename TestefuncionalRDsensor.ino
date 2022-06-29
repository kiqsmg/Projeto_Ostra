/*
Main programa de Arduino para desenvolvimento de uma máquina seletora de ostras.
*/

#include<LiquidCrystal.h>

LiquidCrystal lcd(8,7,6,5,4,10);

int contador =0;
int OnOff=0;
int flag_OnOff;


void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Bem vindo ao");
  lcd.setCursor(0,1);
  lcd.print("programa!!");
  pinMode(2,INPUT);
  pinMode(9, OUTPUT); 
  
  delay(3000);
  lcd.clear();
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Ostras contadas:");
  lcd.setCursor(0,1);
  lcd.print(contador);
  if(digitalRead(2)==HIGH)
  {
    OnOff=1;
    //digitalWrite(9,HIGH);
    tone(9, 440, 100); // play tone 57 (A4 = 440 Hz);
  }
  else
  {
    OnOff=-1;
    digitalWrite(9,LOW);  
  }
  if((flag_OnOff == -1)&& (OnOff ==1))
  {
    contador++;
    delay(100);
  }
  flag_OnOff=OnOff;
}
