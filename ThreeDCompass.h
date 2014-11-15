/*
 * This library was written by Timendainum based on code from:
 * GY-271 HMC5883L digital compass module for Arduino
 * HMC5883L Demo.
 * dipmicro electronics, 2014
 *
 * Hardware Used:
 * 
 * Arduino UNO or compatible
 * GY271 module (dipmicro part DE4196
 *  Arduino GND -> GY271/HMC5883L GND
 *  Arduino 3.3V -> GY271/HMC5883L VCC
 *  Arduino A4 (SDA) -> GY271/HMC5883L SDA
 *  Arduino A5 (SCL) -> GY271/HMC5883L SCL 
 */
#ifndef __COMPASS_H__
#define __COMPASS_H__
#define __COMPASS_H__DEBUG 0
#define DECINATION_ANGLE_DEGREES -1.0
#define DECINATION_ANGLE_MINUTES 25.0
#define OFFSET_X -312
#define OFFSET_Y -165

#include <Arduino.h>
#include <Wire.h> //I2C Arduino Library
#include "HMC5883L.h"

class ThreeDCompass
{
  private:
  	HMC5883L _compass;

  public:
  	void init();
  	void update(float* h);
  	bool headingMatches(float currentHeading, float targetHeading, float slop);
  	float headingOffset(float heading, float offset);
  	float headingPinch(float heading);
};

extern ThreeDCompass compass;

#endif
