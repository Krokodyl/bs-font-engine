.include "hdr.asm"

.BASE 0 .BANK 0
.SECTION ".satellaview_text" FORCE

;---------- MAP BS-ROM ----------
;
bsMapFont:
    PHA
    PHP
    SEP #$20
    LDA #$80
    STA $085000
    STA $0E5000
    PLP
    PLA
.ENDS