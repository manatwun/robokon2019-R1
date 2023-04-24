#include <DueTimer.h>

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

#define MHCW 32 //high rope pin//
#define MHPWM 12
#define MHCCW 30

#define MRCW 38 //right rack pin//
#define MRPWM 7
#define MRCCW 40

#define MLCW 34 //left rack pin//
#define MLPWM 8
#define MLCCW 36

#define MHEP 37 //high rope encoder pin//
#define MLEP 45 //right rack encoder pin//
#define MREP 43 //left rack encoder pin//

#define FLEP 29 //front left encoder pin//
#define FREP 27 //front right encoder pin//
#define RLEP 33 //rear left encoder pin//
#define RREP 31 //rear right encoder pin//

#define XEP 49 //X ground encoder pin//
#define YEP 47 //Y ground encoder pin//

//If you want to change {max duty cycle}, you can change max duty cycle under here.//

#define MAXPWM 204
volatile int basis_rotation = 0;
volatile int pwm_flag = 0;
volatile int count = 0;
volatile byte inChar = 0;
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
volatile int MREB = 0;
volatile int MLEB = 0;
volatile int MHEB = 0;

volatile int FRF = 0;
volatile int RLF = 0;
volatile int RRF = 0;

volatile int ACOUNTER;
volatile int BSIGNAL;


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
void RLEC() {
  RLE++;
  //  Serial.print(F("RLE:"));
  //  Serial.print(RLE);
}
void RREC() {
  RRE++;
  //  Serial.print(F("RRE:"));
  //  Serial.print(RRE);
}
void XEC() {//ground encoder CHANGEing//
  //  Serial.print(F("XE:"));
  //  Serial.print(XE);
  XE++;
}
void YEC() {
  //  Serial.print(F("YE:"));
  //  Serial.print(YE);
  YE++;
}
void  MHEC() {//rack encoder CHANGEing//
  MHE++;
  //    Serial.print(F("MHE:"));
  //    Serial.print(MHE);
}
void MREC() {
  MRE++;
}
void MLEC() {
  MLE++;
}

void TIMERSP() {
  Timer1.stop();
}

void TIMERST() {
  Timer1.start();
}

