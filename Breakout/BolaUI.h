#pragma once
#include <curses.h>
#include "Bola.h"

class BolaUI {
private:
    Bola bola;

public:
    BolaUI();

    void inicializar();
    void moverBola();
    void printar();

    // para a main / jogo saber se a bola ainda está em jogo
    bool estaAtiva() const;
    FloatXY retornaPosicao() ;  // útil no futuro
};
