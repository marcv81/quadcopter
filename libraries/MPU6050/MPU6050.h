#ifndef MPU6050_H
#define MPU6050_H

#include <Arduino.h>
#include "config.h"

// I2C address
#define MPU6050_ADDRESS 0x68

// Registers
#define MPU6050_CONFIG 0x6B // 1 byte (bit 7: reset, bit 6: sleep mode)
#define MPU6050_DATA 0x3B // 3x2 bytes (gyro) + 1x2 bytes (temp) + 3x2 bytes (accel)

// Axis sensitivities
#define MPU6050_ACCEL_SENSITIVITY 16384.0 // LSB per G
#define MPU6050_GYRO_SENSITIVITY 7505.7471 // LSB per radian

/*!
 * This class provides functions to read 3-axis accelerometer/gyroscope data from the
 * Invensense MPU-6050. Call init() once, then refresh() (expensive) in the main loop
 * to refresh the data, and use the public accessors (cheap) to access the data.
 */
class MPU6050
{

  public:

    static void init();
    static void refresh();

    static float getAccelX() { return accelX; }
    static float getAccelY() { return accelY; }
    static float getAccelZ() { return accelZ; }
    static float getGyroX() { return gyroX; }
    static float getGyroY() { return gyroY; }
    static float getGyroZ() { return gyroZ; }

  private:

    /*! This type stores raw accelerometer/temperature/gyroscope data. */
    typedef struct rawData_t
    {
      int16_t accelX;
      int16_t accelY;
      int16_t accelZ;
      int16_t temperature;
      int16_t gyroX;
      int16_t gyroY;
      int16_t gyroZ;
    };

    static float accelX;
    static float accelY;
    static float accelZ;
    static float gyroX;
    static float gyroY;
    static float gyroZ;

    static rawData_t rawData;

    /*!
     * This function reads raw accelerometer/temperature/gyroscope data and stores
     * the values in the rawData variable.
     *
     * @return I2C error code
     */
    static uint8_t readRawData();

};

#endif // MPU6050_H
