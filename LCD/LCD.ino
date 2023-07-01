#include <LiquidCrystal.h>

LiquidCrystal lcd(43, 41, 53, 51, 49, 47);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //Define el tamaño del LCD

  lcd.setCursor(0,0); //Donde inicia el cursor

  lcd.print("Hola mundo");

}

void loop() {
  // put your main code here, to run repeatedly:

}
