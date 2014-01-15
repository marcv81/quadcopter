#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include "config.h"

#include "Quaternion.h"

/*!
 * This class provides the logic to combine accelerometer and gyroscope data into
 * an attitude quaternion. Call init() once, then refresh() (expensive) in the
 * main loop to refresh the attitude.
 */
class IMU
{
  public:

    static void init();
    static uint8_t refresh();

    // Calibration
    static void gyroCalibration();

    static uint32_t getLoopTime() { return loopTime; }
    static const Quaternion& getAttitude() { return attitude; }

  private:

    // Loop timer
    static uint32_t loopTime, loopStartTime, loopStopTime;

    // Attitude
    static Quaternion attitude;

    // Calibration
    static AxisAngle gyroBias;
};

#endif // IMU_H
