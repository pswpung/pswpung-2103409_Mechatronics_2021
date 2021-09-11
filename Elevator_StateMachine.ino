#include <ESP32Servo.h>
#include <M5Stack.h>
#include<Keypad.h>

enum State {floor1, floor2, up_button, down_button, choose_down, choose_up, go_up,  go_down};
enum State elevator;
const byte ROWS = 1;
const byte COLS = 2;
byte rowPins[ROWS] = {5};
byte colPins[COLS] = {12, 13};
char keys[ROWS][COLS] = {{'u', 'd'}};
char key = 'a';
bool from1 = false;
bool from2 = false;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo myservo;  

int pos = 0;    
int pos_elevator = 1;

void servo_run(){
    for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) 
    myservo.write(pos);              
    delay(15);                       
  }
}

void setup() {
  elevator = floor1;
  myservo.attach(2); 
  Serial.begin(115200);
}

void loop() {
  switch(elevator)
  {
    case floor1:
      Serial.println("Floor 1");
      key = keypad.getKey();
      if (key == 'u'){
        elevator = up_button;
        key = 'a';
      }
      if (key == 'd'){
        from1 = true;
        elevator = down_button;
        key = 'a';
      }
      if (from2==true){
        from2 = false;
        elevator = choose_up;
      }
      break;

    case floor2:
      Serial.println("Floor 2");
      key = keypad.getKey();
      if (key == 'd'){
        elevator = down_button;
        key = 'a';
      }
      if (key == 'u'){
        from2 = true;
        elevator = up_button;
        key = 'a';
      }
      if (from1 == true){
        from1 = false;
        elevator = choose_down;
      }
      break;

    case up_button:
      Serial.println("button up is pressed.");
      if (pos_elevator == 1){
        elevator = choose_up;
      }
      if (pos_elevator == 2){
        elevator = go_down;
      }
      break;

    case down_button:
      Serial.println("button down is pressed.");
      if (pos_elevator == 1){
        elevator = go_up;
      }
      if (pos_elevator == 2){
        elevator = choose_down;
      }
      break;

    case choose_up:
      Serial.println("Please select the floor to go up.");
      if(M5.BtnA.read() == 1){
        elevator = choose_up;
      }
      if(M5.BtnB.read() == 1){
        elevator = go_up;
      }
      break;

    case choose_down:
      Serial.println("Please select the floor to go down.");
      if(M5.BtnA.read() == 1){
        elevator = go_down;
      }
      if(M5.BtnB.read() == 1){
        elevator = choose_down;
      }
      break;
      
    case go_up:
      Serial.println("Elevator is going up.");
      if(pos_elevator != 2){
        servo_run();
        pos_elevator += 1;
        elevator = go_up;
      }
      if(pos_elevator == 2){
        elevator = floor2;
      }
      break;

    case go_down:
      Serial.println("Elevator is going down.");
      if(pos_elevator != 1){
        servo_run();
        pos_elevator -= 1;
        elevator = go_down;
      }
      if(pos_elevator == 1){
        elevator = floor1;
      }
      break;
  }
  M5.update();
}
