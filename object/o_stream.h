#ifndef o_stream_include
#define o_stream_include

#include "object/strbuf.h"

class O_Stream {
protected:
    Stringbuffer &buf;
    int base;

public:
    O_Stream(Stringbuffer &b) : buf(b), base(10) {}

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
        return *this << (long long)n;
    }

    O_Stream& operator<<(unsigned int n) {
        return *this << (unsigned long long)n;
    }

    O_Stream& operator<<(long n) {
        return *this << (long long)n;
    }

    O_Stream& operator<<(unsigned long n) {
        return *this << (unsigned long long)n;
    }

    O_Stream& operator<<(long long n) {
        if (n < 0) {
            buf.put('-');
            unsigned long long value = (unsigned long long)(-(n + 1)) + 1;
            putUnsigned(value);
        } else {
            putUnsigned((unsigned long long)n);
        }
        return *this;
    }

    O_Stream& operator<<(unsigned long long n) {
        putUnsigned(n);
        return *this;
    }

    O_Stream& operator<<(void *p) {
        unsigned long long value = (unsigned long long)(unsigned long)p;
        buf.put('0');
        buf.put('x');
        int old_base = base;
        base = 16;
        putUnsigned(value);
        base = old_base;
        return *this;
    }

    O_Stream& operator<<(O_Stream& (*manip)(O_Stream&)) {
        return manip(*this);
    }

    void setBase(int b) { base = b; }
    int getBase() { return base; }

    void put(char c) { buf.put(c); }
    void flush() { buf.flush(); }

private:
    void putUnsigned(unsigned long long n) {
        if (n == 0) {
            buf.put('0');
            return;
        }

        char tmp[64];
        int i = 0;

        while (n > 0) {
            unsigned int digit = n % base;
            tmp[i++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
            n /= base;
        }

        while (i--)
            buf.put(tmp[i]);
    }
};

O_Stream& dec(O_Stream& os);
O_Stream& hex(O_Stream& os);
O_Stream& oct(O_Stream& os);
O_Stream& bin(O_Stream& os);
O_Stream& endl(O_Stream& os);

#endif