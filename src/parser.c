#include "parser.h"

void parseText(u8 text[]) {

    initLine();

    u8 i=0;
    u8 readByte = 0;
    u16 readWord = 0;
    do {
        readByte = text[i];
        if (readByte==MODE_ASCII) {
            mode = MODE_ASCII;
        }
        else if (readByte==MODE_SHIFT_JIS) {
            mode=MODE_SHIFT_JIS;
        }
        else if (readByte!=END_OF_TEXT) {
            if (mode==MODE_ASCII) {
                decodeAsciiCharacter(readByte);
                printCharacter(decodedChar, 6);

            } else if (mode==MODE_SHIFT_JIS) {
                readWord = readByte<<8;
                i++;
                readByte = text[i];
                readWord = readWord | readByte;
                decodeShiftJisCharacter(readWord);
                printCharacter(decodedChar, 12);

            }
        }
        i++;
    } while (readByte!=END_OF_TEXT);

    endLine();
    copyTilesToVram();
    copyMapToVram();
}