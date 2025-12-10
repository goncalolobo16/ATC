#include "Bola.h"
#include "Base.h"

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


void Bola::atualizar(int maxCols, int maxLines, const Base& base) {
    Entidade::atualizarBolaLimites(*this, velocidade, emJogo, maxCols, maxLines);
    if (!emJogo) return;

    // 2) interação com a base
    Entidade::tratarColisaoBolaBase(*this, velocidade,  base);
}

bool Bola::estaEmJogo() const {
    return emJogo;
}

void Bola::tirardoJogo() {
    emJogo = false;
}

