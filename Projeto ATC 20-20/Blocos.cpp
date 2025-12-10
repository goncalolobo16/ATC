#include "Blocos.h"

Blocos::Blocos()
    : Entidade(),          // <--- chama construtor da classe base
    offsetX(1), offsetY(2)   // margem à esquerda/cima
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

bool Blocos::colideEDestroiBloco(const FloatXY& posBola)
{
    for (int linha = 0; linha < LINHAS; ++linha) {
        for (int col = 0; col < COLUNAS; ++col) {

            if (!ativo[linha][col])
                continue;

            int x, y;
            obterPosicao(linha, col, x, y);

            float esquerda = static_cast<float>(x);
            float direita = esquerda + LARG_BLOCO;
            float topo = static_cast<float>(y);
            float fundo = topo + ALT_BLOCO;

            // bola é 1x1, assumimos que a posição é o "centro"
            if (posBola.x >= esquerda && posBola.x < direita &&
                posBola.y >= topo && posBola.y < fundo)
            {
                // acerta neste bloco -> destrói
                ativo[linha][col] = false;
                return true;
            }
        }
    }

    return false; // não bateu em bloco nenhum
}