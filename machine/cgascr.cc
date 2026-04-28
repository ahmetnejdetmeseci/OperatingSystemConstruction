#include "machine/cgascr.h"
#include "machine/io_port.h"

void CGA_Screen::update_cursor() {
    int pos = y * 80 + x;
    IO_Port indexPort(0x3d4);
    IO_Port dataPort(0x3d5);

    indexPort.outb(0x0f);
    dataPort.outb(pos & 0xff);
    indexPort.outb(0x0e);
    dataPort.outb((pos >> 8) & 0xff);
}

void CGA_Screen::scroll() {
    for (int row = 1; row < 25; row++) {
        for (int col = 0; col < 80; col++) {
            video[(row - 1) * 80 + col] = video[row * 80 + col];
        }
    }

    for (int col = 0; col < 80; col++) {
        video[24 * 80 + col] = (0x07 << 8) | ' ';
    }

    y = 24;
}

void CGA_Screen::putchar(unsigned char c){
    if (c == '\n'){
        x = 0;
        y++;
        if (y >= 25)
            scroll();
        update_cursor();
        return;
    }

    video[y*80 +x] = (0x07 << 8) | static_cast<unsigned char>(c);
    x++;

    if(x >= 80){
        x = 0;
        y++;
    }

    if (y >= 25)
        scroll();

    update_cursor();
}