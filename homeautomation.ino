int lamba1 =2;
int lamba2 =3;
int lamba3 =4;
int fan    =5;
int motor  =6;
int buzzer =7;
int ldr    =A0;
int yangin =A1;
int tnem    =A2;
int nemdeger;
int yangindeger;
int deger;

unsigned long sonzaman = 0;
unsigned long sonzaman2 = 0;
#include <Servo.h>
#include <dht11.h> 
#define DHT11PIN 13 
Servo kapi;
Servo penc;
dht11 DHT11;

void setup() {

Serial.begin(9600);
kapi.attach(11);
penc.attach(12);
kapi.write(40);
pinMode(lamba1,OUTPUT);
pinMode(lamba2,OUTPUT);
pinMode(lamba3,OUTPUT);
pinMode(motor,OUTPUT);
pinMode(fan,OUTPUT);
pinMode(buzzer,OUTPUT);

}



void loop() {
  if(millis()-sonzaman > 2500){
    
  
    int chk = DHT11.read(DHT11PIN);
 deger=analogRead(ldr);
 deger=deger / 10.23;
 yangindeger=analogRead(yangin);
 nemdeger =analogRead(tnem);
 nemdeger = nemdeger / 10.23;
  Serial.print("Sıcaklık = ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.print(" °\n");
  Serial.print("Nem =");
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(" %\n");
  Serial.print("Aydınlık = ");
  Serial.print(deger); 
  Serial.print("%\n");
  Serial.print("Toprak Nemi = ");
  Serial.print(nemdeger);
  Serial.print(" %\n");
  if(yangindeger >100){
    Serial.print("YANGIN!!!");
    digitalWrite(buzzer,HIGH);
    }
  if (yangindeger <99){
    Serial.print("_____ ");
    digitalWrite(buzzer,LOW);
    }
    sonzaman= millis();  
  }
  if(millis()-sonzaman2 > 101){
    kontrol(); 
    sonzaman2= millis();  
  }
}

void kontrol(){

 if(Serial.available()>0){
    char GelenVeri = (char)Serial.read();

    if(GelenVeri =='a'){
      digitalWrite(lamba1,HIGH);
    }
    if(GelenVeri == 'b'){
      digitalWrite(lamba1,LOW);
    }
     if(GelenVeri == 'c'){
      digitalWrite(lamba2,HIGH);
    }
     if(GelenVeri == 'd'){
      digitalWrite(lamba2,LOW);
    }
    if(GelenVeri == 'e'){
      digitalWrite(lamba3,HIGH);
    }
    if(GelenVeri == 'f'){
      digitalWrite(lamba3,LOW);
    }
    if(GelenVeri == 'g'){
      digitalWrite(fan,HIGH);
    }
    if(GelenVeri == 'h'){
      digitalWrite(fan,LOW);
    }
    if(GelenVeri == 't'){
    kapi.write(180); 
   delay(100); 
   }
  if(GelenVeri == 'v') {
    kapi.write(40);
  delay(100);
  }
  if(GelenVeri == 'y') {
    penc.write(0);
   delay(100);  
  }
  if(GelenVeri == 'x') {
    penc.write(70);
    delay(100);
  }
  if(GelenVeri == 'm'){
    digitalWrite(motor,HIGH);
  }
  if(GelenVeri == 'n') {
    digitalWrite(motor,LOW);
  }
  }
 }
