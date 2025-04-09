int b1 = 11;
int b2 = 10;
int b3 = 4;
int b4 = 2;
int L1 = 7;
int L2 = 6;
int L3 = 5;
int L4 = 3;
int bz = 12;
int lvl = 1;
int speed = 0;
int increment = 20;
int speeddelay = 15;
int maxspeed = 600;
int maxspeeddelay = 450;
int buttons[] = {b1, b2, b3, b4};
int leds[] = {L1, L2, L3, L4};
int tones[] = {165, 220, 277, 330};
int seq[40];


void setup() {
  Serial.begin(38400);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(bz, OUTPUT);
}

void loop() {
  randomSeed(analogRead(A5));
  for (int k = 0; k < lvl-1; k++){
    digitalWrite(leds[seq[k]], HIGH);
    tone(bz, tones[seq[k]]);
    delay(800-speed);
    digitalWrite(leds[seq[k]], LOW);
    noTone(bz);
    delay(500-speeddelay);
  }
  int choice = random(0, 4);
  seq[lvl-1] = choice;
  digitalWrite(leds[choice], HIGH);
  tone(bz, tones[choice]);
  delay(800-speed);
  digitalWrite(leds[choice], LOW);
  noTone(bz);
  delay(500-speeddelay);

  for (int i = 0; i < lvl; i++){
    while(digitalRead(b1) == 1 && digitalRead(b2) == 1 && digitalRead(b3) == 1 && digitalRead(b4) == 1){delay(50);}
    int downButton;
    for (int i = 0; i < 4; i++){
      if (digitalRead(buttons[i]) == 0){
        downButton = buttons[i];
        tone(bz, tones[i]);
        digitalWrite(leds[i], HIGH);
        while(digitalRead(downButton) == 0){}
        digitalWrite(leds[i], LOW);
        noTone(bz);
        delay(100);
      }
    }
    if (downButton != buttons[seq[i]]){
      fail();
      while(digitalRead(b1) == 1 && digitalRead(b2) == 1 && digitalRead(b3) == 1 && digitalRead(b4) == 1){}
    }
  }
  if (lvl == -1){
    lvl = 1;
    speed = 0;
    speeddelay = 0;
  }
  else{
    lvl++;
    speed += increment;
    speeddelay += increment/2;
    if (speeddelay > maxspeeddelay){
      speeddelay = maxspeeddelay;
    }
    if (speed > maxspeed){
      speed = maxspeed;
    }
  }
  delay(1000);
}

void fail(){
  delay(250);
  tone(bz, 100, 500);
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(500);
  noTone(bz);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  delay(250);
  tone(bz, 100, 500);
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(500);
  noTone(bz);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  delay(250);
  tone(bz, 100, 500);
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(500);
  noTone(bz);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  for (int i = 0; i < lvl; i++){
    seq[i] = 0;
  }
  lvl = -1;
}
