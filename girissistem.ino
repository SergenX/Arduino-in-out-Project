#include <NewPing.h>
int Buzzer = 5;
//ışık sistemi isteyen arkadaşlarım ekleyebilir uyumlu çalışır.
#define Triggerpin 3
#define echopin 4
#define maxd 400
NewPing mesafesens(Triggerpin,echopin,maxd);
float duration, giris;
void setup() {
Serial.begin(9600);
pinMode(Buzzer,OUTPUT);
Serial.println("Serial and Setup Complete");
Serial.println("Tus Kombinasyonları?");
Serial.println("[0] Eger Giren Kisi Sayisini Sifirlamak Istiyorsaniz.");
Serial.println("[1] Evinizde Yabanci Giris Var Ise");
buzzersistemi(1,0,0);
}
int girdi = 0;
void loop() {
  giris = mesafesens.ping_cm();
  if(giris <= 10) {
    buzzersistemi(1,0,1);
    Serial.println("Mesafe Sensörü Yeni Giriş Algıladı Siz Değilseniz Lütfen 1 i Tuslayiniz.");  
    delay(1000);
    girildi();
    } 
if(Serial.available()) {
 char komut = Serial.read();  
 if(komut = '0'){
  buzzersistemi(1,0,0);
  sifirla();
  Serial.println("Girilen Kisi Sayisi Basariyla Sifirlandi!");
  delay(1000);
  }
   if(komut = '1'){
    Serial.println("Kamera Aciliyor!"); //Yapmak isteyen malzemesi olan arkadaslarım olursa yapabilir.
    Serial.println("Kamera IP:");
    Serial.print("000.000.00");
    Serial.println("Alarm Devreye Giriyor");
    Serial.println("Acil Durum Cagrisi Yapiliyor.."); //arama sistemi eklemek isteyen ekleyebilir ve daha profesyonel yapabilir.

    for(long i = 0 ; i<9999999 ; i++) {
      digitalWrite(Buzzer,HIGH);
      delay(50);
      }
    }
  }
 }
void sifirla() {
girdi = 0;
}
void girildi() {

   girdi++;
   Serial.print("Giren Kisi Sayisi = ");
   Serial.print(girdi);
   Serial.println(".");
}
float buzzersistemi(float bir ,float iki ,float uc) {
if(bir == 1){
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW);  
}  
if(iki == 1){
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW); 
delay(70);
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW);  
}
if(uc == 1){
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW); 
delay(70);
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW);
delay(70);
digitalWrite(Buzzer,HIGH);  
delay(70);
digitalWrite(Buzzer,LOW);  
}
}
