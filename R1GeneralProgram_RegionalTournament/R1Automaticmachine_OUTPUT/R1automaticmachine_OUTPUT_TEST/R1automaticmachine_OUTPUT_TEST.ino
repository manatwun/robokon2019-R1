#include <TimerOne.h>
#include <MsTimer2.h>

#define FLCW 23 //front left  pin//
#define FLPWM 6
#define FLCCW 25

#define FRCW 22 //front right pin//
#define FRPWM 5
#define FRCCW 24

#define RLCW 30 //rear left  pin//
#define RLPWM 2
#define RLCCW 32

#define RRCW 28 //rear right pin//
#define RRPWM 4
#define RRCCW 26

#define MHCW 36 //high rope pin//
#define MHPWM 46
#define MHCCW 34

#define MRCW 38 //right rack pin//
#define MRPWM 45
#define MRCCW 40

#define MLCW 44 //left rack pin//
#define MLPWM 7
#define MLCCW 42

#define MHEP 1
#define MLEP 2
#define MREP 3

#define FLEP 49
#define FREP 47
#define RLEP 43
#define RREP 41

#define XEP 39
#define YEP 37

//If you want to change {max duty cycle}, you can change max duty cycle under here.//

#define MAXPWM 204
volatile int count = 0;
volatile int FL;
volatile int FR;
volatile int RL;
volatile int RR;
volatile int ML;
volatile int MR;
volatile int MH;
volatile int FLB;
volatile int FRB;
volatile int RLB;
volatile int RRB;
volatile int MLB;
volatile int MRB;
volatile int MHB;

volatile int FLCWD = 0;
volatile int FRCWD = 0;
volatile int RLCWD = 0;
volatile int RRCWD = 0;

volatile int FLE = 0;
volatile int FRE = 0;
volatile int RLE = 0;
volatile int RRE = 0;
volatile int XE = 0;
volatile int YE = 0;
volatile int MLE = 0;
volatile int MRE = 0;
volatile int MHE = 0;

volatile int FLEB = 0;
volatile int FREB = 0;
volatile int RLEB = 0;
volatile int RREB = 0;
volatile int XEB = 0;
volatile int YEB = 0;
volatile int MLEB = 0;
volatile int MREB = 0;
volatile int MHEB = 0;

volatile int FLEF = 0;
volatile int FREF = 0;
volatile int RLEF = 0;
volatile int RREF = 0;
volatile int XEF = 0;
volatile int YEF = 0;

volatile int FLEC = 0;
volatile int FREC = 0;
volatile int RLEC = 0;
volatile int RREC = 0;
volatile int XEC = 0;
volatile int YEC = 0;

volatile int ACOUNTER;
volatile int BSIGNAL;


void  MHEC() {
  MHE++;
}
void MREC() {
  MRE++;
}
void MLEC() {
  MLE++;
}

void TIMERST() {
  Timer1.start();
  MsTimer2::start();
}

