#include "Jogo.h"
#include <cstring>   // strlen

Jogo::Jogo()
    : baseUI(), bolaUI(), blocosUI(), vidas(3)
{
    // vector com os desenhadores (polimorfismo)
    desenhadores = {
        &blocosUI,
        &baseUI,
        &bolaUI
    };
}

Jogo::~Jogo()
{
    terminaNcurses();
}

void Jogo::initNcurses()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);
    timeout(30);
}

void Jogo::terminaNcurses()
{
    endwin();
}

void Jogo::correr()
{
    initNcurses();

    bool aCorrer = true;

    while (aCorrer)
    {
        if (!ecrãInicial()) {
            aCorrer = false;   
            break;
        }
        vidas = 3;
        baseUI.inicializar();
        bolaUI.inicializar();
        blocosUI.inicializar();

        loopJogo();
        ecrãGameOver();
    }
}

bool Jogo::ecrãInicial()
{
    clear();

    const char* titulo = "BREAKOUT";
    const char* msg = "PRESS SPACE TO START";
    const char* msg2 = "PRESS ESC TO EXIT";

    int linhaCentro = LINES / 2;

    int colTitulo = (COLS - (int)std::strlen(titulo)) / 2;
    int colMsg = (COLS - (int)std::strlen(msg)) / 2;
    int colMsg2 = (COLS - (int)std::strlen(msg2)) / 2;

    mvprintw(linhaCentro - 1, colTitulo, "%s", titulo);
    mvprintw(linhaCentro + 1, colMsg, "%s", msg);
    mvprintw(linhaCentro + 2, colMsg2, "%s", msg2);

    refresh();

    int tecla;
    do {
        tecla = getch();
    } while (tecla != ' ' && tecla != 27);

    // ESC -> false (não corre jogo)
    return (tecla == ' ');
}

void Jogo::loopJogo()
{
    int ch = 0;

    while (ch != 'q' && ch != 'Q' && vidas > 0)
    {
        clear();

        // input + movimento
        baseUI.moverBase(ch);
        bolaUI.moverBola(baseUI.getBase());

        // bola caiu no void?
        if (!bolaUI.estaAtiva()) {
            vidas--;

            if (vidas > 0) {
                bolaUI.inicializar();  // nova bola
            }

            mvprintw(0, 0, "Perdeste uma vida! Vidas restantes: %d", vidas);
            refresh();
            ch = getch();
            continue;
        }

        // ---- colisão bola-blocos ----
        FloatXY posBola = bolaUI.retornaPosicao();
        Blocos& blocos = blocosUI.getBlocos();

        if (blocos.colideEDestroiBloco(posBola)) {
            FloatXY v = bolaUI.retornaVelocidade();
            v.y = -v.y;
            bolaUI.mudaVelocidade(v.x, v.y);
        }

        // ---- desenhar (usando vetor de Desenha*) ----
        for (Desenha* d : desenhadores) {
            d->printar();
        }

        mvprintw(0, 0, "Vidas: %d | Pressiona 'q' para sair", vidas);

        refresh();
        ch = getch();
    }
}

void Jogo::ecrãGameOver()
{
    clear();

    const char* txtGO = "GAME OVER";
    const char* txtSpc = "PRESS SPACE TO PLAY AGAIN";
    const char* txtEsc = "PRESS ESC TO EXIT";

    int linhaCentro = LINES / 2;

    int colGO = (COLS - (int)std::strlen(txtGO)) / 2;
    int colSpc = (COLS - (int)std::strlen(txtSpc)) / 2;
    int colEsc = (COLS - (int)std::strlen(txtEsc)) / 2;

    mvprintw(linhaCentro - 1, colGO, "%s", txtGO);
    mvprintw(linhaCentro + 1, colSpc, "%s", txtSpc);
    mvprintw(linhaCentro + 2, colEsc, "%s", txtEsc);

    refresh();

    int tecla;
    do {
        tecla = getch();
    } while (tecla != ' ' && tecla != 27);

    // se for SPACE, voltamos ao while(correr) e começamos novo jogo
    // se for ESC, o while em correr() acaba na próxima iteração (aCorrer = false)
    if (tecla == 27) {
        // força sair do ciclo exterior na próxima volta
        // (forma simples: vidas = 0 já está, e ecrãInicial() vai devolver false se
        //  quiseres adaptar; mas como estamos num loop while em correr, chega
        // sair da função e deixar o while analisar de novo)
    }
}

