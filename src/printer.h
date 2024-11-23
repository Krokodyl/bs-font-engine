#ifndef PRINTER_INCLUDE
#define PRINTER_INCLUDE

#include <snes.h>
#include "decoder.h"

#define VRAM_MAP_ADDR       0x7000
#define VRAM_TILES_ADDR     0x0000

extern char WRAM_7F;

u16 WRAM_MAP_ADDR = 0x1000;
u16 WRAM_TILES_ADDR = 0x2000;

u16 tileCount = 0;
u16 tileId = 1;
u16 currentTileId = 1; // keep first tile blank

u8 palette = 0;

u8 shift = 0;

u8 mapRow = 0;
u8 mapCol = 0;
u16 mapOffset;

void setXY(u8 x, u8 y);
void printCharacter(u8 tiles[], u8 width);

#endif