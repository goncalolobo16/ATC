#pragma once
#include <curses.h>
#include "Bola.h"

class BolaUI {
private:
    Bola bola;

public:
    BolaUI();

    void inicializar();
    void moverBola(const Base& base);
    void printar();

    // para a main / jogo saber se a bola ainda está em jogo
    bool estaAtiva() const;
    FloatXY retornaPosicao();  // útil no futuro
    FloatXY retornaVelocidade() { return bola.retornaVelocidade(); }
    void mudaVelocidade(float vx, float vy) { bola.mudaVelocidade(vx, vy); }
};

