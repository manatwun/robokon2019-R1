#include <DueTimer.h>

#define FLCW 46 //front left  pin//
#define FLPWM 5
#define FLCCW 48

#define FRCW 44 //front right pin//
#define FRPWM 6
#define FRCCW 42

#define FLEP 29 //front left encoder pin//
#define FREP 27 //front right encoder pin//

#define MAXPWM 204

#define Kp      30
#define Ki      300
#define Kd      0.1

volatile int FL;
volatile int FR;

volatile int FLB;
volatile int FRB;

volatile int FLE = 0;
volatile int FRE = 0;

volatile int FLEB = 0;
volatile int FREB = 0;

volatile int FLdiff = 0;
volatile int FRdiff = 0;
double dt = 0;
double pretime = 0;
double P = 0;
double I = 0;
double D = 0;
double preP = 0;


void FLEC() {//tire encoder CHANGEing//
  FLE++;
  //  Serial.print(F("FLE:"));
  //  Serial.print(FLE);
}
void FREC() {
  FRE++;
  //  Serial.print(F("FRE:"));
  //  Serial.print(FRE);
}

void setup() {
  attachInterrupt(FLEP, FLEC, CHANGE);
  attachInterrupt(FREP, FREC, CHANGE);
  Timer1.attachInterrupt(PID);
  Timer1.start(100);//1.25ms//

  for (int c = 0; c < 20; c++) {//routine//

    digitalWrite(FLCCW, LOW);
    digitalWrite(FRCCW, LOW);
    digitalWrite(FLCW, HIGH);
    digitalWrite(FRCW, HIGH);
    delay(50);

    digitalWrite(FLCW, LOW);
    digitalWrite(FRCW, LOW);
    analogWrite(FLPWM, MAXPWM);
    analogWrite(FRPWM, MAXPWM);
    delay(50);

    analogWrite(FLPWM, 0);
    analogWrite(FRPWM, 0);
    digitalWrite(FLCCW, HIGH);
    digitalWrite(FRCCW, HIGH);
    delay(50);
  }

  digitalWrite(FLCCW, LOW);
  digitalWrite(FRCCW, LOW);
  delay(50);

  pretime = micros();
}

void loop() {
  digitalWrite(FLCW, HIGH);
  digitalWrite(FLCCW, LOW);
  analogWrite(FLPWM, 150);
  digitalWrite(FRCW, HIGH);
  digitalWrite(FRCCW, LOW);

}

void PID() {
  FLdiff = FLE - FLEB;
  FRdiff = FRE - FREB;
  dt = (micros() - pretime) / 1000000;
  pretime = micros();

  P  = FLdiff - FRdiff;
  I += P * dt;
  D  = (P - preP) / dt;
  preP = P;

  FR += Kp * P + Ki * I + Kd * D;
  FLEB = FLE;//リセット
  FLE = 0;
  FREB = FRE;//リセット
  FRE = 0;
}

