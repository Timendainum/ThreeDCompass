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

#define HMC5883L_ADDR 0x1E //0011110b, I2C 7bit address of HMC5883

#include <Arduino.h>
#include <Wire.h> //I2C Arduino Library

class ThreeDCompass
{
  private:
  	static bool haveHMC5883L;
  	bool detectHMC5883L();

  public:
  	void init();
  	void update(int* x, int* y, int *z);
};

extern ThreeDCompass compass;

#endif
