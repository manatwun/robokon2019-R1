#include <PS3BT.h>
#include <usbhub.h>
#include <TimerOne.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.

volatile int FL = 0;
volatile int FR = 0;
volatile int RL = 0;
volatile int RR = 0;
volatile int FLB = 0;
volatile int FRB = 0;
volatile int RLB = 0;
volatile int RRB = 0;

volatile int FLCWD;
volatile int FRCWD;
volatile int RLCWD;
volatile int RRCWD;
volatile int FLCCWD;
volatile int FRCCWD;
volatile int RRCCWD;
volatile int RLCCWD;

volatile int FLCWDB;
volatile int FRCWDB;
volatile int RLCWDB;
volatile int RRCWDB;
volatile int FLCCWDB;
volatile int FRCCWDB;
volatile int RRCCWDB;
volatile int RLCCWDB;



#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

//If you want to change {OUTPUT pin number}, you can change OUTPUT pin number under here.//

#define FLCW 42 //front left  pin//
#define FLPWM 7
#define FLCCW 44

#define FRCW 29 //front right pin//
#define FRPWM 4
#define FRCCW 27

#define RLCW 46 //rear left  pin//
#define RLPWM 6
#define RLCCW 48

#define RRCW 36 //rear right pin//
#define RRPWM 5
#define RRCCW 28

#define MHCW 22 //high rope pin//
#define MHPWM 3
#define MHCCW 24

#define MRCW 40 //right rack pin//
#define MRPWM 8
#define MRCCW 38

#define MLCW 30 //left rack pin//
#define MLPWM 2
#define MLCCW 32

//If you want to change {max duty cycle}, you can change max duty cycle under here.//

#define MAXPWM 230

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printTemperature, printAngle;

void PWM() {
  if (FL < FLB) {
    FLB = FLB - 1;
    if (FLCWD == 1) {
      digitalWrite(FLCW, HIGH);
      digitalWrite(FLCCW, LOW);
    } else if (FLCWD == 0) {
      digitalWrite(FLCCW, HIGH);
      digitalWrite(FLCW, LOW);
    }
    if (FLCWDB != FLCWD) {
      FLB = 0;
      FL = 0;
    }
    if (FLB > MAXPWM) {
      FLB = MAXPWM;
    }
    FLCWDB = FLCWD;
    analogWrite(FLPWM, FLB);
  } else if (FL > FLB) {
    FLB = FLB + 1;
    if (FLCWD == 1) {
      digitalWrite(FLCW, HIGH);
      digitalWrite(FLCCW, LOW);
    } else if (FLCWD == 0) {
      digitalWrite(FLCCW, HIGH);
      digitalWrite(FLCW, LOW);
    }
    if (FLCWDB != FLCWD) {
      FLB = 0;
      FL = 0;
    }
    if (FLB > MAXPWM) {
      FLB = MAXPWM;
    }
    FLCWDB = FLCWD;
    if (FLB > MAXPWM) {
      FLB = MAXPWM;
    }
    analogWrite(FLPWM, FLB);
  }
  if (FR < FRB) {
    FRB = FRB - 1;
    if (FRCWD == 1) {
      digitalWrite(FRCW, HIGH);
      digitalWrite(FRCCW, LOW);
    } else if (FRCWD == 0) {
      digitalWrite(FRCCW, HIGH);
      digitalWrite(FRCW, LOW);
    }
    if (FRCWDB != FRCWD) {
      FRB = 0;
      FR = 0;
    }
    FRCWDB = FRCWD;
    if (FRB > MAXPWM) {
      FRB = MAXPWM;
    }
    analogWrite(FRPWM, FRB);
  } else if (FR > FRB) {
    FRB = FRB + 1;
    if (FRCWD == 1) {
      digitalWrite(FRCW, HIGH);
      digitalWrite(FRCCW, LOW);
    } else if (FRCWD == 0) {
      digitalWrite(FRCCW, HIGH);
      digitalWrite(FRCW, LOW);
    }
    if (FRCWDB != FRCWD) {
      FRB = 0;
      FR = 0;
    }
    if (FRB > MAXPWM) {
      FLB = MAXPWM;
    }
    FRCWDB = FRCWD;
    if (FRB > MAXPWM) {
      FRB = MAXPWM;
    }
    analogWrite(FRPWM, FRB);
  }
  if (RL < RLB) {
    RLB = RLB - 1;
    if (RLCWD == 1) {
      digitalWrite(RLCW, HIGH);
      digitalWrite(RLCCW, LOW);
    } else if (RLCWD == 0) {
      digitalWrite(RLCCW, HIGH);
      digitalWrite(RLCW, LOW);
    }
    if (RLCWDB != RLCWD) {
      RLB = 0;
      RL = 0;
    }
    RLCWDB = RLCWD;
    if (RLB > MAXPWM) {
      RLB = MAXPWM;
    }
    analogWrite(RLPWM, RLB);
  } else if (RL > RLB) {
    RLB = RLB + 1;
    if (RLCWD == 1) {
      digitalWrite(RLCW, HIGH);
      digitalWrite(RLCCW, LOW);
    } else if (RLCWD == 0) {
      digitalWrite(RLCCW, HIGH);
      digitalWrite(RLCW, LOW);
    }
    if (RLCWDB != RLCWD) {
      RLB = 0;
      RL = 0;
    }
    if (RLB > MAXPWM) {
      RLB = MAXPWM;
    }
    RLCWDB = RLCWD;
    analogWrite(RLPWM, RLB);
  }
  if (RR < RRB) {
    RRB = RRB - 1;
    if (RRCWD == 1) {
      digitalWrite(RRCW, HIGH);
      digitalWrite(RRCCW, LOW);
    } else if (RRCWD == 0) {
      digitalWrite(RRCCW, HIGH);
      digitalWrite(RRCW, LOW);
    }
    if (RRCWDB != RRCWD) {
      RRB = 0;
      RR = 0;
    }
    RRCWDB = RRCWD;
    if (RRB > MAXPWM) {
      RRB = MAXPWM;
    }
    analogWrite(RRPWM, RRB);
  } else if (RR > RRB) {
    RRB = RRB + 1;
    if (RRCWD == 1) {
      digitalWrite(RRCW, HIGH);
      digitalWrite(RRCCW, LOW);
    } else if (RRCWD == 0) {
      digitalWrite(RRCCW, HIGH);
      digitalWrite(RRCW, LOW);
    }
    if (RRCWDB != RRCWD) {
      RRB = 0;
      RR = 0;
    }
    RRCWDB = RRCWD;
    if (RRB > MAXPWM) {
      RRB = MAXPWM;
    }
    analogWrite(RRPWM, RRB);
  }
}

