#include "Base.h"

Base::Base() : Entidade() {
    // posicao ja comeca em (0,0) por causa da Entidade
    velocidade = 1.0f;
}

FloatXY Base::retornaPosicao() {
    // usa o getter da Entidade
    return Entidade::retornaPosicao();
}

float Base::retornaVelocidade() {
    return velocidade;
}

void Base::definePosica(float x, float y) {
    // esta funcao continua a definir posicao absoluta,
    // mas por baixo usa o definePosicao(dx, dy) da Entidade

    FloatXY atual = Entidade::retornaPosicao();
    float dx = x - atual.x;
    float dy = y - atual.y;

    // chama o metodo da Entidade (delta)
    definePosicao(dx, dy); // Entidade::definePosicao(dx, dy)
}
