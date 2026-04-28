#ifndef o_stream_include
#define o_stream_include

#include "object/strbuf.h"

class O_Stream {
protected:
    Stringbuffer &buf;

public:
    O_Stream(Stringbuffer &b) : buf(b) {}

    O_Stream& operator<<(char c) {
        buf.put(c);
        return *this;
    }

    O_Stream& operator<<(const char *str) {
        while (*str)
            buf.put(*str++);
        return *this;
    }

    O_Stream& operator<<(int n) {
        char tmp[16];
        int i = 0;

        if (n == 0) {
            buf.put('0');
            return *this;
        }

        while (n > 0) {
            tmp[i++] = '0' + (n % 10);
            n /= 10;
        }

        while (i--)
            buf.put(tmp[i]);

        return *this;
    }
};

#endif