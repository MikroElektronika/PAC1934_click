/*
    __pac1934_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __pac1934_driver.h
@brief    PAC1934 Driver
@mainpage PAC1934 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   PAC1934
@brief      PAC1934 Click Driver
@{

| Global Library Prefix | **PAC1934** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Mar 2019.**      |
| Developer             | **Jovan Stajkovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PAC1934_H_
#define _PAC1934_H_

/** 
 * @macro T_PAC1934_P
 * @brief Driver Abstract type 
 */
#define T_PAC1934_P    const uint8_t*

/** @defgroup PAC1934_COMPILE Compilation Config */              /** @{ */

//  #define   __PAC1934_DRV_SPI__                            /**<     @macro __PAC1934_DRV_SPI__  @brief SPI driver selector */
    #define   __PAC1934_DRV_I2C__                            /**<     @macro __PAC1934_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __PAC1934_DRV_UART__                           /**<     @macro __PAC1934_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup PAC1934_VAR Variables */                           /** @{ */

/* I2C slave address */
extern const uint8_t _PAC1934_I2C_ADDR;
/* Refresh command */
extern const uint8_t _PAC1934_REFRESH_CMD;
/* Control register */
extern const uint8_t _PAC1934_CTRL_REG;
/* Accumulator count */
extern const uint8_t _PAC1934_ACC_COUNT;
/* Accumulated power registers */
extern const uint8_t _PAC1934_VPOWER1_ACC;
extern const uint8_t _PAC1934_VPOWER2_ACC;
extern const uint8_t _PAC1934_VPOWER3_ACC;
extern const uint8_t _PAC1934_VPOWER4_ACC;
/* Most recent Vbus sample */
extern const uint8_t _PAC1934_VBUS1;
extern const uint8_t _PAC1934_VBUS2;
extern const uint8_t _PAC1934_VBUS3;
extern const uint8_t _PAC1934_VBUS4;
/* Most recent Vsense sample */
extern const uint8_t _PAC1934_VSENSE1;
extern const uint8_t _PAC1934_VSENSE2;
extern const uint8_t _PAC1934_VSENSE3;
extern const uint8_t _PAC1934_VSENSE4;
/* Average Vbus sample */
extern const uint8_t _PAC1934_VBUS1_AVG;
extern const uint8_t _PAC1934_VBUS2_AVG;
extern const uint8_t _PAC1934_VBUS3_AVG;
extern const uint8_t _PAC1934_VBUS4_AVG;
/* Average Vsense sample */
extern const uint8_t _PAC1934_VSENSE1_AVG;
extern const uint8_t _PAC1934_VSENSE2_AVG;
extern const uint8_t _PAC1934_VSENSE3_AVG;
extern const uint8_t _PAC1934_VSENSE4_AVG;
/* Vbus and Vsense product 1 */
extern const uint8_t _PAC1934_VPOWER1;
extern const uint8_t _PAC1934_VPOWER2;
extern const uint8_t _PAC1934_VPOWER3;
extern const uint8_t _PAC1934_VPOWER4;
/* Channel disable and other settings */
extern const uint8_t _PAC1934_CHANNEL_DIS;
/* Bidirectional measurements settings */
extern const uint8_t _PAC1934_NEG_PWR;
/* Refresh G command */
extern const uint8_t _PAC1934_REFRESH_G_CMD;
/* Refresh V command */
extern const uint8_t _PAC1934_REFRESH_V_CMD;
/* Slow pin state and settings */
extern const uint8_t _PAC1934_SLOW;
/* Actual state of CTRL register */
extern const uint8_t _PAC1934_CTRL_ACT;
/* Actual state of CHANNEL_DIS register */
extern const uint8_t _PAC1934_DIS_ACT;
/* Actual state of NEG_PWR register */
extern const uint8_t _PAC1934_NEG_PWR_ACT;
/* Latched state of CTRL register */
extern const uint8_t _PAC1934_CTRL_LAT;
/* Latched state of CHANNEL_DIS register */
extern const uint8_t _PAC1934_DIS_LAT;
 /* Latched state of NEG_PWR register */
extern const uint8_t _PAC1934_NEG_PWR_LAT;
/* Product ID register */
extern const uint8_t _PAC1934_PRODUCT_ID;
/* Manufacturer ID register*/
extern const uint8_t _PAC1934_MANUFACT_ID;
/* Revision ID register*/
extern const uint8_t _PAC1934_REVISION_ID;
                                                                       /** @} */
/** @defgroup PAC1934_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PAC1934_INIT Driver Initialization */              /** @{ */

#ifdef   __PAC1934_DRV_SPI__
void pac1934_spiDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P spiObj);
#endif
#ifdef   __PAC1934_DRV_I2C__
void pac1934_i2cDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P i2cObj, uint8_t slave);
#endif
#ifdef   __PAC1934_DRV_UART__
void pac1934_uartDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void pac1934_gpioDriverInit(T_PAC1934_P gpioObj);
                                                                       /** @} */
