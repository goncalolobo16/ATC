#include "BolaUI.h"
#include <curses.h>

BolaUI::BolaUI()
    : bola()
{
}

void BolaUI::inicializar() {
    // inicializa a bola com o tamanho atual do ecrã
    bola.inicializar(COLS, LINES);
}

void BolaUI::moverBola() {
    // pede à logica da bola para atualizar com o tamanho do ecrã
    bola.atualizar(COLS, LINES);
}

void BolaUI::printar() {
    if (!bola.estaEmJogo())
        return;    // se caiu no void, nao desenha

    FloatXY p = bola.retornaPosicao();   // <-- aqui estava retronaPosicao()
    mvaddch((int)p.y, (int)p.x, 'o');
}

bool BolaUI::estaAtiva() const {
    return bola.estaEmJogo();
}

FloatXY BolaUI::retornaPosicao() {
    return bola.retornaPosicao();        
}
