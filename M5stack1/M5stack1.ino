#include "MPU9250.h"
#include "quaternionFilters.h"

#define processing_out false
#define AHRS true         // Set to false for basic data read
#define SerialDebug true  // Set to true to get Serial output for debugging
#define LCD

MPU9250 IMU;
// Kalman kalmanX, kalmanY, kalmanZ; // Create the Kalman instances

void setup()
{
  M5.begin();
  Wire.begin();

  IMU.MPU9250SelfTest(IMU.SelfTest);

  // キャリブレーション
  IMU.calibrateMPU9250(IMU.gyroBias, IMU.accelBias);
  IMU.initMPU9250();

  delay(500);
  // 磁気のキャリブレーション
  IMU.initAK8963(IMU.magCalibration);

  // LCDの設定
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(GREEN ,BLACK);
  M5.Lcd.fillScreen(BLACK);
}

void loop()
{
  // If intPin goes high, all data registers have new data
  // On interrupt, check if data ready interrupt
  if (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)
  {  
    IMU.readAccelData(IMU.accelCount);  // Read the x/y/z adc values
    IMU.getAres();

    // 加速度の計算
    IMU.ax = (float)IMU.accelCount[0]*IMU.aRes; // - accelBias[0];
    IMU.ay = (float)IMU.accelCount[1]*IMU.aRes; // - accelBias[1];
    IMU.az = (float)IMU.accelCount[2]*IMU.aRes; // - accelBias[2];

    IMU.readGyroData(IMU.gyroCount);  // Read the x/y/z adc values
    IMU.getGres();

    // ジャイロの値を取得
    IMU.gx = (float)IMU.gyroCount[0]*IMU.gRes;
    IMU.gy = (float)IMU.gyroCount[1]*IMU.gRes;
    IMU.gz = (float)IMU.gyroCount[2]*IMU.gRes;

    IMU.readMagData(IMU.magCount);  // Read the x/y/z adc values
    IMU.getMres();
    IMU.magbias[0] = +470.;
    IMU.magbias[1] = +120.;
    IMU.magbias[2] = +125.;

    // 磁力[mG:ミリガウス]を取得
    IMU.mx = (float)IMU.magCount[0]*IMU.mRes*IMU.magCalibration[0] - IMU.magbias[0];
    IMU.my = (float)IMU.magCount[1]*IMU.mRes*IMU.magCalibration[1] - IMU.magbias[1];
    IMU.mz = (float)IMU.magCount[2]*IMU.mRes*IMU.magCalibration[2] - IMU.magbias[2];
  }

  IMU.updateTime();

  MahonyQuaternionUpdate(IMU.ax, IMU.ay, IMU.az, IMU.gx*DEG_TO_RAD,
                         IMU.gy*DEG_TO_RAD, IMU.gz*DEG_TO_RAD, IMU.my,
                         IMU.mx, IMU.mz, IMU.deltat);

  IMU.delt_t = millis() - IMU.count;

  // 100ms毎のロールピッチヨー角を計算して表示
  if (IMU.delt_t > 100)
  {
      IMU.yaw   = atan2(2.0f * (*(getQ()+1) * *(getQ()+2) + *getQ() *
                    *(getQ()+3)), *getQ() * *getQ() + *(getQ()+1) * *(getQ()+1)
                    - *(getQ()+2) * *(getQ()+2) - *(getQ()+3) * *(getQ()+3));
      IMU.pitch = -asin(2.0f * (*(getQ()+1) * *(getQ()+3) - *getQ() *
                    *(getQ()+2)));
      IMU.roll  = atan2(2.0f * (*getQ() * *(getQ()+1) + *(getQ()+2) *
                    *(getQ()+3)), *getQ() * *getQ() - *(getQ()+1) * *(getQ()+1)
                    - *(getQ()+2) * *(getQ()+2) + *(getQ()+3) * *(getQ()+3));
      IMU.pitch *= RAD_TO_DEG;
      IMU.yaw   *= RAD_TO_DEG;
      IMU.yaw   -= 8.5;
      IMU.roll  *= RAD_TO_DEG;

      M5.Lcd.setCursor(0, 0); M5.Lcd.print("    x      y      z ");
      M5.Lcd.setCursor(0,  24);
      M5.Lcd.printf("% 5d  % 5d  % 5d  mg  \n",  (int)(1000*IMU.ax), (int)(1000*IMU.ay), (int)(1000*IMU.az));
      M5.Lcd.setCursor(0,  44);
      M5.Lcd.printf("% 5d  % 5d  % 5d  deg/s \n", (int)(IMU.gx), (int)(IMU.gy), (int)(IMU.gz));
      M5.Lcd.setCursor(0,  64);
      M5.Lcd.printf("% 5d  % 5d  % 5d  mG   \n",  (int)(IMU.mx), (int)(IMU.my), (int)(IMU.mz));

      M5.Lcd.setCursor(0,  100);
      M5.Lcd.printf("yaw : % 5.2f  \r\n",(IMU.yaw));
      M5.Lcd.printf("pitch : % 5.2f  \r\n",(IMU.pitch));
      M5.Lcd.printf("roll : % 5.2f  \r\n",(IMU.roll));
      IMU.count = millis();
  }
}
