#include<LiquidCrystal.h>
const int LED1 = 10;
const int LED2 = 9;
const int LED3 = 8;
const int RS = 12;
const int E = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

int analogIn = A5;
int analogValue = 0;

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  lcd.begin(16,2);
  lcd.print("Analog Value:");

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);

  pinMode(analogIn, INPUT);
}

void loop() {
  lcd.setCursor(0, 1);
  analogValue = analogRead(analogIn);
  lcd.print(analogValue);
  if(analogValue > 500){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
  }
  else if(analogValue>= 100 && analogValue <= 500){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
  }
  else{
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    
  }
  delay(100);
  
}
  
