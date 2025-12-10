#pragma once
#include <curses.h>
#include "Base.h"

class BaseUI {
    Base base;

public:
    BaseUI();

    void inicializar();
    void moverBase(int tecla);
    void printar();

    const Base& getBase() const { return base; }
};

