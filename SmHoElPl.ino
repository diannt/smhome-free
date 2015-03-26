
#include <SoftwareSerial.h>   //Software Serial Port

#define RxD 6
#define TxD 7 
char incomingByte;  // входящие данные
String dataIn; 
int i,in,out,operation;
void setup() {
  Serial.begin(9600); // инициализация порта
  Serial.println("Hello");
  operation = 0;
  pinMode(3, OUTPUT);
  
  
}
int convert(String data )  {
  int n ;
  n = data[dataIn.indexOf("1")];
  if (!n>0)  
  n = data[dataIn.indexOf("0")];  
  return (n);
  
}

void loop() {
  if (Serial.available() > 0) {  //если пришли данные
    incomingByte = Serial.read(); // считываем байт
    dataIn = String(dataIn + incomingByte); // Формируем строку
  }
  // принимаем десятичное число, преобразуем к 
  switch ( operation )
     {        
       case  0: {
        Serial.write(" 1 -2 ; 2 - 16"); operation++; dataIn = ""; digitalWrite(3, LOW); //выключить лампочку
        break;
        };
       case  1: {if (dataIn.indexOf("1")>=0 | dataIn.indexOf("0")>=0 )
                 Serial.write("ok");
                 dataIn = "";
                 digitalWrite(3, HIGH);  //включить лампочку
                 in = convert(dataIn);
                 Serial.write("sadsdfdfsgd");
                 operation+=1;
                 break;
               };
    
     }   
}
