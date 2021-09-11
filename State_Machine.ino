#include <M5Stack.h>

enum State {expired, countdown, ringing};
enum State mystate;
unsigned long mytime;

//timing
unsigned long T = 0;
const int t = 5000;

void setup() {
  mystate = expired;
//  M5.begin();
  Serial.begin(115200);
}

void loop() {
  mytime = millis();
 
  switch (mystate)
  {
    case expired:
      T = mytime;
      Serial.println("This is Expired.");
      if (M5.BtnA.read() == 1){
        Serial.printf("State : end of expired.");
        mystate = countdown;
      }
      break;
      
    case countdown:
      Serial.printf("State : countdown. %d\n", mytime - T);
      if (mytime - T > t){
        mystate = ringing;
      } 
      if (M5.BtnB.read() == 1){
        T = millis();
        mystate = countdown;
       }
      break;

     case ringing:
      Serial.printf("State : ringing. %d\n", mytime - T);
      M5.Speaker.beep();
      if (M5.BtnC.read() == 1){
        Serial.printf("Acknowledge! move to expired");
        mystate = expired;
       }
      break;
  }
  M5.update();
}
