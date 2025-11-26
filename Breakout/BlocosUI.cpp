#include "BlocosUI.h"

BlocosUI::BlocosUI()
    : blocos(), simbolo('#')
{
}

void BlocosUI::inicializar()
{
    // se quiseres mudar a posição:
    // blocos.setOffset(2, 2);
    blocos.reset();
}

void BlocosUI::printar()
{
    for (int linha = 0; linha < Blocos::LINHAS; ++linha) {
        for (int col = 0; col < Blocos::COLUNAS; ++col) {

            if (!blocos.estaAtivo(linha, col))
                continue;

            int x, y;
            blocos.obterPosicao(linha, col, x, y);

            // desenha o bloco como um rectângulo 11x2 de '#'
            for (int dy = 0; dy < Blocos::ALT_BLOCO; ++dy) {
                for (int dx = 0; dx < Blocos::LARG_BLOCO; ++dx) {
                    mvaddch(y + dy, x + dx, simbolo);
                }
            }
        }
    }
}

Blocos& BlocosUI::getBlocos()
{
    return blocos;
}
