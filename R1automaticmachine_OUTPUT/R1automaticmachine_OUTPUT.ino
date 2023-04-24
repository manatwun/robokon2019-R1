#include <TimerOne.h>
#include <MsTimer2.h>
//If you want to change {OUTPUT pin number}, you can change OUTPUT pin number under here.//

#define FLCW 28 //front left  pin//
#define FLPWM 9
#define FLCCW 26

#define FRCW 30 //front right pin//
#define FRPWM 2
#define FRCCW 32

#define RLCW 23 //rear left  pin//
#define RLPWM 5
#define RLCCW 25

#define RRCW 22 //rear right pin//
#define RRPWM 4
#define RRCCW 24

#define MHCW 36 //high rope pin//
#define MHPWM 11
#define MHCCW 34

#define MRCW 44 //right rack pin//
#define MRPWM 6
#define MRCCW 42

#define MLCW 38 //left rack pin//
#define MLPWM 7
#define MLCCW 40

//If you want to change {max duty cycle}, you can change max duty cycle under here.//

#define MAXPWM 204
volatile int count = 0;
volatile int FL;
volatile int FR;
volatile int RL;
volatile int RR;
volatile int FLB;
volatile int FRB;
volatile int RLB;
volatile int RRB;

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

volatile int RIM1;
volatile int RIM2;
volatile int RIM3;
volatile int RIM4;

volatile int ACOUNTER;
volatile int BSIGNAL;

void PWM() {
  //  if (FLCWD == 1) {
  //    digitalWrite(FLCW, HIGH);
  //    digitalWrite(FLCCW, LOW);
  //  } else if (FLCWD == 0) {
  //    digitalWrite(FLCW, LOW);
  //    digitalWrite(FLCCW, HIGH);
  //  }
  //  if (FLE + 3 < FLE) {
  //    FL++;
  //  } else if (FLE - 3 > FLE) {
  //    FL--;
  //  }
  //  analogWrite(FLPWM, FL);
  //
  //  if (FRCWD == 1) {
  //    digitalWrite(FRCW, HIGH);
  //    digitalWrite(FRCCW, LOW);
  //  } else if (FRCWD == 0) {
  //    digitalWrite(FRCW, LOW);
  //    digitalWrite(FRCCW, HIGH);
  //  }
  //  if (FRE + 3 < FLE) {
  //    FR++;
  //  } else if (FRE - 3 > FLE) {
  //    FR--;
  //  }
  //  analogWrite(FRPWM, FR);
  //
  //  if (RLCWD == 1) {
  //    digitalWrite(RLCW, HIGH);
  //    digitalWrite(RLCCW, LOW);
  //  } else if (RLCWD == 0) {
  //    digitalWrite(RLCW, LOW);
  //    digitalWrite(RLCCW, HIGH);
  //  }
  //  if (RLE + 3 < FLE) {
  //    RL++;
  //  } else if (RLE - 3 > FLE) {
  //    RL--;
  //  }
  //  analogWrite(RLPWM, RL);
  //
  //  if (RRCWD == 1) {
  //    digitalWrite(RRCW, HIGH);
  //    digitalWrite(RRCCW, LOW);
  //  } else if (RRCWD == 0) {
  //    digitalWrite(RRCW, LOW);
  //    digitalWrite(RRCCW, HIGH);
  //  }
  //  if (RRE + 3 < FLE) {
  //    RR++;
  //  } else if (RRE - 3 > FLE) {
  //    RR--;
  //  }
  //  analogWrite(RRPWM, RR);
}

