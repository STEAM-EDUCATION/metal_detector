#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

const int soundSensorPin = A0;
const int coilPin = A1;
const int ledPin = 7;
const int buzzerPin = 8;

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(coilPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Metal Detector");
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  int coilValue = analogRead(coilPin);

  Serial.print("Sound Value: ");
  Serial.print(soundValue);
  Serial.print("\tCoil Value: ");
  Serial.println(coilValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Metal Detector");

  if (soundValue > 500) {  // Threshold for detecting a sound
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Metal Detected!");

    // Determine metal type based on sound value (example logic)
    if (soundValue > 500 && soundValue < 600) {
      lcd.setCursor(0, 1);
      lcd.print("Type: Iron");
    } else if (soundValue >= 600 && soundValue < 700) {
      lcd.setCursor(0, 1);
      lcd.print("Type: Copper");
    } else if (soundValue >= 700) {
      lcd.setCursor(0, 1);
      lcd.print("Type: Aluminum");
    }
    
    digitalWrite(buzzerPin, HIGH);  // Turn on active buzzer
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);  // Turn off active buzzer
  }

  delay(100);
}
