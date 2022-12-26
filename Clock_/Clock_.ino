unsigned long t = 0;
int a = 0; //секунды
int b = 0; //минуты
int c = 0; //часы
void setup() {
  Serial.begin(9600);
}

void loop() {
  serialTime();

//  timer_used();
}

void timer(int hour, int minut, int sec, bool state, int pin) { //создаем функцию с праметрами
  pinMode(pin, OUTPUT); //нстраеваем пин
  if (a == sec  and b == minut and c == hour and state) { //берем значения с функции serialTime и если они совподают с нашими значениями то...
    digitalWrite(pin, 1); //включем светодиот
  }
  if (a == sec and b == minut and c == hour and !state) { //а если state равен 0 то...
    digitalWrite(pin, 0); //выключаем светодиот
  }
}

void timer_used() {
  timer(0, 0, 1, 1, 13); //при 0:0:1 включаем светодиот на 13 пине
  timer(0, 0, 2, 1, 12); //при 0:0:2 включаем светодиот на 12 пине
  timer(0, 0, 3, 1, 11); //при 0:0:3 включаем светодиот на 11 пине
  timer(0, 0, 4, 1, 10); //при 0:0:4 включаем светодиот на 10 пине
  timer(0, 0, 5, 1, 9); //при 0:0:5 включаем светодиот на 9 пине

  timer(0, 0, 6, 0, 13); //при 0:0:6 выключаем светодиот на 13 пине
  timer(0, 0, 7, 0, 12); //при 0:0:7 выключаем светодиот на 12 пине
  timer(0, 0, 8, 0, 11); //при 0:0:8 выключаем светодиот на 11 пине
  timer(0, 0, 9, 0, 10); //при 0:0:9 выключаем светодиот на 10 пине
  timer(0, 1, 10, 0, 9); //при 0:0:10 выключаем светодиот на 9 пине
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
