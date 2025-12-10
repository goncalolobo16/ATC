#pragma once
#include <curses.h>
#include "Base.h"
#include "Desenha.h"

class BaseUI :public Desenha
{
    Base base;

public:
    BaseUI();

    void inicializar();
    void moverBase(int tecla);
    void printar()override;

    const Base& getBase() const { return base; }
};

