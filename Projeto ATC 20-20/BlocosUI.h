#pragma once
#include <curses.h>
#include "Blocos.h"
#include "Desenha.h"

class BlocosUI:public Desenha
{
private:
    Blocos blocos;
    int simbolo;     

public:
    BlocosUI();

    void inicializar();
    void printar()override;
    Blocos& getBlocos();
};

