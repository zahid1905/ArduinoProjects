int pines [7] = {38,36,34,46,48,42,44};

int display1 = 24, display2 = 26;

int entrada = A1;

int display7 [16] [7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,0,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,1,0,1,1},//9
  {1,1,1,0,1,1,1},//A
  {0,0,1,1,1,1,1},//b
  {1,0,0,1,1,1,0},//C
  {0,1,1,1,1,0,1},//d
  {1,0,0,1,1,1,1},//E
  {1,0,0,0,1,1,1} //F
  };

void setup() {
  // put your setup code here, to run once:
  for (int z = 0; z < 7; z++){
    pinMode(pines[z], OUTPUT);
  }

  for (int z = 0; z < 7; z++){
    digitalWrite(pines[z], LOW);
  }

  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);

  pinMode(entrada, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int temperatura = analogRead(entrada);

  temperatura = (5.0 * temperatura * 100.0) / 1024.0;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  if (temperatura < 100){
  
    int arreglo[2];
    for (int i = 2; i >= 0; i--) {
      arreglo[i] = temperatura % 10;
      temperatura /= 10;
    }
    
    for (int contador = 0; contador <= 50; contador ++){
      digitalWrite(display1, HIGH);
      digitalWrite(display2, LOW);
      for (int y = 0; y < 7; y++){
        digitalWrite(pines[y], display7[arreglo[1]][y]);
      }
      delay(10);
      digitalWrite(display1, LOW);
      digitalWrite(display2, HIGH);
      for (int y = 0; y < 7; y++){
        digitalWrite(pines[y], display7[arreglo[2]][y]);
      }
      delay(10);
    }
  }
}
