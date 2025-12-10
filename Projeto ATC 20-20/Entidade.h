#pragma once
struct FloatXY {
    float x;
    float y;
};

// Entidade = coisa com posicao + tamanho (largura x altura)
// Aqui vão ficar as interações genéricas (colisões, etc.)
class Entidade {
private:
    FloatXY posicao;
    float largura;
    float altura;

public:
    // construtor
    // por defeito, largura=1, altura=1 (ex: bola = 1x1)
    Entidade(float larg = 1.0f, float alt = 1.0f);

    // ---- POSIÇÃO ----
    FloatXY retornaPosicao() const;

    // move por delta (dx, dy), como já tinhas
    void definePosicao(float dx, float dy);

    // se precisares de pôr em absoluto:
    void definePosicaoAbsoluta(float x, float y);

    // ---- TAMANHO ----
    float retornaLargura() const { return largura; }
    float retornaAltura()  const { return altura; }

    // ---- COLISÕES GENÉRICAS ----
    // colisão retângulo vs retângulo (AABB)
    bool colideCom(const Entidade& outra) const;


    static void atualizarBolaLimites(Entidade& bola,FloatXY& velocidade,bool& emJogo,int maxCols,int maxLines);

    static void tratarColisaoBolaBase(Entidade& bola,FloatXY& velocidade,const Entidade& base);

 
};
