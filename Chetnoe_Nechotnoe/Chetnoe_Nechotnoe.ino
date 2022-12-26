void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
  int c= Serial.parseInt();
  int a= c%2;
  if(a==1)
    Serial.println("Вы ввели нечетное число");
  if(a==0)
    Serial.println("Вы ввели четное число");
  
}}
