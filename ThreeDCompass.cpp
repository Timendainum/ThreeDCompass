#include "ThreeDCompass.h"

void ThreeDCompass::init()
{
  Serial.println("Initialize HMC5883L");
  while (!_compass.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }

  // Set measurement range
  _compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  _compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  _compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  _compass.setSamples(HMC5883L_SAMPLES_8);

  // Set calibration offset. See HMC5883L_calibration.ino
  _compass.setOffset(OFFSET_X, OFFSET_Y);
}

void ThreeDCompass::update(float* h)
{
  Vector norm = _compass.readNormalize();

  // Calculate heading
  float heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (DECINATION_ANGLE_DEGREES + (DECINATION_ANGLE_MINUTES / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  // Convert to degrees
  float headingDegrees = heading * 180/M_PI;

  *h = headingDegrees;

  // Output
  #if __COMPASS_H__DEBUG
    Serial.print(" Heading = ");
    Serial.print(heading);
    Serial.print(" Degress = ");
    Serial.print(headingDegrees);
    Serial.println();  
  #endif
}
  

ThreeDCompass compass;
