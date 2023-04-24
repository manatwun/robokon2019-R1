#include <TimerOne.h>

#define PRIM1 22
#define PRIM2 23
#define PRIM3 27
#define PRIM4 29

#define FLENC 4
#define FRENC 5
#define RLENC 2
#define RRENC 3

#define XENC 0
#define YENC 1

volatile int FLE = 0;
volatile int FRE = 0;
volatile int RLE = 0;
volatile int RRE = 0;
volatile int RIM1 = 0;
volatile int RIM2 = 0;
volatile int RIM3 = 0;
volatile int RIM4 = 0;
volatile int XE = 0;
volatile int YE = 0;

void sendA(int value) {
  Serial3.write('A'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
  Serial.print(F("\nFL:"));
  Serial.print(FLE);
}
void sendB(int value) {
  Serial3.write('B'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
}
void sendC(int value) {
  Serial3.write('C'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
}
void sendD(int value) {
  Serial3.write('D'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
}
void sendE(int value) {
  Serial3.write('E'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
}
void sendF(int value) {
  Serial3.write('F'); // ヘッダの送信
  Serial3.write(lowByte(value)); // 下位バイトの送信
  Serial3.write(highByte(value)); // 上位バイトの送信
}
//void sendG(int value) {
//  Serial3.write('G'); // ヘッダの送信
//  Serial3.write(lowByte(value)); // 下位バイトの送信
//  Serial3.write(highByte(value)); // 上位バイトの送信
//}
//void sendH(int value) {
//  Serial3.write('H'); // ヘッダの送信
//  Serial3.write(lowByte(value)); // 下位バイトの送信
//  Serial3.write(highByte(value)); // 上位バイトの送信
//}
//void sendI(int value) {
//  Serial3.write('I'); // ヘッダの送信
//  Serial3.write(lowByte(value)); // 下位バイトの送信
//  Serial3.write(highByte(value)); // 上位バイトの送信
//}
//void sendJ(int value) {
//  Serial3.write('J'); // ヘッダの送信
//  Serial3.write(lowByte(value)); // 下位バイトの送信
//  Serial3.write(highByte(value)); // 上位バイトの送信
//}
//void sendK(int value) {
//  Serial.write('K'); // ヘッダの送信
//  Serial.write(lowByte(value)); // 下位バイトの送信
//  Serial.write(highByte(value)); // 上位バイトの送信
//}

void RIM() {
  if (digitalRead(PRIM1) == HIGH) {
    RIM1 = 1;
  } else {
    RIM1 = 0;
  }
  if (digitalRead(PRIM2) == HIGH) {
    RIM2 = 1;
  } else {
    RIM2 = 0;
  }
  if (digitalRead(PRIM3) == HIGH) {
    RIM3 = 1;
  } else {
    RIM3 = 0;
  }
  if (digitalRead(PRIM4) == HIGH) {
    RIM4 = 1;
  } else {
    RIM4 = 0;
  }
}


void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(PRIM1, INPUT);
  pinMode(PRIM2, INPUT);
  pinMode(PRIM3, INPUT);
  pinMode(PRIM4, INPUT);
//  Timer1.initialize(1);
//  Timer1.attachInterrupt(RIM);
//  Timer1.stop();
//  Timer1.resume();

  attachInterrupt(0, XCOUNTER, CHANGE);
  attachInterrupt(1, YCOUNTER, CHANGE);
  attachInterrupt(2, FLCOUNTER, CHANGE);
  attachInterrupt(3, FRCOUNTER, CHANGE);
  attachInterrupt(4, RLCOUNTER, CHANGE);
  attachInterrupt(5, RRCOUNTER, CHANGE);
}

void XCOUNTER() {
  Serial.print(F("\nXE:"));
  Serial.print(XE);
  XE++;
}
void YCOUNTER() {
  Serial.print(F("\nYE:"));
  Serial.print(YE);
  YE++;
}
void FLCOUNTER() {
  Serial.print(F("\nFLE:"));
  Serial.print(FLE);
  FLE++;
}
void FRCOUNTER() {
  Serial.print(F("\nFRE:"));
  Serial.print(FRE);
  FRE++;
}
void RLCOUNTER() {
  Serial.print(F("\nRLE:"));
  Serial.print(RLE);
  RLE++;
}
void RRCOUNTER() {
  Serial.print(F("\nRRE:"));
  Serial.print(RRE);
  RRE++;
}
void loop() {
  sendA(FLE);
  sendB(FRE);
  sendC(RLE);
  sendD(RRE);
  sendE(XE);
  sendF(YE);
//  sendG(RIM1);
//  sendH(RIM2);
//  sendI(RIM3);
//  sendJ(RIM4);
}
