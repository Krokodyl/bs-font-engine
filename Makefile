ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME by following this guide: https://github.com/alekmaul/pvsneslib/wiki/Installation")
endif

export SFCBSCONV := tools/sfc-bs-converter-1.0

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: bitmaps all

#---------------------------------------------------------------------------------
# ROMNAME is used in snes_rules file
export ROMNAME := main
export BSROMNAME := main-bs

all: bitmaps $(ROMNAME).sfc sfcbsconv

clean: cleanBuildRes cleanRom cleanGfx

sfcbsconv:
	@echo Converting rom for the Satellaview
	$(SFCBSCONV) -d 28 -m 12 -b 29 80 -t "BS-DEMO-FONT" -i $(ROMNAME).sfc -o $(BSROMNAME).bs $<
	
#---------------------------------------------------------------------------------

palettes.pic: palettes.bmp
	@echo convert bitmap ... $(notdir $@)	
	$(GFXCONV) -s 8 -o 16 -u 16 -e 0 -p -g -t bmp -m -i $<

bitmaps : palettes.pic
