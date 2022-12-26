int a=0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a=analogRead(A0);
  Serial.println(analogRead(A0));
  if(a<100){
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);

    delay(200);
    digitalWrite(11,1);
    delay(200);
    digitalWrite(12,1);
    digitalWrite(10,1);
    delay(200);
    digitalWrite(13,1);
    digitalWrite(9,1);
    delay(200);
    
}
  if(a>100 and a<200){
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    
    digitalWrite(13,1);
    delay(200);
    digitalWrite(12,1);
    delay(200);
    digitalWrite(11,1);
    delay(200);
    digitalWrite(10,1);
    delay(200);
    digitalWrite(9,1);
    delay(200);    
}
  if(a>200){
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,0);
    digitalWrite(9,0);
    
    digitalWrite(13,1);
    digitalWrite(11,1);
    delay(200);
    digitalWrite(13,0);
    digitalWrite(11,0);
    delay(200);
    digitalWrite(11,1);
    digitalWrite(9,1);
    delay(200);
    digitalWrite(11,0);
    digitalWrite(9,0);
    delay(200);
    
}
  if(a<400){
//digitalWrite();
}
  if(a<500){
//digitalWrite();
}  
  if(a>500){
//digitalWrite(13,1);
}

}
