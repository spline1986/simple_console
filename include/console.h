#pragma once
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

struct termsize {
    int w, h;
};

const std::string fg[8] = {
    "30",
    "34",
    "32",
    "36",
    "31",
    "35",
    "33",
    "37",
};

const std::string bg[8] = {
    "40",
    "44",
    "42",
    "46",
    "41",
    "45",
    "43",
    "47",
};

void clrscr() {
    std::printf("\033[2J");
    std::printf("\033[0;0H");
}

void gotoxy(int x, int y) {
    std::printf("\033[%d;%df", y, x);
}

void setcolors(int b, int f) {
    bool bright = false;
    if (f > 7) {
        f -= 8;
        bright = true;
    }
    std::printf("\033[%s;%sm", bg[b].c_str(), fg[f].c_str());
    if (bright)
        std::printf("\033[1m");
}

void resetcolors() {
    std::printf("\033[0m");
}

termsize getsize() {
    struct winsize size;
    termsize s;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    s.w = size.ws_col;
    s.h = size.ws_row;
    return s;
}
