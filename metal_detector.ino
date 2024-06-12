#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int soundSensorPin = A0;
const int ledPin = 7;
const int buzzerPin = 8;

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Metal Detector");
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Metal Detector");

  if (soundValue > 500) {  // Threshold for detecting a sound
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Metal Detected!");

    // Determine metal type based on sound value (example logic)
    if (soundValue > 500 && soundValue < 600) {
      lcd.setCursor(0, 2);
      lcd.print("Type: Iron");
    } else if (soundValue >= 600 && soundValue < 700) {
      lcd.setCursor(0, 2);
      lcd.print("Type: Copper");
    } else if (soundValue >= 700) {
      lcd.setCursor(0, 2);
      lcd.print("Type: Aluminum");
    }
   
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
