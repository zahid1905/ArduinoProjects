#include "LedControlMS.h"

LedControl matriz = LedControl(12,11,10,1);

void setup() {
  // put your setup code here, to run once:
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 8);
  matriz.clearDisplay(0);

}

void loop() { 
  
  matriz.clearDisplay(0);
  delay(500);
  matriz.writeString(0, "Hola mundo");
  delay(500);
//  for (int fila=0; fila<8; fila++){
//    for(int columna=0; columna<8; columna++){
//      matriz.setLed(0, columna-1, fila, true);
//      matriz.setLed(0, columna, fila, false);
//      delay(25);
//    }
//  }

}
