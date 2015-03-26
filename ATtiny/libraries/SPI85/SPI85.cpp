/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "pins_arduino.h"
#include "SPI85.h"

//#if defined( __AVR_ATtinyX5__ )
const static uint8_t SS   = PB4;
const static uint8_t MOSI = PB1;
const static uint8_t MISO = PB0;
const static uint8_t SCK  = PB2;
//#endif

//#if defined( __AVR_ATtinyX4__ )
//const static uint8_t SS   = PA7;
//const static uint8_t MOSI = PA5;
//const static uint8_t MISO = PA6;
//const static uint8_t SCK  = PA4;
//#endif

SPI85Class SPI85;

void SPI85Class::begin() {
  // Set direction register for SCK and MOSI pin.
  // MISO pin automatically overrides to INPUT.
  // When the SS pin is set as OUTPUT, it can be used as
  // a general purpose output port (it doesn't influence
  // SPI operations).

  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(MISO,INPUT);

  digitalWrite(MISO,HIGH);
  digitalWrite(SCK, LOW);
  digitalWrite(MOSI, LOW);

}

void SPI85Class::end() {
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO,INPUT);
}



void SPI85Class::setDataMode(uint8_t mode)
{
  //SPCR = (SPCR & ~SPI_MODE_MASK) | mode; //FOR 328 NOT TINY
}

void SPI85Class::setClockDivider(uint8_t rate)
{
//  SPCR = (SPCR & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
  //SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | ((rate >> 2) & SPI_2XCLOCK_MASK);
}

