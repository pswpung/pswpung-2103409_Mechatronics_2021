#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.lcd.setBrightness(128);
  M5.Lcd.setTextSize(3);
  M5.Speaker.setBeep(250, 100);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("Connected");  
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(CYAN, BLACK);
  M5.Lcd.print("\r\n Pressed Btn = ");
  if(M5.BtnA.pressedFor(2000)){
      M5.Lcd.printf("A");
      Serial.println("A");
    }    
  if(M5.BtnB.pressedFor(2000)){
      M5.Lcd.printf("B");
      Serial.println("B");
      M5.Speaker.beep();
    }
    
  if(M5.BtnC.pressedFor(2000)){
      M5.Lcd.printf("C");
      Serial.println("C");
      M5.Speaker.tone(762, 100);
    }
    
  M5.update();
}