/** @defgroup PAC1934_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic write function
 *
 * @param[in] wrAddr  8-bit register address
 * @param[in] wrData  8-bit data to be written into register
 *
 * Function writes single byte of data into specified register.
**/
void pac1934_writeByte( uint8_t wrAddr, uint8_t wrData );

/**
 * @brief Read one byte function
 *
 * @param[in] rdAddr  8-bit register address
 *
 * @returns 8-bit data from address specified register
 *
 * Function reads single byte of data from specified register.
**/
uint8_t pac1934_readByte( uint8_t rdAddr );

/**
 * @brief Read two bytes function
 *
 * @param[in] rdAddr 8-bit register address
 *
 * @returns 16-bit data from address specified registers
 *
 * Function reads 2 bytes of data from specified, registers.
**/
uint16_t pac1934_readTwoByte( uint8_t rdAddr );

/*  */
/**
 * @brief Read four bytes function
 *
 * @param[in] rdAddr 8-bit register address
 *
 * @returns 32-bit data from address specified registers
 *
 * Function reads 4 bytes of data from specified, registers.
**/
uint32_t pac1934_readFourByte( uint8_t rdAddr );

/**
 * @brief Read chosen number of bytes function
 *
 * @param[in] rdAddr 8-bit register address
 * @param[in] cnt 8-bit register address
 * @param[out] outputData data from address specified registers
 *
 * Function reads user defined number bytes of data from specified, registers.
**/
void pac1934_readReg( uint8_t regAddr, uint8_t *outputData, uint8_t cnt );

/**
 * @brief Send Command
 *
 * @param[in] wrCmd 8-bit command to execute
 *
 * Executes refresh commands.
 *
 * @note Calling this function with '_PAC1934_REFRESH_G_CMD' parameter will issue a
 * global command to all the devices on the bus.
 */
void pac1934_sendCommand( uint8_t wrCmd );

/**
 * @brief Measure Voltage function
 *
 * @param[in] channel  Channel from which to read
 *
 * @returns result float value that represents voltage
 *
 * Reads the voltage data from one of the _PAC1934_VBUS registers, depending
 * on the selected channel and converts it into float value expressed in Volts.
 * @note This command reads voltage from the time of the most recent refresh command.
**/
float pac1934_measureVoltage( uint8_t channel );

/**
 * @brief Measure Current function
 *
 * @param[in] channel  Channel from which to read
 *
 * @returns result float value that represents current
 *
 * Reads the current data from one of the _PAC1934_VSENSE registers, depending
 * on the selected channel and converts it into float value expressed in mA.
 * @note This command reads current from the time of the most recent refresh command.
**/
float pac1934_measureCurrent( uint8_t channel );

/**
 * @brief Measure Power function
 *
 * @param[in] channel  Channel from which to read
 *
 * @returns result float value that represents power.
 *
 * Reads the power data from one of the _PAC1934_VPOWER registers, depending
 * on the selected channel and converts it into float value expressed in Watts.
 * @note This command reads power from the time of the most recent refresh command.
**/
float pac1934_measurePower( uint8_t channel );

/**
 * @brief Enable device function
 *
 * Function is used to enable the device.
**/
void pac1934_devEnable();

/**
 * @brief Disable device function
 *
 * Function is used to disable the device.
**/
void pac1934_devDisable();

/**
 * @brief Reset device function
 *
 * Function is used to reset the device.
 * @note Function has a small 200 milisecond delay.
**/
void pac1934_devReset();

/**
 * @brief Check Interrupt function
 *
 * @returns Result  State of the INT pin
 *
 * Function is used to check the state of INT pin.
**/
uint8_t pac1934_checkInrterrupt();


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_PAC1934_STM.c
    @example Click_PAC1934_TIVA.c
    @example Click_PAC1934_CEC.c
    @example Click_PAC1934_KINETIS.c
    @example Click_PAC1934_MSP.c
    @example Click_PAC1934_PIC.c
    @example Click_PAC1934_PIC32.c
    @example Click_PAC1934_DSPIC.c
    @example Click_PAC1934_AVR.c
    @example Click_PAC1934_FT90x.c
    @example Click_PAC1934_STM.mbas
    @example Click_PAC1934_TIVA.mbas
    @example Click_PAC1934_CEC.mbas
    @example Click_PAC1934_KINETIS.mbas
    @example Click_PAC1934_MSP.mbas
    @example Click_PAC1934_PIC.mbas
    @example Click_PAC1934_PIC32.mbas
    @example Click_PAC1934_DSPIC.mbas
    @example Click_PAC1934_AVR.mbas
    @example Click_PAC1934_FT90x.mbas
    @example Click_PAC1934_STM.mpas
    @example Click_PAC1934_TIVA.mpas
    @example Click_PAC1934_CEC.mpas
    @example Click_PAC1934_KINETIS.mpas
    @example Click_PAC1934_MSP.mpas
    @example Click_PAC1934_PIC.mpas
    @example Click_PAC1934_PIC32.mpas
    @example Click_PAC1934_DSPIC.mpas
    @example Click_PAC1934_AVR.mpas
    @example Click_PAC1934_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __pac1934_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */