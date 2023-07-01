#include <SoftwareSerial.h>
SoftwareSerial noel(10, 11); 

#define echo 8
#define trig 9
#define line1 6
#define line2 7
#define enable 3
#define m1i 4
#define m1d 12
#define m2i 2
#define m2d A2
#define led A6
#define buzzer A4

int datos = 0, datos2 = 0;
double dis, dur;

void setup() {
  Serial.begin(9600);
  noel.begin(9600);
  
  pinMode(line1, INPUT);
  pinMode(line2, INPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(m1i, OUTPUT);  
  pinMode(m1d, OUTPUT);
  pinMode(m2i, OUTPUT);
  pinMode(m2d, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (noel.available() > 0) {
    datos = noel.read();
  }
 if((datos >= 48 && datos <= 57) || datos == 113){
    if(datos != 113){
    datos2 = map(datos, 48, 57, 0, 240);
    }
    else{
      datos2 = 255;
    }
    analogWrite(enable,datos2);
 }
  else if (datos == 70) { //adelante
    digitalWrite(m1i, HIGH);
    digitalWrite(m1d, LOW);
    digitalWrite(m2i, HIGH);
    digitalWrite(m2d, LOW);
  }
  else if (datos == 66) { //atras
    digitalWrite(m1i, LOW);
    digitalWrite(m1d, HIGH);
    digitalWrite(m2i, LOW);
    digitalWrite(m2d, HIGH);
  }
  else if (datos == 82) { //dere
    digitalWrite(m1i, HIGH);
    digitalWrite(m1d, LOW);
    digitalWrite(m2i, LOW);
    digitalWrite(m2d, HIGH);
  }
  else if (datos == 76) { //izq
    digitalWrite(m1i, LOW);
    digitalWrite(m1d, HIGH);
    digitalWrite(m2i, HIGH);
    digitalWrite(m2d, LOW);
  }
  else if (datos == 83) {
    digitalWrite(m1i, LOW);
    digitalWrite(m1d, LOW);
    digitalWrite(m2i, LOW);
    digitalWrite(m2d, LOW);
  }
//  else if (datos == 'U') {
//
//    while (noel.read() != 'N') {
//      digitalWrite(led, HIGH);
//      analogWrite(enable, 100);
//      digitalWrite(trig, LOW);
//      delayMicroseconds(2);
//      digitalWrite(trig, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(trig, LOW);
//      du = pulseIn(echo, HIGH);
//      dis = dur1 * 0.017;
//      if (digitalRead(6) == 1 || (digitalRead(7) == 1) {
//      digitalWrite(m1i, LOW);
//        digitalWrite(m1d, HIGH);
//        digitalWrite(m2i, LOW);
//        digitalWrite(m2d, HIGH);
//        delay(500);
//        digitalWrite(m1i, HIGH);
//        digitalWrite(m1d, LOW);
//        digitalWrite(m2i, LOW);
//        digitalWrite(m2d, HIGH);
//        delay(500);
//      }
//      else if (dis <= 5.0) {
//      tone(buzzer, 1000);
//        analogWrite(enable, 255);
//        digitalWrite(m1i, HIGH);
//        digitalWrite(m1d, LOW);
//        digitalWrite(m2i, HIGH);
//        digitalWrite(m2d, LOW);
//      }
//      else {
//        noTone(buzzer);
//        digitalWrite(m1i, HIGH);
//        digitalWrite(m1d, LOW);
//        digitalWrite(m2i, HIGH);
//        digitalWrite(m2d, LOW);
//      }
//    }
//    digitalWrite(led, LOW);
//  }
}
