#pragma once
#include "Entidade.h"

class Base : public Entidade {
    float velocidade;

public:
    Base();

    void inicializar(int maxCols, int maxLines);
    void moverEsquerda(int maxCols);
    void moverDireita(int maxCols);
};
