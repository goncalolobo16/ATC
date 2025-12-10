#pragma once
#include <curses.h>
#include "Bola.h"
#include "Desenha.h"

class BolaUI : public Desenha
{
private:
    Bola bola;

public:
    BolaUI();

    void inicializar();
    void moverBola(const Base& base);
    void printar()override;

  
    bool estaAtiva() const;
    FloatXY retornaPosicao();  // útil no futuro
    FloatXY retornaVelocidade();
    void mudaVelocidade(float vx, float vy);
};

