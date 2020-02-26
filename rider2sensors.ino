#include <NewPing.h>
#define TRIGGER_PINL  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define TRIGGER_PINR  6
#define ECHO_PINL     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define ECHO_PINR     7
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int distanceL = 0;
int distanceR = 0;

NewPing sonar1(TRIGGER_PINL, ECHO_PINL, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PINR, ECHO_PINR, MAX_DISTANCE);

void setup() {
  // these pins have to be PWM capable
  //engineL
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  //engineR
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);

  Serial.begin(9600);
  Serial.println("All systems ready");
}

void loop() {

  delay(50);
  distanceL = sonar1.ping_cm();
  delay(50);
  distanceR = sonar2.ping_cm();

  if (distanceL == 0) {
    distanceL = 100;
  }
  if (distanceR == 0) {
    distanceR = 100;
  }

  if (distanceL < 15 and distanceR < 15) { //Reverse
    Reverse();
  } else if (distanceL > distanceR) {
    if (distanceL < 30 and distanceL > 15) {
      ObstacleL();
    }  else if (distanceR < 30 and distanceR > 15) {
      ObstacleR();
    }
  }
  if (distanceL > 30 and distanceR > 30) {
    GoAhead();
  }
  Serial.println(distanceL + " " + distanceR);

}
void GoAhead() {
  analogWrite(5, 55);
  analogWrite(6, 0);
  analogWrite(10, 55);
  analogWrite(11, 0);
  Serial.println("Foreward");
}
void Reverse() {
  analogWrite(5, 0);
  analogWrite(6, 45);
  analogWrite(10, 0);
  analogWrite(11, 45);
  Serial.println("Reverse");
}
void ObstacleL() {
  analogWrite(5, 55);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
  Serial.println("Avoid obstacle L");
}
void ObstacleR() {
  analogWrite(5, 0);
  analogWrite(6, 55);
  analogWrite(10, 0);
  analogWrite(11, 0);
  Serial.println("Avoid obstacle R");
}