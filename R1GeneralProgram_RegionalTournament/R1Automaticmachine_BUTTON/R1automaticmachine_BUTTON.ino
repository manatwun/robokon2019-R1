#include <PS3BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printTemperature, printAngle;

volatile byte count = 0;
#define SHEETS 2
#define TOWEL 4
#define OSHEETS 5
#define OTOWEL 7
#define BR 3
#define RESET 6
#define DBOARD 8
#define EMER 9
#define CHECK 0

void setup() {
  Serial.begin(500000);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {

    while (1); //halt
  }
  pinMode(SHEETS, INPUT);
  pinMode(TOWEL, INPUT);
  pinMode(OSHEETS, INPUT);
  pinMode(OTOWEL, INPUT);
  pinMode(BR, INPUT);
  pinMode(RESET, INPUT);
  pinMode(DBOARD, OUTPUT);
  pinMode(EMER, OUTPUT);
  digitalWrite(EMER, HIGH);
}

void loop() {
  Usb.Task();
//  Serial.print(F("V:"));
//  Serial.print(analogRead(CHECK));
//  Serial.print(F("\n\n\n\n"));


  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    if (PS3.getButtonClick(PS)) {
      digitalWrite(EMER, LOW);
      digitalWrite(DBOARD, HIGH);
    }
  }
  count = 0;
  if (analogRead(CHECK) > 1000) {
    if (digitalRead(SHEETS) == HIGH && digitalRead(BR) == HIGH) {
      count = 1;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));;
    } else if (digitalRead(SHEETS) == HIGH && digitalRead(BR) == LOW) {
      count = 2;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } else if (digitalRead(TOWEL) == HIGH && digitalRead(BR) == HIGH) {
      count = 3;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } else if (digitalRead(TOWEL) == HIGH && digitalRead(BR) == HIGH) {
      count = 4;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } else if (digitalRead(OSHEETS) == HIGH) {
      count = 5;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } else if (digitalRead(OTOWEL) == HIGH) {
      count = 6;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } else if (digitalRead(RESET) == HIGH) {
      count = 6;
      Serial.write(count);
//      Serial.print(F("count:"));
//      Serial.print(count);
//      Serial.print(F("\n\n\n\n"));
    } /*else if (digitalRead(EMER) == HIGH) {
      count = 7;
      Serial.write(count);
      Serial.print(count);
    } /*else if (analogRead(OSHEETS) == LOW) {
      Serial.write(9);
    }*/
  }
}
