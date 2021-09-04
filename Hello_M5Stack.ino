#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:
  M5.begin(true, false, true);
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.Lcd.setCursor(0, 200);
  M5.Lcd.println("Hello M5Stack!");
  delay(1000);
  M5.Lcd.clear(BLACK);
  delay(1000);
}
