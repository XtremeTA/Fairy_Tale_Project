#include <Servo.h>

Servo myservo;
const int buttonPin = 2;
int buttonState = 0;
int prevButtonState = 0;
bool A = true;

//Code for First Scene

void setup() {
  myservo.attach(9);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevButtonState){
    if (buttonState == LOW) {
      A = false;
      Serial.println("Start Part B");
    }
  }
  if (A == false){
    if (buttonState != prevButtonState){
      if (buttonState == HIGH) {
        myservo.write(180);
      }
    }
  }
  prevButtonState = buttonState;

}
