int pines [7] = {38,36,34,46,48,42,44};


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
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x < 16; x++){
    for (int y = 0; y < 7; y++){
      digitalWrite(pines[y], display7[x][y]);
    }
    delay(1000);
  }
}
