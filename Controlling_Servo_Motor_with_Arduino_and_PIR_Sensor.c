#include <Servo.h>

// constants won't change
const int MOTION_SENSOR_PIN = 12; // Arduino pin connected to motion sensor's pin
const int SERVO_PIN         = 9; // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor  
int currentMotionState; // the current state of motion sensor

void setup() {
  Serial.begin(1500);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentMotionState = digitalRead(MOTION_SENSOR_PIN);
}

void loop() {
  currentMotionState = digitalRead(MOTION_SENSOR_PIN);
 
  if (currentMotionState == HIGH && angle <= 90) { // pin state change: LOW -> HIGH
    angle ++;
    servo.write(angle); }
  else
  if (currentMotionState == HIGH && angle >= 0) {
    angle --;
    servo.write(angle);
  }
}
