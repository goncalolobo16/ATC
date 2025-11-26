#pragma once
#include <curses.h>
#include "Blocos.h"

class BlocosUI
{
private:
    Blocos blocos;
    char simbolo;     // carácter usado para desenhar o bloco (ex: '#')

public:
    BlocosUI();

    // prepara a parede (offset + layout inicial)
    void inicializar();

    // desenha todos os blocos ativos
    void printar();

    // acesso à lógica se precisares no futuro
    Blocos& getBlocos();
};
