/*---------------------------------------------------------------------------------


    Mode1BG3HighPriority
        example of how to use the BG3 for hud as the high priority background
        (use of BG3_MODE1_PRIORITY_HIGH mode)
    -- odelot

 Backgrounds inspired in SoR2

---------------------------------------------------------------------------------*/
#include <snes.h>
#include "src/parser.h"

extern char palettes, palettes_end;

extern char page1, page1_end;

#define BG1 0
#define BG2 1
#define BG3 2
#define BG4 3

#define VRAM_MAP_ADDR       0x7000
#define VRAM_TILES_ADDR     0x0000

u32 address = 0x11223344;
u8 value = 0x77;

//---------------------------------------------------------------------------------
int main(void)
{

    bgSetMapPtr(BG3, VRAM_MAP_ADDR, SC_32x32);
    bgSetGfxPtr(BG3, VRAM_TILES_ADDR);
    
    dmaCopyCGram(&palettes, 0, (&palettes_end-&palettes));

    bsMapFont();

    
    //consoleMesenBreakpoint();
    /*value = 0xBB;
    address = 0x89AF70;
    value = *((u8*)address);*/
    //consoleMesenBreakpoint();


    clearMap();
    //printText();

    setXY(2, 2);
    parseText(&page1);
    setXY(2, 4);
    parseText(&page1+0x20);

    setMode(BG_MODE1, BG3_MODE1_PRIORITY_HIGH);

    bgSetDisable(BG1);
    bgSetDisable(BG2);
    bgSetEnable(BG3);
    
    setScreenOn();

    //decodeCharacter();

    // Wait for nothing :P
    while (1)
    {

        // Wait VBL 'and update sprites too ;-) )
        WaitForVBlank();
    }
    return 0;
}
