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

    // ---- INTERAÇÕES ESPECÍFICAS DE JOGO ----
    // 1) Atualiza a bola com base na velocidade e nos limites do ecrã.
    //    Esta função É basicamente o teu Bola::atualizar,
    //    mas metida aqui.
    //    - bola      : a entidade que representa a bola
    //    - velocidade: velocidade da bola (x,y)
    //    - emJogo    : bool que diz se a bola ainda está ativa
    //    - maxCols, maxLines: tamanho do ecrã
    static void atualizarBolaLimites(Entidade& bola,
        FloatXY& velocidade,
        bool& emJogo,
        int maxCols,
        int maxLines);

    // 2) Tratar colisão bola ? base
    //    - bola      : entidade da bola
    //    - velocidade: velocidade da bola (alterada se bater)
    //    - base      : entidade da base
    static void tratarColisaoBolaBase(Entidade& bola,
        FloatXY& velocidade,
        const Entidade& base);

 
};
