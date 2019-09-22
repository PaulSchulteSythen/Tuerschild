//Bildschirm Bibliothek laden
#include <GxEPD.h>

#include <GxGDEH029A1/GxGDEH029A1.h>      // 2.9" b/w

#if !defined(_GxFont_GFX_TFT_eSPI_H_)
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
//#include <Fonts/FreeMonoBold24pt7b.h>
#endif
#if defined(_ADAFRUIT_TF_GFX_H_)
#include <Fonts/Open_Sans_Bold_12pt.h>
#endif


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP8266)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\2.4.2\variants\generic\common.h

GxIO_Class io(SPI, /*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2); // arbitrary selection of D3(=0), D4(=2), selected for default of GxEPD_Class
GxEPD_Class display(io /*RST=D4*/ /*BUSY=D2*/); // default selection of D4(=2), D2(=4)

#elif defined(ESP32)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\espressif\esp32\variants\lolin32\pins_arduino.h

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4

#elif defined(ARDUINO_ARCH_SAMD)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\arduino\hardware\samd\1.6.19\variants\mkr1000\variant.h
// C:\Users\xxx\AppData\Local\Arduino15\packages\arduino\hardware\samd\1.6.19\variants\mkrzero\variant.h

GxIO_Class io(SPI, /*CS=*/ 4, /*DC=*/ 7, /*RST=*/ 6);
GxEPD_Class display(io, /*RST=*/ 6, /*BUSY=*/ 5);

#elif defined(ARDUINO_GENERIC_STM32F103C) && defined(MCU_STM32F103C8)

// STM32 Boards(STM32duino.com) Generic STM32F103C series STM32F103C8
// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\Arduino_STM32\STM32F1\variants\generic_stm32f103c\variant.h
// C:\Users\xxx\Documents\Arduino\hardware\Arduino_STM32\STM32F1\variants\generic_stm32f103c\board\board.h

// new mapping suggestion for STM32F1, e.g. STM32F103C8T6 "BluePill"
// BUSY -> A1, RST -> A2, DC -> A3, CS-> A4, CLK -> A5, DIN -> A7

GxIO_Class io(SPI, /*CS=*/ SS, /*DC=*/ 3, /*RST=*/ 2);
GxEPD_Class display(io, /*RST=*/ 2, /*BUSY=*/ 1);

#elif defined(ARDUINO_GENERIC_STM32F103V) && defined(MCU_STM32F103VB)

// STM32 Boards(STM32duino.com) Generic STM32F103V series STM32F103VB
// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\Arduino_STM32\STM32F1\variants\generic_stm32f103vb\variant.h
// C:\Users\xxx\Documents\Arduino\hardware\Arduino_STM32\STM32F1\variants\generic_stm32f103vb\board\board.h

// Good Display DESPI-M01
// note: needs jumper wires from SS=PA4->CS, SCK=PA5->SCK, MOSI=PA7->SDI

GxIO_Class io(SPI, /*CS=*/ SS, /*DC=*/ PE15, /*RST=*/ PE14); // DC, RST as wired by DESPI-M01
GxEPD_Class display(io, /*RST=*/ PE14, /*BUSY=*/ PE13); // RST, BUSY as wired by DESPI-M01

#else

// for SPI pin definitions see e.g.:
// C:\Users\xxx\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.21\variants\standard\pins_arduino.h

GxIO_Class io(SPI, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9); // arbitrary selection of 8, 9 selected for default of GxEPD_Class
GxEPD_Class display(io /*RST=9*/ /*BUSY=7*/); // default selection of (9), 7

#endif

#if defined(_GxGDEW0154Z04_H_) || defined(_GxGDEW0213Z16_H_) || defined(_GxGDEW029Z10_H_) || defined(_GxGDEW027C44_H_) || defined(_GxGDEW042Z15_H_) || defined(_GxGDEW075Z09_H_)
#define HAS_RED_COLOR
#endif

//Bibliotheken Laden
#include "WiFi.h"
#include "HTTPClient.h"
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <Preferences.h>
