/* Copyright 2015, Mariano Cerdeiro
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Configuration file for I2C
 **
 ** This file contains the configuration of the I2C Devices
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup I2C I2C
 ** @{ */
/** \addtogroup I2C_CFG I2C Configuration
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20151004 v0.0.1 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaI2CDevices.h"

/*==================[macros and definitions]=================================*/
/** \brief indicates the count of I2C buses on the system */
#define CIAA_I2C_BUSES_COUNT           2

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
/** Add one struct of the type ciaaI2CDevices_masterType for each
 ** I2C master bus. You can choose the name you like for this structure
 ** since it has to be referenced from ciaaI2CDevices.
 **
 ** This strcture contains the following elements:
 **
 ** driverName    -> name of the driver where this bus is located.
 **                  e.g.: "/dev/i2c/0"
 ** devicesCount  -> count of devices on this driver
 ** deviceStruct  -> devicesCount devices structs, one for each slave on this
 **                  bus.
 **
 ** Each deviceStruct contains:
 **
 ** deviceName    -> name of the device. e.g.: eeprom. In this case the path
 **                  to open the device will be /dev/i2c/0/eeprom
 ** maxAddr       -> last supported addres. e.g.: 255 will indicate that the
 **                  address range from 0 to 255 inclusive is supported. Gaps
 **                  are not supported.
 ** maxInputBuffer-> the input buffer of the device. After writing this amount
 **                  of bytes a delay of writeDelayMs will be performed. If
 **                  0 no max size is configured, writeDelayMs will be also
 **                  ignored.
 ** writeDelayMs  -> delay in ms after writing maxInputBuffer bytes. Set to 0
 **                  if not delay is needed.
 ** id            -> id of this device.
 ** addWidth      -> size in bytes of the address.
 **
 **/
ciaaI2CDevices_masterType ciaaI2CDevice_master01 = {
   "/dev/i2c/0",     /* name of the driver */
   2,                /* count of devices in this bus */
   /* configuration of first device */
   {
      "eeprom",         /* name of the device */
      255,              /* max addres, addresse range from 0 to 255 */
      16,               /* max size of input buffer */
      10,               /* delay in ms after writing the maximal size */
      20,               /* id of the device */
      2                 /* 1 bytes for address */
   }
   /* configuration of first device */
   {
      "sensor",         /* name of the device */
      511,              /* max addres, addresse range from 0 to 511 */
      0,                /* no limit */
      0,                /* no delay needed */
      10,               /* id of the device */
      2                 /* 2 bytes for address */
   }
}

/* TODO */
ciaaI2CDevices_slaveType ciaaI2CDevice_slave01 = {
   /* TODO */
}

/** This structure list all I2C buses.
 **
 ** For each bus the following configuration parameter shall be provided:
 **
 ** busType       -> can be CIAA_I2C_MASTER_BUS if this is a master or
 **                  CIAA_I2C_SLAVE_BUS if it is a salve bus.
 ** devDesc       -> pointer to the description of all devices on the bus.
 **
 **/
ciaaI2CBuses_Type ciaaI2CDevices = {
   /* do not change the following line, edit the count of buses
    * by changing the macro CIAA_I2C_BUSES_COUNT at the bigging of this file */
   CIAA_I2C_BUSES_COUNT,            /* count of buses */
   {
      CIAA_I2C_MASTER_BUS,          /* this bus is a master */
      ciaaI2CDevice_master01        /* pointer to the bus descriptor */
   },
   {
      CIAA_I2C_SLAVE_BUS,           /* in this bus we are the slave */
      ciaaI2CDevice_slave01         /* pointer to the bus descriptor */
   }
}

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

