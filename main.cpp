#include <iostream>
#include <ncurses/ncurses.h>

using namespace std;

int main()
{
    initscr(); //inicjalizacja

    printw("alfonso kastel gandolfo"); //drukuje na ekranie znaki

    refresh(); //odœwierza

    getch(); //czeka na klikniêcie i zwraca integer wciœniêtego klawisza

    endwin(); //koniec ncurses

    return 0;
}
