#include "LedControlMS.h"

LedControl matriz = LedControl(12,11,10,1);

int up = 52;
int down = 53;

int filaFlapy = 3;

int tuberia4[] = {3,6,2,4,5,3,1,3,5};

void setup() {
  // put your setup code here, to run once:
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8);
  matriz.clearDisplay(0);

  pinMode(up, INPUT);
  pinMode(down, INPUT);

  Serial.begin(9600);
  
  matriz.setLed(0, 1, filaFlapy, true);
}

void loop() {
  // put your main code here, to run repeatedly:  
  //matriz.setLed(0, 7, tuberia4, true);}
  //Generar tuberia

  int num = random(1,5);

  Serial.println(num);

  matriz.setLed(0, 1, filaFlapy, true);
  
  for (int col = 7; col >= -1; col--){
    
    //Mover el bird
    if (digitalRead(up) == true){
      matriz.setLed(0, 1, filaFlapy, false);
      filaFlapy ++;
      matriz.setLed(0, 1, filaFlapy, true);    
    }
    if (digitalRead(down) == true){
      matriz.setLed(0, 1, filaFlapy, false);
      filaFlapy --;
      matriz.setLed(0, 1, filaFlapy, true);
    }
    //Fin Mover el bird

    //Generar tuberia 1
    for (int i1=0; i1 <= num; i1++){
      matriz.setLed(0, col, i1, true);
      matriz.setLed(0, col+1, i1, false);
    }
    for (int i=7; i > (num+1); i--){
      matriz.setLed(0, col, i, true);
      matriz.setLed(0, col+1, i, false);
    }

    if (col == 1){
      if (filaFlapy == num || filaFlapy == num-1 || filaFlapy == num+2 || filaFlapy == num+3 || filaFlapy == num-2 || filaFlapy == num+4){
        matriz.clearDisplay(0);
        matriz.writeString(0, "X");
        matriz.clearDisplay(0);
      break;
      }
    }
    //Fin Generar tuberia 1
    
    delay(200);
  }


}
