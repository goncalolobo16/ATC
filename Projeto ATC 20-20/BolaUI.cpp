#include "BolaUI.h"
#include <curses.h>

BolaUI::BolaUI()
    : bola()
{
}

void BolaUI::inicializar() {
    bola.inicializar(COLS, LINES);
}

void BolaUI::moverBola(const Base& base) {
    // pede à logica da bola para atualizar com o tamanho do ecrã
    bola.atualizar(COLS, LINES, base);
}

void BolaUI::printar() {
    if (!bola.estaEmJogo())
        return;    

    FloatXY p = bola.retornaPosicao();   
    mvaddch((int)p.y, (int)p.x, 'O');
}

bool BolaUI::estaAtiva() const {
    return bola.estaEmJogo();
}

FloatXY BolaUI::retornaPosicao() {
    return bola.retornaPosicao();
}

FloatXY BolaUI::retornaVelocidade()
{ return bola.retornaVelocidade(); }

void BolaUI::mudaVelocidade(float vx, float vy)
{ bola.mudaVelocidade(vx, vy); }