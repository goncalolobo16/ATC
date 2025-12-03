// Base.h
#pragma once
#include "Entidade.h"

class Base : public Entidade {
private:
    float velocidade;

public:
    Base();

    // mantive estes para nao partires o resto do codigo
    FloatXY retornaPosicao();   // apenas delega para Entidade
    float retornaVelocidade();
    void definePosica(float x, float y); // define posicao absoluta
};
