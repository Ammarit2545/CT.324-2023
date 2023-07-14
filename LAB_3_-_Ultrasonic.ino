#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address (0x27) to match your LCD

const int pingPin = 13;
int inPin = 12;

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with the desired columns and rows
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD1602 I2C Test");
  delay(2000);

  Serial.begin(115200);
}

void loop() {
  float duration, cm;

  pinMode(pingPin, OUTPUT);

  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  lcd.setCursor(0, 1); // Set the cursor to the beginning of the second row
  lcd.print("                "); // Clear the previous content on the second row
  lcd.setCursor(0, 0);
  lcd.print(cm);
  lcd.print(" cm");
  Serial.println();
  delay(100);
}

float microsecondsToCentimeters(float microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
