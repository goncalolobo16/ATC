// Base.h
#pragma once
#include "Entidade.h"

class Base : public Entidade {
private:
    float velocidade;

public:
    Base();

    
    FloatXY retornaPosicao();   
    float retornaVelocidade();
    void definePosica(float x, float y);
};
