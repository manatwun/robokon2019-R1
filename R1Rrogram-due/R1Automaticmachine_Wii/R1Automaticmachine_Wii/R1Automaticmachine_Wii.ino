#include <Wii.h>
#include <usbhub.h>

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
WII Wii(&Btd, PAIR); // This will start an inquiry and then pair with your Wiimote - you only have to do this once
//WII Wii(&Btd); // After that you can simply create the instance like so and then press any button on the Wiimote

bool printAngle;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    while (1); //halt
  }
}
void loop() {
  Usb.Task();
  if (Wii.wiimoteConnected) {
    printAngle = !printAngle;
    if (Wii.getButtonClick(HOME)) { // You can use getButtonPress to see if the button is held down
      Serial.print(F("\r\nHOME"));
      Wii.disconnect();
    }

#if 1 // Set this to 1 in order to see the angle of the controllers
    if (printAngle) {
      Serial.print(F("\r\nPitch: "));
      Serial.print(Wii.getPitch());
      Serial.print(F("\tRoll: "));
      Serial.print(Wii.getRoll());
      if (Wii.motionPlusConnected) {
        Serial.print(F("\tYaw: "));
        Serial.print(Wii.getYaw());
      }
      if (Wii.nunchuckConnected) {
        Serial.print(F("\tNunchuck Pitch: "));
        Serial.print(Wii.getNunchuckPitch());
        Serial.print(F("\tNunchuck Roll: "));
        Serial.print(Wii.getNunchuckRoll());
      }
    }
#endif
  }
}
