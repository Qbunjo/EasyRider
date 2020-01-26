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

}

void loop() {
  
  delay(50);
  unsigned int uS = sonar.ping(); 
  distance=(sonar.convert_cm(uS));
  if (distance==0) {distance=100;}
  if (distance <10) {
    Reverse();
  } 
    else
    if (distance >10 and distance <25){
      Obstacle(); 
  }else
  {GoAhead();
}
}
void GoAhead(){
  digitalWrite(5,200);
  digitalWrite(6,0);
  digitalWrite(10,200);
  digitalWrite(11,0);
}
void Reverse(){
  digitalWrite(5,0);
  digitalWrite(6,100);
  digitalWrite(10,0);
  digitalWrite(11,100);
}
void Obstacle(){
  digitalWrite(5,100);
  digitalWrite(6,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
}
