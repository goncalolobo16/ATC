#include <curses.h>
#include "BlocosUI.h"

/*int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);

    BlocosUI blocosUI;
    blocosUI.inicializar();

    int ch = 0;
    while (ch != 'q' && ch != 'Q') {
        clear();

        blocosUI.printar();

        refresh();
        ch = getch();
    }

    endwin();
    return 0;
}
*/