void TSTOP() {
  Serial.print(F("uuuuuuuuuuuuuuuuuuuuuuuuuuuuu"));
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

void RENC() {
  if ( Serial1.available() >= sizeof('A') + sizeof(int) ) {
    if ( Serial1.read() == 'A' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      FLE = makeWord(high, low);
      Serial.print(F("\nFLE:"));
      Serial.print(FLE);
    }
  }
  if ( Serial1.available() >= sizeof('B') + sizeof(int) ) {
    if ( Serial1.read() == 'B' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      FRE = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('C') + sizeof(int) ) {
    if ( Serial1.read() == 'C' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RLE = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('D') + sizeof(int) ) {
    if ( Serial1.read() == 'D' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RRE = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('E') + sizeof(int) ) {
    if ( Serial1.read() == 'E' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      XE = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('F') + sizeof(int) ) {
    if ( Serial1.read() == 'F' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      YE = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('G') + sizeof(int) ) {
    if ( Serial1.read() == 'G' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RIM1 = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('H') + sizeof(int) ) {
    if ( Serial1.read() == 'H' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RIM2 = makeWord(high, low);
    }
  }
  if ( Serial1.available() >= sizeof('I') + sizeof(int) ) {
    if ( Serial1.read() == 'I' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RIM3 = makeWord(high, low);
    }
  }

  if ( Serial1.available() >= sizeof('J') + sizeof(int) ) {
    if ( Serial1.read() == 'J' ) {
      int low = Serial1.read();
      int high = Serial1.read();
      RIM4 = makeWord(high, low);
    }
  }
}

void RTOWEL() {
  Serial.print(F("jjjjjjjjjjjjjjjjjjjjj"));
  FLCWD = 1;
  FRCWD = 1;
  RLCWD = 1;
  RRCWD = 1;
  FL = 200;
  FR = 200;
  RL = 200;
  RR = 200;
  YEB = YE;
  digitalWrite(FLCCW, HIGH);
  digitalWrite(FRCCW, HIGH);
  digitalWrite(RLCCW, HIGH);
  digitalWrite(RRCCW, HIGH);
  digitalWrite(FLCW, HIGH);
  digitalWrite(FRCW, HIGH);
  digitalWrite(RLCW, HIGH);
  digitalWrite(RRCW, HIGH);
  digitalWrite(MHCW, HIGH);
  digitalWrite(MHCCW, HIGH);
  digitalWrite(MRCW, HIGH);
  digitalWrite(MRCCW, HIGH);
  digitalWrite(MLCW, HIGH);
  digitalWrite(MLCCW, HIGH);
  analogWrite(FLPWM,240);
  analogWrite(FRPWM,240);
  analogWrite(RLPWM,240);
  analogWrite(RRPWM,240);
  analogWrite(MLPWM,240);
  analogWrite(MHPWM,240);
  analogWrite(MRPWM,240);
  while (YE - YEB < 200) {
  }
  FLCWD = 1;
  FRCWD = 1;
  RLCWD = 0;
  RRCWD = 0;
  FL = 240;
  FR = 240;
  RL = 240;
  RR = 240;
  YEB = YE;
  Serial.print(F("hhhhhhhhhhhhhhhhhhhh"));
  while (YE - YEB < 1875) {
  }
  FLCWD = 1;
  FRCWD = 1;
  RLCWD = 0;
  RRCWD = 0;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  YEB = YE;
  while (YE - YEB < 200) {
  }
  TSTOP();
  while (MHE - MHEB < 500) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (XE - XEB < 1037) {
  }
  TSTOP();
  XEB = XE;
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (XE - XEB < 424) {
  }
  TSTOP();
  XEB = XE;
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (XE - XEB < 424) {
  }
  TSTOP();
  XEB = XE;
  while (MHE - MHEB < 100) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 0;
  RLCWD = 0;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (XE - XEB < 620) {
  }
  XEB = XE;
  TSTOP();
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 1;
  RLCWD = 1;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (YE - YEB < 100) {
  }
  TSTOP();
  YEB = YE;
  while (MHE - MHEB < 200) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
  }
  digitalWrite(MHCCW, LOW);
  analogWrite(MHPWM, 0);
  MHEB = MHE;
  delay(100);
  FRCWD = 1;
  RLCWD = 1;
  FLCWD = 1;
  RRCWD = 1;
  FL = 50;
  FR = 50;
  RL = 50;
  RR = 50;
  while (XE - XEB < 2507) {
  }
  XEB = XE;
  TSTOP();
  FLCWD = 0;
  RRCWD = 0;
  FRCWD = 1;
  RLCWD = 1;
  FL = 240;
  FR = 240;
  RL = 240;
  RR = 240;
  while (YE - YEB < 2175) {
  }
  TSTOP();
  delay(2000);
}

void RSHEETS() {
  /* FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    YEB = YE;
    while (YE - YEB < 200) {
    }
    FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 240;
    FR = 240;
    RL = 240;
    RR = 240;
    YEB = YE;
    while (YE - YEB < 2936) {
    }
    FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    YEB = YE;
    while (YE - YEB < 200) {
    }
    TSTOP();
  */
}

void BTOWEL() {
  /*
    FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    YEB = YE;
    while (YE - YEB < ) {
    }
    FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 150;
    FR = 150;
    RL = 150;
    RR = 150;
    YEB = YE;
    while (YE - YEB距離が短い間) {
    }
    FLCWD = 1;
    FRCWD = 1;
    RLCWD = 0;
    RRCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    YEB = YE;
    while (距離が近くなった) {
    }
    TSTOP();
    while (巻き上げロリコン) {
    digitalWrite(MHCW, HIGH);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 50);
    }
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 0);
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (右1) {
    }
    TSTOP();
    while (巻き下げロリコン1) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
    }
    digitalWrite(MHCW, LOW);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 0);
    delay(100);
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (右2) {
    }
    TSTOP();
    while (巻き下げロリコン2) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
    }
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 0);
    delay(100);
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (右3) {
    }
    TSTOP();
    while (巻き下げ3) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
    }
    digitalWrite(MHCW, LOW);
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 0);
    delay(100);
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (右最後) {
    }
    TSTOP();
    while (巻き下げリセット) {
    digitalWrite(MHCCW, HIGH);
    digitalWrite(MHCW, LOW);
    analogWrite(MHPWM, 50);
    }
    digitalWrite(MHCCW, LOW);
    analogWrite(MHPWM, 0);
    delay(100);
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 1;
    RLCWD = 1;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (下がる) {
    }
    TSTOP();
    FRCWD = 1;
    RLCWD = 1;
    FLCWD = 1;
    RRCWD = 1;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    while (左) {
    }
    FLCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    RRCWD = 0;
    FL = 0;
    FR = 0;
    RL = 0;
    RR = 0;
    while (下がる) {
    FLCWD = 0;
    RRCWD = 0;
    FRCWD = 1;
    RLCWD = 1;
    FL = 50;
    FR = 50;
    RL = 50;
    RR = 50;
    }
    FLCWD = 0;
    FRCWD = 0;
    RLCWD = 0;
    RRCWD = 0;
    FL = 0;
    FR = 0;
    RL = 0;
    RR = 0;
    delay(5000);
  */
}

void BSHEETS() {

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

  delay(500);

  MsTimer2::set(10, PWM);
  MsTimer2::start();

  //  Timer1.initialize(999);
  //  Timer1.attachInterrupt(RENC);
  //  Timer1.stop();
  //  Timer1.resume();



  Serial2.begin(9600);



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
  XE = 0;
  YE = 0;
  Serial.print(F("BSIGNAL"));
  Serial.print(BSIGNAL);
  Serial.print(F("\n"));

  RTOWEL();
  while (Serial2.available()) {
    byte inChar = (byte)Serial2.read();
    delay(10);
    BSIGNAL = inChar;
    Serial.print(F("BSIGNAL"));
    Serial.print(BSIGNAL);
    Serial.print(F("\n"));

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
    Serial.print(F("BSIGNAL"));
    Serial.print(BSIGNAL);
    Serial.print(F("\n"));
    break;
  }
}
