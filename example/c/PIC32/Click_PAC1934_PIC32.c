/*
Example for PAC1934 Click

    Date          : Mar 2019.
    Author        : Jovan Stajkovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input and RST pin as output.
- Application Initialization - Initalizes I2C driver, enables the device and makes an initial log.
- Application Task - (code snippet)  This is an example that shows the most important
                     functions that PAC1934 click has, it mesures current voltage, amperage and power.

*/

#include "Click_PAC1934_types.h"
#include "Click_PAC1934_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_PAC1934_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    pac1934_i2cDriverInit( (T_PAC1934_P)&_MIKROBUS1_GPIO, (T_PAC1934_P)&_MIKROBUS1_I2C, _PAC1934_I2C_ADDR );
    Delay_ms( 100 );
    
    pac1934_devReset();
    mikrobus_logWrite( "-----------------", _LOG_LINE );
    mikrobus_logWrite( " PAC1934  Click  ", _LOG_LINE );
    mikrobus_logWrite( "-----------------", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationTask()
{
    float readValue;
    char logTxt[ 20 ];

    mikrobus_logWrite( "Send command : ", _LOG_LINE );
    pac1934_sendCommand( _PAC1934_REFRESH_CMD );
    mikrobus_logWrite( " Refreshed! ", _LOG_LINE );
    delay_ms (200);

    readValue = pac1934_measureVoltage( 4 );
    Delay_ms( 100 );
    mikrobus_logWrite( "Voltage : ", _LOG_TEXT );
    IntToStr( readValue, logTxt );
    Ltrim( logTxt );
    mikrobus_logWrite( logTxt, _LOG_TEXT );
    mikrobus_logWrite( "V", _LOG_LINE );
    
    readValue = pac1934_measureCurrent( 4 );
    Delay_ms( 100 );
    mikrobus_logWrite( "Amperage : ", _LOG_TEXT );
    IntToStr( readValue, logTxt );
    Ltrim( logTxt );
    mikrobus_logWrite( logTxt, _LOG_TEXT );
    mikrobus_logWrite( "mA", _LOG_LINE );

    readValue = pac1934_measureCurrent( 4 );
    Delay_ms( 100 );
    mikrobus_logWrite( "Power : ", _LOG_TEXT );
    IntToStr( readValue, logTxt );
    Ltrim( logTxt );
    mikrobus_logWrite( logTxt, _LOG_TEXT );
    mikrobus_logWrite( "W", _LOG_LINE );

    mikrobus_logWrite( "-----------------", _LOG_LINE );
    Delay_ms( 2000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}