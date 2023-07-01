int boton = 47;
int motor1 = 49;
int motor2 = 51;
int activarMotor = 53;

void setup() {
  // put your setup code here, to run once:
  pinMode(boton, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(activarMotor, OUTPUT);

  digitalWrite(activarMotor, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(boton) == HIGH){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
  }
  else{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }

}
