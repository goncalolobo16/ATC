#include <curses.h>
#include "BaseUI.h"
#include "BolaUI.h"
#include "BlocosUI.h"

int main() {
    // --------- inicialização ncurses ----------
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);        // esconder cursor
    timeout(30);        // getch() espera ~30ms (animação)

    // --------- criar objetos UI ----------
    BaseUI   baseUI;
    BolaUI   bolaUI;
    BlocosUI blocosUI;

    // --------- inicializar ----------
    baseUI.inicializar();
    bolaUI.inicializar();
    blocosUI.inicializar();

    int ch = 0;

    // --------- game loop ----------
    while (ch != 'q' && ch != 'Q') {
        clear();

        // mover base com a última tecla
        baseUI.moverBase(ch);

        // atualizar bola (bate nas paredes/teto/void, mas não fechamos o jogo ainda)
        bolaUI.moverBola();

        // desenhar tudo
        blocosUI.printar();
        baseUI.printar();
        bolaUI.printar();

        mvprintw(0, 0, "Pressiona 'q' para sair");

        refresh();

        // lê tecla para a próxima iteração
        ch = getch();
    }

    endwin();
    return 0;
}
