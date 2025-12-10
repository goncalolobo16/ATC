#include "Base.h"

Base::Base()
    : Entidade(11.0f, 1.0f), velocidade(2.0f) // largura 11, altura 1
{
}

void Base::inicializar(int maxCols, int maxLines) {
    float x = maxCols / 2.0f - retornaLargura() / 2.0f;
    float y = maxLines - 2.0f;
    definePosicaoAbsoluta(x, y);
}

void Base::moverEsquerda(int maxCols) {
    FloatXY p = retornaPosicao();
    if (p.x > 0.0f) {
        definePosicao(-velocidade, 0.0f);
    }
}

void Base::moverDireita(int maxCols) {
    FloatXY p = retornaPosicao();
    if (p.x + retornaLargura() < maxCols) {
        definePosicao(velocidade, 0.0f);
    }
}
