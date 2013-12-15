#include "config.h"

#include "I2C.h"
#include "IMU.h"
#include "Servo.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("---");

  I2C::begin();
  IMU::init();
  Servo::init();
}

void loop()
{
  IMU::refresh();

  Quaternion attitude = IMU::getAttitude();
  float roll = attitude.getRoll();
  float pitch = attitude.getPitch();
  float yaw = attitude.getYaw();

  Serial.print(roll);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.print(yaw);
  Serial.println("");

  // Compensate for roll and pitch
  Servo::setChannel(0, 1500 - (K_GIMBAL * pitch));
  Servo::setChannel(1, 1500 - (K_GIMBAL * roll));
}