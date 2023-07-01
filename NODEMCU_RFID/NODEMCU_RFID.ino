#include <MFRC522.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//Datos WiFi
const char* ssid = "redUAQ";
const char* password = "";

//Datos servidor MQTT
const char* mqttServer = "148.220.211.36";
const int mqttPort = 1883;
const char* mqttUser = "zahid";
const char* mqttPassword = "190501";

//Declarar objetos 
WiFiClient espClient;
PubSubClient client(espClient);

//Pines RFID
const int pinSDA= D8;
const int pinRST= D1;

//Declarar obejo RFID
MFRC522 mfrc522(pinSDA, pinRST);


void setup() {
  // put your setup code here, to run once:
  //Inicializar serial
  Serial.begin(115200);

  //Inicializar el SPI
  SPI.begin();

  //Inicializar  el MFRC522
  mfrc522.PCD_Init();

  //Conectar WiFi
  WiFi.begin(ssid, password);

  //Esperar a que se conecte a la red
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");

  //Seleccionar el SV
  client.setServer(mqttServer, mqttPort);

  //Comentar luego
  client.setCallback(callback);

  //Esperar a que se conecte al servidor
  while (!client.connected()) {
    Serial.print(".");
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      Serial.println("Serividor conectado");
    }
    else{
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  //Publicar un mensaje a un tema
  client.publish("esp/test", "Hola desde ESP8266");

  //Suscribirse al tema
  client.subscribe("esp/test");

}

//Funcion que recibe y muestras los mensajes recibidos, recibe el topico, la carga en byte y el tamaño
void callback(char* topic, byte* payload, unsigned int length) {

  Serial.println();
  Serial.print("Mensaje recibido en el topico: ");
  Serial.println(topic);
  
  Serial.print("Mensaje:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  Serial.println();
  Serial.println("-----------------------");
}

void loop() {
  // put your main code here, to run repeatedly:

  //Revisar si hay nuevas tarjetas presentes
  if ( mfrc522.PICC_IsNewCardPresent()) {  
    //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial()) {
      // Enviamos a un tema el UID
      //char valor1[mfrc522.uid.size];
      char valor2[mfrc522.uid.size];
      String datos = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX); 
        //valor1[i] = String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");  
        valor2[i] = mfrc522.uid.uidByte[i];
        datos = datos + String(valor2[i], HEX);
      }

      client.publish("esp/test", datos.c_str());
      
      // Terminamos la lectura de la tarjeta  actual
      mfrc522.PICC_HaltA();         
    }      
  }  

  client.loop();
}
