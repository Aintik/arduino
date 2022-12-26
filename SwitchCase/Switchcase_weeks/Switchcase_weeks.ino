int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT_PULLUP);
}

void loop() {
if(digitalRead(13)==0){
  a++;
  Serial.println(a);
  delay(1000);
  }
switch(a){
  case 1:{Serial.println("Monday");break;} //можно без скобок?
  case 2:{Serial.println("Tuesday");break;}
  case 3:{Serial.println("Wednesday");break;}
  case 4:{Serial.println("Thursday");break;}
  case 5:{Serial.println("Friday");break;}
  case 6:{Serial.println("Saturday");break;}
  case 7:{Serial.println("Sunday");break;}
  default:{a=0;}
  }}
