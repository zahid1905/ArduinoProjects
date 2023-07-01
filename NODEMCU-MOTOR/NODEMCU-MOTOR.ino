//Libreria para utilizar el WiFi
#include <ESP8266WiFi.h>

//Pines motor
int motor1 = D1;
int motor2 = D2;
int activarMotor = D3;

//Nombre de la red
const char* ssid = "redUAQ";

//Contraseña de la red
const char* pass = "";

//Puerto
WiFiServer port(80);

void setup() {
  //Inicializar el serial (Para el Node se utiliza 115200)
  Serial.begin(115200); 

  //Motor
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(activarMotor, OUTPUT);
  
  digitalWrite(activarMotor, HIGH);

  //Imprimir la red
  Serial.print("Conectando a ");
  Serial.println(ssid);
  
  //Conectar a la red
  WiFi.begin(ssid,pass);

  //Esperar a que se conecte a la red
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");

  //Inicializar el puerto
  port.begin();
  Serial.println("Servidor iniciado");

  //Imprimir la IP
  Serial.print("URL para conectarse al servidor: ");
  Serial.print(WiFi.localIP());
  Serial.println("\n");
}

void loop() {

  //Crea un cliente que se conecte a un puerto disponible
  WiFiClient client = port.available();
  
  //Si no hay un cliente conectado al servidor el se reinicia el loop
  if(!client){
    return;
  }
  
  //Retiene hasta que el cliente realice una peticion  
  while(!client.available()){
    delay(1);
  }

  //Lee los datos solicitados por el cliente hasta que se termine la linea
  String request = client.readStringUntil('\r');

  //Busca el caracter de una cadena
  if(request.indexOf("/favicon")==-1){
    Serial.print("Nuevo cliente: ");
    Serial.println(request);
  }

  //Borra los datos de buffer del cliente
  client.flush();

  int value = 2;

  //Busca el caracter de una cadena y enciende el led
  if(request.indexOf("/MOTOR=IZQ") != -1 ){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    value = 1;
  }

  if(request.indexOf("/MOTOR=OFF") != -1 ){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    value = 2;
  }
  
  //Busca el caracter de una cadena y apaga el led
  if(request.indexOf("/MOTOR=DER") != -1 ){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    value = 3;
  }
  
  //Archivo HTML que recibira el cliente
  client.println("HTTP/1.1 200 OK"); //Version del protocolo
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Motor</title>");
  client.println("</head>");
  client.println("<body>");
  client.print("Motor: ");
  if(value == 1){
    client.print("IZQ");  
  }else{
    if(value == 2){
      client.print("OFF");
    }
    else{
      client.println("DER");    
    }
  }
  client.println("<br><br>");
  
  //Girar el motor a la izquierda cuando el cliente solicite el vinculo del href
  client.println("<a href=\"/MOTOR=IZQ\"\"><button>Izquierda</button></a>");

  //Girar el motor a la izquierda cuando el cliente solicite el vinculo del href
  client.println("<a href=\"/MOTOR=OFF\"\"><button>Apagar</button></a>");
  
  //Girar el motor a la derecha cuando el cliente solicite el vinculo del href
  client.println("<a href=\"/MOTOR=DER\"\"><button>Derecha</button></a><br/>");
  
  //client.println("<p> valor analogico:"+String(a)+" </p>");
  client.println("</body>");
  client.println("</html>");

  delay(1);
  if(request.indexOf("/favicon") == -1) {
    Serial.println("Cliente desconectado\n");  
  }
}
