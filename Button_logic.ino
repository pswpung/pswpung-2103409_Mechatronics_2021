#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.setBrightness(128);
  M5.Lcd.setTextSize(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(CYAN, BLACK);
  
//  M5.Lcd.println("read()");
//  M5.Lcd.printf(" Read BtnA = %d \r\n", M5.BtnA.read());
//  M5.Lcd.printf(" Read BtnB = %d \n", M5.BtnB.read());
//  M5.Lcd.printf(" Read BtnC = %d \r\n", M5.BtnC.read());
  
//  M5.Lcd.println("isPressed()");
//  M5.Lcd.printf(" IsPressed BtnA = %d \r\n", M5.BtnA.isPressed());
//  M5.Lcd.printf(" IsPressed BtnB = %d \n", M5.BtnB.isPressed());
//  M5.Lcd.printf(" IsPressed BtnC = %d \r\n", M5.BtnC.isPressed());
 
//  M5.Lcd.println("isReleased()");
//  M5.Lcd.printf(" IsReleased BtnA = %d \r\n", M5.BtnA.isReleased());
//  M5.Lcd.printf(" IsReleased BtnB = %d \n", M5.BtnB.isReleased());
//  M5.Lcd.printf(" IsReleased BtnC = %d \r\n", M5.BtnC.isReleased());

//  M5.Lcd.println("wasPressed()");
//  M5.Lcd.printf(" IsPressed BtnA = %d \r\n", M5.BtnA.wasPressed());
//  M5.Lcd.printf(" IsPressed BtnB = %d \n", M5.BtnB.wasPressed());
//  M5.Lcd.printf(" IsPressed BtnC = %d \r\n", M5.BtnC.wasPressed());
//
//  M5.Lcd.println("wasReleased()");
//  M5.Lcd.printf(" IsReleased BtnA = %d \r\n", M5.BtnA.wasReleased());
//  M5.Lcd.printf(" IsReleased BtnB = %d \n", M5.BtnB.wasReleased());
//  M5.Lcd.printf(" IsReleased BtnC = %d \r\n", M5.BtnC.wasReleased());

  M5.Lcd.println("pressedFor(ms)");
  M5.Lcd.printf(" IsPressed BtnA = %d \r\n", M5.BtnA.pressedFor(1000));
  M5.Lcd.printf(" IsPressed BtnB = %d \n", M5.BtnB.pressedFor(1000));
  M5.Lcd.printf(" IsPressed BtnC = %d \r\n", M5.BtnC.pressedFor(1000));

  M5.Lcd.println("releasedFor(ms)");
  M5.Lcd.printf(" IsPressed BtnA = %d \r\n", M5.BtnA.releasedFor(1000));
  M5.Lcd.printf(" IsPressed BtnB = %d \n", M5.BtnB.releasedFor(1000));
  M5.Lcd.printf(" IsPressed BtnC = %d \r\n", M5.BtnC.releasedFor(1000));

  M5.Lcd.println("lastChange()");
  M5.Lcd.printf(" IsPressed BtnA = %d \r\n", M5.BtnA.lastChange());
  M5.Lcd.printf(" IsPressed BtnB = %d \n", M5.BtnB.lastChange());
  M5.Lcd.printf(" IsPressed BtnC = %d \r\n", M5.BtnC.lastChange()); 

  M5.update();
}
