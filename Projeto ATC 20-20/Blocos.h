#pragma once
#include "Entidade.h"   

class Blocos : public Entidade   
{
public:
    // grelha lógica
    static const int LINHAS = 6;   
    static const int COLUNAS = 10;  

    // dimensões visuais de cada bloco
    static const int LARG_BLOCO = 11; 
    static const int ALT_BLOCO = 1;  
    static const int ESPACO_X = 1;  
    static const int ESPACO_Y = 1; 

private:
    bool ativo[LINHAS][COLUNAS]; 

    int offsetX;  
    int offsetY;  

public:
    Blocos();

    void reset();
    void setOffset(int x, int y);
    bool estaAtivo(int linha, int coluna) const;


    void obterPosicao(int linha, int coluna, int& x, int& y) const;
    bool colideEDestroiBloco(const FloatXY& posBola);
};


