#include "console.h"

using namespace std;

int main() {
    clrscr();
    termsize s = getsize();
    for (int f = 0; f < 16; f++) {
        gotoxy((s.w - 56) / 2, (s.h - 16) / 2 + 1 + f);
        for (int b = 0; b < 8; b++) {
            setcolors(b, f);
            cout << "*HELLO*";
        }
        cout << endl;
    }
    resetcolors();
    return 0;
}
