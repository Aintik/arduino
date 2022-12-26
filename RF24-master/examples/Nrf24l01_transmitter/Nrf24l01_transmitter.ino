#include <SPI.h>                        // Подключаем библиотеку SPI
#include <nRF24L01.h>                   // Подключаем библиотеку nRF24L01 
#include <RF24.h>                       // Подключаем библиотеку RF24 
 
int data;                            // Создаём массив для приёма данных
RF24 radio(9,10);                       // Указываем номера выводов nRF24L01+ (CE, CSN)
int button = 6;                         // Создаем переменную button и указываем номер вывода
int button2 = 5;
 
void setup(void){
  pinMode(button, INPUT_PULLUP);    // Устанавливаем вывод 7 на вход
  pinMode(button2, INPUT_PULLUP);
  Serial.begin(9600);
  radio.begin();                        // Инициируем работу nRF24L01+
  radio.setChannel(100);                // Указываем канал передачи (от 0 до 126)
  radio.setDataRate (RF24_1MBPS);       // Указываем скорость передачи (250KBPS, 1MBPS, 2MBPS)
  radio.setPALevel(RF24_PA_HIGH);       // Указываем мощность передатчика (MIN=-18dBm, LOW=-12dBm, HIGH=-6dBm, MAX=0dBm)
  radio.openWritingPipe(0x0123456789LL);// Задаем идентификатором 0x0123456789LL для передачи данных данных 
 }
 
 
void loop(void)
{
  if (digitalRead(button) == 0){     // Считываем переменную "button", если HIGH идем дальше, если LOW зацикливаемся                     
  data = 1;                        // Записываем значение 123 в массив data
  radio.write(&data, 1);} // Отправляем данные из массива data
  if (digitalRead(button2) == 0){     // Считываем переменную "button", если HIGH идем дальше, если LOW зацикливаемся                     
  data = 2;                        // Записываем значение 123 в массив data
  radio.write(&data, 1);}
  Serial.println(data);
}
