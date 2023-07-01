float distancia = 0;
float tiempo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(D2, INPUT); //Pin rebote
  pinMode(D1, OUTPUT); //Pin pulso
  pinMode(D3, OUTPUT); //Led

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(D1, LOW); //Reiniciar estado
  delayMicroseconds(5);
  digitalWrite(D1, HIGH); //Enviar pulso
  delayMicroseconds(10);
  
  tiempo = pulseIn(D2, HIGH); //Medir el tiempo que tarda en regresar el pulso

  distancia = 0.01715*tiempo; //Convertirlo a CM

  if (distancia <= 15.00){
    digitalWrite(D3, HIGH);
  }
  else{
    digitalWrite(D3, LOW);
  }

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println();
  delay (2000);
}
