![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# PAC1934 Click

- **CIC Prefix**  : PAC1934
- **Author**      : Jovan Stajkovic
- **Verison**     : 1.0.0
- **Date**        : Mar 2019.

---


### Software Support

We provide a library for the PAC1934 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2173/pac1934-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing and reading
data in and from registers. The library includes a functions for reading voltage, amperage, power as well as 
miscellaneous functions, such as enable, disable, reset and check interrupt. The library also has generic read and write functions
that allow full usage of the PAC1934 Click.

Key functions :

- ``` uint8_t pac1934_readByte( uint8_t rdAddr ) ``` - Function reads single byte of data from specified register.
- ``` float pac1934_measureVoltage( uint8_t channel ) ``` - Reads the voltage data from one of the _PAC1934_VBUS registers, depending
                                                            on the selected channel and converts it into float value expressed in Volts.
- ``` float pac1934_measureCurrent( uint8_t channel ) ``` - Reads the current data from one of the _PAC1934_VSENSE registers, depending
                                                            on the selected channel and converts it into float value expressed in mA.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input and RST pin as output.
- Application Initialization - Initalizes I2C driver, enables the device and makes an initial log.
- Application Task - (code snippet)  This is an example that shows the most important
                     functions that PAC1934 click has, it mesures current voltage, amperage and power.


```.c

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

```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2173/pac1934-click) page.

Other mikroE Libraries used in the example:

- I2C  
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
