void setup() {

  }


void loop() {
  if(but(2)) {
    led(13, 1);
    delay(700);
    led(13, 0);
    delay(700);
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

bool but(int pin) {
  pinMode(pin, INPUT_PULLUP);
  if (digitalRead(pin) == 0) {
return true;
  }
    if (digitalRead(pin) == 1) {
return false;
  }
}
