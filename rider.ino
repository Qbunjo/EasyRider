#include <NewPing.h>
#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int distance=0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

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
  unsigned int uS = sonar.ping(); 
  distance=(sonar.convert_cm(uS));
  if (distance==0) {distance=100;}
  if (distance <15) {
    Reverse();
  } 
    else
    if (distance >15 and distance <30){
      Obstacle(); 
  }else
  {GoAhead();
  Serial.println(distance);
}
}
void GoAhead(){
  analogWrite(5,55);
  analogWrite(6,0);
  analogWrite(10,55);
  analogWrite(11,0);
  Serial.println("Foreward");
}
void Reverse(){
  analogWrite(5,0);
  analogWrite(6,45);
  analogWrite(10,0);
  analogWrite(11,45);
  Serial.println("Reverse");
}
void Obstacle(){
  analogWrite(5,55);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(11,0);
  Serial.println("Avoid obstacle");
}
