int a=1;
void setup() {
  Serial.begin(9600);

}

void loop() {
  switch(a){
case 1:{Serial.println("January");
break;}
case 2:{Serial.println("Fabuary");break;}
case 3:{Serial.println("March");break;}
case 4:{Serial.println("April");break;}
case 5:{Serial.println("May");break;}
case 6:{Serial.println("June");break;}
case 7:{Serial.println("July");break;}
case 8:{Serial.println("August");break;}
case 9:{Serial.println("September");break;}
case 10:{Serial.println("Octomber");break;}
case 11:{Serial.println("November");break;}
case 12:{Serial.println("December");break;}

}
a++;
delay(1000);}