void PWMCOUNTER() {
  if (pwm_flag == 1
     ) {
    basis_rotation = FLE - FLEB;
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
    if ( (basis_rotation + (basis_rotation * (2 / 100))) < (FRE - FREB) ) { //if more rotation//
      FR = FR - 1;
    } else if ((basis_rotation - (basis_rotation * (2 / 100))) > (RLE - RLEB)) {
      FR = FR + 1;
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
    if ( (basis_rotation + (basis_rotation * (2 / 100))) < (RLE - RLEB) ) { //if more rotation//
      RL = RL - 1;
    } else if ((basis_rotation - (basis_rotation * (2 / 100))) > (RLE - RLEB)) {
      RL = RL + 1;
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

    if ( (basis_rotation + (basis_rotation * (2 / 100))) < (RRE - RREB) ) { //if more rotation//
      RR = RR - 1;
    } else if ((basis_rotation - (basis_rotation * (2 / 100))) > (RRE - RREB)) {
      RR = RR + 1;
    }
    if (RR < 0) {
      RR = 0;
    }
    if (RR > 240) {
      RR = 240;
    }
    analogWrite(RRPWM, RR);
    //    Serial.print(F("---\n"));
    //    Serial.println(FLE);
    //    Serial.println(FRE);
    //    Serial.println(RLE);
    //    Serial.println(RRE);
    //    Serial.println(FL);
    //    Serial.println(FR);
    //    Serial.println(RL);
    //    Serial.println(RR);
    pwm_flag = 0;
  } else {
    FLB = FL;
    FRB = FR;
    RLB = RL;
    RRB = RR;
    pwm_flag ++;
  }
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
  analogWrite(MHPWM, 255);
  TIMERST();
  FLCWD = 0;
  FRCWD = 1;
  RLCWD = 1;
  RRCWD = 0;//true//
  FL = 150;
  FR = 150;
  RL = 150;
  RR = 150;
  YEB = YE;
  while (YE - YEB < 100) {
  }
  TSTOP();
  TIMERSP();
  MREB = MRE;
  while (MRE - MREB < 387) {
    digitalWrite(MRCCW, LOW);
    digitalWrite(MRCW, HIGH);
    digitalWrite(MLCW, LOW);
    digitalWrite(MLCCW, HIGH);
    analogWrite(MRPWM, 200);
    analogWrite(MLPWM, 200);
  }
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  MREB = MRE;
  MHEB = MHE;
  while (MHE - MHEB < 2400) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 230);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
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
  while (XE - XEB < 800) {
  }
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MHE - MHEB < 400) {//1//
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 240);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 800) {
  }
  TSTOP();
  XEB = XE;
  TIMERSP();
  while (MHE - MHEB < 300) {//2//
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 230);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 800) {
  }
  TSTOP();
  XEB = XE;
  MHEB = MHE;
  TIMERSP();
  while (MHE - MHEB < 300) {//3//
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 230);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  TIMERST();
  FLCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  RRCWD = 0;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 1200) {
  }
  XEB = XE;
  TSTOP();
  FLCWD = 1;
  FRCWD = 0;
  RLCWD = 0;
  RRCWD = 1;//rear//
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (YE - YEB < 1200) {
  }
  TSTOP();
  YEB = YE;
  MHEB = MHE;
  TIMERSP();
  while (MHE - MHEB < 1400) {//reset//
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 230);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  while (MRE - MREB < 387) {
    digitalWrite(MRCW, LOW);
    digitalWrite(MRCCW, HIGH);
    digitalWrite(MLCW, HIGH);
    digitalWrite(MLCCW, LOW);
    analogWrite(MRPWM, 200);
    analogWrite(MLPWM, 200);
  }
  digitalWrite(MRCCW, LOW);
  digitalWrite(MLCCW, LOW);
  analogWrite(MRPWM, 0);
  analogWrite(MLPWM, 0);
  TIMERST();
  FLCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  RRCWD = 1;
  FL = 100;
  FR = 100;
  RL = 100;
  RR = 100;
  while (XE - XEB < 3600) {
  }
  XEB = XE;
  TSTOP();
  //  FLCWD = 1;
  //  FRCWD = 0;
  //  RLCWD = 0;
  //  RRCWD = 1;
  //  FL = 100;
  //  FR = 100;
  //  RL = 100;
  //  RR = 100;
  //  while (YE - YEB < 218) {
  //  }
  //  TSTOP();
  delay(2000);
  TIMERSP();
  inChar = 0;
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

void setup() {
  Serial.begin(2400);
  Serial3.begin(1200);

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

  attachInterrupt(FLEP, FLEC, CHANGE);
  attachInterrupt(FREP, FREC, CHANGE);
  attachInterrupt(RLEP, RLEC, CHANGE);
  attachInterrupt(RREP, RREC, CHANGE);
  attachInterrupt(XEP, XEC, CHANGE);
  attachInterrupt(YEP, YEC, CHANGE);
  attachInterrupt(MHEP, MHEC, CHANGE);
  attachInterrupt(MLEP, MLEC, CHANGE);
  attachInterrupt(MREP, MREC, CHANGE);

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
    analogWrite(MHPWM, 255);
    analogWrite(MRPWM, 255);
    analogWrite(MLPWM, 255);
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

  Timer1.attachInterrupt(PWMCOUNTER);
  Timer1.start(5000);//5ms//

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

}

void loop() {
  Serial.print(F("\nstart"));
  XE = 0;
  YE = 0;
  //    Serial.print(F("\nBSIGNAL:"));
  //    Serial.print(BSIGNAL);
  //    Serial.print(F("\n"));
  while (Serial3.available()) {
    inChar = (byte)Serial3.read();
    //  BSIGNAL = 3;
    //    Serial.print(F("\nBSIGNAL:"));
    //    Serial.print(BSIGNAL);
    //    Serial.print(F("\n"));
    //    inChar = 3;
    switch (inChar) {
      case 1:
        Serial.print(F("1"));
        RSHEETS();
        break;
      case 2:
        Serial.print(F("2"));
        BSHEETS();
        break;
      case 3:
        Serial.print(F("3"));
        RTOWEL();
        break;
      case 4:
        Serial.print(F("4"));
        BTOWEL();
        break;
      case 255:
        Serial.print(F("255"));
        break;
      default:
        Serial.print(F("default"));
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
  }
}
