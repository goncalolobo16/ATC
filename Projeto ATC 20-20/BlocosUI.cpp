#include "BlocosUI.h"

BlocosUI::BlocosUI(): blocos(), simbolo(219){}

void BlocosUI::inicializar()
{
    // blocos.setOffset(2, 2);  // se quiseres mudar
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

