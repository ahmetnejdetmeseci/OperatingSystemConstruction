#include "machine/cgascr.h"

void CGA_Screen::putchar(char c){
    if (c == '\n'){
        x =0;
        y++;
        return;
    }

    video[y*80 +x] = (0x07 << 8) | c;
    x++;

    if(x >= 80){
        x = 0;
        y++;
    }
}