/*
$Id:$

ST7565 LCD library!

Copyright (C) 2010 Limor Fried, Adafruit Industries

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

// some of this code was written by <cstone@pobox.com> originally; it is in the public domain.
*/

#include <stdint.h>

#define swap(a, b) { uint8_t t = a; a = b; b = t; }

#define BLACK 1
#define WHITE 0

#define LCDWIDTH 128
#define LCDHEIGHT 64

#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF

#define CMD_SET_DISP_START_LINE  0x40
#define CMD_SET_PAGE  0xB0

#define CMD_SET_COLUMN_UPPER  0x10
#define CMD_SET_COLUMN_LOWER  0x00

#define CMD_SET_ADC_NORMAL  0xA0
#define CMD_SET_ADC_REVERSE 0xA1

#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7

#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON  0xA5
#define CMD_SET_BIAS_9 0xA2 
#define CMD_SET_BIAS_7 0xA3

#define CMD_RMW  0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET  0xE2
#define CMD_SET_COM_NORMAL  0xC0
#define CMD_SET_COM_REVERSE  0xC8
#define CMD_SET_POWER_CONTROL  0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST  0x81
#define  CMD_SET_VOLUME_SECOND  0
#define CMD_SET_STATIC_OFF  0xAC
#define  CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_SET_BOOSTER_234  0
#define  CMD_SET_BOOSTER_5  1
#define  CMD_SET_BOOSTER_6  3
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0

class ST7565 {
 public:
  ST7565(char SID, char SCLK, char A0, char RST, char CS) :sid(SID), sclk(SCLK), a0(A0), rst(RST), cs(CS) {}
  ST7565(char SID, char SCLK, char A0, char RST) :sid(SID), sclk(SCLK), a0(A0), rst(RST), cs(-1) {}

  void st7565_init(void);
  void begin(uint8_t contrast);
  void st7565_command(char c);
  void st7565_data(char c);
  void st7565_set_brightness(char val);
  void clear_display(void);
  void clear();
  void display();

  void setpixel(uint8_t x, char y, char color);
  uint8_t getpixel(char x, char y);
  void fillcircle(char x0, char y0, char r, 
		  char color);
  void drawcircle(char x0, char y0, char r, 
		  char color);
  void fillrect(char x, char y, char w, char h, 
		char color);
  void drawline(char x0, char y0, char x1, char y1, 
		char color);
  void drawchar(char x, char line, char c);
  void drawcharInv(char x, char line, char c); //JH: invertierte Zeichenausgabe
  void drawstring(char x, char line, char *c);
  void drawstring_P(char x, char line, const char *c);

  void drawbitmap(char x, char y, 
		  const char *bitmap, char w, char h,
		  char color);

 private:
  char sid, sclk, a0, rst, cs;
  void shiftOut(char dataPin,char clockPin, char bitOrder, char val);
  void spiwrite(char c);
  void my_setpixel(char x, char y, char color);

  //byte buffer[128*64/8]; 
};

