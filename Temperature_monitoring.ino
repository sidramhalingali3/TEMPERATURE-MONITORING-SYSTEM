#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LM35 connected to A0
const int tempPin = A0;

void setup() {
  lcd.begin(16, 2); // 16x2 LCD
  lcd.print("Temp Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(tempPin);
  float voltage = (rawValue / 1023.0) * 5.0;
  float temperatureC = voltage * 100.0; // For LM35

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print((char)223); // degree symbol
  lcd.print("C");

  delay(1000); // update every 1 second
}
