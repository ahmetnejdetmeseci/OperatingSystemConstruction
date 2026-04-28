#include "device/cgastr.h"

void CGA_Stream::flush() {
    for (int i = 0; i < pos; i++) {
        screen.putchar(buffer[i]);
    }
    pos = 0;
}

void CGA_Stream::clear() {
    screen.clear();
}

void CGA_Screen::clear() {
    for (int i = 0; i < 80 * 25; i++)
        video[i] = (0x07 << 8) | ' ';
    x = 0;
    y = 0;
}