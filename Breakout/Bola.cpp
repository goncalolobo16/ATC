#include "Bola.h"

Bola::Bola() : Entidade() {
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
    emJogo = true;   
}

FloatXY Bola::retornaVelocidade() {
    return velocidade;
}

void Bola::mudaVelocidade(float x, float y) {
    velocidade.x = x;
    velocidade.y = y;
}

void Bola::inicializar(int cols, int lines) {
    // queremos por a bola no centro, independentemente da posicao atual
    FloatXY atual = retornaPosicao();
    float alvoX = cols / 2.0f;
    float alvoY = lines / 2.0f;

    // como so temos definePosicao(dx, dy), calculamos o delta:
    float dx = alvoX - atual.x;
    float dy = alvoY - atual.y;

    definePosicao(dx, dy);

    velocidade.x = 0.5f;
    velocidade.y = 0.5f;
    emJogo = true;   // quando inicializas, ela volta a ficar ativa
}

// logica de movimento e colisoes
void Bola::atualizar(int maxCols, int maxLines) {
    if (!emJogo) return;   // se ja caiu no void, nao faz mais nada

    // posicao atual vinda da Entidade
    FloatXY oldP = retornaPosicao();
    FloatXY p = oldP;
    FloatXY v = velocidade;

    // movimento
    p.x += v.x;
    p.y += v.y;

    // paredes esquerda/direita
    if (p.x <= 0.0f) {
        p.x = 0.0f;
        v.x = -v.x;
    }
    if (p.x >= maxCols - 1) {
        p.x = static_cast<float>(maxCols - 1);
        v.x = -v.x;
    }

    // teto
    if (p.y <= 0.0f) {
        p.y = 0.0f;
        v.y = -v.y;
    }

    // FUNDO = VOID
    if (p.y >= maxLines - 1) {
        // bateu no chao, consideramos que caiu no void
        emJogo = false;

        // atualizar posicao na Entidade com o delta
        float dx = p.x - oldP.x;
        float dy = p.y - oldP.y;
        definePosicao(dx, dy);

        velocidade = v;
        return;
    }

    // atualizar posicao na Entidade com o delta
    float dx = p.x - oldP.x;
    float dy = p.y - oldP.y;
    definePosicao(dx, dy);

    velocidade = v;
}

bool Bola::estaEmJogo() const {
    return emJogo;
}

void Bola::tirardoJogo() {
    emJogo = false;
}
