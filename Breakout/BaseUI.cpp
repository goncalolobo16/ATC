#include "BaseUI.h"
#include <curses.h>

BaseUI::BaseUI() : base(), x(0), y(0), ch(0), largura(11) {}

void BaseUI::inicializar() {
    x = COLS / 2;
    y = LINES - 2;
    ch = 0;
}

void BaseUI::moverBase(int tecla) {
    ch = tecla;

    switch (ch) {
    case KEY_LEFT:
    case 'a':
    case 'A':
        if (x > 0) x--;
        break;

    case KEY_RIGHT:
    case 'd':
    case 'D':
        if (x < COLS - (int)largura) x++;
        break;

    default:
        break;
    }
}

void BaseUI::printar() {
    for (int i = 0; i < (int)largura; ++i) {
        mvaddch(y, x + i, '-');
    }
}
