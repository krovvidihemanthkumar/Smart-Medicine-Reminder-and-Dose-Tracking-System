#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int ledPin = 8;
int buzzerPin = 13;
int buttonPin = 2;

int doseCount = 0;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Medicine");
  lcd.setCursor(0,1);
  lcd.print("Reminder");

  delay(3000);
}

void loop() {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Medicine Time!");
  lcd.setCursor(0,1);
  lcd.print("Take Tablet");

  digitalWrite(ledPin,HIGH);
  digitalWrite(buzzerPin,HIGH);

  unsigned long startTime = millis();

  while(millis()-startTime < 10000){

    if(digitalRead(buttonPin)==LOW){

      doseCount++;

      digitalWrite(ledPin,LOW);
      digitalWrite(buzzerPin,LOW);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Medicine Taken");
      lcd.setCursor(0,1);
      lcd.print("Dose:");
      lcd.print(doseCount);

      delay(3000);

      return;
    }
  }

  digitalWrite(ledPin,LOW);
  digitalWrite(buzzerPin,LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Missed Dose!");
  lcd.setCursor(0,1);
  lcd.print("Take Medicine");

  delay(5000);
}