void TIMERSP() {
  Timer1.stop();
  MsTimer2::stop();
}
void ENC() {
  //    Serial.print(F("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"));
  //    Serial.print(F("MHE"));
  //    Serial.print(MHE);
  //    Serial.print(F("\n"));
  //    Serial.print(F("MRE"));
  //    Serial.print(MRE);
  Serial.print(F("\n\n"));
  Serial.print(F("FLE:"));
  Serial.print(FLE);
  Serial.print(F("\n"));
  Serial.print(F("FRE:"));
  Serial.print(FRE);
  Serial.print(F("\n"));
  Serial.print(F("RLE:"));
  Serial.print(RLE);
  Serial.print(F("\n"));
  Serial.print(F("RRE:"));
  Serial.print(RRE);
  //    Serial.print(F("\n"));
  //    Serial.print(F("\n"));
  //    Serial.print(F("XEP:"));
  //    Serial.print(XE);
  //    Serial.print(F("\n"));
  //    Serial.print(F("YEP:"));
  //    Serial.print(YE);
  //    Serial.print(F("\n"));
  //    Serial.print(F("\n"));
  //    Serial.print(F("FL:"));
  //    Serial.print(FL);
  //    Serial.print(F("\n"));
  //    Serial.print(F("FR:"));
  //    Serial.print(FR);
  //    Serial.print(F("\n"));
  //    Serial.print(F("RL:"));
  //    Serial.print(RL);
  //    Serial.print(F("\n"));
  //    Serial.print(F("RR:"));
  //    Serial.print(RR);
  //    Serial.print(F("\n"));
  //  Serial.print(F("\nMRE:"));
  //  Serial.print(MRE);

  if (digitalRead(FLEP) == HIGH) {
    if (FLEF == 0) {
      FLE++;
      FLEF = 1;
    }
  }
  if (digitalRead(FLEP) == LOW) {
    if (FLEF == 1) {
      FLE++;
      FLEF = 0;
    }
  }

  if (digitalRead(FREP) == HIGH) {
    if (FREF == 0) {
      FRE++;
      FREF = 1;
    }
  }
  if (digitalRead(FREP) == LOW) {
    if (FREF == 1) {
      FRE++;
      FREF = 0;
    }
  }

  if (digitalRead(RLEP) == HIGH) {
    if (RLEF == 0) {
      RLE++;
      RLEF = 1;
    }
  }
  if (digitalRead(RLEP) == LOW) {
    if (RLEF == 1) {
      RLE++;
      RLEF = 0;
    }
  }

  if (digitalRead(RREP) == HIGH) {
    if (RREF == 0) {
      RRE++;
      RREF = 1;
    }
  }
  if (digitalRead(RREP) == LOW) {
    if (RREF == 1) {
      RRE++;
      RREF = 0;
    }
  }

  if (digitalRead(XEP) == HIGH) {
    if (XEF == 0) {
      XE++;
      XEF = 1;
    }
  }
  if (digitalRead(XEP) == LOW) {
    if (XEF == 1) {
      XE++;
      XEF = 0;
    }
  }

  if (digitalRead(YEP) == HIGH) {
    if (YEF == 0) {
      YE++;
      YEF = 1;
    }
  }
  if (digitalRead(YEP) == LOW) {
    if (YEF == 1) {
      YE++;
      YEF = 0;
    }
  }

}

void PWM() {
  if (FLCWD == 1) {
    digitalWrite(FLCW, HIGH);
    digitalWrite(FLCCW, LOW);
  } else if (FLCWD == 0) {
    digitalWrite(FLCW, LOW);
    digitalWrite(FLCCW, HIGH);
  }
  if (FL < 0) {
    FL = 0;
  }
  if (FL > 240) {
    FL = 240;
  }
  analogWrite(FLPWM, FL);

  if (FRCWD == 1) {
    digitalWrite(FRCW, HIGH);
    digitalWrite(FRCCW, LOW);
  } else if (FRCWD == 0) {
    digitalWrite(FRCW, LOW);
    digitalWrite(FRCCW, HIGH);
  }
  if (FRE + 10 < FLE) {
    FR++;
  } else if (FRE - 10 > FLE) {
    FR--;
  }
  if (FR < 0) {
    FR = 0;
  }
  if (FR > 240) {
    FR = 240;
  }
  analogWrite(FRPWM, FR);

  if (RLCWD == 1) {
    digitalWrite(RLCW, HIGH);
    digitalWrite(RLCCW, LOW);
  } else if (RLCWD == 0) {
    digitalWrite(RLCW, LOW);
    digitalWrite(RLCCW, HIGH);
  }
  if (RLE + 10 < FLE) {
    RL++;
  } else if (RLE - 10 > FLE) {
    RL--;
  }
  if (RL < 0) {
    RL = 0;
  }
  if (RL > 240) {
    RL = 240;
  }
  analogWrite(RLPWM, RL);

  if (RRCWD == 1) {
    digitalWrite(RRCW, HIGH);
    digitalWrite(RRCCW, LOW);
  } else if (RRCWD == 0) {
    digitalWrite(RRCW, LOW);
    digitalWrite(RRCCW, HIGH);
  }
  if (RRE + 10 < FLE) {
    RR++;
  } else if (RRE - 10 > FLE) {
    RR--;
  }
  if (RR < 0) {
    RR = 0;
  }
  if (RR > 240) {
    RR = 240;
  }
  analogWrite(RRPWM, RL);

}

void TSTOP() {
  digitalWrite(FLCW, LOW);
  digitalWrite(FLCCW, LOW);
  digitalWrite(FRCW, LOW);
  digitalWrite(FRCCW, LOW);
  digitalWrite(RLCW, LOW);
  digitalWrite(RLCCW, LOW);
  digitalWrite(RRCW, LOW);
  digitalWrite(RRCCW, LOW);
  FL = 0;
  FR = 0;
  RL = 0;
  RR = 0;
  delay(100);
}

