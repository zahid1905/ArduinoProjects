#include <RH_ASK.h>
#include <SPI.h>

//El receptor utiliza un pin MOSI

//Crear objeto driver
RH_ASK driver;

void setup() {
  // put your setup code here, to run once:
  //Inicializar serial
  Serial.begin(9600);

  //Inicializar driver
  if (!driver.init()){
    Serial.println("Inicializar fallo");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  //Establecer un buffer del tamaño del mensaje a recibir 
  uint8_t buf[4];
  uint8_t buflen = sizeof(buf);

  //Esperar a recibir un mensaje valido e imprimirlo
  if (driver.recv(buf, &buflen)){
    Serial.print("Mensaje: ");
    Serial.println((char*)buf);
  }

}
