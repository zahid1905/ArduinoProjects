#include <Servo.h>



void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(8); 

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = 0;

  servoMotor.write(0);
  
  for (x = 0; x <= 180; x++){
    servoMotor.write(x);
    delay (50);
  }
  for (x = 180; x >= 0; x--){
    servoMotor.write(x);
    delay (50);
  }
  //servoMotor.write(0);
  /*
  delay(1000);
  servoMotor.write(90);
  delay(1000);
  servoMotor.write(180);
  delay(1000);*/

}
