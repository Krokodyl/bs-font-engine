#include "printer.h"

void setXY(u8 x, u8 y) {
    mapRow = y;
    mapCol = x;
}

void clearMap() {
    u16 i=0;
    while (i<0x800) {
        *((u8*)&WRAM_7F+WRAM_MAP_ADDR+i) = 0;
        i++;
    }
}

void clearCurrentTiles() {
    u16 offset = (currentTileId-1)*0x10;
    u8 i=0;
    while (i<16) {
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i) = 0;
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16) = 0;
        i++;
    }
}
void clearNextTiles() {
    u16 offset = (currentTileId)*0x10;
    u8 i=0;
    while (i<16) {
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i) = 0;
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16) = 0;
        i++;
    }
}

void updateMap() {
    mapOffset = mapRow*0x40 + mapCol*2;
    *((u8*)&WRAM_7F+WRAM_MAP_ADDR+mapOffset) = tileId;
    *((u8*)&WRAM_7F+WRAM_MAP_ADDR+mapOffset+1) = 0x20 | (tileId>>8);
    tileId++;
    *((u8*)&WRAM_7F+WRAM_MAP_ADDR+mapOffset+0x40) = tileId;
    *((u8*)&WRAM_7F+WRAM_MAP_ADDR+mapOffset+0x41) = 0x20 | (tileId>>8);
    tileId++;
}

void endLine() {
    if (shift>0) {
        tileCount+=2;
        currentTileId+=2;
        updateMap();
        mapCol++;
    }
}

void initLine() {
    shift = 0;
    clearCurrentTiles();
}

void updateShift(u8 width) {
    shift=shift+width+1;
    while (shift>=8) {
        shift-=8;
        tileCount+=2;
        currentTileId+=2;
        updateMap();
        mapCol++;
    }
}

void printCharacter(u8 tiles[], u8 width) {
    u8 i=0;
    u16 offset = (currentTileId-1)*0x10;

    if (shift<=1) clearCurrentTiles();

    // first tile
    while (i<16) {
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i) = (tiles[i]>>shift) | *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i);
        *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16) = (tiles[i+32]>>shift) | *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16);
        i++;
    }
    
    if (shift+width>8) {
        // second tile
        i=0;
        while (i<16) {
            *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+32) = (tiles[i]<<(8-shift)) | (tiles[i+16]>>(shift));
            *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16+32) = (tiles[i+32]<<(8-shift)) | (tiles[i+32+16]>>(shift));
            i++;       
        }
    }
    if (shift+width>16) {
        // third tile
        i=0;
        while (i<16) {
                *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+64) = (tiles[i+16])<<(8-shift);
                *((u8*)&WRAM_7F+WRAM_TILES_ADDR+offset+i+16+64) = (tiles[i+32+16]<<(8-shift));
            i++;
        }
    }
    updateShift(width);
}

void copyTilesToVram(){
    dmaCopyVram(&WRAM_7F+WRAM_TILES_ADDR, VRAM_TILES_ADDR+0x08, tileCount*0x10);
}

void copyMapToVram() {
    dmaCopyVram(&WRAM_7F+WRAM_MAP_ADDR, VRAM_MAP_ADDR, 0x800);
}
