
#pragma once
#include "Entidade.h"
#include "Base.h"

class Bola : public Entidade {
private:
    FloatXY velocidade;
    bool emJogo;

public:
    Bola();

    FloatXY retornaVelocidade();
    void mudaVelocidade(float x, float y);

    void inicializar(int cols, int lines);
    void atualizar(int maxCols, int maxLines, const Base& base);

    bool estaEmJogo() const;
    void tirardoJogo();

};

