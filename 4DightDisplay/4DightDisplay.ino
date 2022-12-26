#include <TM1637.h>
int CLK = 2; //pin CLK
int DIO = 3; //pin DIO
TM1637 tm(CLK, DIO);

int a;
int b;
int c;
int y;
unsigned long t;

void setup() {
  tm.init();
  tm.set(2); //set brightness 0-7
  Serial.begin(9600);
}

void loop() {
  /*
    //example 12:ab
    //tm.display(position, character);

    tm.display(0,1);
    tm.display(1,2);
    tm.point(1);
    tm.display(2,10);
    tm.display(3,11); //10-15
  */
  serialTime();
  seconds();
  tm.point(1);
  minute();
}

void serialTime() {
  if (millis() - t >= 1000) { //секунды
    t = millis();
    a++;
  }

  if (a == 60) { //минуты
    b++;
    a = 0;
  }
  if (b == 60) { //часы
    c++;
    b = 0;
  }

  if (c == 24) { //часы
    c = 0;
  }
  if (a > y) {
    Serial.print(c);
    Serial.print(":");
    Serial.print(b);
    Serial.print(":");
    Serial.println(a);
    y = a;
  }
}

void minute() {
  int n = b / 10;
  int v = n * 10;
  tm.display(0, n);
  delay(1);
  tm.display(1, b - v);
  delay(1);
}

void seconds() {
  int n = a / 10;
  int v = n * 10;
  tm.display(2, n);
  delay(1);
  tm.display(3, a - v);
  delay(1);
}
