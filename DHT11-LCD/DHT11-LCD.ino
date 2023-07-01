#include <LiquidCrystal.h>
#include <DHT.h>

DHT dht(52, DHT11); //Pin de entrada 52 y tipo de sensor

LiquidCrystal lcd(43, 41, 53, 51, 49, 47);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  
  lcd.begin(16,2); //Define el tamaño del LCD
  lcd.setCursor(0,0); //Donde inicia el cursor

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(temperatura);
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(humedad);

  Serial.print("\nTemperatura: ");
  Serial.print(temperatura);

  Serial.print("\nHumedad: ");
  Serial.print(humedad);

  delay(1000);
}
