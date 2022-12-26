
unsigned long t ;
int a ; //секунды
int b ; //минуты
int c ; //часы

#define D1 13
#define D2 12
#define D3 11
#define D4 10
#define A 9
#define B 8
#define C 7
#define D 6
#define E 5
#define F 4
#define G 3

void setup() {
  Serial.begin(9600);
}

void loop() {
  //serialTime();
 // timer(1);
}

void minute(){
  int n = b / 10;
  int v = n * 10;
  d3(n);
  delay(1);
  d4(b - v);
  delay(1);
}

void timer(int q) {

  if (q<10 and q >= 0) {
    d1(q);
  }
  if (q > 9 and q < 100) {
    int n = q / 10;
    int v = n * 10;
    d1(n);
    delay(1);
    d2(q - v);
    delay(1);
  }
  if (q > 99) {
    int k = q / 100;
    int w = k * 100;
    int p = (q - w) / 10;
    d1(k);
    delay(1);
    d2(p);
    delay(1);
    d3((q - (p * 10)) - w);
    delay(1);
  }
  if (q > 999 and q < 10000) {
    int r = q / 1000;
    int k = r * 1000;
    int w = (q - k) / 100;
    int p = w * 100;
    int o = k + p + ((((q - p) - k) / 10) * 10);

    d1(r);
    delay(1);
    d2(w);
    delay(1);
    d3(((q - p) - k) / 10);
    delay(1);
    d4(q - o);
  }
  else {
    eror();
  }
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

  Serial.print(c);
  Serial.print(":");
  Serial.print(b);
  Serial.print(":");
  Serial.println(a);
}

void d1(int z) {
  pinMode(D1, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(D1, 1);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  digitalWrite(D4, 0);
  num(z);
}

void d2(int z2) {
  pinMode(D2, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(D2, 1);
  digitalWrite(D1, 0);
  digitalWrite(D3, 0);
  digitalWrite(D4, 0);
  num(z2);
}

void d3(int mi) {
  pinMode(D3, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(D3, 1);
  digitalWrite(D2, 0);
  digitalWrite(D1, 0);
  digitalWrite(D4, 0);
  num(mi);
}

void d4(int h) {
  pinMode(D4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(D4, 1);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  digitalWrite(D1, 0);
  num(h);
}

void num(int s) {
  if (s == 1) {
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
  }
  if (s == 2) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
    digitalWrite(E, 1);
    digitalWrite(D, 1);
  }
  if (s == 3) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(F, 0);
    digitalWrite(E, 0);
    digitalWrite(G, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
  }
  if (s == 4) {
    digitalWrite(A, 0);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(B, 1);
    digitalWrite(G, 1);
    digitalWrite(C, 1);
  }
  if (s == 5) {
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
  }
  if (s == 6) {
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(F, 1);
    digitalWrite(E, 1);
    digitalWrite(D, 1);
    digitalWrite(C, 1);
    digitalWrite(G, 1);
  }
  if (s == 7) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
  }
  if (s == 8) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
  }
  if (s == 9) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
  }
  if (s == 0) {
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 0);
  }
}

void eror() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  digitalWrite(D1, 1);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  digitalWrite(D4, 0);
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);

  delay(5);

  digitalWrite(D1, 0);
  digitalWrite(D2, 1);
  digitalWrite(D3, 0);
  digitalWrite(D4, 0);
  digitalWrite(A, 1);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);

  delay(5);

  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3, 1);
  digitalWrite(D4, 0);
  digitalWrite(A, 1);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 0);

  delay(5);

  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  digitalWrite(D4, 1);
  digitalWrite(A, 1);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}
