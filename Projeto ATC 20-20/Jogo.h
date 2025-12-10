#pragma once

#include <vector>
#include <curses.h>

#include "Desenha.h"
#include "BaseUI.h"
#include "BolaUI.h"
#include "BlocosUI.h"

class Jogo
{
public:
    Jogo();
    ~Jogo();

    void correr();          // função principal do jogo

private:
    // ---- métodos internos ----
    void initNcurses();
    void terminaNcurses();

    bool ecrãInicial();     // mostra BREAKOUT / SPACE / ESC, devolve false se sair
    void loopJogo();        // game loop (vidas, colisões, desenho, etc.)
    void ecrãGameOver();    // mensagem GAME OVER

    // ---- objetos de interface ----
    BaseUI   baseUI;
    BolaUI   bolaUI;
    BlocosUI blocosUI;

    std::vector<Desenha*> desenhadores;  // ponteiros para UI genéricos

    int vidas;
};
