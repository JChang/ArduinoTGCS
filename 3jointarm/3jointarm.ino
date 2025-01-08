#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;
int joint1 = A0;
int joint2 = A2;
int joint3 = A1;
int joint4 = A3;
int angle1;
int angle2;
int angle3;
int angle4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.attach(9);
  s2.attach(6);
  s3.attach(10);
  s4.attach(8);
  s1.write(0);
  s2.write(0);
  s3.write(0);
  s4.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  angle1 = 1023-analogRead(joint1);
  angle1 = map(angle1, 0, 1023, 0, 180);
  angle2 = analogRead(joint2);
  angle2 = map(angle2, 0, 1023, 0, 180);
  angle3 = 1023-analogRead(joint3);
  angle3 = map(angle3, 0, 1023, 0, 180);
  angle4 = analogRead(joint4);
  angle4 = map(angle4, 0, 1023, 0, 180);
  // Serial.println(angle1);
  Serial.println(angle2);
  // Serial.println(angle3);
  s1.write(angle1);
  s2.write(angle2);
  s3.write(angle3);
  s4.write(angle4);
  delay(10);
}
