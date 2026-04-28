#include "machine/keyctrl.h"
#include "device/cgastr.h"
#include <cstdint>

CGA_Stream kout;
Keyboard_Controller keyboard;

int main() {
    kout.clear();

    kout << "Hello Its Nejo" << endl;
    kout << "Test          <stream result> -> <expected>" << endl;
    kout << "zero:         " << 0 << " -> 0" << endl;
    kout << "decimal:      " << dec << 42 << " -> 42" << endl;
    kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
    kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
    kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
    kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615" << endl;
    kout << "int64_t max:  " << ~(1l<<63) << " -> 9223372036854775807" << endl;
    kout << "int64_t min:  " << (1l<<63) << " -> -9223372036854775808" << endl;
    kout << "some int64_t: " << (-1234567890123456789ll) << " -> -1234567890123456789" << endl;
    kout << "some int64_t: " << (1234567890123456789ull) << " -> 1234567890123456789" << endl;
    kout << "pointer:      " << reinterpret_cast<void*>(1994473406541717165ul) << " -> 0x1badcafefee1dead" << endl;
    kout << "smiley:       " << static_cast<char>(1) << endl;
    kout.flush();

    while (1) {
        Key k = keyboard.key_hit();

        if (k.valid()) {
            kout << (char)k.ascii();
            kout.flush();
        }
    }
}