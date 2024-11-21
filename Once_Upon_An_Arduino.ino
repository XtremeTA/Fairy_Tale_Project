#include <Servo.h>

Servo firstservo;
Servo secondservo;
Servo thirdservo;
Servo fourthservo;
const int potionPin = 10;
const int victimPin = 12;
const int bedPin = 6;
const int poisonPin = 4;
int potionState = 0;
int prevPotionState = 0;
int victimState = 0;
int prevVictimState = 0;
int bedState = 0;
int poisonState = 0;
bool A = true;
bool B = false;
bool C = false;
bool D = false;


/* This is the code for the first scene
   The potion would be on the table already,
   and when someone takes it off and puts it back,
   the servo would turn 180 degrees so Jekyll would turn into Hyde.
*/

void setup() {
  firstservo.attach(9);
  firstservo.write(180);
  secondservo.attach(11);
  secondservo.write(180);
  thirdservo.attach(5);
  thirdservo.write(0);
  fourthservo.attach(3);
  fourthservo.write(180);
  pinMode(potionPin, INPUT);
  pinMode(victimPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potionState = digitalRead(potionPin);
  victimState = digitalRead(victimPin);
  bedState = digitalRead(bedPin);
  poisonState = digitalRead(poisonPin);
  
  //First Scene

  if (potionState != prevPotionState){
    if (potionState == LOW) {
      A = false;
      Serial.println("Start Potion Part");
    }
  }
  if (A == false){
    if (potionState != prevPotionState){
      if (potionState == HIGH) {
        firstservo.write(0);
        B = true;
      }
    }
  }

  //Second Scene

  if (B == true){
    if (victimState != prevVictimState){
      if (victimState == HIGH) {
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

// Third Scene

  if (C == true) {
    if (bedState == HIGH) {
      delay(1000);
      thirdservo.write(180);
      D = true;
    }
  }

// Fifth Scene

  if (D == true) {
    if (poisonState == HIGH) {
      fourthservo.write(90);
    }
  }
  prevPotionState = potionState;
  prevVictimState = victimState;

}
