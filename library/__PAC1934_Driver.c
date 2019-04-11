/*
    __pac1934_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__pac1934_driver.h"
#include "__pac1934_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __PAC1934_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* I2C slave address */
const uint8_t _PAC1934_I2C_ADDR                                     = 0x10;
/* Refresh command */
const uint8_t _PAC1934_REFRESH_CMD                                  = 0x00;
/* Control register */
const uint8_t _PAC1934_CTRL_REG                                     = 0x01;
/* Accumulator count */
const uint8_t _PAC1934_ACC_COUNT                                    = 0x02;
/* Accumulated power registers */
const uint8_t _PAC1934_VPOWER1_ACC                                  = 0x03;
const uint8_t _PAC1934_VPOWER2_ACC                                  = 0x04;
const uint8_t _PAC1934_VPOWER3_ACC                                  = 0x05;
const uint8_t _PAC1934_VPOWER4_ACC                                  = 0x06;
/* Most recent Vbus sample */
const uint8_t _PAC1934_VBUS1                                        = 0x07;
const uint8_t _PAC1934_VBUS2                                        = 0x08;
const uint8_t _PAC1934_VBUS3                                        = 0x09;
const uint8_t _PAC1934_VBUS4                                        = 0x0A;
/* Most recent Vsense sample */
const uint8_t _PAC1934_VSENSE1                                      = 0x0B;
const uint8_t _PAC1934_VSENSE2                                      = 0x0C;
const uint8_t _PAC1934_VSENSE3                                      = 0x0D;
const uint8_t _PAC1934_VSENSE4                                      = 0x0E;
/* Average Vbus sample */
const uint8_t _PAC1934_VBUS1_AVG                                    = 0x0F;
const uint8_t _PAC1934_VBUS2_AVG                                    = 0x10;
const uint8_t _PAC1934_VBUS3_AVG                                    = 0x11;
const uint8_t _PAC1934_VBUS4_AVG                                    = 0x12;
/* Average Vsense sample */
const uint8_t _PAC1934_VSENSE1_AVG                                  = 0x13;
const uint8_t _PAC1934_VSENSE2_AVG                                  = 0x14;
const uint8_t _PAC1934_VSENSE3_AVG                                  = 0x15;
const uint8_t _PAC1934_VSENSE4_AVG                                  = 0x16;
/* Vbus and Vsense product 1 */
const uint8_t _PAC1934_VPOWER1                                      = 0x17;
const uint8_t _PAC1934_VPOWER2                                      = 0x18;
const uint8_t _PAC1934_VPOWER3                                      = 0x19;
const uint8_t _PAC1934_VPOWER4                                      = 0x1A;
/* Channel disable and other settings */
const uint8_t _PAC1934_CHANNEL_DIS                                  = 0x1C;
/* Bidirectional measurements settings */
const uint8_t _PAC1934_NEG_PWR                                      = 0x1D;
/* Refresh G command */
const uint8_t _PAC1934_REFRESH_G_CMD                                = 0x1E;
/* Refresh V command */
const uint8_t _PAC1934_REFRESH_V_CMD                                = 0x1F;
/* Slow pin state and settings */
const uint8_t _PAC1934_SLOW                                         = 0x20;
/* Actual state of CTRL register */
const uint8_t _PAC1934_CTRL_ACT                                     = 0x21;
/* Actual state of CHANNEL_DIS register */
const uint8_t _PAC1934_DIS_ACT                                      = 0x22;
/* Actual state of NEG_PWR register */
const uint8_t _PAC1934_NEG_PWR_ACT                                  = 0x23;
/* Latched state of CTRL register */
const uint8_t _PAC1934_CTRL_LAT                                     = 0x24;
/* Latched state of CHANNEL_DIS register */
const uint8_t _PAC1934_DIS_LAT                                      = 0x25;
 /* Latched state of NEG_PWR register */
const uint8_t _PAC1934_NEG_PWR_LAT                                  = 0x26;
/* Product ID register */
const uint8_t _PAC1934_PRODUCT_ID                                   = 0xFD;
/* Manufacturer ID register*/
const uint8_t _PAC1934_MANUFACT_ID                                  = 0xFE;
/* Revision ID register*/
const uint8_t _PAC1934_REVISION_ID                                  = 0xFF;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PAC1934_DRV_SPI__

void pac1934_spiDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __PAC1934_DRV_I2C__

