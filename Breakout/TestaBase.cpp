#include <curses.h>
#include "BaseUI.h"

/*int main() {
    // 1) Inicializar ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);     // esconder cursor (opcional)
    // timeout(50);  // opcional: animação mais fluida se quiseres

    // 2) Criar e inicializar a base
    BaseUI base;
    base.inicializar();   // usa COLS e LINES, mas não chama initscr

    int ch = 0;
    while (ch != 'q' && ch != 'Q') {
        clear();

        // 3) Desenhar a base
        base.printar();

        refresh();

        // 4) Ler tecla e mover a base
        ch = getch();
        base.moverBase(ch);
    }

    // 5) Sair do ncurses
    endwin();
    return 0;
}
*/