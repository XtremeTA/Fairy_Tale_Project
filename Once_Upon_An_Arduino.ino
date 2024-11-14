#include <Servo.h>

Servo myservo;
const int buttonPin = 10;
int buttonState = 0;
int prevButtonState = 0;
bool A = true;


/* This is the code for the first scene
   The potion would be on the table already,
   and when someone takes it off and puts it back,
   the servo would turn 180 degrees so Jekyll would turn into Hyde.
*/

void setup() {
  myservo.attach(9);
  myservo.write(0);
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
