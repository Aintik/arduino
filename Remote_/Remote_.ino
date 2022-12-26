#include "IRremote.h"

IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
decode_results results;
unsigned long a;

void setup() {
  set;
}

void loop() {
  recieve();
  
  if( result(16769055) ){
    led(42, 1);
    delay(10);}
  else{
    led(42, 0);
    delay(10);
  }
}

void led(int pin, int state) {
  pinMode(pin, OUTPUT);
  if (state) {
    digitalWrite(pin, 1);
  }
  if (!state) {
    digitalWrite(pin, 0);
  }
}

void set() {
  Serial.begin(9600); // выставляем скорость COM порта
  irrecv.enableIRIn(); // запускаем прием
}

void recieve() {
  if ( irrecv.decode( &results )) { // если данные пришли
    Serial.println( results.value); // печатаем данные
    irrecv.resume(); // принимаем следующую команду
    a = results.value;
    Serial.println(a );
  }
}

bool result(unsigned long b) {
  if (results.value == b) {
    return true;
  }
  if (!(results.value == b)) {
    return false;
  }
}
