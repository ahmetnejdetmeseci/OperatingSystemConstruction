#ifndef strbuf_include
#define strbuf_include

class Stringbuffer {
protected:
    static const int size = 128;
    char buffer[size];
    int pos;

public:
    Stringbuffer() : pos(0) {}

    void put(char c) {
        buffer[pos++] = c;
        if (pos == size)
            flush();
    }

    virtual void flush() = 0;
};

#endif