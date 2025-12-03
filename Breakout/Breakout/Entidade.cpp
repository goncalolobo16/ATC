#include "Entidade.h"
Entidade::Entidade() {
	posicao.x = 0;
	posicao.y = 0;

}

FloatXY Entidade::retornaPosicao()const {
	return posicao;
}

void Entidade::definePosicao(float dx, float dy) {
	posicao.x += dx;
	posicao.y += dy;
}
