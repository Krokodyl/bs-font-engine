# bs-font-engine

PVSnesLib project implementation of the bs font.

Work in progress

Supports single-byte ascii and two-byte shift-jis.

# Font Mapping

Font provided in the BS-X bios.<br/>
This font is mostly mapped on the [Shift-JIS](https://en.wikipedia.org/wiki/Shift_JIS) standard where every character is coded by two bytes.<br/>

The narrow latin alphabet seems to be based on one of the [JIS X extension](https://en.wikipedia.org/wiki/Shift_JIS#Other_variants).<br/>
Three characters differ from ASCII:<br/>

0x5C    is ¥ instead of backslash \ <br/>
0x60    is a white space instead of backtick `<br/>
0x7E    is an underscore instead of tilde ~<br/>


[Shift-JIS Complete Table](http://www.rikai.com/library/kanjitables/kanji_codes.sjis.shtml)


| Offset      | Content                           | Comment                                                                                  |
|-------------|-----------------------------------|------------------------------------------------------------------------------------------|
| 48000-50000 | ![48000](img/bios-mapping/01.png) | Kanjis:<br/>88 9F<br/>89 40<br/>8A 40<br/>8B 40 - 8B 5B                                  |
| 50000-58000 | ![50000](img/bios-mapping/02.png) | Kanjis:<br/>8B 5C - 8B xx<br/>8C 40<br/>8D 40<br/>8E 40<br/>8F 40<br/>90 40 - 90 B0<br/> |
| 58000-60000 | ![58000](img/bios-mapping/03.png) | Kanjis:<br/>90 B1 - 90 xx<br/>91 40<br/>92 40<br/>93 40<br/>94 40<br/>95 40              |
| 60000-68000 | ![60000](img/bios-mapping/04.png) | Kanjis:<br/>96 40<br/>97 40<br/>98 40<br/>99 40<br/>9A 40<br/>9B 40                      |
| 68000-70000 | ![68000](img/bios-mapping/05.png) | Kanjis:<br/>9C 40<br/>9D 40<br/>9E 40<br/>9F 40<br/>E0 40                                |
| 70000-78000 | ![70000](img/bios-mapping/06.png) | Kanjis:<br/>E1 40<br/>E2 40<br/>E3 40<br/>E4 40<br/>E5 40<br/>E6 40                      |
| 78000-80000 | ![78000](img/bios-mapping/07.png) | Kanjis:<br/>E7 40<br/>E8 40<br/>E9 40<br/>EA 40                                          |
