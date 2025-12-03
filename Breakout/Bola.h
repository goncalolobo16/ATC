// Bola.h
#pragma once
#include "Entidade.h"

class Bola : public Entidade {
private:
    FloatXY velocidade;
    bool emJogo;

public:
    Bola();

    FloatXY retornaVelocidade();
    void mudaVelocidade(float x, float y);

    void inicializar(int cols, int lines);
    void atualizar(int maxCols, int maxLines);

    bool estaEmJogo() const;
    void tirardoJogo();
};
