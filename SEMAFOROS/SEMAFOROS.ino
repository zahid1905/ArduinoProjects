void setup() {
  //Semaforo 1
  pinMode(53, OUTPUT);//Verde
  pinMode(51, OUTPUT);//Amarillo
  pinMode(48, OUTPUT);//Rojo

  //Semaforo 2
  pinMode(47, OUTPUT);//Verde
  pinMode(45, OUTPUT);//Amarillo
  pinMode(43, OUTPUT);//Rojo

  digitalWrite(53,LOW);
  digitalWrite(51,LOW);
  digitalWrite(48,LOW);
  digitalWrite(47,LOW);
  digitalWrite(45,LOW);
  digitalWrite(43,LOW);
 
}

void loop() {
  int contador1 = 0;
  int contador2 = 0;
  
  //4 segundos Verde 1

  digitalWrite(43, HIGH);
  digitalWrite(53, HIGH);
  delay(2000);
  digitalWrite(53, LOW);
  while (contador1 < 5){
    digitalWrite(51,HIGH);
    delay(200);
    digitalWrite(51, LOW);
    delay(200);
    contador1 ++;
  }
  digitalWrite(43, LOW);

  digitalWrite(48, HIGH);
  digitalWrite(47, HIGH);
  delay(2000);
  digitalWrite(47, LOW);
  while (contador2 < 5){
    digitalWrite(45,HIGH);
    delay(200);
    digitalWrite(45, LOW);
    delay(200);
    contador2 ++;
  }
  digitalWrite(48, LOW);

}
