#include "Bola.h"

Bola::Bola() {
    velocidade.x = 0;
    velocidade.y = 0;
    posicao.x = 0;
    posicao.y = 0;
    emJogo = true;             // por defeito, ativa
}

FloatXY Bola::retornaVelocidade() {
    return velocidade;
}


void Bola::mudaVelocidade(float x, float y) {
    velocidade.x = x;
    velocidade.y = y;
}


void Bola::inicializar(int cols, int lines) {
    posicao.x = cols / 2;
    posicao.y = lines / 2;

    velocidade.x = 0.5;
    velocidade.y = 0.5;
    emJogo = true;             // quando inicializas, ela volta a ficar ativa
}

// ? AQUI vai a lógica toda
void Bola::atualizar(int maxCols, int maxLines) {
    if (!emJogo) return;   // se já caiu no void, não faz mais nada

    FloatXY p = posicao;
    FloatXY v = velocidade;

    // movimento
    p.x += v.x;
    p.y += v.y;

    // paredes esquerda/direita
    if (p.x <= 0) {
        p.x = 0;
        v.x = -v.x;
    }
    if (p.x >= maxCols - 1) {
        p.x = maxCols - 1;
        v.x = -v.x;
    }

    // teto
    if (p.y <= 0) {
        p.y = 0;
        v.y = -v.y;
    }

    // FUNDO = VOID
    if (p.y >= maxLines - 1) {
        // bateu no chão ? consideramos que caiu no void
        emJogo = false;
        // se quiseres, podes fixar a posição:
        // p.y = maxLines - 1;
        posicao = p;
        velocidade = v;
        return;
    }

    posicao = p;
    velocidade = v;
}

bool Bola::estaEmJogo() const {
    return emJogo;
}

void Bola::tirardoJogo() {
    emJogo = false;
}
