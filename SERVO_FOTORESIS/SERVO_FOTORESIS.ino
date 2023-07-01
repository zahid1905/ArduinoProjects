#include <Servo.h>

Servo servoMotor;

int cero = A2;
int noventa = A1;
int cienochenta = A0;
int servo = 8;

int vcero = 0;
int vnoventa = 0;
int vcienochenta = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(cero, INPUT);
  pinMode(noventa,INPUT);
  pinMode(cienochenta,INPUT);
  servoMotor.attach(8);
  servoMotor.write(90);
  Serial.begin(9600);
}

void loop() {
  vcero = analogRead(cero);
  vnoventa = analogRead(noventa);
  vcienochenta = analogRead(cienochenta);

  Serial.print(vcero);
  Serial.print(" ");
  Serial.print(vnoventa);
  Serial.print(" ");
  Serial.print(vcienochenta);
  Serial.println();

  if (vcero > vnoventa && vcero > vcienochenta){
    servoMotor.write(0);
  }
  else{
    if (vnoventa > vcero && vnoventa > vcienochenta){
      servoMotor.write(90);
    }
    else{
      servoMotor.write(180);
    }
  }
  delay(1000);
}
