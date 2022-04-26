// LCD-näyttö
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Muuttujat
int sPin = A0;      //Äänimodulin pinni
int analog = 0;    //Äänimodulilta luettu arvo
int baseline;           //Taustamelu-muuttuja

//LEDIT
int pPin = 7;    //Ledin pinni

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);             
  pinMode(sPin, INPUT);         //Äänimodulin pinni inputiksi
  baseline = analogRead(sPin);  //Taustamelu

  pinMode(pPin, OUTPUT);
}

void loop() {
  
  analog = abs(analogRead(sPin) - baseline); 
  Serial.println(analog);
  lcd.print("Taso: ");

  if (analog < 3){
    lcd.print("Normaali");
    lcd.setCursor(0,1);
    lcd.print("Noin 39 dB");
  }

  if (analog >= 3 && analog<= 6){
    lcd.print("Kova");
    lcd.setCursor(0,1);
    lcd.print("Noin 57 dB");
  }

  if (analog >7){
    lcd.clear();
    lcd.print("Suojatkaa");
    lcd.setCursor(0,1);
    lcd.print("kuulonne!");
    digitalWrite(pPin, HIGH);
  }

  else{
    digitalWrite(pPin, LOW);
  }

delay(300);
lcd.clear();

}
//eof
