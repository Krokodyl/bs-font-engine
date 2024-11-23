#include "decoder.h"


void decodeCharacter(u8 romData[]) {
    //consoleMesenBreakpoint();
    u8 i=0, j=0;
    while (i<8) {
        encodedChar[i]=0;
        i++;
    }
    while (i<32) {
        encodedChar[i]=romData[j];
        //encodedChar[i]=(u8*)(&romAddr+j);
        i++;
        j++;
    }
    i=0;
    u8 a,b,a1,a2,b1,b2;
    u8 shift=0;
    while (i<64) {
        a = encodedChar[i];
        b = encodedChar[i+1];
        a1 = a;
        a2 = a>>1;
        if (a>=0x80) a2=a2 | 0x80;
        if (b>=0x80) a2++;
        b2 = (b & 0x7F)<<1;
        b1 = b;

        shift =((i>>4)<<4);

        decodedChar[shift+i] = a1;
        decodedChar[shift+i+1] = a2;
        decodedChar[shift+i+16] = b1;
        decodedChar[shift+i+1+16] = b2;

        i=i+2;
    }
    //consoleMesenBreakpoint();
}

void decodeAsciiCharacter(u8 c) {
    //consoleMesenBreakpoint();
    u16 offset = (c-0x20)*0x18;
    u8 i=0;
    while (i<0x18) {
        //consoleMesenBreakpoint();
        characterData[i] = *((u8*)ascii_addr+offset+i);
        i++;
    }
    decodeCharacter(characterData);
}

void decodeShiftJisCharacter(u16 c) {
    //consoleMesenBreakpoint();
    u8 section = 1;
    u8 found = 0;
    u16 offset = 0;
    u32 addr = 0;
    while (found==0) {
        if (c<shift_jis_values[section]) {
            offset = (c-shift_jis_values[section-1])*0x18;
            addr = shift_jis_addr[section-1];
            found=1;
        }
        section++;
    }

    u8 i=0;
    while (i<0x18) {
        //consoleMesenBreakpoint();
        characterData[i] = *((u8*)addr+offset+i);
        i++;
    }
    decodeCharacter(characterData);
}
