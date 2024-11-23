.include "hdr.asm"

.RAMSECTION ".section7f" BANK $7F SLOT 3
WRAM_7F		DB
.ENDS

.section ".rodata1" superfree
palettes: .incbin "palettes.pal"
palettes_end
.ends

.section ".page1" superfree
page1: .incbin "text.data"
page1_end:
.ends
