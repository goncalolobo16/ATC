#include "BaseUI.h"

BaseUI::BaseUI()
    : base()
{
}

void BaseUI::inicializar() {
    base.inicializar(COLS, LINES);
}

void BaseUI::moverBase(int tecla) {
    switch (tecla) {
    case KEY_LEFT:
    case 'a':
    case 'A':
        base.moverEsquerda(COLS);
        break;

    case KEY_RIGHT:
    case 'd':
    case 'D':
        base.moverDireita(COLS);
        break;

    default:
        break;
    }
}

void BaseUI::printar() {
    FloatXY p = base.retornaPosicao();
    int y = static_cast<int>(p.y);
    int x = static_cast<int>(p.x);

    int larg = static_cast<int>(base.retornaLargura());
    for (int i = 0; i < larg; ++i) {
        mvaddch(y, x + i, 223);  // o teu caracter da base
    }
}
