#include <Servo.h>

Servo firstservo;
Servo secondservo;
const int potionPin = 10;
const int victimPin = 12;
int potionState = 0;
int prevPotionState = 0;
int victimState = 0;
int prevVictimState = 0;
bool A = true;
bool B = false;
bool C = false;


/* This is the code for the first scene
   The potion would be on the table already,
   and when someone takes it off and puts it back,
   the servo would turn 180 degrees so Jekyll would turn into Hyde.
*/

void setup() {
  firstservo.attach(9);
  firstservo.write(0);
  secondservo.attach(11);
  secondservo.write(180);
  pinMode(potionPin, INPUT);
  pinMode(victimPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potionState = digitalRead(potionPin);
  victimState = digitalRead(victimPin);
  """
  First Scene
  """

  if (potionState != prevPotionState){
    if (potionState == LOW) {
      A = false;
      Serial.println("Start Potion Part");
    }
  }
  if (A == false){
    if (potionState != prevPotionState){
      if (potionState == HIGH) {
        firstservo.write(180);
        B = true;
      }
    }
  }

  """
  Second Scence
  """

  if (B == true){
    if (victimState != prevVictimState){
      if (victimState = HIGH) {
        for (int i = 0; i < 3; i++){
          secondservo.write(0);
          delay(500);
          secondservo.write(180);
          delay(500);
        }
        B = false;
        C = true;
      }
    }
  }
  """
  Third Scene (in progress)
  """
  /*
  if (C == true) {

  }
  */
  prevPotionState = potionState;
  prevVictimStae = victimState;

}
