#ifndef PARSER_INCLUDE
#define PARSER_INCLUDE

#include <snes.h>
#include "decoder.h"
#include "printer.h"

#define MODE_ASCII          0x01
#define MODE_SHIFT_JIS      0x02

#define LINE_BREAK          0xFE
#define END_OF_TEXT         0xFF

u8 mode = 0;

u8 text1[7] = {
    0x01, 'H', 'e', 'l', 'l', 'o', 0xFF
};

u8 text2[8] = {
    0x02, 0x88, 0x9F, 0x88, 0xA0, 0x88, 0xA1, 0xFF
};

void setXY(u8 x, u8 y);
void parseText(u8 text[]);

#endif