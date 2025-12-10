#include "Entidade.h"
#include <cmath> // para std::fabs

Entidade::Entidade(float larg, float alt)
    : largura(larg), altura(alt)
{
    posicao.x = 0.0;
    posicao.y = 0.0;
}

FloatXY Entidade::retornaPosicao() const {
    return posicao;
}

void Entidade::definePosicao(float dx, float dy) {
    posicao.x += dx;
    posicao.y += dy;
}

void Entidade::definePosicaoAbsoluta(float x, float y) {
    posicao.x = x;
    posicao.y = y;
}

//  COLISaO AABB 
// this vs outra
bool Entidade::colideCom(const Entidade& outra) const
{
    float esquerdaA = posicao.x;
    float direitaA = posicao.x + largura;
    float topoA = posicao.y;
    float fundoA = posicao.y + altura;

    float esquerdaB = outra.posicao.x;
    float direitaB = outra.posicao.x + outra.largura;
    float topoB = outra.posicao.y;
    float fundoB = outra.posicao.y + outra.altura;

    bool separado =
        (direitaA <= esquerdaB) ||
        (esquerdaA >= direitaB) ||
        (fundoA <= topoB) ||
        (topoA >= fundoB);

    return !separado;
}

//  LoGICA DA BOLA vs ECRa 
//
// Isto é basicamente o teu Bola::atualizar,
// mas feito aqui e usando a interface de Entidade.
//
void Entidade::atualizarBolaLimites(Entidade& bola,
    FloatXY& velocidade,
    bool& emJogo,
    int maxCols,
    int maxLines)
{
    if (!emJogo) return;

    // posicao atual
    FloatXY oldP = bola.retornaPosicao();
    FloatXY p = oldP;
    FloatXY v = velocidade;

    // movimento
    p.x += v.x;
    p.y += v.y;

    // paredes esquerda/direita
    if (p.x <= 0.0) {
        p.x = 0.0;
        v.x = -v.x;
    }
    if (p.x >= maxCols - 1) {
        p.x = static_cast<float>(maxCols - 1);
        v.x = -v.x;
    }

    // teto
    if (p.y <= 1.0) {
        p.y = 1.0;
        v.y = -v.y;
    }

    // FUNDO = VOID
    if (p.y >= maxLines - 1) {
        // bateu no chao ? bola perde
        emJogo = false;

        float dx = p.x - oldP.x;
        float dy = p.y - oldP.y;
        bola.definePosicao(dx, dy);

        velocidade = v;
        return;
    }

    // atualizar posicao normalmente
    float dx = p.x - oldP.x;
    float dy = p.y - oldP.y;
    bola.definePosicao(dx, dy);

    velocidade = v;
}

//  LoGICA BOLA vs BASE 
//
// Aqui usas colideCom + ajustas a velocidade, etc.
//
void Entidade::tratarColisaoBolaBase(Entidade& bola,
    FloatXY& velocidade,
    const Entidade& base)
{
    // só interessa colisão quando a bola vem para baixo
    if (velocidade.y <= 0.0) return;

    // se nao colide, bazamos
    if (!bola.colideCom(base))
        return;

    // encostar a bola por cima da base
    FloatXY posBola = bola.retornaPosicao();
    FloatXY posBase = base.retornaPosicao();

    float alturaBola = bola.retornaAltura(); // em princípio 1
    float novaY = posBase.y - alturaBola;
    float dy = novaY - posBola.y;

    bola.definePosicao(0.0, dy);

    // inverter velocidade vertical
    velocidade.y = -std::fabs(velocidade.y);

    // opcional: alterar velocidade.x em função do sítio onde bate na base
    float larguraBase = base.retornaLargura();
    float centroBase = posBase.x + larguraBase / 2.0;
    float distancia = posBola.x - centroBase;             // negativo = esquerda
    float norma = distancia / (larguraBase / 2.0);   // -1..1 aprox

    if (norma < -1.0) norma = -1.0;
    if (norma > 1.0) norma = 1.0;

    // ajusta vx para dar "efeito" consoante a zona
    velocidade.x = norma * 0.8;
}



