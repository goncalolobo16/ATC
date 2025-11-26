#pragma once
#include "Entidade.h"
#include "Base.h"
#include "Blocos.h"

class Bola:public Entidade
{
	FloatXY velocidade;
	bool emJogo;

public:
	Bola();
	FloatXY retornaVelocidade();
	void mudaVelocidade(float x, float y);
	
	void inicializar(int cols, int lines);
	void atualizar(int maxCols, int maxLines);
	bool estaEmJogo()const;
	void tirardoJogo();
};

