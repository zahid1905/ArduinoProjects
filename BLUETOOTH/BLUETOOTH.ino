#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial ModuloHC05 (10, 11); //RX y TX

LiquidCrystal_I2C lcd(0x3F,16,2);

char dato;

String datos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);        //Inicializa puerto serie por hard
  ModuloHC05.begin(9600);    //Inicializa puerto serie por soft

  lcd.init();
  lcd.backlight();
  //lcd.print("Hola Mundo");

}

void loop() {
  // put your main code here, to run repeatedly:
  
//  lcd.setCursor(0, 1);
  //if (ModuloHC05.available()){
  String datos = "";
    //while (ModuloHC05.available()) {              //Llega algo por bluetooth?
      
      while (ModuloHC05.available()) {
        dato=ModuloHC05.read();                   //Leer lo que llegó
        datos=datos+dato;
      }
      //lcd.write(dato);    
    if (datos != ""){
      Serial.print(datos);                       //Sacarlo a la terminal
      Serial.print("\n");
      
      lcd.clear();
      lcd.print(datos);                       //Sacarlo a la terminal
      //
    }
    
  
}