void setup() {
  Serial.begin(115200);
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

  Timer1.initialize(1000);
  Timer1.attachInterrupt(PWM);
  Timer1.stop();
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  pinMode(MHCW, OUTPUT);
  pinMode(MHCCW, OUTPUT);
  pinMode(MRCW, OUTPUT);
  pinMode(MRCCW, OUTPUT);
  pinMode(MLCW, OUTPUT);
  pinMode(MLCCW, OUTPUT);
  analogWrite(MRPWM, 0);
}

void loop() {
  unsigned long int XY;
  double xys, PWMX, PWMY, slope, xpy;
  double speedy, speedx;

  Usb.Task();

  double LY = 255 - (PS3.getAnalogHat(LeftHatY));
  double RY = 255 - (PS3.getAnalogHat(RightHatY));

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    Timer1.resume();

    if  (PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || RY > 137 || RY < 117) {
      Serial.print(F("bbbbbbbbbbbbbbbbbbbb"));

      if (RY > 137) {
        digitalWrite(MRCW, HIGH);
        digitalWrite(MRCCW, LOW);
        analogWrite(MRPWM, 100);
        digitalWrite(MLCW, HIGH);
        digitalWrite(MLCCW, LOW);
        analogWrite(MLPWM, 100);
        Serial.print(F("aaaaaaaaaaaaaaaaaa"));
      } else if (RY < 117) {
        digitalWrite(MRCW, LOW);
        digitalWrite(MRCCW, HIGH);
        analogWrite(MRPWM, 100);
        digitalWrite(MLCW, LOW);
        digitalWrite(MLCCW, HIGH);
        analogWrite(MLPWM, 100);
      } else {
        digitalWrite(MRCW, LOW);
        digitalWrite(MRCCW, LOW);
        analogWrite(MRPWM, 0);
        digitalWrite(MLCW, LOW);
        digitalWrite(MLCCW, LOW);
        analogWrite(MLPWM, 0);
      }
    } else if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || LY > 137 || LY < 117) {


      if ( PS3.getAnalogHat(LeftHatX) >= 128 && LY >= 128 ) {
        xys = (double)LY / PS3.getAnalogHat(LeftHatX);
        if (xys <= 1) { //0 to pai/4//
          PWMX =  (PS3.getAnalogHat(LeftHatX) - 127) * 2 - 19;
          PWMY = (LY - 127) * 2 - 19;
          if (PWMX < 1) {
            PWMX = 1;
          }
          if (PWMY < 1) {
            PWMY = 1;
          }
          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = 1.00 - xpy;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FL = speedy;
          RR = speedy;
          FR = speedx;
          RL = speedx;
          speedx = (int)speedx;
          speedy = (int)speedy;
          FLCWD = 0;
          RRCWD = 0;
          FRCCWD = 1;
          RLCCWD = 1;
          FLCCWD = 1;
          RRCCWD = 1;
          FRCWD = 0;
          RLCWD = 0;
        } else if (xys > 1) { //pai/4 to pai/2//
          PWMX =  (PS3.getAnalogHat(LeftHatX) - 127) * 2 - 19;
          PWMY = (LY - 127) * 2 - 19;
          if (PWMX < 1) {
            PWMX = 1;
          }
          if (PWMY < 1) {
            PWMY = 1;
          }

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = xpy - 1.0;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FL = speedy;
          RR = speedy;
          FR = speedx;
          RL = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;
          FLCWD = 1;
          RRCWD = 1;
          FRCCWD = 1;
          RLCCWD = 1;
          FLCCWD = 0;
          RRCCWD = 0;
          FRCWD = 0;
          RLCWD = 0;
        }
      }
      if ( PS3.getAnalogHat(LeftHatX) <= 127 && LY >= 128 ) {
        PWMX = (127 - PS3.getAnalogHat(LeftHatX)) * 2 - 19;
        PWMY = (LY - 127) * 2 - 19;
        if (PWMX < 1) {
          PWMX = 1;
        }
        if (PWMY < 1) {
          PWMY = 1;
        }
        xys = (double)PWMY / PWMX;
        if (xys >= 1) { //pai/2 to 3pai/4//
          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = xpy - 1.0;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }

          FR = speedy;
          RL = speedy;
          FL = speedx;
          RR = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;
          FLCWD = 1;
          RRCWD = 1;
          FRCCWD = 1;
          RLCCWD = 1;
          FLCCWD = 0;
          RRCCWD = 0;
          FRCWD = 0;
          RLCWD = 0;
        } else if (xys < 1) { //3pai/4 to pai//

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = 1.00 - xpy;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }

          FR = speedy;
          RL = speedy;
          FL = speedx;
          RR = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;
          FRCWD = 1;
          RLCWD = 1;
          FLCCWD = 0;
          RRCCWD = 0;
          FRCCWD = 0;
          RLCCWD = 0;
          FLCWD = 1;
          RRCWD = 1;
        }
      }

      if ( PS3.getAnalogHat(LeftHatX) <= 127 && LY <= 127 ) {
        PWMX = (127 - PS3.getAnalogHat(LeftHatX)) * 2 - 19;
        PWMY = (127 - LY) * 2 - 19;
        if (PWMX < 1) {
          PWMX = 1;
        }
        if (PWMY < 1) {
          PWMY = 1;
        }
        xys = (double)PWMY / PWMX;

        if (xys < 1) { //pai to 5pai/4//

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = 1.0 - xpy;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FL = speedy;
          RR = speedy;
          FR = speedx;
          RL = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;
          FLCCWD = 0;
          FRCWD = 1;
          RLCWD = 1;
          RRCCWD = 0;
          FLCWD = 1;
          FRCCWD = 0;
          RRCWD = 1;
          RLCCWD = 0;

        } else if (xys >= 1) { //5pai/4 to 3pai/2//

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = xpy - 1.0;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FL = speedy;
          RR = speedy;
          FR = speedx;
          RL = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;
          FLCCWD = 1;
          RRCCWD = 1;
          FRCCWD = 0;
          RLCCWD = 0;
          FLCWD = 0;
          RRCWD = 0;
          FRCWD = 1;
          RLCWD = 1;
        }
      }

      if ( PS3.getAnalogHat(LeftHatX) >= 128 && LY <= 127 ) {
        PWMX = (PS3.getAnalogHat(LeftHatX) - 128) * 2 - 19;
        PWMY = (127 - LY) * 2 - 19;
        if (PWMX <= 1) {
          PWMX = 1;
        }
        if (PWMY < 1) {
          PWMY = 1;
        }
        xys = (double)PWMY / PWMX;
        if (xys > 1) { //3pai/2 to 7pai/4//

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;

          xpy = xpy - 1.0;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FR = speedy;
          RL = speedy;
          FL = speedx;
          RR = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;

          FLCCWD = 1;
          RRCCWD = 1;
          FRCCWD = 0;
          RLCCWD = 0;
          FLCWD = 0;
          RRCWD = 0;
          FRCWD = 1;
          RLCWD = 1;

        } else if (xys < 1) { //7pai/4 to 2pai//

          XY = (PWMX * PWMX) + (PWMY * PWMY);
          slope = sqrt(XY);
          speedx = slope;
          if (speedx < 1) {
            speedx = 1;
          } else if (speedx > MAXPWM) {
            speedx = MAXPWM;
          }

          xpy = PWMY / PWMX;
          xpy = 1.0 - xpy;
          speedy = slope * xpy;
          if (speedy < 1) {
            speedy = 1;
          } else if (speedy > MAXPWM) {
            speedy = MAXPWM;
          }
          FR = speedy;
          RL = speedy;
          FL = speedx;
          RR = speedx;

          speedx = (int)speedx;
          speedy = (int)speedy;

          FRCCWD = 1;
          RLCCWD = 1;
          FLCWD = 0;
          RRCWD = 0;
          FLCCWD = 1;
          RRCCWD = 1;
          FRCWD = 0;
          RLCWD = 0;
        }
      }
    } else if (PS3.getAnalogButton(L2) && PS3.getAnalogButton(R2)) {
      if (PS3.getAnalogButton(L2) > PS3.getAnalogButton(R2)) {
        double turnL = (double)PS3.getAnalogButton(L2) - 19;
        if (turnL < 1) {
          turnL = 0;
        }
        double turnR = (double)PS3.getAnalogButton(R2) - 19;
        if (turnR < 1) {
          turnR = 0;
        }
        turnL = turnL - turnR;
        if (turnL < 1) {
          turnL = 0;
        }
        if (turnL > MAXPWM) {
          turnL = MAXPWM;
        }
        FR = turnL;
        RL = turnL;
        FL = turnL;
        RR = turnL;
        FLCCWD = 1;
        FLCWD = 0;
        FRCWD = 0;
        FRCCWD = 1;
        RLCCWD = 0;
        RLCWD = 1;
        RRCWD = 1;
        RRCCWD = 0;
      } else if (PS3.getAnalogButton(L2) < PS3.getAnalogButton(R2)) {
        double turnL = (double)PS3.getAnalogButton(L2) - 19;
        if (turnL < 1) {
          turnL = 0;
        }
        double turnR = (double)PS3.getAnalogButton(R2) - 19;
        if (turnR < 1) {
          turnR = 0;
        }
        turnR = turnR - turnL;
        if (turnR < 1) {
          turnR = 0;
        }
        if (turnR > MAXPWM) {
          turnR = MAXPWM;
        }
        FL = turnR;
        FR = turnR;
        RL = turnR;
        RR = turnR;

        FLCWD = 1;
        FLCCWD = 0;
        FRCWD = 1;
        FRCCWD = 0;
        RLCWD = 0;
        RLCCWD = 1;
        RRCWD = 0;
        RRCCWD = 1;
      } else {
        FL = 0;
        FR = 0;
        RL = 0;
        RR = 0;

        FLB = 0;
        FRB = 0;
        RLB = 0;
        RRB = 0;

        FLCWD = 0;
        FLCCWD = 0;
        FRCWD = 0;
        FRCCWD = 0;
        RLCWD = 0;
        RLCCWD = 0;
        RRCWD = 0;
        RRCCWD = 0;
      }
    } else if (PS3.getAnalogButton(L2)) {
      double turnL = (double)PS3.getAnalogButton(L2) - 19;
      if (turnL < 1) {
        turnL = 0;
      }
      FR = turnL;
      RL = turnL;
      FL = turnL;
      RR = turnL;
      FLCCWD = 1;
      FLCWD = 0;
      FRCWD = 0;
      FRCCWD = 1;
      RLCCWD = 0;
      RLCWD = 1;
      RRCWD = 1;
      RRCCWD = 0;
    } else if (PS3.getAnalogButton(R2)) {
      double turnR = (double)PS3.getAnalogButton(R2) - 19;
      if (turnR < 1) {
        turnR = 0;
      }
      FL = turnR;
      FR = turnR;
      RL = turnR;
      RR = turnR;

      FLCWD = 1;
      FLCCWD = 0;
      FRCWD = 1;
      FRCCWD = 0;
      RLCWD = 0;
      RLCCWD = 1;
      RRCWD = 0;
      RRCCWD = 1;
    } else if (PS3.getAnalogButton(UP)) {
      digitalWrite(MHCW, HIGH);
      digitalWrite(MHCCW, LOW);
      analogWrite(MHPWM, 230);
      Serial.print(F("up\n"));
    } else if (PS3.getAnalogButton(DOWN)) {
      digitalWrite(MHCW, LOW);
      digitalWrite(MHCCW, HIGH);
      analogWrite(MHPWM, 230);
      Serial.print(F("down\n"));
    } else {
      digitalWrite(FLCW, LOW);
      digitalWrite(FLCCW, LOW);
      analogWrite(FLPWM, 0);
      digitalWrite(FRCW, LOW);
      digitalWrite(FRCCW, LOW);
      analogWrite(FRPWM, 0);
      digitalWrite(RLCW, LOW);
      digitalWrite(RLCCW, LOW);
      analogWrite(RLPWM, 0);
      digitalWrite(RRCW, LOW);
      digitalWrite(RRCCW, LOW);
      analogWrite(RRPWM, 0);
      digitalWrite(MRCW, LOW);
      digitalWrite(MRCCW, LOW);
      analogWrite(MRPWM, 0);
      digitalWrite(MLCW, LOW);
      digitalWrite(MLCCW, LOW);
      analogWrite(MLPWM, 0);
      digitalWrite(MHCW, LOW);
      digitalWrite(MHCCW, LOW);
      analogWrite(MHPWM, 0);
      FL = 0;
      FR = 0;
      RL = 0;
      RR = 0;
      FLB = 0;
      FRB = 0;
      RLB = 0;
      RRB = 0;
    }

    if (PS3.getButtonClick(PS)) {

      PS3.disconnect();
      digitalWrite(FLCW, LOW);
      digitalWrite(FLCCW, LOW);
      analogWrite(FLPWM, 0);
      digitalWrite(FRCW, LOW);
      digitalWrite(FRCCW, LOW);
      analogWrite(FRPWM, 0);
      digitalWrite(RLCW, LOW);
      digitalWrite(RLCCW, LOW);
      analogWrite(RLPWM, 0);
      digitalWrite(RRCW, LOW);
      digitalWrite(RRCCW, LOW);
      analogWrite(RRPWM, 0);
      digitalWrite(MHCW, LOW);
      digitalWrite(MHCCW, LOW);
      analogWrite(MHPWM, 0);
      digitalWrite(MLCW, LOW);
      digitalWrite(MLCCW, LOW);
      analogWrite(MLPWM, 0);
      digitalWrite(MRCW, LOW);
      digitalWrite(MRCCW, LOW);
      analogWrite(MRPWM, 0);
      Timer1.stop();
    }
  } else {
    FL = 0;
    FR = 0;
    RL = 0;
    RR = 0;
    FLB = 0;
    FRB = 0;
    RLB = 0;
    RRB = 0;
    digitalWrite(MRCW, LOW);
    digitalWrite(MRCCW, LOW);
    analogWrite(MRPWM, 0);
    digitalWrite(MLCW, LOW);
    digitalWrite(MLCCW, LOW);
    analogWrite(MLPWM, 0);
  }
}
