#include "machine/keyctrl.h"
#include "device/cgastr.h"

CGA_Stream kout;
Keyboard_Controller keyboard;

int main() {
    kout.clear();
	kout << "Hello Its Nejo";
	kout.flush();
    while (1) {
        Key k = keyboard.key_hit();

        if (k.valid()) {
            kout << (char)k.ascii();
            kout.flush();
        }
    }
}