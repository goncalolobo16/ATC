#include "Base.h"
#include "Entidade.h"

Base::Base() {
	posicao.x = 0;
	posicao.y = 0;
	velocidade = 1;
}

FloatXY Base::retornaPosicao() {
	return posicao;
}

float Base::retornaVelocidade(){
	return velocidade;
}
void Base::definePosica(float x, float y) {
	posicao.x = x;
	posicao.y = y;
}
