#include <RH_ASK.h>
#include <SPI.h>

//El transmisor utiliza un pin MISO

//Crear objeto driver
RH_ASK driver;

void setup() {
  // put your setup code here, to run once:

  pinMode(47, INPUT);
  
  //Inicializar serial
  Serial.begin(9600);

  //Inicializar driver
  if (!driver.init()){
    Serial.println("Inicializar fallo");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  const char *mensaje = "Hola";

  //Esperar que el boton se active para mandar mensaje
  if (digitalRead(47) == LOW){
    driver.send((uint8_t *)mensaje, strlen(mensaje));
    driver.waitPacketSent();
  }
  delay(400);
}