void RTOWEL() {
  TIMERST();
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  RRCWD = 0;
  FL = 30;
  FR = 30;
  RL = 30;
  RR = 30;
  YEB = YE;
  while (YE - YEB < 220) {

  }
  TSTOP();
  TIMERSP();
  MREB = MRE;
  while (MRE - MREB < 460) {
    digitalWrite(MRCCW, LOW);
    digitalWrite(MRCW, HIGH);
    digitalWrite(MLCW, LOW);
    digitalWrite(MLCCW, HIGH);
    analogWrite(MRPWM, 50);
    analogWrite(MLPWM, 50);
  }
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  MREB = MRE;
  MHEB = MHE;
  while (MHE - MHEB < 5000) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XEB = XE;
  while (XE - XEB < 104) {
  }
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 42) {
  }
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 42) {
  }
  TSTOP();
  XEB = XE;
  MHEB = MHE;
  TIMERSP();
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 62) {
  }
  XEB = XE;
  TSTOP();
  FLCWD = 0;
  RRCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (YE - YEB < 10) {
  }
  TSTOP();
  YEB = YE;
  MHEB = MHE;
  TIMERSP();
  while (MHE - MHEB < 200) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  while (MRE - MREB < 460) {
    digitalWrite(MRCW, LOW);
    digitalWrite(MRCCW, HIGH);
    digitalWrite(MLCW, HIGH);
    digitalWrite(MLCCW, LOW);
    analogWrite(MRPWM, 50);
    analogWrite(MLPWM, 50);
  }
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCCW, LOW);
  analogWrite(MRPWM, 50);
  analogWrite(MLPWM, 50);
  TIMERST();
  FRCWD = 0;
  RLCWD = 0;
  FLCWD = 0;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 251) {
  }
  XEB = XE;
  TSTOP();
  FLCWD = 0;
  RRCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (YE - YEB < 218) {
  }
  TSTOP();
  delay(2000);
  TIMERSP();
}

void RSHEETS() {
  TIMERST();
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  //  while (YE - YEB < 200) {
  //  }
  delay(15000);
  TIMERSP();
    MREB = MRE;
  //  while (MRE - MREB < ) {
  digitalWrite(MRCW, HIGH);
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCW, HIGH);
  digitalWrite(MLCCW, LOW);
  analogWrite(MRPWM, 50);
  analogWrite(MLPWM, 50);
  //  }
  delay(7000);
  digitalWrite(MRCW, LOW);
  digitalWrite(MLCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  MREB = MRE;
  MHEB = MHE;
  while (MHE - MHEB < 500) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  TIMERST();
  FLCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  RRCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 418) {
  }
  TSTOP();
  TIMERSP();
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  TIMERST();
  FLCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XEB = XE;
  while (XE - XEB < 418) {
  }
  TSTOP();
  XEB = XE;
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  MHEB = MHE;
  TIMERSP();
  while (MHE - MHEB < 400) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  TIMERST();
  FLCWD = 0;
  FRCWD = 1;
  RLCWD = 0;
  RRCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  while (YE - YEB < 200) {
  }
  FLCWD = 0;
  FRCWD = 1;
  RLCWD = 0;
  RRCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  while (YE - YEB < 2936) {
  }
  FLCWD = 0;
  FRCWD = 1;
  RLCWD = 0;
  RRCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  while (YE - YEB < 200) {
  }
  TSTOP();
  YEB = YE;
  TIMERSP();
}

void BTOWEL() {
  TIMERST();
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  //  while (YE - YEB < 200) {
  //  }
  delay(15000);
  TSTOP();
  TIMERSP();
  MREB = MRE;
  //  while (MRE - MREB < 1600) {
  digitalWrite(MRCCW, LOW);
  digitalWrite(MRCW, HIGH);
  digitalWrite(MLCW, LOW);
  digitalWrite(MLCCW, HIGH);
  analogWrite(MRPWM, 50);
  analogWrite(MLPWM, 50);
  delay(7000);
  //  }
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  MREB = MRE;
  MHEB = MHE;
  //  while (MHE - MHEB < 5000) {
  digitalWrite(MHCW, HIGH);
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 180);
  //  }
  delay(9000);
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  TIMERST();
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XEB = XE;
  delay(3000);
  //  while (XE - XEB < 189) {
  //  }
  TSTOP();
  XE = XEB;
  TIMERSP();
  MH = MHB;
  //  while (MH - MHB < 800) {
  digitalWrite(MHCCW, HIGH);
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 50);
  //  }
  delay(9000);
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHB = MH;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  //  while (XE - XEB < 42) {
  //  }
  delay(10000);
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MH - MHB < 800) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  MH = MHB;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XE = XEB;
  while (XEB - XE < 42) {
  }
  TSTOP();
  TIMERSP();
  XE = XEB;
  while (MHB - MH < 800) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  MH = MHB;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  TIMERSP();
  XE = XEB;
  while (XEB - XE < 104) {
  }
  TSTOP();
  XE = XEB;
  MH = MHB;
  while (MHB - MH < 2600) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  TIMERST();
  FLCWD = 0;
  RRCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YE = YEB;
  while (YE - YEB < 228) {
  }
  TSTOP();
  TIMERSP();
  delay(2000);
}

