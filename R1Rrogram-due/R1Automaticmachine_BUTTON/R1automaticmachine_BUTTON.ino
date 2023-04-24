//#include <PS3BT.h>
//#include <usbhub.h>
//
//// Satisfy the IDE, which needs to see the include statment in the ino too.
//#ifdef dobogusinclude
//#include <spi4teensy3.h>
//#endif
//#include <SPI.h>
//
//USB Usb;
////USBHub Hub1(&Usb); // Some dongles have a hub inside
//
//BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
///* You can create the instance of the class in two ways */
//PS3BT PS3(&Btd); // This will just create the instance
////PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch
//
//bool printTemperature, printAngle;

volatile byte count = 0;
#define SHEETS 4
#define TOWEL 5
#define BR 6
#define SWITCH 7

void setup() {
  Serial.begin(1200);
//#if !defined(__MIPSEL__)
//  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
//#endif
//  if (Usb.Init() == -1) {
//
//    while (1); //halt
//  }
  pinMode(SHEETS, INPUT);
  pinMode(TOWEL, INPUT);
  pinMode(BR, INPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
//  Usb.Task();

//  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
//    if (PS3.getButtonClick(PS)) {
//      digitalWrite(EMER, LOW);
//      digitalWrite(DBOARD, HIGH);
//    }
//  }
  count = 0;
    if (digitalRead(SHEETS) == HIGH && digitalRead(BR) == HIGH && digitalRead(SWITCH) == LOW) {
      count = 1;
      Serial.write(count);
    } else if (digitalRead(SHEETS) == HIGH && digitalRead(BR) == LOW && digitalRead(SWITCH) == LOW) {
      count = 2;
      Serial.write(count);
    } else if (digitalRead(TOWEL) == HIGH && digitalRead(BR) == HIGH && digitalRead(SWITCH) == LOW) {
      count = 3;
      Serial.write(count);
    } else if (digitalRead(TOWEL) == HIGH && digitalRead(BR) == LOW && digitalRead(SWITCH) == LOW) {
      count = 4;
      Serial.write(count);
    }
}
