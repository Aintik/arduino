void setup() {
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 for(int a=0; a<256; a++){
   analogWrite(11, a);
   delay(5);
 }
  for(int a=256; a>0; a--){
   analogWrite(11, a); delay(5);
 }
}