void BSHEETS() {
  TIMERST();
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YEB = YE;
  while (YE - YEB < 333) {
  }
  TSTOP();
  TIMERSP();
  MREB = MRE;
  while (MRE - MREB < 1600) {
    digitalWrite(MRCW, HIGH);
    digitalWrite(MRCCW, LOW);
    digitalWrite(MLCW, HIGH);
    digitalWrite(MLCCW, LOW);
    analogWrite(MRPWM, 50);
    analogWrite(MLPWM, 50);
  }
  digitalWrite(MRCW, LOW);
  digitalWrite(MLCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  MREB = MRE;
  MHEB = MHE;
  while (MHE - MHEB < 500) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 180);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  TIMERST();
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XEB = XE;
  while (XE - XEB < 189) {
  }
  TSTOP();
  XE = XEB;
  TIMERSP();
  MH = MHB;
  while (MH - MHB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  MHB = MH;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 424) {
  }
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MH - MHB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  MH = MHB;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XEB - XE < 424) {
  }
  TSTOP();
  XE = XEB;
  TIMERSP();
  while (MHB - MH < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  MH = MHB;
  TIMERST();
  FLCWD = 1;
  RRCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  XE = XEB;
  while (XEB - XE < 1037) {
  }
  TSTOP();
  XE = XEB;
  TIMERSP();
  MH = MHB;
  while (MHB - MH < 200) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  delay(100);
  TIMERST();
  FLCWD = 0;
  RRCWD = 1;
  FRCWD = 0;
  RLCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  YE = YEB;
  while (YE - YEB < 2275) {
  }
  TSTOP();
  delay(2000);
  TIMERSP();
}

void MAKIAGE() {

}
void MAKISAGE() {

}

void RESET() {

}

