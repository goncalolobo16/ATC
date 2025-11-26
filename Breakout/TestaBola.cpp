#include <curses.h>
#include "BolaUI.h"

/*int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);  
    timeout(50);   
    BolaUI bola;
    bola.inicializar();  

    int ch = 0;
    while (ch != 'q' && ch != 'Q') {
        clear();

        bola.moverBola(); 
        bola.printar(); 
        refresh();
        ch = getch();     
    }

    endwin();
    return 0;
}
*/