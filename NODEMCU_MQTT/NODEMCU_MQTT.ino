#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//Datos WiFi
const char* ssid = "redUAQ";
const char* password = "";

//Datos servidor MQTT
const char* mqttServer = "148.220.211.202";
const int mqttPort = 1883;
const char* mqttUser = "zahid";
const char* mqttPassword = "190501";

//Declarar objetos 
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  //Inicializar serial
  Serial.begin(115200);

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
  client.loop();
  int x = 0;
  while (x<10){
    char b[2];
    String str;
    str=String(x);
    str.toCharArray(b,2);
    
    client.publish("esp/test", b);
    x++;
    delay(2000);
  }
}
