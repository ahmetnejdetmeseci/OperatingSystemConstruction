#ifndef screen_include
#define screen_include

class CGA_Screen {
private:
    unsigned short *video;
    int x, y;

    void update_cursor();
    void scroll();

public:
    CGA_Screen() : video((unsigned short*)0xb8000), x(0), y(0) {}

    void putchar(unsigned char c);
    void clear();
};

#endif