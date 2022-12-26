
/*
  Тестирование производилось на Arduino IDE 1.6.11
  Дата тестирования 07.10.2016г.
*/
 
#include <SPI.h>                          // Подключаем библиотеку SPI
#include <nRF24L01.h>                     // Подключаем библиотеку nRF24L01 
#include <RF24.h>                         // Подключаем библиотеку RF24 
 
int data1;                              // Создаём массив для приёма данных
RF24 radio(9,10);                         // Указываем номера выводов nRF24L01+ (CE, CSN)
int LED = 3;                              // Создаем переменную SW1 и указываем номер вывода
int LED2 = 4; 
 
void setup(void){
  delay(1000);                            // Ждем 1с
  pinMode(LED,OUTPUT);                    // Устанавливаем вывод 3 на выход
  pinMode(LED2,OUTPUT);
  radio.begin();                          // Инициируем работу nRF24L01+
  radio.setChannel(100);                  // Указываем канал передачи (от 0 до 126)
  radio.setDataRate (RF24_1MBPS);         // Указываем скорость передачи (250KBPS, 1MBPS, 2MBPS)
  radio.setPALevel(RF24_PA_HIGH);         // Указываем мощность передатчика (MIN=-18dBm, LOW=-12dBm, HIGH=-6dBm, MAX=0dBm)
  radio.openReadingPipe(1,0x0123456789LL);// Задаем идентификатором 0x1234567890LL для передачи данных данных 
  radio.startListening  ();
  Serial.begin(9600);
}
 
void loop(void)
{
  if (radio.available()){                 // Если в буфере поступили данные
      radio.read(data1, 2);                // Считываем данные с массива data и задаем количество считываемых байт                
      if(data1 == 1){                 // Если в массиве data значение 123 
         digitalWrite(LED, HIGH);}        // Включаем светодиод
         delay(10);                       // Ждем 10мс
      if(data1 == 1){                 // Если в массиве data значение 123 
         digitalWrite(LED2, HIGH);}        // Включаем светодиод
         delay(10);  
   }
  else{                                   // Если в массиве data другое значение
      digitalWrite(LED, LOW);             // Выключаем светодиод
      digitalWrite(LED2, LOW); 
      delay(10);}                          // Ждем 10мс
    
}
