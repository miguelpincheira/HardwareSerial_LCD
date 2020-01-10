/*
 * HardwareSerialLCD.cpp
 * Serial LCD driver Library working with Hardware Serial instead of Software Serial
 * Compatible with STM32 Boards under Arduino IDE 
 * Base on the code by 
* Copyright (c) 2010 seeed technology inc.
 * Author        :   Miguel Pincheira
 * Create Time   :   Jan 2020
 * Change Log    :   Modified 08 January,2020 
 *
 * Based on the code of 2010 seeed technology inc.
 * Url: https://github.com/Seeed-Studio/Serial_LCD
 *  
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>

#include "HardwareSerialLCD.h"

HardwareSerialLCD::HardwareSerialLCD(uint8_t rx, uint8_t tx):HardwareSerial(rx,tx)
{

}

/********** High level commands, for the user! **********/

// Initialize the Serial LCD Driver. SerialLCD Module initiates the communication.
void HardwareSerialLCD::begin()
{
    HardwareSerial::begin(9600);
    /* For the hardware version, we increased the delay between commands */
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_POWER_OFF); 
    delay(10);
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_POWER_ON);
    delay(10);
    HardwareSerial::write(SLCD_INIT_ACK);
    /* For the hardware version, we don't wait for response */ 
    short i;
    while(1)
    {
        if (HardwareSerial::available() > 0 &&HardwareSerial::read()==SLCD_INIT_DONE)
            break;
        i++;
        if (i==100)
          break;
    }
    delay(2);
}

// Clear the display
void HardwareSerialLCD::clear()
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_CLEAR_DISPLAY);   
}

// Return to home(top-left corner of LCD)
void HardwareSerialLCD::home()
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_RETURN_HOME);  
    delay(2);//this command needs more time;  
}

// Set Cursor to (Column,Row) Position
void HardwareSerialLCD::setCursor(uint8_t column, uint8_t row)
{
    HardwareSerial::write(SLCD_CONTROL_HEADER); 
    HardwareSerial::write(SLCD_CURSOR_HEADER); //cursor header command
    HardwareSerial::write(column);
    HardwareSerial::write(row);
}

// Switch the display off without clearing RAM
void HardwareSerialLCD::noDisplay() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_DISPLAY_OFF);    
}

// Switch the display on
void HardwareSerialLCD::display() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_DISPLAY_ON);    
}

// Switch the underline cursor off
void HardwareSerialLCD::noCursor() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_CURSOR_OFF);     
}

// Switch the underline cursor on
void HardwareSerialLCD::cursor() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_CURSOR_ON);     
}

// Switch off the blinking cursor
void HardwareSerialLCD::noBlink() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_BLINK_OFF);     
}

// Switch on the blinking cursor
void HardwareSerialLCD::blink() 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_BLINK_ON);     
}

// Scroll the display left without changing the RAM
void HardwareSerialLCD::scrollDisplayLeft(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_SCROLL_LEFT);
}

// Scroll the display right without changing the RAM
void HardwareSerialLCD::scrollDisplayRight(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_SCROLL_RIGHT);
}

// Set the text flow "Left to Right"
void HardwareSerialLCD::leftToRight(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_LEFT_TO_RIGHT);
}

// Set the text flow "Right to Left"
void HardwareSerialLCD::rightToLeft(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_RIGHT_TO_LEFT);
}

// This will 'right justify' text from the cursor
void HardwareSerialLCD::autoscroll(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_AUTO_SCROLL);
}

// This will 'left justify' text from the cursor
void HardwareSerialLCD::noAutoscroll(void) 
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);
    HardwareSerial::write(SLCD_NO_AUTO_SCROLL);
}
void HardwareSerialLCD::Power(void)
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_POWER_ON); 
}
void HardwareSerialLCD::noPower(void)
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_POWER_OFF); 
}
//Turn off the backlight
void HardwareSerialLCD::noBacklight(void)
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_BACKLIGHT_OFF);   
}
//Turn on the back light
void HardwareSerialLCD::backlight(void)
{
    HardwareSerial::write(SLCD_CONTROL_HEADER);   
    HardwareSerial::write(SLCD_BACKLIGHT_ON);   
}
// Print Commands
void HardwareSerialLCD::print(uint8_t b)
{
    HardwareSerial::write(SLCD_CHAR_HEADER);
    HardwareSerial::write(b);
}
void HardwareSerialLCD::print(const char b[])
{
    HardwareSerial::write(SLCD_CHAR_HEADER);
    HardwareSerial::write(b);
}

/* Not tested yet */
/*
void HardwareSerialLCD::print(unsigned long n, uint8_t base)
{
    HardwareSerial::write(SLCD_CHAR_HEADER);
    //HardwareSerial::print(n, base); 
}
*/

void HardwareSerialLCD::write(const char b[], uint8_t len)
{
    HardwareSerial::write(SLCD_CHAR_HEADER);
    HardwareSerial::write(b, len);
}
