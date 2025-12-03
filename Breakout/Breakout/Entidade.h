#pragma once
struct FloatXY {
	float x;
	float y;
};

class Entidade
{
	FloatXY posicao;

	public:
		Entidade();
		FloatXY retornaPosicao()const;
		void definePosicao(float x, float y);
		
};

