#include <Servo.h>
#include "src/Pixy2/Pixy2.h"
#include "src/HCSR04/HCSR04.h"
#include "src/L298N/L298N.h"

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 11

#define R_TRIG 2
#define R_ECHO A0
#define L_TRIG 4
#define L_ECHO A1

#define SERVO 9
#define LIGHT 13

HCSR04 left(L_TRIG, L_ECHO);
HCSR04 right(R_TRIG, R_ECHO);
L298N motor(IN1, IN2, IN3, IN4);
Servo servo;

int leftDistance = 0;
int rightDistance = 0;
int i = 0;
int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  left.begin();
  right.begin();
  motor.begin();
  servo.attach(SERVO);

  delay(10);
}

void loop() {
  Serial.print("loop: ");

  if (digitalRead(7)) {
    servo.write(30);
    delay(1000);
    servo.write(100);
    delay(1000);
    servo.write(135);
    delay(1000);
  }

  // leftDistance = left.distance();
  // rightDistance = right.distance();
  // avoidance();

  delay(50);
  Serial.println();
}

void avoidance() {
  if ((leftDistance < 25) && (rightDistance < 25)) {
    motor.back(100);
  } else if (leftDistance < 25) {
    motor.right(100);
  } else if (rightDistance < 25) {
    motor.left(100);
  } else {
    motor.forward(100);
  }
}