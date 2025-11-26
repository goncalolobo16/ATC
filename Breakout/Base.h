#pragma once
#include "Entidade.h"
class Base
{
private:
	FloatXY posicao;
	float velocidade;

public:
	Base();
	FloatXY retornaPosicao();
	float retornaVelocidade();
	void definePosica(float x, float y);
	
};

