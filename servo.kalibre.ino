#include <Servo.h>    // include servo library

// Define 8 Servos
Servo myServo1; // Front Left Pivot Servo
Servo myServo2; // Front Left Lift Servo
Servo myServo3; // Back Left Pivot Servo
Servo myServo4; // Back Left Lift Servo
Servo myServo5; // Back Right Pivot Servo
Servo myServo6; // Back Right Lift Servo
Servo myServo7; // Front Right Pivot Servo
Servo myServo8; // Front Right Lift Servo

void setup() {
  // put your setup code here, to run once:
  myServo1.attach(1);
  myServo2.attach(2);
  myServo3.attach(3);
  myServo4.attach(4);
  myServo5.attach(5);
  myServo6.attach(6);
  myServo7.attach(7);
  myServo8.attach(8);
  
  myServo1.write(90);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  myServo5.write(90);
  myServo6.write(90);
  myServo7.write(90);
  myServo8.write(90);
}

void loop() {
  
  // put your main code here, to run repeatedly:
}
