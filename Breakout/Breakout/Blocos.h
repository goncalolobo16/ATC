#pragma once
#include "Entidade.h"   // <--- ADICIONADO

class Blocos : public Entidade   // <--- agora herda de Entidade
{
public:
    // grelha lógica
    static const int LINHAS = 6;   // 4 linhas de blocos
    static const int COLUNAS = 10;  // 10 blocos por linha

    // dimensões visuais de cada bloco
    static const int LARG_BLOCO = 11; // "###########"
    static const int ALT_BLOCO = 1;  // 2 linhas
    static const int ESPACO_X = 1;  // 1 coluna vazia entre blocos
    static const int ESPACO_Y = 1;  // 1 linha vazia entre filas

private:
    bool ativo[LINHAS][COLUNAS]; // true = há bloco, false = vazio

    int offsetX;  // coluna onde começa a parede (no ecrã)
    int offsetY;  // linha onde começa a parede (no ecrã)

public:
    Blocos();

    // repõe o layout inicial (matriz 0/1 fixa)
    void reset();

    // mudar onde a parede aparece no ecrã
    void setOffset(int x, int y);

    // saber se numa dada célula existe bloco
    bool estaAtivo(int linha, int coluna) const;

    // obter posição em ecrã do canto sup. esquerdo do bloco (linha,coluna)
    void obterPosicao(int linha, int coluna, int& x, int& y) const;
};
