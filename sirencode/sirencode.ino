int pots = A0;
int servo = 12;
#include <Servo.h>
Servo myservo; 
int potsVal;
int val;

void setup() {
  Serial.begin(9600);
  myservo.attach(servo);  
  myservo.write(0);
}


void loop() {
  int potsVal = analogRead(pots);
  // Serial.println(val);
  // myservo.write(val);
  // delay(20);
  val = map(potsVal, 0, 700, 0, 5);
  for (int i=0; i < 180; i++){
    int potsVal = analogRead(pots);
    val = map(potsVal, 0, 700, 0, 10);
    myservo.write(i);
    Serial.println(i);
    Serial.println(val);
    i+=val;
    delay(40);

  }
  for (int i=180; i >=0; i--){
    int potsVal = analogRead(pots);
    val = map(potsVal, 0, 700, 0, 10);
    myservo.write(i);
    Serial.println(i);
    Serial.println(val);
    i-=val;
    delay(40);
  }
}
