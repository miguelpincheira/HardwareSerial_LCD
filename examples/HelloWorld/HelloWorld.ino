/*
  Hardware SerialLCD Library - Hello World
 
 Demonstrates the use a 16x2 LCD SerialLCD driver from Seeedstudio under STM32 Boards.
 Tested on F401RE, F452RE, and F030R8. 
 
 This sketch prints "Hello STM32!" on the first line, and shows a counter on the second line.
 
 */

// include the library code:
#include <HarwareSerialLCD.h>

// Instanciate the library
SerialLCD hslcd(PA9,PA10); 
int counter = 0; 


void setup() {
  // Intialize the display
  hslcd.begin();  
  // Clean the display
  hslcd.clear();
}

void loop() {  
  // Put the cursor on the first row (column, row)
  hslcd.setCursor(0, 0);
  // Print the message
  hslcd.print("Hello STM32");

  // Put the cursor on the first row (column, row)
  hslcd.setCursor(0, 1);
  // Print the counter
  hslcd.print(i);
  i++
  delay(1000)
}
