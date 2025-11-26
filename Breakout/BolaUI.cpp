#include "BolaUI.h"

BolaUI::BolaUI()
    : bola()
{
}

void BolaUI::inicializar() {
    bola.inicializar(COLS, LINES);
}

void BolaUI::moverBola() {
    // só pede à lógica para atualizar com o tamanho do ecrã
    bola.atualizar(COLS, LINES);
}

void BolaUI::printar() {
    if (!bola.estaEmJogo())
        return;    // se caiu no void, não desenha

    FloatXY p = bola.retronaPosicao();
    mvaddch((int)p.y, (int)p.x, '0');
}

bool BolaUI::estaAtiva() const {
    return bola.estaEmJogo();
}

FloatXY BolaUI::retornaPosicao()  {
    return bola.retronaPosicao();
}
