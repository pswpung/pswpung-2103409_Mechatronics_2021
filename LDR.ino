#include <M5Stack.h>

// Declare Global Variable
int LDR_input_Analog = 15; 
int LDR_input_Digital = 2;
int sensor_value_Analog = 0;
int sensor_value_Digital = 0;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setBrightness(128);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  
  sensor_value_Analog = analogRead(LDR_input_Analog);
  Serial.print("Analog : ");
  Serial.println(sensor_value_Analog);
  M5.Lcd.print("Analog : ");
  M5.Lcd.println(sensor_value_Analog);

  sensor_value_Digital = digitalRead(LDR_input_Digital);
  Serial.print("Digital : ");
  Serial.println(sensor_value_Digital);
  M5.Lcd.print("Digital : ");
  M5.Lcd.println(sensor_value_Digital);
  
//  M5.update();
  delay(1000);
}
