#include <iostream>
#include <ncurses/ncurses.h>

using namespace std;

int main()
{
    initscr(); //inicjalizacja

    printw("alfonso kastel gandolfo"); //drukuje na ekranie znaki

    refresh(); //od�wierza

    getch(); //czeka na klikni�cie i zwraca integer wci�ni�tego klawisza

    endwin(); //koniec ncurses

    return 0;
}
