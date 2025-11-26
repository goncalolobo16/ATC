#include "Blocos.h"

Blocos::Blocos()
    : offsetX(2), offsetY(2)   // margem à esquerda/cima
{
    reset();
}

void Blocos::reset()
{
    // 1 = há bloco, 0 = vazio
    int layout[LINHAS][COLUNAS] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            ativo[i][j] = (layout[i][j] == 1);
        }
    }
}

void Blocos::setOffset(int x, int y)
{
    offsetX = x;
    offsetY = y;
}

bool Blocos::estaAtivo(int linha, int coluna) const
{
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS)
        return false;

    return ativo[linha][coluna];
}

void Blocos::obterPosicao(int linha, int coluna, int& x, int& y) const
{
    // cada linha lógica ocupa ALT_BLOCO linhas + ESPACO_Y vazia
    y = offsetY + linha * (ALT_BLOCO + ESPACO_Y);

    // cada coluna anda (largura do bloco + espaço) em x
    x = offsetX + coluna * (LARG_BLOCO + ESPACO_X);
}
