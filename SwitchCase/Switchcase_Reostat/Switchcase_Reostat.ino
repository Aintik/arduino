int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT_PULLUP);
}
//map что это, как 7 сделать
void loop() {
if(digitalRead(13)==0){
  a++;
  Serial.println(a);
  delay(1000);
  }
switch(a){
  case 1:{Serial.println(analogRead(1));break;} //можно без скобок?
  case 2:{Serial.println(analogRead(2));break;}
  default:{a=0;}
  }}
