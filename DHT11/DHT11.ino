#include <DHT.h>

DHT dht(45, DHT11); //Pin de entrada 45 y tipo de sensor

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  
  Serial.begin(9600); //Iniciar la consola serial

}

void loop() {
  // put your main code here, to run repeatedly:
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  Serial.print("\nTemperatura: ");
  Serial.print(temperatura);

  Serial.print("\nHumedad: ");
  Serial.print(humedad);

  delay(1000);

}
