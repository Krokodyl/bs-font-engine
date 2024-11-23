#ifndef DECODER_INCLUDE
#define DECODER_INCLUDE

#include <snes.h>

u8 characterData[24];

// 0x89AF58    ' '
// 0x89AF70    '!'
u32 ascii_addr = 0x89AF58;

u16 shift_jis_values[] = {
    0x8140,
    0x824F,
    0x8340,
    0x8440,
    0x853F,
    0x859E,
    0x889F,
    0x8B5C,
    0x90B1,
    0x9640
};

u32 shift_jis_addr[] = {
    0x898000,
    0x898A38,
    0x899980,
    0x89A7A8,
    0x89AF58,
    0x89B840,
    0x89BE40,
    0x8A8000,
    0x8B8000,
    0x8C8000
};

u8 encodedChar[32];
u8 decodedChar[64];

void decodeAsciiCharacter(u8 c);
void decodeShiftJisCharacter(u16 c);

#endif