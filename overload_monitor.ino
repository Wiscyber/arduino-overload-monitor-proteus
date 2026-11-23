#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int SENSOR_PIN = A0;
const int RELAY_PIN = 13;
const float OVERLOAD_LIMIT = 20.0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("I2C LCD MONITOR");
  lcd.setCursor(0, 1);
  lcd.print("BUS READY: I2C ");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawADC = analogRead(SENSOR_PIN);
  float current = ((float)rawADC / 1023.0) * 30.0;

  lcd.setCursor(0, 0);
  lcd.print("LOAD: ");
  lcd.print(current, 1);
  lcd.print(" A    ");

  lcd.setCursor(0, 1);
  if (current >= OVERLOAD_LIMIT) {
    digitalWrite(RELAY_PIN, HIGH);
    lcd.print("STATUS: OVERLOAD");
    Serial.println("STATUS: OVERLOAD DETECTED");
  } else {
    digitalWrite(RELAY_PIN, LOW);
    lcd.print("STATUS: NORMAL  ");
    Serial.println("STATUS: NORMAL OPERATION");
  }

  delay(500);
}