void pac1934_i2cDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __PAC1934_DRV_UART__

void pac1934_uartDriverInit(T_PAC1934_P gpioObj, T_PAC1934_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void pac1934_gpioDriverInit(T_PAC1934_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic write function */
void pac1934_writeByte( uint8_t wrAddr, uint8_t wrData )
{
    uint8_t wBuffer[ 2 ];

    wBuffer[ 0 ] = wrAddr;
    wBuffer[ 1 ] = wrData;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 2, END_MODE_STOP );
}

/* Read one byte function */
uint8_t pac1934_readByte( uint8_t rdAddr )
{
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 1 ];

    wBuffer[ 0 ] = rdAddr;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 1, END_MODE_STOP );

    return rBuffer[ 0 ];
}

/* Read two bytes function */
uint16_t pac1934_readTwoByte( uint8_t rdAddr )
{
    uint16_t result;
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 2 ];

    wBuffer[ 0 ] = rdAddr;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 2, END_MODE_STOP );

    result = rBuffer[ 0 ];
    result <<= 8;
    result |= rBuffer[ 1 ];

    return result;
}

/* Read four bytes function */
uint32_t pac1934_readFourByte( uint8_t rdAddr )
{
    uint32_t result;
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 4 ];

    wBuffer[ 0 ] = rdAddr;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 4, END_MODE_STOP );

    result = rBuffer[ 0 ];
    result <<= 8;
    result |= rBuffer[ 1 ];
    result <<= 8;
    result |= rBuffer[ 2 ];
    result <<= 8;
    result |= rBuffer[ 3 ];

    return result;
}

/* Read chosen number of bytes */
void pac1934_readReg( uint8_t regAddr, uint8_t *outputData, uint8_t cnt )
{
    uint8_t wBuffer[ 1 ];
    uint8_t *rBuffer = outputData;

    wBuffer[ 0 ] = regAddr;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, cnt, END_MODE_STOP );
}

/* Send Command */
void pac1934_sendCommand( uint8_t wrCmd )
{
    uint8_t wBuffer[ 1 ];

    wBuffer[ 0 ] = wrCmd;

    if ( wrCmd == _PAC1934_REFRESH_G_CMD )
    {
        hal_i2cStart();
        hal_i2cWrite( 0x00, wBuffer, 1, END_MODE_STOP );
    }
    else
    {
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_STOP );
    }
}

/* Measure Voltage */
float pac1934_measureVoltage( uint8_t channel )
{
    uint8_t wBuffer[ 1 ];
    float result;
    result = 0.0;

    wBuffer[ 0 ] = channel + 0x06;

    result = pac1934_readTwoByte( wBuffer[ 0 ] );

    result = result * 32;
    result = result / 0xFFFF;

    return result;
}
/* Measure Current */
float pac1934_measureCurrent( uint8_t channel )
{
    uint8_t wBuffer[ 1 ];
    float result;
    result = 0.0;

    wBuffer[ 0 ] = channel + 0x0A;

    result = pac1934_readTwoByte( wBuffer[ 0 ] );

    result = result * 25000;
    result = result / 0xFFFF;

    return result;
}

/* Measure Power */
float pac1934_measurePower( uint8_t channel )
{
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 4 ];
    uint32_t returnInt;
    float result;

    wBuffer[ 1 ] = channel + 0x16;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 4, END_MODE_STOP );

    returnInt = rBuffer[ 0 ];
    returnInt <<= 8;
    returnInt |= rBuffer[ 1 ];
    returnInt <<= 8;
    returnInt |= rBuffer[ 2 ];
    returnInt <<= 4;
    rBuffer[ 3 ] >>= 4;
    returnInt |= rBuffer[ 3 ];

    result = returnInt;
    result = result * 800;
    result = result / 0xFFFFFFF;

    return result;
}

/* Enable device */
void pac1934_devEnable()
{
    hal_gpio_rstSet( 1 );
}

/* Disable device */
void pac1934_devDisable()
{
    hal_gpio_rstSet( 0 );
}

/* Reset device */
void pac1934_devReset()
{
    hal_gpio_rstSet( 0 );
    Delay_100ms();
    hal_gpio_rstSet( 1 );
    Delay_100ms();
}

/* Check Interrupt */
uint8_t pac1934_checkInrterrupt()
{
    return hal_gpio_intGet();
}

/* -------------------------------------------------------------------------- */
/*
  __pac1934_driver.c

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