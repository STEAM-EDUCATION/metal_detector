#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int soundSensorPin = A0;
const int ledPin = 7;
const int buzzerPin = 8;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the I2C address (0x27) as needed

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
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
      lcd.setCursor(0, 1);  // 1 instead of 2 because 16x2 LCD has only 2 rows
      lcd.print("Type: Iron");
    } else if (soundValue >= 600 && soundValue < 700) {
      lcd.setCursor(0, 1);  // 1 instead of 2 because 16x2 LCD has only 2 rows
      lcd.print("Type: Copper");
    } else if (soundValue >= 700) {
      lcd.setCursor(0, 1);  // 1 instead of 2 because 16x2 LCD has only 2 rows
      lcd.print("Type: Aluminum");
    }
   
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}
