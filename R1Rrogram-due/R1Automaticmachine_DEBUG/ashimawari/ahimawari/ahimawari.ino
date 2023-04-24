#define FLCW 46 //front left  pin//
#define FLPWM 5
#define FLCCW 48

#define FRCW 44 //front right pin//
#define FRPWM 6
#define FRCCW 42

#define RLCW 23 //rear left  pin//
#define RLPWM 4
#define RLCCW 25

#define RRCW 22 //rear right pin//
#define RRPWM 3
#define RRCCW 24

volatile int count = 0;

void setup() {
  pinMode(FLCW, OUTPUT);
  pinMode(FLCCW, OUTPUT);
  pinMode(FRCW, OUTPUT);
  pinMode(FRCCW, OUTPUT);
  pinMode(RLCW, OUTPUT);
  pinMode(RLCCW, OUTPUT);
  pinMode(RRCW, OUTPUT);
  pinMode(RRCCW, OUTPUT);
}

void loop() {
  if(count == 0){
    digitalWrite(FLCW,HIGH);
    digitalWrite(FLCCW,LOW);
    analogWrite(FLPWM,240);
    digitalWrite(FRCW,HIGH);
    digitalWrite(FRCCW,LOW);
    analogWrite(FRPWM,240);
    digitalWrite(RLCW,HIGH);
    digitalWrite(RLCCW,LOW);
    analogWrite(RLPWM,240);
    digitalWrite(RRCW,HIGH);
    digitalWrite(RRCCW,LOW);
    analogWrite(RRPWM,240);
    delay(1000);
    count = 1;
  }else{
    digitalWrite(FLCW,LOW);
    digitalWrite(FLCCW,HIGH);
    analogWrite(FLPWM,240);
    digitalWrite(FRCW,LOW);
    digitalWrite(FRCCW,HIGH);
    analogWrite(FRPWM,240);
    digitalWrite(RLCW,LOW);
    digitalWrite(RLCCW,HIGH);
    analogWrite(RLPWM,240);
    digitalWrite(RRCW,LOW);
    digitalWrite(RRCCW,HIGH);
    analogWrite(RRPWM,240);
    delay(1000);
    count = 0;
  }
}
