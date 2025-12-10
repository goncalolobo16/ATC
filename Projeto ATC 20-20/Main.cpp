#include <curses.h>
#include "BaseUI.h"
#include "BolaUI.h"
#include "BlocosUI.h"
#include <cstring>   

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);
    timeout(30);

    bool aCorrer = true;

    while (aCorrer) {

        // ---------- ECRÃ INICIAL ----------
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

        int teclaInicio;
        // espera até carregar SPACE ou ESC
        do {
            teclaInicio = getch();
        } while (teclaInicio != ' ' && teclaInicio != 27);

        if (teclaInicio == 27) {   // ESC -> sair logo
            aCorrer = false;
            break;
        }
        // se foi espaço, continua para iniciar o jogo


        // ---------- AQUI COMEÇA O JOGO MESMO ----------

        BaseUI   baseUI;
        BolaUI   bolaUI;
        BlocosUI blocosUI;

        baseUI.inicializar();
        bolaUI.inicializar();
        blocosUI.inicializar();

        int ch = 0;
        int vidas = 3;

        while (ch != 'q' && ch != 'Q' && vidas > 0) {
            clear();

            baseUI.moverBase(ch);
            bolaUI.moverBola(baseUI.getBase());

            // bola caiu no void?
            if (!bolaUI.estaAtiva()) {
                vidas--;

                if (vidas > 0) {
                    bolaUI.inicializar();
                }

                mvprintw(0, 0, "Perdeste uma vida! Vidas restantes: %d", vidas);
                refresh();
                ch = getch();
                continue;
            }

            // colisão bola-blocos
            FloatXY posBola = bolaUI.retornaPosicao();

            Blocos& blocos = blocosUI.getBlocos();
            if (blocos.colideEDestroiBloco(posBola)) {
                FloatXY v = bolaUI.retornaVelocidade();
                v.y = -v.y;
                bolaUI.mudaVelocidade(v.x, v.y);
            }

            // desenhar
            blocosUI.printar();
            baseUI.printar();
            bolaUI.printar();

            mvprintw(0, 0, "Vidas: %d | Pressiona 'q' para sair", vidas);

            refresh();
            ch = getch();
        }

        // aqui depois entra o teu ecrã de GAME OVER,
        // que já te mostrei antes: GAME OVER / SPACE para repetir / ESC para sair

        // ...
    }

    endwin();
    return 0;
}