void EMER() {

}
void OTOWEL() {

}
void setup() {
  Serial3.begin(9600);
  Serial2.begin(9600);
  Serial.begin(9600);
  TCCR1B = (TCCR1B & 0b11111000) | 0x02;
  TCCR2B = (TCCR2B & 0b11111000) | 0x02;
  TCCR3B = (TCCR3B & 0b11111000) | 0x02;
  TCCR4B = (TCCR4B & 0b11111000) | 0x02;
  TCCR5B = (TCCR5B & 0b11111000) | 0x02;
  pinMode(FLCW, OUTPUT);
  pinMode(FLCCW, OUTPUT);
  pinMode(FRCW, OUTPUT);
  pinMode(FRCCW, OUTPUT);
  pinMode(RLCW, OUTPUT);
  pinMode(RLCCW, OUTPUT);
  pinMode(RRCW, OUTPUT);
  pinMode(RRCCW, OUTPUT);
  pinMode(MHCW, OUTPUT);
  pinMode(MHCCW, OUTPUT);
  pinMode(MRCW, OUTPUT);
  pinMode(MRCCW, OUTPUT);
  pinMode(MLCW, OUTPUT);
  pinMode(MLCCW, OUTPUT);

  pinMode(FLEP, INPUT_PULLUP);
  pinMode(FREP, INPUT_PULLUP);
  pinMode(RLEP, INPUT_PULLUP);
  pinMode(RREP, INPUT_PULLUP);
  pinMode(XEP, INPUT_PULLUP);
  pinMode(YEP, INPUT_PULLUP);
  for (int c = 0; c < 20; c++) {

    digitalWrite(FLCCW, LOW);
    digitalWrite(FRCCW, LOW);
    digitalWrite(RLCCW, LOW);
    digitalWrite(RRCCW, LOW);
    digitalWrite(FLCW, HIGH);
    digitalWrite(FRCW, HIGH);
    digitalWrite(RLCW, HIGH);
    digitalWrite(RRCW, HIGH);
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    digitalWrite(MRCW, HIGH);
    digitalWrite(MRCCW, LOW);
    digitalWrite(MLCW, HIGH);
    digitalWrite(MLCCW, LOW);
    delay(50);

    digitalWrite(FLCW, LOW);
    digitalWrite(FRCW, LOW);
    digitalWrite(RLCW, LOW);
    digitalWrite(RRCW, LOW);
    digitalWrite(MHCW, LOW);
    digitalWrite(MRCW, LOW);
    digitalWrite(MLCW, LOW);
    analogWrite(FLPWM, MAXPWM);
    analogWrite(FRPWM, MAXPWM);
    analogWrite(RLPWM, MAXPWM);
    analogWrite(RRPWM, MAXPWM);
    analogWrite(MHPWM, 12.75);
    analogWrite(MRPWM, 12.75);
    analogWrite(MLPWM, 12.75);
    delay(50);

    analogWrite(FLPWM, 0);
    analogWrite(FRPWM, 0);
    analogWrite(RLPWM, 0);
    analogWrite(RRPWM, 0);
    analogWrite(MHPWM, 0);
    analogWrite(MRPWM, 0);
    analogWrite(MLPWM, 0);
    digitalWrite(FLCCW, HIGH);
    digitalWrite(FRCCW, HIGH);
    digitalWrite(RLCCW, HIGH);
    digitalWrite(RRCCW, HIGH);
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MRCCW, HIGH);
    digitalWrite(MLCCW, HIGH);
    delay(50);
  }

  digitalWrite(MHCCW, LOW);
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCCW, LOW);
  digitalWrite(RLCCW, LOW);
  digitalWrite(RRCCW, LOW);
  digitalWrite(FLCCW, LOW);
  digitalWrite(FRCCW, LOW);

  delay(50);

  Timer1.initialize(7000);
  Timer1.attachInterrupt(ENC);
  Timer1.start();


  MsTimer2::set(100, PWM);
  MsTimer2::start();

  TIMERSP();


  digitalWrite(MHCW, LOW);
  digitalWrite(MRCW, LOW);
  digitalWrite(MLCW, LOW);
  digitalWrite(MHCCW, LOW);
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCCW, LOW);

  digitalWrite(RLCW, LOW);
  digitalWrite(RRCW, LOW);
  digitalWrite(FLCW, LOW);
  digitalWrite(FRCW, LOW);
  digitalWrite(RLCCW, LOW);
  digitalWrite(RRCCW, LOW);
  digitalWrite(FLCCW, LOW);
  digitalWrite(FRCCW, LOW);

  analogWrite(FLPWM, 0);
  analogWrite(FRPWM, 0);
  analogWrite(RLPWM, 0);
  analogWrite(RRPWM, 0);
  analogWrite(MHPWM, 0);
  analogWrite(MLPWM, 0);
  analogWrite(MRPWM, 0);

  attachInterrupt(MHEP, MHEC, CHANGE);
  attachInterrupt(MLEP, MLEC, CHANGE);
  attachInterrupt(MREP, MREC, CHANGE);
}

void loop() {
  XE = 0;
  YE = 0;
  RTOWEL();
  //  Serial.print(F("\nBSIGNAL:"));
  //  Serial.print(BSIGNAL);
  while (Serial2.available()) {
    byte inChar = (byte)Serial2.read();
    BSIGNAL = inChar;
    switch (BSIGNAL) {
      case 1:
        RSHEETS();
        break;
      case 2:
        BSHEETS();
        break;
      case 3:
        RTOWEL();
        break;
      case 4:
        BTOWEL();
        break;
      case 5:
        MAKISAGE();
        break;
      case 6:
        OTOWEL();
        break;
      case 7:
        RESET();
        break;
      case 8:
        EMER();
        break;
      case 9:
        MAKISAGE();
        break;
      case 255:
        break;
      default:
        digitalWrite(MHCW, LOW);
        digitalWrite(MRCW, LOW);
        digitalWrite(MLCW, LOW);
        digitalWrite(MHCCW, LOW);
        digitalWrite(MRCCW, LOW);
        digitalWrite(MLCCW, LOW);

        digitalWrite(RLCW, LOW);
        digitalWrite(RRCW, LOW);
        digitalWrite(FLCW, LOW);
        digitalWrite(FRCW, LOW);
        digitalWrite(RLCCW, LOW);
        digitalWrite(RRCCW, LOW);
        digitalWrite(FLCCW, LOW);
        digitalWrite(FRCCW, LOW);

        analogWrite(FLPWM, 0);
        analogWrite(FRPWM, 0);
        analogWrite(RLPWM, 0);
        analogWrite(RRPWM, 0);
        analogWrite(MHPWM, 0);
        analogWrite(MLPWM, 0);
        analogWrite(MRPWM, 0);
        break;
    }
    //    Serial.print(F("BSIGNAL2:"));
    //    Serial.print(BSIGNAL);
    //    Serial.print(F("\n"));
    break;
  }
}
